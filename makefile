

FLAGS = 

main : ./debug/src/http_grammar_adapter.o ./debug/src/main.o ./debug/src/non_terminals.o 
	g++ ./debug/src/http_grammar_adapter.o ./debug/src/main.o ./debug/src/non_terminals.o  -o ./debug/main

./debug/src/http_grammar_adapter.o: src/http_grammar_adapter.cpp \
 src/http_grammar_adapter.h src/non_terminals.h src/symbol.h

	g++ -std=c++20 ./src/http_grammar_adapter.cpp -o ./debug/src/http_grammar_adapter.o -c $(FLAGS) 

./debug/src/main.o: src/main.cpp src/http_grammar_adapter.h src/non_terminals.h \
 src/symbol.h

	g++ -std=c++20 ./src/main.cpp -o ./debug/src/main.o -c $(FLAGS) 

./debug/src/non_terminals.o: src/non_terminals.cpp src/non_terminals.h src/symbol.h

	g++ -std=c++20 ./src/non_terminals.cpp -o ./debug/src/non_terminals.o -c $(FLAGS) 


clean:
	rm -d -r debug
	mkdir debug
	mkdir debug/src

