

FLAGS = 

main : ./debug/src/model.o ./debug/src/utils.o ./debug/src/main.o ./debug/src/server.o ./debug/src/mod_to_http.o ./debug/src/html_response.o ./debug/src/parsing_grammar_adapter.o ./debug/src/dechomskify.o ./debug/src/chomskify.o ./debug/src/mod_parser.o ./debug/src/ptable.o ./debug/src/mod_postprocess_trees.o ./debug/src/mod_from_http.o ./debug/src/mod_check_errors.o 
	g++ ./debug/src/model.o ./debug/src/utils.o ./debug/src/main.o ./debug/src/server.o ./debug/src/mod_to_http.o ./debug/src/html_response.o ./debug/src/parsing_grammar_adapter.o ./debug/src/dechomskify.o ./debug/src/chomskify.o ./debug/src/mod_parser.o ./debug/src/ptable.o ./debug/src/mod_postprocess_trees.o ./debug/src/mod_from_http.o ./debug/src/mod_check_errors.o  -o ./debug/main

./debug/src/model.o: src//model.cpp src//model.h src/from_http/mod_from_http.h \
 src/grammar.h src/utils.h src/symbol.h src/non_terminals.h src/head.h \
 src/rules.h src/word.h src/error.h src/check_errors/mod_check_errors.h \
 src/parser/mod_parser.h src/parser/parsing_grammar_adapter.h \
 src/parser/chomsky_grammar.h src/non_terminals.h src/symbol.h src/head.h \
 src/rules.h src/utils.h src/parser/ptable.h src/ptree.h src/word.h \
 src/grammar.h src/parser/chomskify.h src/parser/dechomskify.h

	g++ -std=c++20 ./src//model.cpp -o ./debug/src/model.o  -I ./src/to_http -I ./src/parser -I ./src/ -I ./src/check_errors -I ./src/postprocess_trees -I ./src/from_http -c $(FLAGS) 

./debug/src/utils.o: src//utils.cpp src//utils.h

	g++ -std=c++20 ./src//utils.cpp -o ./debug/src/utils.o  -I ./src/to_http -I ./src/parser -I ./src/ -I ./src/check_errors -I ./src/postprocess_trees -I ./src/from_http -c $(FLAGS) 

./debug/src/main.o: src//main.cpp src//server.h src//httplib.h \
 src/to_http/mod_to_http.h src/ptree.h src/word.h src/symbol.h \
 src/grammar.h src/utils.h src/non_terminals.h src/head.h src/rules.h \
 src/error.h src/to_http/html_response.h src/utils.h \
 src/to_http/html_response.h src//model.h src/from_http/mod_from_http.h \
 src/grammar.h src/word.h src/check_errors/mod_check_errors.h \
 src/parser/mod_parser.h src/parser/parsing_grammar_adapter.h \
 src/parser/chomsky_grammar.h src/non_terminals.h src/symbol.h src/head.h \
 src/rules.h src/parser/ptable.h src/parser/chomskify.h \
 src/parser/dechomskify.h

	g++ -std=c++20 ./src//main.cpp -o ./debug/src/main.o  -I ./src/to_http -I ./src/parser -I ./src/ -I ./src/check_errors -I ./src/postprocess_trees -I ./src/from_http -c $(FLAGS) 

./debug/src/server.o: src//server.cpp src//server.h src//httplib.h \
 src/to_http/mod_to_http.h src/ptree.h src/word.h src/symbol.h \
 src/grammar.h src/utils.h src/non_terminals.h src/head.h src/rules.h \
 src/error.h src/to_http/html_response.h src/utils.h \
 src/to_http/html_response.h src//model.h src/from_http/mod_from_http.h \
 src/grammar.h src/word.h src/check_errors/mod_check_errors.h \
 src/parser/mod_parser.h src/parser/parsing_grammar_adapter.h \
 src/parser/chomsky_grammar.h src/non_terminals.h src/symbol.h src/head.h \
 src/rules.h src/parser/ptable.h src/parser/chomskify.h \
 src/parser/dechomskify.h

	g++ -std=c++20 ./src//server.cpp -o ./debug/src/server.o  -I ./src/to_http -I ./src/parser -I ./src/ -I ./src/check_errors -I ./src/postprocess_trees -I ./src/from_http -c $(FLAGS) 

./debug/src/mod_to_http.o: src/to_http/mod_to_http.cpp src/to_http/mod_to_http.h \
 src/ptree.h src/word.h src/symbol.h src/grammar.h src/utils.h \
 src/non_terminals.h src/head.h src/rules.h src/error.h \
 src/to_http/html_response.h src/utils.h

	g++ -std=c++20 ./src/to_http/mod_to_http.cpp -o ./debug/src/mod_to_http.o  -I ./src/to_http -I ./src/parser -I ./src/ -I ./src/check_errors -I ./src/postprocess_trees -I ./src/from_http -c $(FLAGS) 

./debug/src/html_response.o: src/to_http/html_response.cpp \
 src/to_http/html_response.h src/utils.h

	g++ -std=c++20 ./src/to_http/html_response.cpp -o ./debug/src/html_response.o  -I ./src/to_http -I ./src/parser -I ./src/ -I ./src/check_errors -I ./src/postprocess_trees -I ./src/from_http -c $(FLAGS) 

