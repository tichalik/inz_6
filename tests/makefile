

FLAGS = -fno-access-control

main : ./debug/src/main.o ./debug/src/grammar.o ./debug/src/head.o ./debug/src/html_response.o ./debug/src/http_grammar_adapter.o ./debug/src/non_terminals.o ./debug/src/parser.o ./debug/src/parsing_grammar_adapter.o ./debug/src/ptree.o ./debug/src/rules.o ./debug/src/server.o ./debug/src/symbol.o ./debug/src/utils.o ./debug/src/word.o ./debug/src/tester.o ./debug/src/tst_hga_head_from_http.o ./debug/src/tst_hga_http_grammar_adapter_errors.o ./debug/src/tst_hga_non_terminal_from_http.o ./debug/src/tst_hga_rules_from_http.o ./debug/src/tst_html_response.o ./debug/src/tst_http_grammar_adapter.o ./debug/src/tst_parser.o 
	g++ ./debug/src/main.o ./debug/src/grammar.o ./debug/src/head.o ./debug/src/html_response.o ./debug/src/http_grammar_adapter.o ./debug/src/non_terminals.o ./debug/src/parser.o ./debug/src/parsing_grammar_adapter.o ./debug/src/ptree.o ./debug/src/rules.o ./debug/src/server.o ./debug/src/symbol.o ./debug/src/utils.o ./debug/src/word.o ./debug/src/tester.o ./debug/src/tst_hga_head_from_http.o ./debug/src/tst_hga_http_grammar_adapter_errors.o ./debug/src/tst_hga_non_terminal_from_http.o ./debug/src/tst_hga_rules_from_http.o ./debug/src/tst_html_response.o ./debug/src/tst_http_grammar_adapter.o ./debug/src/tst_parser.o  -o ./debug/main

