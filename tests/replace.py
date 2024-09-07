def read_file(filename):
	f = open(filename)
	txt = f.read()
	f.close()
	return txt

def save_file(txt, filename):
	f = open(filename, "w")
	f.write(txt)
	f.close()

import re

def re_replace(filename, what, with_what):
	txt = read_file(filename)
	txt = re.sub(what, with_what, txt)
	save_file(txt, filename)


re_replace("src/tst/parser/tst_mp_extract_trees.cpp", 
	"""{
.+std::cout(.+)
.+std::cout(.+)
.+std::cout(.+)""",
	"""
	std::cout \\1
	std::cout \\2
	std::cout \\3
	{"""
)