./debug/src/parsing_grammar_adapter.o: src/parser/parsing_grammar_adapter.cpp \
 src/parser/parsing_grammar_adapter.h src/parser/chomsky_grammar.h \
 src/non_terminals.h src/symbol.h src/symbol.h src/head.h src/rules.h \
 src/utils.h src/non_terminals.h src/utils.h

	g++ -std=c++20 ./src/parser/parsing_grammar_adapter.cpp -o ./debug/src/parsing_grammar_adapter.o  -I ./src/to_http -I ./src/parser -I ./src/ -I ./src/check_errors -I ./src/postprocess_trees -I ./src/from_http -c $(FLAGS) 

./debug/src/dechomskify.o: src/parser/dechomskify.cpp src/parser/dechomskify.h \
 src/ptree.h src/word.h src/symbol.h src/grammar.h src/utils.h \
 src/non_terminals.h src/head.h src/rules.h src/parser/chomsky_grammar.h \
 src/non_terminals.h src/symbol.h src/head.h src/rules.h

	g++ -std=c++20 ./src/parser/dechomskify.cpp -o ./debug/src/dechomskify.o  -I ./src/to_http -I ./src/parser -I ./src/ -I ./src/check_errors -I ./src/postprocess_trees -I ./src/from_http -c $(FLAGS) 

./debug/src/chomskify.o: src/parser/chomskify.cpp src/parser/chomskify.h \
 src/grammar.h src/utils.h src/symbol.h src/non_terminals.h src/head.h \
 src/rules.h src/error.h src/parser/chomsky_grammar.h src/non_terminals.h \
 src/symbol.h src/head.h src/rules.h src/utils.h

	g++ -std=c++20 ./src/parser/chomskify.cpp -o ./debug/src/chomskify.o  -I ./src/to_http -I ./src/parser -I ./src/ -I ./src/check_errors -I ./src/postprocess_trees -I ./src/from_http -c $(FLAGS) 

./debug/src/mod_parser.o: src/parser/mod_parser.cpp src/parser/mod_parser.h \
 src/parser/parsing_grammar_adapter.h src/parser/chomsky_grammar.h \
 src/non_terminals.h src/symbol.h src/symbol.h src/head.h src/rules.h \
 src/utils.h src/non_terminals.h src/utils.h src/parser/ptable.h \
 src/word.h src/grammar.h src/head.h src/rules.h src/error.h src/ptree.h \
 src/word.h src/grammar.h src/parser/chomskify.h src/parser/dechomskify.h

	g++ -std=c++20 ./src/parser/mod_parser.cpp -o ./debug/src/mod_parser.o  -I ./src/to_http -I ./src/parser -I ./src/ -I ./src/check_errors -I ./src/postprocess_trees -I ./src/from_http -c $(FLAGS) 

./debug/src/ptable.o: src/parser/ptable.cpp src/parser/ptable.h src/word.h \
 src/symbol.h src/symbol.h

	g++ -std=c++20 ./src/parser/ptable.cpp -o ./debug/src/ptable.o  -I ./src/to_http -I ./src/parser -I ./src/ -I ./src/check_errors -I ./src/postprocess_trees -I ./src/from_http -c $(FLAGS) 

./debug/src/mod_postprocess_trees.o: src/postprocess_trees/mod_postprocess_trees.cpp \
 src/postprocess_trees/mod_postprocess_trees.h src/grammar.h src/utils.h \
 src/symbol.h src/non_terminals.h src/head.h src/rules.h src/word.h \
 src/ptree.h src/word.h src/grammar.h

	g++ -std=c++20 ./src/postprocess_trees/mod_postprocess_trees.cpp -o ./debug/src/mod_postprocess_trees.o  -I ./src/to_http -I ./src/parser -I ./src/ -I ./src/check_errors -I ./src/postprocess_trees -I ./src/from_http -c $(FLAGS) 

./debug/src/mod_from_http.o: src/from_http/mod_from_http.cpp \
 src/from_http/mod_from_http.h src/grammar.h src/utils.h src/symbol.h \
 src/non_terminals.h src/head.h src/rules.h src/word.h src/error.h

	g++ -std=c++20 ./src/from_http/mod_from_http.cpp -o ./debug/src/mod_from_http.o  -I ./src/to_http -I ./src/parser -I ./src/ -I ./src/check_errors -I ./src/postprocess_trees -I ./src/from_http -c $(FLAGS) 

./debug/src/mod_check_errors.o: src/check_errors/mod_check_errors.cpp \
 src/check_errors/mod_check_errors.h src/grammar.h src/utils.h \
 src/symbol.h src/non_terminals.h src/head.h src/rules.h src/word.h \
 src/error.h

	g++ -std=c++20 ./src/check_errors/mod_check_errors.cpp -o ./debug/src/mod_check_errors.o  -I ./src/to_http -I ./src/parser -I ./src/ -I ./src/check_errors -I ./src/postprocess_trees -I ./src/from_http -c $(FLAGS) 


clean:
	rm -d -r debug
	mkdir debug
	mkdir debug/src

