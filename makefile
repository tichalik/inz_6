

FLAGS = 

main : ./debug/src/grammar.o ./debug/src/html_response.o ./debug/src/http_grammar_adapter.o ./debug/src/main.o ./debug/src/parser.o ./debug/src/parsing_grammar_adapter.o ./debug/src/ptree.o ./debug/src/server.o ./debug/src/tester.o ./debug/src/utils.o ./debug/src/word.o 
	g++ ./debug/src/grammar.o ./debug/src/html_response.o ./debug/src/http_grammar_adapter.o ./debug/src/main.o ./debug/src/parser.o ./debug/src/parsing_grammar_adapter.o ./debug/src/ptree.o ./debug/src/server.o ./debug/src/tester.o ./debug/src/utils.o ./debug/src/word.o  -o ./debug/main

./debug/src/grammar.o: src/grammar.cpp src/grammar.h src/utils.h src/error.h

	g++ -std=c++20 ./src/grammar.cpp -o ./debug/src/grammar.o -c $(FLAGS) 

./debug/src/html_response.o: src/html_response.cpp src/html_response.h src/utils.h

	g++ -std=c++20 ./src/html_response.cpp -o ./debug/src/html_response.o -c $(FLAGS) 

./debug/src/http_grammar_adapter.o: src/http_grammar_adapter.cpp \
 src/http_grammar_adapter.h src/grammar.h src/utils.h src/error.h

	g++ -std=c++20 ./src/http_grammar_adapter.cpp -o ./debug/src/http_grammar_adapter.o -c $(FLAGS) 

./debug/src/main.o: src/main.cpp src/grammar.h src/utils.h src/error.h src/parser.h \
 src/parsing_grammar_adapter.h src/word.h src/ptree.h src/tester.h \
 src/server.h src/httplib.h src/http_grammar_adapter.h \
 src/html_response.h

	g++ -std=c++20 ./src/main.cpp -o ./debug/src/main.o -c $(FLAGS) 

./debug/src/parser.o: src/parser.cpp src/parser.h src/parsing_grammar_adapter.h \
 src/grammar.h src/utils.h src/error.h src/word.h src/ptree.h

	g++ -std=c++20 ./src/parser.cpp -o ./debug/src/parser.o -c $(FLAGS) 

./debug/src/parsing_grammar_adapter.o: src/parsing_grammar_adapter.cpp \
 src/parsing_grammar_adapter.h src/grammar.h src/utils.h src/error.h

	g++ -std=c++20 ./src/parsing_grammar_adapter.cpp -o ./debug/src/parsing_grammar_adapter.o -c $(FLAGS) 

./debug/src/ptree.o: src/ptree.cpp src/ptree.h src/word.h src/grammar.h src/utils.h \
 src/error.h

	g++ -std=c++20 ./src/ptree.cpp -o ./debug/src/ptree.o -c $(FLAGS) 

./debug/src/server.o: src/server.cpp src/server.h src/httplib.h src/grammar.h \
 src/utils.h src/error.h src/http_grammar_adapter.h \
 src/parsing_grammar_adapter.h src/html_response.h src/parser.h \
 src/word.h src/ptree.h

	g++ -std=c++20 ./src/server.cpp -o ./debug/src/server.o -c $(FLAGS) 

./debug/src/tester.o: src/tester.cpp src/tester.h src/parser.h \
 src/parsing_grammar_adapter.h src/grammar.h src/utils.h src/error.h \
 src/word.h src/ptree.h

	g++ -std=c++20 ./src/tester.cpp -o ./debug/src/tester.o -c $(FLAGS) 

./debug/src/utils.o: src/utils.cpp src/utils.h

	g++ -std=c++20 ./src/utils.cpp -o ./debug/src/utils.o -c $(FLAGS) 

./debug/src/word.o: src/word.cpp src/word.h src/grammar.h src/utils.h src/error.h

	g++ -std=c++20 ./src/word.cpp -o ./debug/src/word.o -c $(FLAGS) 


clean:
	rm -d -r debug
	mkdir debug
	mkdir debug/src

