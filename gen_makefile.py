# prints out a makefile 
# generated for files from `path` directory (non recursive)
# the makefile generates output to the `dest` directory
# where `<dest>/main` is the name of the executable and 
# `<dest>/src` stores the .o files

import os 

dest = "./debug/"
path = "./src/"

#stupid name to prevent overwriting actual files named `tmp` or similarly
TMP = "ADAADA"  

res = ""
link_files = ""

for f in os.listdir(path):
    if f.endswith(".cpp"):
        
        target = dest + "src/"+f.replace(".cpp",".o")
        dependency = path+f
        
        os.system( "g++ [[FILENAME]] -MM -I [[PATH]] > [[TMP]]"\
            .replace("[[FILENAME]]", dependency)\
            .replace("[[PATH]]", path)\
            .replace("[[TMP]]", TMP))
        
        F = open(TMP)
        head = F.read()
        F.close()
        
        os.system( "rm " + TMP )
        
        head = dest +"src/"+ head 
        body = "\tg++ -std=c++20 [[SOURCE]] -o [[DESTINATION]] -c $(FLAGS) "\
            .replace("[[SOURCE]]", dependency)\
            .replace("[[DESTINATION]]", target)
            
        link_files += target+ " "
        
        res += head+ "\n"+body +"\n\n"
        
res = """

FLAGS = 

main : """+ link_files + "\n" \
    +"\tg++ " +link_files + " -o " + dest + "main\n\n" \
    + res

res += """
clean:
    rm -d -r debug
    mkdir debug
    mkdir debug/src
""".replace("    ","\t")

print (res)