./debug/src/main.o: src//main.cpp src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/error.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/word.h src/sw/ptree.h src/sw/grammar.h \
 src/sw/word.h src/sw/http_grammar_adapter.h src/sw/html_response.h \
 src/tst/tst_html_response.h src/tst/tester.h \
 src/tst/tst_http_grammar_adapter.h src/tst/tst_parser.h

	g++ -std=c++20 ./src//main.cpp -o ./debug/src/main.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/grammar.o: src/sw/grammar.cpp src/sw/grammar.h src/sw/utils.h \
 src/sw/error.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h

	g++ -std=c++20 ./src/sw/grammar.cpp -o ./debug/src/grammar.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/head.o: src/sw/head.cpp src/sw/head.h src/sw/utils.h src/sw/error.h \
 src/sw/symbol.h src/sw/non_terminals.h

	g++ -std=c++20 ./src/sw/head.cpp -o ./debug/src/head.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/html_response.o: src/sw/html_response.cpp src/sw/html_response.h \
 src/sw/utils.h

	g++ -std=c++20 ./src/sw/html_response.cpp -o ./debug/src/html_response.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/http_grammar_adapter.o: src/sw/http_grammar_adapter.cpp \
 src/sw/http_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/error.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h

	g++ -std=c++20 ./src/sw/http_grammar_adapter.cpp -o ./debug/src/http_grammar_adapter.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/non_terminals.o: src/sw/non_terminals.cpp src/sw/non_terminals.h \
 src/sw/symbol.h src/sw/error.h

	g++ -std=c++20 ./src/sw/non_terminals.cpp -o ./debug/src/non_terminals.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/parser.o: src/sw/parser.cpp src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/error.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/word.h src/sw/ptree.h

	g++ -std=c++20 ./src/sw/parser.cpp -o ./debug/src/parser.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/parsing_grammar_adapter.o: src/sw/parsing_grammar_adapter.cpp \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/error.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h

	g++ -std=c++20 ./src/sw/parsing_grammar_adapter.cpp -o ./debug/src/parsing_grammar_adapter.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/ptree.o: src/sw/ptree.cpp src/sw/ptree.h src/sw/word.h src/sw/grammar.h \
 src/sw/utils.h src/sw/error.h src/sw/symbol.h src/sw/non_terminals.h \
 src/sw/head.h src/sw/rules.h

	g++ -std=c++20 ./src/sw/ptree.cpp -o ./debug/src/ptree.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/rules.o: src/sw/rules.cpp src/sw/rules.h src/sw/utils.h src/sw/error.h \
 src/sw/symbol.h src/sw/non_terminals.h

	g++ -std=c++20 ./src/sw/rules.cpp -o ./debug/src/rules.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/server.o: src/sw/server.cpp src/sw/server.h src/sw/httplib.h \
 src/sw/grammar.h src/sw/utils.h src/sw/error.h src/sw/symbol.h \
 src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/http_grammar_adapter.h src/sw/parsing_grammar_adapter.h \
 src/sw/html_response.h src/sw/parser.h src/sw/word.h src/sw/ptree.h

	g++ -std=c++20 ./src/sw/server.cpp -o ./debug/src/server.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/symbol.o: src/sw/symbol.cpp src/sw/symbol.h src/sw/error.h

	g++ -std=c++20 ./src/sw/symbol.cpp -o ./debug/src/symbol.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/utils.o: src/sw/utils.cpp src/sw/utils.h

	g++ -std=c++20 ./src/sw/utils.cpp -o ./debug/src/utils.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/word.o: src/sw/word.cpp src/sw/word.h src/sw/grammar.h src/sw/utils.h \
 src/sw/error.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h

	g++ -std=c++20 ./src/sw/word.cpp -o ./debug/src/word.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/tester.o: src/tst/tester.cpp src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/error.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/word.h src/sw/ptree.h src/sw/grammar.h \
 src/sw/word.h src/sw/http_grammar_adapter.h src/sw/html_response.h

	g++ -std=c++20 ./src/tst/tester.cpp -o ./debug/src/tester.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/tst_hga_head_from_http.o: src/tst/tst_hga_head_from_http.cpp \
 src/tst/tst_http_grammar_adapter.h src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/error.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/word.h src/sw/ptree.h src/sw/grammar.h \
 src/sw/word.h src/sw/http_grammar_adapter.h src/sw/html_response.h

	g++ -std=c++20 ./src/tst/tst_hga_head_from_http.cpp -o ./debug/src/tst_hga_head_from_http.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/tst_hga_http_grammar_adapter_errors.o: \
 src/tst/tst_hga_http_grammar_adapter_errors.cpp \
 src/tst/tst_http_grammar_adapter.h src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/error.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/word.h src/sw/ptree.h src/sw/grammar.h \
 src/sw/word.h src/sw/http_grammar_adapter.h src/sw/html_response.h

	g++ -std=c++20 ./src/tst/tst_hga_http_grammar_adapter_errors.cpp -o ./debug/src/tst_hga_http_grammar_adapter_errors.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/tst_hga_non_terminal_from_http.o: \
 src/tst/tst_hga_non_terminal_from_http.cpp \
 src/tst/tst_http_grammar_adapter.h src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/error.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/word.h src/sw/ptree.h src/sw/grammar.h \
 src/sw/word.h src/sw/http_grammar_adapter.h src/sw/html_response.h

	g++ -std=c++20 ./src/tst/tst_hga_non_terminal_from_http.cpp -o ./debug/src/tst_hga_non_terminal_from_http.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/tst_hga_rules_from_http.o: src/tst/tst_hga_rules_from_http.cpp \
 src/tst/tst_http_grammar_adapter.h src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/error.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/word.h src/sw/ptree.h src/sw/grammar.h \
 src/sw/word.h src/sw/http_grammar_adapter.h src/sw/html_response.h

	g++ -std=c++20 ./src/tst/tst_hga_rules_from_http.cpp -o ./debug/src/tst_hga_rules_from_http.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/tst_html_response.o: src/tst/tst_html_response.cpp \
 src/tst/tst_html_response.h src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/error.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/word.h src/sw/ptree.h src/sw/grammar.h \
 src/sw/word.h src/sw/http_grammar_adapter.h src/sw/html_response.h

	g++ -std=c++20 ./src/tst/tst_html_response.cpp -o ./debug/src/tst_html_response.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/tst_http_grammar_adapter.o: src/tst/tst_http_grammar_adapter.cpp \
 src/tst/tst_http_grammar_adapter.h src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/error.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/word.h src/sw/ptree.h src/sw/grammar.h \
 src/sw/word.h src/sw/http_grammar_adapter.h src/sw/html_response.h

	g++ -std=c++20 ./src/tst/tst_http_grammar_adapter.cpp -o ./debug/src/tst_http_grammar_adapter.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 

./debug/src/tst_parser.o: src/tst/tst_parser.cpp src/tst/tst_parser.h \
 src/tst/tester.h src/sw/parser.h src/sw/parsing_grammar_adapter.h \
 src/sw/grammar.h src/sw/utils.h src/sw/error.h src/sw/symbol.h \
 src/sw/non_terminals.h src/sw/head.h src/sw/rules.h src/sw/word.h \
 src/sw/ptree.h src/sw/grammar.h src/sw/word.h \
 src/sw/http_grammar_adapter.h src/sw/html_response.h

	g++ -std=c++20 ./src/tst/tst_parser.cpp -o ./debug/src/tst_parser.o  -I ./src/sw -I ./src/tst -c $(FLAGS) 


clean:
	rm -d -r debug
	mkdir debug
	mkdir debug/src
	mkdir debug/src/tst

