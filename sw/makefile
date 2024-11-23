

FLAGS = 

main : ./debug/src/model.o ./debug/src/utils.o ./debug/src/main.o ./debug/src/server.o ./debug/src/mod_to_http.o ./debug/src/html_response.o ./debug/src/parsing_grammar_adapter.o ./debug/src/mod_parser.o ./debug/src/tokenizer.o ./debug/src/mod_from_http.o ./debug/src/mod_check_errors.o ./debug/src/mod_visualize_grammar.o 
	g++ ./debug/src/model.o ./debug/src/utils.o ./debug/src/main.o ./debug/src/server.o ./debug/src/mod_to_http.o ./debug/src/html_response.o ./debug/src/parsing_grammar_adapter.o ./debug/src/mod_parser.o ./debug/src/tokenizer.o ./debug/src/mod_from_http.o ./debug/src/mod_check_errors.o ./debug/src/mod_visualize_grammar.o  -o ./debug/main

./debug/src/model.o: src//model.cpp src//model.h src/from_http/mod_from_http.h \
 src/grammar.h src/utils.h src/symbol.h src/non_terminals.h src/head.h \
 src/rules.h src/word.h src/error.h src/from_http/token.h \
 src/check_errors/mod_check_errors.h src/parser/mod_parser.h \
 src/parser/parsing_grammar_adapter.h src/utils.h src/sppf.h src/pnode.h \
 src/pnode.h src/visualize_grammar/mod_visualize_grammar.h src/vnode.h

	g++ -std=c++20 ./src//model.cpp -o ./debug/src/model.o  -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/ -I ./src/visualize_grammar -I ./src/to_http -c $(FLAGS) 

./debug/src/utils.o: src//utils.cpp src//utils.h

	g++ -std=c++20 ./src//utils.cpp -o ./debug/src/utils.o  -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/ -I ./src/visualize_grammar -I ./src/to_http -c $(FLAGS) 

./debug/src/main.o: src//main.cpp src//server.h src//httplib.h \
 src/to_http/mod_to_http.h src/error.h src/to_http/html_response.h \
 src/utils.h src/vnode.h src/symbol.h src/sppf.h src/rules.h src/utils.h \
 src/non_terminals.h src/pnode.h src/to_http/html_response.h src//model.h \
 src/from_http/mod_from_http.h src/grammar.h src/head.h src/word.h \
 src/from_http/token.h src/check_errors/mod_check_errors.h \
 src/parser/mod_parser.h src/parser/parsing_grammar_adapter.h src/pnode.h \
 src/visualize_grammar/mod_visualize_grammar.h

	g++ -std=c++20 ./src//main.cpp -o ./debug/src/main.o  -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/ -I ./src/visualize_grammar -I ./src/to_http -c $(FLAGS) 

./debug/src/server.o: src//server.cpp src//server.h src//httplib.h \
 src/to_http/mod_to_http.h src/error.h src/to_http/html_response.h \
 src/utils.h src/vnode.h src/symbol.h src/sppf.h src/rules.h src/utils.h \
 src/non_terminals.h src/pnode.h src/to_http/html_response.h src//model.h \
 src/from_http/mod_from_http.h src/grammar.h src/head.h src/word.h \
 src/from_http/token.h src/check_errors/mod_check_errors.h \
 src/parser/mod_parser.h src/parser/parsing_grammar_adapter.h src/pnode.h \
 src/visualize_grammar/mod_visualize_grammar.h

	g++ -std=c++20 ./src//server.cpp -o ./debug/src/server.o  -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/ -I ./src/visualize_grammar -I ./src/to_http -c $(FLAGS) 

./debug/src/mod_to_http.o: src/to_http/mod_to_http.cpp src/to_http/mod_to_http.h \
 src/error.h src/to_http/html_response.h src/utils.h src/vnode.h \
 src/symbol.h src/sppf.h src/rules.h src/utils.h src/non_terminals.h \
 src/pnode.h

	g++ -std=c++20 ./src/to_http/mod_to_http.cpp -o ./debug/src/mod_to_http.o  -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/ -I ./src/visualize_grammar -I ./src/to_http -c $(FLAGS) 

./debug/src/html_response.o: src/to_http/html_response.cpp \
 src/to_http/html_response.h src/utils.h

	g++ -std=c++20 ./src/to_http/html_response.cpp -o ./debug/src/html_response.o  -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/ -I ./src/visualize_grammar -I ./src/to_http -c $(FLAGS) 

./debug/src/parsing_grammar_adapter.o: src/parser/parsing_grammar_adapter.cpp \
 src/parser/parsing_grammar_adapter.h src/utils.h src/grammar.h \
 src/utils.h src/symbol.h src/non_terminals.h src/head.h src/rules.h

	g++ -std=c++20 ./src/parser/parsing_grammar_adapter.cpp -o ./debug/src/parsing_grammar_adapter.o  -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/ -I ./src/visualize_grammar -I ./src/to_http -c $(FLAGS) 

./debug/src/mod_parser.o: src/parser/mod_parser.cpp src/parser/mod_parser.h \
 src/parser/parsing_grammar_adapter.h src/utils.h src/grammar.h \
 src/utils.h src/symbol.h src/non_terminals.h src/head.h src/rules.h \
 src/error.h src/word.h src/sppf.h src/pnode.h src/pnode.h

	g++ -std=c++20 ./src/parser/mod_parser.cpp -o ./debug/src/mod_parser.o  -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/ -I ./src/visualize_grammar -I ./src/to_http -c $(FLAGS) 

./debug/src/tokenizer.o: src/from_http/tokenizer.cpp src/from_http/mod_from_http.h \
 src/grammar.h src/utils.h src/symbol.h src/non_terminals.h src/head.h \
 src/rules.h src/word.h src/error.h src/from_http/token.h

	g++ -std=c++20 ./src/from_http/tokenizer.cpp -o ./debug/src/tokenizer.o  -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/ -I ./src/visualize_grammar -I ./src/to_http -c $(FLAGS) 

./debug/src/mod_from_http.o: src/from_http/mod_from_http.cpp \
 src/from_http/mod_from_http.h src/grammar.h src/utils.h src/symbol.h \
 src/non_terminals.h src/head.h src/rules.h src/word.h src/error.h \
 src/from_http/token.h

	g++ -std=c++20 ./src/from_http/mod_from_http.cpp -o ./debug/src/mod_from_http.o  -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/ -I ./src/visualize_grammar -I ./src/to_http -c $(FLAGS) 

./debug/src/mod_check_errors.o: src/check_errors/mod_check_errors.cpp \
 src/check_errors/mod_check_errors.h src/grammar.h src/utils.h \
 src/symbol.h src/non_terminals.h src/head.h src/rules.h src/word.h \
 src/error.h

	g++ -std=c++20 ./src/check_errors/mod_check_errors.cpp -o ./debug/src/mod_check_errors.o  -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/ -I ./src/visualize_grammar -I ./src/to_http -c $(FLAGS) 

./debug/src/mod_visualize_grammar.o: src/visualize_grammar/mod_visualize_grammar.cpp \
 src/visualize_grammar/mod_visualize_grammar.h src/vnode.h src/symbol.h \
 src/grammar.h src/utils.h src/non_terminals.h src/head.h src/rules.h

	g++ -std=c++20 ./src/visualize_grammar/mod_visualize_grammar.cpp -o ./debug/src/mod_visualize_grammar.o  -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/ -I ./src/visualize_grammar -I ./src/to_http -c $(FLAGS) 


clean:
	rm -d -r debug
	mkdir debug
	mkdir debug/src

