

FLAGS = -fno-access-control

run: ./debug/main
	./debug/main > ./debug/results.txt

./debug/main : ./debug/src/main.o ./debug/src/html_response.o ./debug/src/non_terminals.o ./debug/src/parser.o ./debug/src/parsing_grammar_adapter.o ./debug/src/ptree.o ./debug/src/server.o ./debug/src/utils.o ./debug/src/mod_check_errors.o ./debug/src/mod_from_http.o ./debug/src/mod_to_http.o ./debug/src/tester.o ./debug/src/tst_html_response.o ./debug/src/tst_parser.o ./debug/src/tst_mce_head.o ./debug/src/tst_mce_non_terminals.o ./debug/src/tst_mce_rules.o ./debug/src/tst_mce_word.o ./debug/src/tst_mfh_compares.o ./debug/src/tst_mfh_head.o ./debug/src/tst_mfh_non_terminals.o ./debug/src/tst_mfh_rules.o ./debug/src/tst_mfh_word.o 
	g++ ./debug/src/main.o ./debug/src/html_response.o ./debug/src/non_terminals.o ./debug/src/parser.o ./debug/src/parsing_grammar_adapter.o ./debug/src/ptree.o ./debug/src/server.o ./debug/src/utils.o ./debug/src/mod_check_errors.o ./debug/src/mod_from_http.o ./debug/src/mod_to_http.o ./debug/src/tester.o ./debug/src/tst_html_response.o ./debug/src/tst_parser.o ./debug/src/tst_mce_head.o ./debug/src/tst_mce_non_terminals.o ./debug/src/tst_mce_rules.o ./debug/src/tst_mce_word.o ./debug/src/tst_mfh_compares.o ./debug/src/tst_mfh_head.o ./debug/src/tst_mfh_non_terminals.o ./debug/src/tst_mfh_rules.o ./debug/src/tst_mfh_word.o  -o ./debug/main

