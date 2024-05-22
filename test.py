import os
import datetime
def read_file(filename):
    f = open(filename)
    res = f.read()
    f.close()
    return res

def save_file(filename, content):
    f = open(filename, "w")
    f.write(content)
    f.close()


def execute(command):
    tmp_filename = "lkasjdlkajdflkejfjasdnkasfajweoi2jof.tmp"
    os.system( command + " > " + tmp_filename)
    res = read_file(tmp_filename)
    os.system( "rm " + tmp_filename)
    return res
    
    
reset = "git reset --hard"
make = "make"
make_clean = "make clean"
run = "./debug/main"
    

commands = [
    reset,
    make_clean,
    make,
    run,
    run,
    run,
    run,
    run,
    run,
    run,
    run,
    ]
    
    
def is_ok(txt):
    if "<<a b c d e f>>" in txt:
        return "1"
    else:
        return "0"
        
txt = ""
txt += str(commands)+"\n"
    
for i in range(20):
    res = [is_ok(execute(c)) for c in commands if c==run]
    
    txt += " ".join(res[:7])+"\n"
    txt += " ".join(res[7:])+"\n"
            
    txt += 60*"-"+"\n"

now = str(datetime.datetime.now()).replace(" ","_").replace(":",".")
save_file("notes/results" +now + ".txt", txt)