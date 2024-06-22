

FLAGS = 

main : ./debug/src/error.o ./debug/src/errorable.o ./debug/src/grammar.o ./debug/src/head.o ./debug/src/html_response.o ./debug/src/main.o ./debug/src/non_terminals.o ./debug/src/parser.o ./debug/src/parsing_grammar_adapter.o ./debug/src/ptree.o ./debug/src/rules.o ./debug/src/server.o ./debug/src/symbol.o ./debug/src/utils.o ./debug/src/word.o ./debug/src/mod_from_http.o ./debug/src/mod_to_http.o 
	g++ ./debug/src/error.o ./debug/src/errorable.o ./debug/src/grammar.o ./debug/src/head.o ./debug/src/html_response.o ./debug/src/main.o ./debug/src/non_terminals.o ./debug/src/parser.o ./debug/src/parsing_grammar_adapter.o ./debug/src/ptree.o ./debug/src/rules.o ./debug/src/server.o ./debug/src/symbol.o ./debug/src/utils.o ./debug/src/word.o ./debug/src/mod_from_http.o ./debug/src/mod_to_http.o  -o ./debug/main

./debug/src/error.o: src//error.cpp src//error.h

	g++ -std=c++20 ./src//error.cpp -o ./debug/src/error.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/errorable.o: src//errorable.cpp src//errorable.h src//error.h

	g++ -std=c++20 ./src//errorable.cpp -o ./debug/src/errorable.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/grammar.o: src//grammar.cpp src//grammar.h src//utils.h src//errorable.h \
 src//error.h src//symbol.h src//non_terminals.h src//head.h src//rules.h

	g++ -std=c++20 ./src//grammar.cpp -o ./debug/src/grammar.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/head.o: src//head.cpp src//head.h src//utils.h src//errorable.h \
 src//error.h src//symbol.h src//non_terminals.h

	g++ -std=c++20 ./src//head.cpp -o ./debug/src/head.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/html_response.o: src//html_response.cpp src//html_response.h src//utils.h

	g++ -std=c++20 ./src//html_response.cpp -o ./debug/src/html_response.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/main.o: src//main.cpp src//grammar.h src//utils.h src//errorable.h \
 src//error.h src//symbol.h src//non_terminals.h src//head.h src//rules.h \
 src//parser.h src//parsing_grammar_adapter.h src//word.h src//ptree.h \
 src//server.h src//httplib.h src/from_http/mod_from_http.h src/grammar.h \
 src/word.h src/error.h src/to_http/mod_to_http.h src//html_response.h

	g++ -std=c++20 ./src//main.cpp -o ./debug/src/main.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/non_terminals.o: src//non_terminals.cpp src//non_terminals.h \
 src//symbol.h src//errorable.h src//error.h

	g++ -std=c++20 ./src//non_terminals.cpp -o ./debug/src/non_terminals.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/parser.o: src//parser.cpp src//parser.h src//parsing_grammar_adapter.h \
 src//grammar.h src//utils.h src//errorable.h src//error.h src//symbol.h \
 src//non_terminals.h src//head.h src//rules.h src//word.h src//ptree.h

	g++ -std=c++20 ./src//parser.cpp -o ./debug/src/parser.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/parsing_grammar_adapter.o: src//parsing_grammar_adapter.cpp \
 src//parsing_grammar_adapter.h src//grammar.h src//utils.h \
 src//errorable.h src//error.h src//symbol.h src//non_terminals.h \
 src//head.h src//rules.h

	g++ -std=c++20 ./src//parsing_grammar_adapter.cpp -o ./debug/src/parsing_grammar_adapter.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/ptree.o: src//ptree.cpp src//ptree.h src//word.h src//errorable.h \
 src//error.h src//symbol.h src//non_terminals.h src//grammar.h \
 src//utils.h src//head.h src//rules.h

	g++ -std=c++20 ./src//ptree.cpp -o ./debug/src/ptree.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/rules.o: src//rules.cpp src//rules.h src//utils.h src//errorable.h \
 src//error.h src//symbol.h src//non_terminals.h

	g++ -std=c++20 ./src//rules.cpp -o ./debug/src/rules.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/server.o: src//server.cpp src//server.h src//httplib.h \
 src/from_http/mod_from_http.h src/grammar.h src/utils.h src/errorable.h \
 src/error.h src/symbol.h src/non_terminals.h src/head.h src/rules.h \
 src/word.h src/error.h src/to_http/mod_to_http.h \
 src//parsing_grammar_adapter.h src//grammar.h src//utils.h \
 src//html_response.h src//parser.h src//word.h src//ptree.h

	g++ -std=c++20 ./src//server.cpp -o ./debug/src/server.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/symbol.o: src//symbol.cpp src//symbol.h src//errorable.h src//error.h

	g++ -std=c++20 ./src//symbol.cpp -o ./debug/src/symbol.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/utils.o: src//utils.cpp src//utils.h

	g++ -std=c++20 ./src//utils.cpp -o ./debug/src/utils.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/word.o: src//word.cpp src//word.h src//errorable.h src//error.h \
 src//symbol.h src//non_terminals.h

	g++ -std=c++20 ./src//word.cpp -o ./debug/src/word.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/mod_from_http.o: src/from_http/mod_from_http.cpp \
 src/from_http/mod_from_http.h src/grammar.h src/utils.h src/errorable.h \
 src/error.h src/symbol.h src/non_terminals.h src/head.h src/rules.h \
 src/word.h src/error.h

	g++ -std=c++20 ./src/from_http/mod_from_http.cpp -o ./debug/src/mod_from_http.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 

./debug/src/mod_to_http.o: src/to_http/mod_to_http.cpp src/to_http/mod_to_http.h \
 src/ptree.h src/word.h src/errorable.h src/error.h src/symbol.h \
 src/non_terminals.h src/grammar.h src/utils.h src/head.h src/rules.h \
 src/error.h

	g++ -std=c++20 ./src/to_http/mod_to_http.cpp -o ./debug/src/mod_to_http.o  -I ./src/from_http -I ./src/ -I ./src/to_http -c $(FLAGS) 


clean:
	rm -d -r debug
	mkdir debug
	mkdir debug/src

