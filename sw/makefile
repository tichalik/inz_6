

FLAGS = 

main : ./debug/src/html_response.o ./debug/src/main.o ./debug/src/parser.o ./debug/src/parsing_grammar_adapter.o ./debug/src/ptree.o ./debug/src/server.o ./debug/src/utils.o ./debug/src/mod_check_errors.o ./debug/src/mod_from_http.o ./debug/src/mod_to_http.o 
	g++ ./debug/src/html_response.o ./debug/src/main.o ./debug/src/parser.o ./debug/src/parsing_grammar_adapter.o ./debug/src/ptree.o ./debug/src/server.o ./debug/src/utils.o ./debug/src/mod_check_errors.o ./debug/src/mod_from_http.o ./debug/src/mod_to_http.o  -o ./debug/main

./debug/src/html_response.o: src//html_response.cpp src//html_response.h src//utils.h

	g++ -std=c++20 ./src//html_response.cpp -o ./debug/src/html_response.o  -I ./src/ -I ./src/from_http -I ./src/check_errors -I ./src/to_http -c $(FLAGS) 

./debug/src/main.o: src//main.cpp src//grammar.h src//utils.h src//symbol.h \
 src//non_terminals.h src//head.h src//rules.h src//parser.h \
 src//parsing_grammar_adapter.h src//word.h src//ptree.h src//server.h \
 src//httplib.h src/from_http/mod_from_http.h src/grammar.h src/word.h \
 src/error.h src/to_http/mod_to_http.h src/ptree.h \
 src/check_errors/mod_check_errors.h src//html_response.h

	g++ -std=c++20 ./src//main.cpp -o ./debug/src/main.o  -I ./src/ -I ./src/from_http -I ./src/check_errors -I ./src/to_http -c $(FLAGS) 

./debug/src/parser.o: src//parser.cpp src//parser.h src//parsing_grammar_adapter.h \
 src//grammar.h src//utils.h src//symbol.h src//non_terminals.h \
 src//head.h src//rules.h src//word.h src//ptree.h

	g++ -std=c++20 ./src//parser.cpp -o ./debug/src/parser.o  -I ./src/ -I ./src/from_http -I ./src/check_errors -I ./src/to_http -c $(FLAGS) 

./debug/src/parsing_grammar_adapter.o: src//parsing_grammar_adapter.cpp \
 src//parsing_grammar_adapter.h src//grammar.h src//utils.h src//symbol.h \
 src//non_terminals.h src//head.h src//rules.h

	g++ -std=c++20 ./src//parsing_grammar_adapter.cpp -o ./debug/src/parsing_grammar_adapter.o  -I ./src/ -I ./src/from_http -I ./src/check_errors -I ./src/to_http -c $(FLAGS) 

./debug/src/ptree.o: src//ptree.cpp src//ptree.h src//word.h src//symbol.h \
 src//grammar.h src//utils.h src//non_terminals.h src//head.h \
 src//rules.h

	g++ -std=c++20 ./src//ptree.cpp -o ./debug/src/ptree.o  -I ./src/ -I ./src/from_http -I ./src/check_errors -I ./src/to_http -c $(FLAGS) 

./debug/src/server.o: src//server.cpp src//server.h src//httplib.h \
 src/from_http/mod_from_http.h src/grammar.h src/utils.h src/symbol.h \
 src/non_terminals.h src/head.h src/rules.h src/word.h src/error.h \
 src/to_http/mod_to_http.h src/ptree.h src/word.h src/grammar.h \
 src/check_errors/mod_check_errors.h src//parsing_grammar_adapter.h \
 src//grammar.h src//utils.h src//html_response.h src//parser.h \
 src//word.h src//ptree.h

	g++ -std=c++20 ./src//server.cpp -o ./debug/src/server.o  -I ./src/ -I ./src/from_http -I ./src/check_errors -I ./src/to_http -c $(FLAGS) 

./debug/src/utils.o: src//utils.cpp src//utils.h

	g++ -std=c++20 ./src//utils.cpp -o ./debug/src/utils.o  -I ./src/ -I ./src/from_http -I ./src/check_errors -I ./src/to_http -c $(FLAGS) 

./debug/src/mod_check_errors.o: src/check_errors/mod_check_errors.cpp \
 src/check_errors/mod_check_errors.h src/grammar.h src/utils.h \
 src/symbol.h src/non_terminals.h src/head.h src/rules.h src/word.h \
 src/error.h

	g++ -std=c++20 ./src/check_errors/mod_check_errors.cpp -o ./debug/src/mod_check_errors.o  -I ./src/ -I ./src/from_http -I ./src/check_errors -I ./src/to_http -c $(FLAGS) 

./debug/src/mod_from_http.o: src/from_http/mod_from_http.cpp \
 src/from_http/mod_from_http.h src/grammar.h src/utils.h src/symbol.h \
 src/non_terminals.h src/head.h src/rules.h src/word.h src/error.h

	g++ -std=c++20 ./src/from_http/mod_from_http.cpp -o ./debug/src/mod_from_http.o  -I ./src/ -I ./src/from_http -I ./src/check_errors -I ./src/to_http -c $(FLAGS) 

./debug/src/mod_to_http.o: src/to_http/mod_to_http.cpp src/to_http/mod_to_http.h \
 src/ptree.h src/word.h src/symbol.h src/grammar.h src/utils.h \
 src/non_terminals.h src/head.h src/rules.h src/error.h

	g++ -std=c++20 ./src/to_http/mod_to_http.cpp -o ./debug/src/mod_to_http.o  -I ./src/ -I ./src/from_http -I ./src/check_errors -I ./src/to_http -c $(FLAGS) 


clean:
	rm -d -r debug
	mkdir debug
	mkdir debug/src

