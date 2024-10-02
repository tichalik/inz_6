
# ContextFreeParsing101

# What it is 

Just like regex101.com helps with using regexes, ContextFreeParsing101 aims to help 
you in your context-free parsing needs. It is a served based app.

## supported functionalities:
 * define context-free formal grammar (terminals, nonterminals, head, production rules) and check it for formal errors
 * produce all parsings of a word from defined grammar
 * include incomplete parsings of the word -- those that do not belong to a parse tree spanning the whole word and having grammar head as its root
 
## limitations
 * all rules must have 2 or more symbols on LHS

# Project overview

The `sw` directory contains source files as well as their documentation.
The `tests` directory contains unit tests for the software.
 
# How to use 

To compile the software run `make` in the `sw` directory:

	cd sw
	make
	
To run the sofware call `debug/main` from the `sw` directory. The server opens on port `8413`.

	cd sw
	./debug/main
