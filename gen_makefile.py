import os 

def save_flle(filename, txt):
    f = open(filename, "w")
    f.write(txt)
    f.close()

def get_includes(path):
    res = []
    for root, dirs, files in os.walk(path):
        for f in files:
            if f.endswith(".h"):
                res.append(root)
                break
    return " -I " + " -I ".join(res)

def run_command(command):
    TMP = "ADAADA"  #stupid name to prevent overwriting actual files named `tmp` or similarly
    os.system(command + " > " + TMP)
    F = open(TMP)
    res = F.read()
    F.close()
    os.system( "rm " + TMP )
    return res

def get_rules(path, includes, prefix, flags):
    res = ""
    links = ""
    for root, dirs, files in os.walk(path):
        for f in files:
            if f.endswith(".cpp"):

                dependency = root+"/"+f

                cmd = "g++ [[FILENAME]] -MM [[INCLUDES]]"\
                    .replace("[[FILENAME]]", dependency)\
                    .replace("[[INCLUDES]]", includes)

                head = "./build/.o/"+prefix+run_command(cmd)[:-1] + " ./build/.o\n"
                target = head.split(":")[0]

                body = "\tg++ [[DEPENDENCY]] -o [[TARGET]] [[INCLUDES]] [[FLAGS]] -c $(FLAGS) "\
                   .replace("[[DEPENDENCY]]", dependency)\
                   .replace("[[INCLUDES]]", includes)\
                   .replace("[[FLAGS]]", flags)\
                   .replace("[[TARGET]]", target)

                
                res += head + body +"\n\n"
                links += target + " "
    return (res, links)

def get_link_rule(target, links):
    return """./build/[[TARGET]] : [[LINKS]]
\tg++ [[LINKS]] -o ./build/[[TARGET]]"""\
        .replace("[[TARGET]]", target)\
        .replace("[[LINKS]]", links)

sw_includes = get_includes("./src")
tst_includes = sw_includes + get_includes("./tests")

SW_RULES, sw_links = get_rules("./src", sw_includes, "sw_", "")
tst_tst_rules, tst_tst_links = get_rules("./tests", tst_includes, "tst_", " -fno-access-control ")
tst_sw_rules, tst_sw_links = get_rules("./src", tst_includes, "tst_", " -fno-access-control ")

TESTS_RULES = tst_tst_rules + "\n" + tst_sw_rules
tst_links = tst_tst_links + " " + tst_sw_links.replace("./build/.o/tst_main.o", "")

APP_RULE = get_link_rule("app", sw_links)
TESTS_RULE = get_link_rule("tests", tst_links)

res = """

FLAGS = 

[[APP_RULE]]

[[TESTS_RULE]]
    

tests: ./build/tests
    ./build/tests > ./build/test_results.txt

[[SW_RULES]]

[[TESTS_RULES]]

clean: ./build ./build/.o
    rm ./build -r
    mkdir build
    mkdir build/.o
    
./build/.o: ./build
    mkdir -p ./build/.o

./build:
    mkdir -p ./build
    
""".replace("    ", "\t")\
    .replace("[[APP_RULE]]", APP_RULE )\
    .replace("[[TESTS_RULE]]", TESTS_RULE )\
    .replace("[[SW_RULES]]", SW_RULES )\
    .replace("[[TESTS_RULES]]", TESTS_RULES )

save_flle("makefile", res)