./debug/src/main.o: src//main.cpp src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/ptree.h src/sw/grammar.h src/sw/word.h \
 src/sw/html_response.h src/sw/error.h \
 src/tst/check_errors/tst_mod_check_errors.h \
 src/sw/check_errors/mod_check_errors.h \
 src/tst/from_http/tst_mod_from_http.h src/sw/from_http/mod_from_http.h

	g++ -std=c++20 ./src//main.cpp -o ./debug/src/main.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/html_response.o: src/sw/html_response.cpp src/sw/html_response.h \
 src/sw/utils.h

	g++ -std=c++20 ./src/sw/html_response.cpp -o ./debug/src/html_response.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/non_terminals.o: src/sw/non_terminals.cpp src/sw/non_terminals.h \
 src/sw/symbol.h

	g++ -std=c++20 ./src/sw/non_terminals.cpp -o ./debug/src/non_terminals.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/parser.o: src/sw/parser.cpp src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/ptree.h

	g++ -std=c++20 ./src/sw/parser.cpp -o ./debug/src/parser.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/parsing_grammar_adapter.o: src/sw/parsing_grammar_adapter.cpp \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h

	g++ -std=c++20 ./src/sw/parsing_grammar_adapter.cpp -o ./debug/src/parsing_grammar_adapter.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/ptree.o: src/sw/ptree.cpp src/sw/ptree.h src/sw/word.h src/sw/symbol.h \
 src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h

	g++ -std=c++20 ./src/sw/ptree.cpp -o ./debug/src/ptree.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/server.o: src/sw/server.cpp src/sw/server.h src/sw/httplib.h \
 src/sw/from_http/mod_from_http.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/error.h src/sw/to_http/mod_to_http.h src/sw/ptree.h \
 src/sw/word.h src/sw/grammar.h src/sw/check_errors/mod_check_errors.h \
 src/sw/parsing_grammar_adapter.h src/sw/html_response.h src/sw/parser.h \
 src/sw/ptree.h

	g++ -std=c++20 ./src/sw/server.cpp -o ./debug/src/server.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/utils.o: src/sw/utils.cpp src/sw/utils.h

	g++ -std=c++20 ./src/sw/utils.cpp -o ./debug/src/utils.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/mod_check_errors.o: src/sw/check_errors/mod_check_errors.cpp \
 src/sw/check_errors/mod_check_errors.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/error.h

	g++ -std=c++20 ./src/sw/check_errors/mod_check_errors.cpp -o ./debug/src/mod_check_errors.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/mod_from_http.o: src/sw/from_http/mod_from_http.cpp \
 src/sw/from_http/mod_from_http.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/error.h

	g++ -std=c++20 ./src/sw/from_http/mod_from_http.cpp -o ./debug/src/mod_from_http.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/mod_to_http.o: src/sw/to_http/mod_to_http.cpp \
 src/sw/to_http/mod_to_http.h src/sw/ptree.h src/sw/word.h \
 src/sw/symbol.h src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h \
 src/sw/head.h src/sw/rules.h src/sw/error.h

	g++ -std=c++20 ./src/sw/to_http/mod_to_http.cpp -o ./debug/src/mod_to_http.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tester.o: src/tst/tester.cpp src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/ptree.h src/sw/grammar.h src/sw/word.h \
 src/sw/html_response.h src/sw/error.h

	g++ -std=c++20 ./src/tst/tester.cpp -o ./debug/src/tester.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_html_response.o: src/tst/tst_html_response.cpp \
 src/tst/tst_html_response.h src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/ptree.h src/sw/grammar.h src/sw/word.h \
 src/sw/html_response.h src/sw/error.h

	g++ -std=c++20 ./src/tst/tst_html_response.cpp -o ./debug/src/tst_html_response.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_parser.o: src/tst/tst_parser.cpp src/tst/tst_parser.h \
 src/tst/tester.h src/sw/parser.h src/sw/parsing_grammar_adapter.h \
 src/sw/grammar.h src/sw/utils.h src/sw/symbol.h src/sw/non_terminals.h \
 src/sw/head.h src/sw/rules.h src/sw/word.h src/sw/ptree.h \
 src/sw/grammar.h src/sw/word.h src/sw/html_response.h src/sw/error.h

	g++ -std=c++20 ./src/tst/tst_parser.cpp -o ./debug/src/tst_parser.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mce_head.o: src/tst/check_errors/tst_mce_head.cpp \
 src/tst/check_errors/tst_mod_check_errors.h src/tst/tester.h \
 src/sw/parser.h src/sw/parsing_grammar_adapter.h src/sw/grammar.h \
 src/sw/utils.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/word.h src/sw/ptree.h src/sw/grammar.h \
 src/sw/word.h src/sw/html_response.h src/sw/error.h \
 src/sw/check_errors/mod_check_errors.h

	g++ -std=c++20 ./src/tst/check_errors/tst_mce_head.cpp -o ./debug/src/tst_mce_head.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mce_non_terminals.o: src/tst/check_errors/tst_mce_non_terminals.cpp \
 src/tst/check_errors/tst_mod_check_errors.h src/tst/tester.h \
 src/sw/parser.h src/sw/parsing_grammar_adapter.h src/sw/grammar.h \
 src/sw/utils.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/word.h src/sw/ptree.h src/sw/grammar.h \
 src/sw/word.h src/sw/html_response.h src/sw/error.h \
 src/sw/check_errors/mod_check_errors.h

	g++ -std=c++20 ./src/tst/check_errors/tst_mce_non_terminals.cpp -o ./debug/src/tst_mce_non_terminals.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mce_rules.o: src/tst/check_errors/tst_mce_rules.cpp \
 src/tst/check_errors/tst_mod_check_errors.h src/tst/tester.h \
 src/sw/parser.h src/sw/parsing_grammar_adapter.h src/sw/grammar.h \
 src/sw/utils.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/word.h src/sw/ptree.h src/sw/grammar.h \
 src/sw/word.h src/sw/html_response.h src/sw/error.h \
 src/sw/check_errors/mod_check_errors.h

	g++ -std=c++20 ./src/tst/check_errors/tst_mce_rules.cpp -o ./debug/src/tst_mce_rules.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mce_word.o: src/tst/check_errors/tst_mce_word.cpp \
 src/tst/check_errors/tst_mod_check_errors.h src/tst/tester.h \
 src/sw/parser.h src/sw/parsing_grammar_adapter.h src/sw/grammar.h \
 src/sw/utils.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/word.h src/sw/ptree.h src/sw/grammar.h \
 src/sw/word.h src/sw/html_response.h src/sw/error.h \
 src/sw/check_errors/mod_check_errors.h

	g++ -std=c++20 ./src/tst/check_errors/tst_mce_word.cpp -o ./debug/src/tst_mce_word.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mfh_compares.o: src/tst/from_http/tst_mfh_compares.cpp \
 src/tst/from_http/tst_mod_from_http.h src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/ptree.h src/sw/grammar.h src/sw/word.h \
 src/sw/html_response.h src/sw/error.h src/sw/from_http/mod_from_http.h

	g++ -std=c++20 ./src/tst/from_http/tst_mfh_compares.cpp -o ./debug/src/tst_mfh_compares.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mfh_head.o: src/tst/from_http/tst_mfh_head.cpp \
 src/tst/from_http/tst_mod_from_http.h src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/ptree.h src/sw/grammar.h src/sw/word.h \
 src/sw/html_response.h src/sw/error.h src/sw/from_http/mod_from_http.h

	g++ -std=c++20 ./src/tst/from_http/tst_mfh_head.cpp -o ./debug/src/tst_mfh_head.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mfh_non_terminals.o: src/tst/from_http/tst_mfh_non_terminals.cpp \
 src/tst/from_http/tst_mod_from_http.h src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/ptree.h src/sw/grammar.h src/sw/word.h \
 src/sw/html_response.h src/sw/error.h src/sw/from_http/mod_from_http.h

	g++ -std=c++20 ./src/tst/from_http/tst_mfh_non_terminals.cpp -o ./debug/src/tst_mfh_non_terminals.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mfh_rules.o: src/tst/from_http/tst_mfh_rules.cpp \
 src/tst/from_http/tst_mod_from_http.h src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/ptree.h src/sw/grammar.h src/sw/word.h \
 src/sw/html_response.h src/sw/error.h src/sw/from_http/mod_from_http.h

	g++ -std=c++20 ./src/tst/from_http/tst_mfh_rules.cpp -o ./debug/src/tst_mfh_rules.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mfh_word.o: src/tst/from_http/tst_mfh_word.cpp \
 src/tst/from_http/tst_mod_from_http.h src/tst/tester.h src/sw/parser.h \
 src/sw/parsing_grammar_adapter.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/ptree.h src/sw/grammar.h src/sw/word.h \
 src/sw/html_response.h src/sw/error.h src/sw/from_http/mod_from_http.h

	g++ -std=c++20 ./src/tst/from_http/tst_mfh_word.cpp -o ./debug/src/tst_mfh_word.o  -I ./src/sw -I ./src/tst/check_errors -I ./src/sw/to_http -I ./src/sw/from_http -I ./src/tst/from_http -I ./src/tst -I ./src/sw/check_errors -c $(FLAGS) 


clean:
	rm -d -r debug
	mkdir debug
	mkdir debug/src
	mkdir debug/src/tst

