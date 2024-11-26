

FLAGS = -fno-access-control -g

run: ./debug/main
	./debug/main > ./debug/results.txt

./debug/main : ./debug/src/main.o ./debug/src/model.o ./debug/src/utils.o ./debug/src/server.o ./debug/src/mod_to_http.o ./debug/src/html_response.o ./debug/src/parsing_grammar_adapter.o ./debug/src/mod_parser.o ./debug/src/tokenizer.o ./debug/src/mod_from_http.o ./debug/src/mod_check_errors.o ./debug/src/mod_visualize_grammar.o ./debug/src/compares.o ./debug/src/to_string.o ./debug/src/tester.o ./debug/src/tst_html_response.o ./debug/src/tst_mod_to_http.o ./debug/src/tst_mp_complete_parser_tests.o ./debug/src/tst_mp_combine.o ./debug/src/tst_mp_extract_trees.o ./debug/src/tst_mp_parsing_grammar_adapter.o ./debug/src/tst_mfh_nonterminals.o ./debug/src/tst_mfh_head.o ./debug/src/tst_mfh_terminals.o ./debug/src/tst_mfh_rules.o ./debug/src/tst_mfh_tokenize.o ./debug/src/tst_mfh_word.o ./debug/src/tst_mce_head.o ./debug/src/tst_mce_rules.o ./debug/src/tst_mce_non_terminals.o ./debug/src/tst_mce_word.o ./debug/src/tst_visualize_grammar.o ./debug/src/tst_http_to_errors.o 
	g++ ./debug/src/main.o ./debug/src/model.o ./debug/src/utils.o ./debug/src/server.o ./debug/src/mod_to_http.o ./debug/src/html_response.o ./debug/src/parsing_grammar_adapter.o ./debug/src/mod_parser.o ./debug/src/tokenizer.o ./debug/src/mod_from_http.o ./debug/src/mod_check_errors.o ./debug/src/mod_visualize_grammar.o ./debug/src/compares.o ./debug/src/to_string.o ./debug/src/tester.o ./debug/src/tst_html_response.o ./debug/src/tst_mod_to_http.o ./debug/src/tst_mp_complete_parser_tests.o ./debug/src/tst_mp_combine.o ./debug/src/tst_mp_extract_trees.o ./debug/src/tst_mp_parsing_grammar_adapter.o ./debug/src/tst_mfh_nonterminals.o ./debug/src/tst_mfh_head.o ./debug/src/tst_mfh_terminals.o ./debug/src/tst_mfh_rules.o ./debug/src/tst_mfh_tokenize.o ./debug/src/tst_mfh_word.o ./debug/src/tst_mce_head.o ./debug/src/tst_mce_rules.o ./debug/src/tst_mce_non_terminals.o ./debug/src/tst_mce_word.o ./debug/src/tst_visualize_grammar.o ./debug/src/tst_http_to_errors.o  -o ./debug/main

./debug/src/main.o: src//main.cpp src/tst/tester.h src/sw/non_terminals.h \
 src/sw/symbol.h src/sw/word.h src/sw/error.h src/sw/grammar.h \
 src/sw/utils.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/tst/compares.h src/tst/to_string.h src/sw/parser/mod_parser.h \
 src/sw/parser/parsing_grammar_adapter.h src/sw/utils.h src/sw/sppf.h \
 src/sw/pnode.h src/sw/pnode.h src/sw/vnode.h src/sw/from_http/token.h \
 src/tst/check_errors/tst_mod_check_errors.h \
 src/sw/check_errors/mod_check_errors.h \
 src/tst/from_http/tst_mod_from_http.h src/sw/from_http/mod_from_http.h \
 src/sw/from_http/token.h src/tst/to_http/tst_mod_to_http.h \
 src/sw/to_http/mod_to_http.h src/sw/to_http/html_response.h \
 src/tst/parser/tst_mod_parser.h \
 src/tst/visualize_grammar/tst_visualize_grammar.h \
 src/sw/visualize_grammar/mod_visualize_grammar.h

	g++ -std=c++20 ./src//main.cpp -o ./debug/src/main.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/model.o: src/sw/model.cpp src/sw/model.h src/sw/from_http/mod_from_http.h \
 src/sw/grammar.h src/sw/utils.h src/sw/symbol.h src/sw/non_terminals.h \
 src/sw/head.h src/sw/rules.h src/sw/word.h src/sw/error.h \
 src/sw/from_http/token.h src/sw/check_errors/mod_check_errors.h \
 src/sw/parser/mod_parser.h src/sw/parser/parsing_grammar_adapter.h \
 src/sw/utils.h src/sw/sppf.h src/sw/pnode.h src/sw/pnode.h \
 src/sw/visualize_grammar/mod_visualize_grammar.h src/sw/vnode.h

	g++ -std=c++20 ./src/sw/model.cpp -o ./debug/src/model.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/utils.o: src/sw/utils.cpp src/sw/utils.h

	g++ -std=c++20 ./src/sw/utils.cpp -o ./debug/src/utils.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/server.o: src/sw/server.cpp src/sw/server.h src/sw/httplib.h \
 src/sw/to_http/mod_to_http.h src/sw/error.h \
 src/sw/to_http/html_response.h src/sw/utils.h src/sw/vnode.h \
 src/sw/symbol.h src/sw/sppf.h src/sw/rules.h src/sw/utils.h \
 src/sw/non_terminals.h src/sw/pnode.h src/sw/to_http/html_response.h \
 src/sw/model.h src/sw/from_http/mod_from_http.h src/sw/grammar.h \
 src/sw/head.h src/sw/word.h src/sw/from_http/token.h \
 src/sw/check_errors/mod_check_errors.h src/sw/parser/mod_parser.h \
 src/sw/parser/parsing_grammar_adapter.h src/sw/pnode.h \
 src/sw/visualize_grammar/mod_visualize_grammar.h

	g++ -std=c++20 ./src/sw/server.cpp -o ./debug/src/server.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/mod_to_http.o: src/sw/to_http/mod_to_http.cpp \
 src/sw/to_http/mod_to_http.h src/sw/error.h \
 src/sw/to_http/html_response.h src/sw/utils.h src/sw/vnode.h \
 src/sw/symbol.h src/sw/sppf.h src/sw/rules.h src/sw/utils.h \
 src/sw/non_terminals.h src/sw/pnode.h

	g++ -std=c++20 ./src/sw/to_http/mod_to_http.cpp -o ./debug/src/mod_to_http.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/html_response.o: src/sw/to_http/html_response.cpp \
 src/sw/to_http/html_response.h src/sw/utils.h

	g++ -std=c++20 ./src/sw/to_http/html_response.cpp -o ./debug/src/html_response.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/parsing_grammar_adapter.o: src/sw/parser/parsing_grammar_adapter.cpp \
 src/sw/parser/parsing_grammar_adapter.h src/sw/utils.h src/sw/grammar.h \
 src/sw/utils.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h

	g++ -std=c++20 ./src/sw/parser/parsing_grammar_adapter.cpp -o ./debug/src/parsing_grammar_adapter.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/mod_parser.o: src/sw/parser/mod_parser.cpp src/sw/parser/mod_parser.h \
 src/sw/parser/parsing_grammar_adapter.h src/sw/utils.h src/sw/grammar.h \
 src/sw/utils.h src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/error.h src/sw/word.h src/sw/sppf.h src/sw/pnode.h \
 src/sw/pnode.h

	g++ -std=c++20 ./src/sw/parser/mod_parser.cpp -o ./debug/src/mod_parser.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tokenizer.o: src/sw/from_http/tokenizer.cpp \
 src/sw/from_http/mod_from_http.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/error.h src/sw/from_http/token.h

	g++ -std=c++20 ./src/sw/from_http/tokenizer.cpp -o ./debug/src/tokenizer.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/mod_from_http.o: src/sw/from_http/mod_from_http.cpp \
 src/sw/from_http/mod_from_http.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/error.h src/sw/from_http/token.h

	g++ -std=c++20 ./src/sw/from_http/mod_from_http.cpp -o ./debug/src/mod_from_http.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/mod_check_errors.o: src/sw/check_errors/mod_check_errors.cpp \
 src/sw/check_errors/mod_check_errors.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/error.h

	g++ -std=c++20 ./src/sw/check_errors/mod_check_errors.cpp -o ./debug/src/mod_check_errors.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/mod_visualize_grammar.o: \
 src/sw/visualize_grammar/mod_visualize_grammar.cpp \
 src/sw/visualize_grammar/mod_visualize_grammar.h src/sw/vnode.h \
 src/sw/symbol.h src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h \
 src/sw/head.h src/sw/rules.h

	g++ -std=c++20 ./src/sw/visualize_grammar/mod_visualize_grammar.cpp -o ./debug/src/mod_visualize_grammar.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/compares.o: src/tst/compares.cpp src/tst/compares.h src/tst/to_string.h \
 src/sw/non_terminals.h src/sw/symbol.h src/sw/word.h src/sw/error.h \
 src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/parser/mod_parser.h \
 src/sw/parser/parsing_grammar_adapter.h src/sw/utils.h src/sw/sppf.h \
 src/sw/pnode.h src/sw/pnode.h src/sw/vnode.h src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/compares.cpp -o ./debug/src/compares.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/to_string.o: src/tst/to_string.cpp src/tst/to_string.h \
 src/sw/non_terminals.h src/sw/symbol.h src/sw/word.h src/sw/error.h \
 src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/sw/parser/mod_parser.h \
 src/sw/parser/parsing_grammar_adapter.h src/sw/utils.h src/sw/sppf.h \
 src/sw/pnode.h src/sw/pnode.h src/sw/vnode.h src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/to_string.cpp -o ./debug/src/to_string.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tester.o: src/tst/tester.cpp src/tst/tester.h src/sw/non_terminals.h \
 src/sw/symbol.h src/sw/word.h src/sw/error.h src/sw/grammar.h \
 src/sw/utils.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/tst/compares.h src/tst/to_string.h src/sw/parser/mod_parser.h \
 src/sw/parser/parsing_grammar_adapter.h src/sw/utils.h src/sw/sppf.h \
 src/sw/pnode.h src/sw/pnode.h src/sw/vnode.h src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/tester.cpp -o ./debug/src/tester.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_html_response.o: src/tst/tst_html_response.cpp \
 src/tst/tst_html_response.h src/tst/tester.h src/sw/non_terminals.h \
 src/sw/symbol.h src/sw/word.h src/sw/error.h src/sw/grammar.h \
 src/sw/utils.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/tst/compares.h src/tst/to_string.h src/sw/parser/mod_parser.h \
 src/sw/parser/parsing_grammar_adapter.h src/sw/utils.h src/sw/sppf.h \
 src/sw/pnode.h src/sw/pnode.h src/sw/vnode.h src/sw/from_http/token.h \
 src/sw/to_http/html_response.h

	g++ -std=c++20 ./src/tst/tst_html_response.cpp -o ./debug/src/tst_html_response.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mod_to_http.o: src/tst/to_http/tst_mod_to_http.cpp \
 src/tst/to_http/tst_mod_to_http.h src/sw/to_http/mod_to_http.h \
 src/sw/error.h src/sw/to_http/html_response.h src/sw/utils.h \
 src/sw/vnode.h src/sw/symbol.h src/sw/sppf.h src/sw/rules.h \
 src/sw/utils.h src/sw/non_terminals.h src/sw/pnode.h src/tst/tester.h \
 src/sw/non_terminals.h src/sw/word.h src/sw/grammar.h src/sw/head.h \
 src/tst/compares.h src/tst/to_string.h src/sw/parser/mod_parser.h \
 src/sw/parser/parsing_grammar_adapter.h src/sw/pnode.h \
 src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/to_http/tst_mod_to_http.cpp -o ./debug/src/tst_mod_to_http.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mp_complete_parser_tests.o: \
 src/tst/parser/tst_mp_complete_parser_tests.cpp \
 src/tst/parser/tst_mod_parser.h src/tst/tester.h src/sw/non_terminals.h \
 src/sw/symbol.h src/sw/word.h src/sw/error.h src/sw/grammar.h \
 src/sw/utils.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/tst/compares.h src/tst/to_string.h src/sw/parser/mod_parser.h \
 src/sw/parser/parsing_grammar_adapter.h src/sw/utils.h src/sw/sppf.h \
 src/sw/pnode.h src/sw/pnode.h src/sw/vnode.h src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/parser/tst_mp_complete_parser_tests.cpp -o ./debug/src/tst_mp_complete_parser_tests.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mp_combine.o: src/tst/parser/tst_mp_combine.cpp \
 src/tst/parser/tst_mod_parser.h src/tst/tester.h src/sw/non_terminals.h \
 src/sw/symbol.h src/sw/word.h src/sw/error.h src/sw/grammar.h \
 src/sw/utils.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/tst/compares.h src/tst/to_string.h src/sw/parser/mod_parser.h \
 src/sw/parser/parsing_grammar_adapter.h src/sw/utils.h src/sw/sppf.h \
 src/sw/pnode.h src/sw/pnode.h src/sw/vnode.h src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/parser/tst_mp_combine.cpp -o ./debug/src/tst_mp_combine.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mp_extract_trees.o: src/tst/parser/tst_mp_extract_trees.cpp \
 src/tst/parser/tst_mod_parser.h src/tst/tester.h src/sw/non_terminals.h \
 src/sw/symbol.h src/sw/word.h src/sw/error.h src/sw/grammar.h \
 src/sw/utils.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/tst/compares.h src/tst/to_string.h src/sw/parser/mod_parser.h \
 src/sw/parser/parsing_grammar_adapter.h src/sw/utils.h src/sw/sppf.h \
 src/sw/pnode.h src/sw/pnode.h src/sw/vnode.h src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/parser/tst_mp_extract_trees.cpp -o ./debug/src/tst_mp_extract_trees.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mp_parsing_grammar_adapter.o: \
 src/tst/parser/tst_mp_parsing_grammar_adapter.cpp \
 src/tst/parser/tst_mod_parser.h src/tst/tester.h src/sw/non_terminals.h \
 src/sw/symbol.h src/sw/word.h src/sw/error.h src/sw/grammar.h \
 src/sw/utils.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/tst/compares.h src/tst/to_string.h src/sw/parser/mod_parser.h \
 src/sw/parser/parsing_grammar_adapter.h src/sw/utils.h src/sw/sppf.h \
 src/sw/pnode.h src/sw/pnode.h src/sw/vnode.h src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/parser/tst_mp_parsing_grammar_adapter.cpp -o ./debug/src/tst_mp_parsing_grammar_adapter.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mfh_nonterminals.o: src/tst/from_http/tst_mfh_nonterminals.cpp \
 src/tst/from_http/tst_mod_from_http.h src/tst/tester.h \
 src/sw/non_terminals.h src/sw/symbol.h src/sw/word.h src/sw/error.h \
 src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/tst/compares.h src/tst/to_string.h \
 src/sw/parser/mod_parser.h src/sw/parser/parsing_grammar_adapter.h \
 src/sw/utils.h src/sw/sppf.h src/sw/pnode.h src/sw/pnode.h \
 src/sw/vnode.h src/sw/from_http/token.h src/sw/from_http/mod_from_http.h \
 src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/from_http/tst_mfh_nonterminals.cpp -o ./debug/src/tst_mfh_nonterminals.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mfh_head.o: src/tst/from_http/tst_mfh_head.cpp \
 src/tst/from_http/tst_mod_from_http.h src/tst/tester.h \
 src/sw/non_terminals.h src/sw/symbol.h src/sw/word.h src/sw/error.h \
 src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/tst/compares.h src/tst/to_string.h \
 src/sw/parser/mod_parser.h src/sw/parser/parsing_grammar_adapter.h \
 src/sw/utils.h src/sw/sppf.h src/sw/pnode.h src/sw/pnode.h \
 src/sw/vnode.h src/sw/from_http/token.h src/sw/from_http/mod_from_http.h \
 src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/from_http/tst_mfh_head.cpp -o ./debug/src/tst_mfh_head.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mfh_terminals.o: src/tst/from_http/tst_mfh_terminals.cpp \
 src/tst/from_http/tst_mod_from_http.h src/tst/tester.h \
 src/sw/non_terminals.h src/sw/symbol.h src/sw/word.h src/sw/error.h \
 src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/tst/compares.h src/tst/to_string.h \
 src/sw/parser/mod_parser.h src/sw/parser/parsing_grammar_adapter.h \
 src/sw/utils.h src/sw/sppf.h src/sw/pnode.h src/sw/pnode.h \
 src/sw/vnode.h src/sw/from_http/token.h src/sw/from_http/mod_from_http.h \
 src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/from_http/tst_mfh_terminals.cpp -o ./debug/src/tst_mfh_terminals.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mfh_rules.o: src/tst/from_http/tst_mfh_rules.cpp \
 src/tst/from_http/tst_mod_from_http.h src/tst/tester.h \
 src/sw/non_terminals.h src/sw/symbol.h src/sw/word.h src/sw/error.h \
 src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/tst/compares.h src/tst/to_string.h \
 src/sw/parser/mod_parser.h src/sw/parser/parsing_grammar_adapter.h \
 src/sw/utils.h src/sw/sppf.h src/sw/pnode.h src/sw/pnode.h \
 src/sw/vnode.h src/sw/from_http/token.h src/sw/from_http/mod_from_http.h \
 src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/from_http/tst_mfh_rules.cpp -o ./debug/src/tst_mfh_rules.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mfh_tokenize.o: src/tst/from_http/tst_mfh_tokenize.cpp \
 src/tst/from_http/tst_mod_from_http.h src/tst/tester.h \
 src/sw/non_terminals.h src/sw/symbol.h src/sw/word.h src/sw/error.h \
 src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/tst/compares.h src/tst/to_string.h \
 src/sw/parser/mod_parser.h src/sw/parser/parsing_grammar_adapter.h \
 src/sw/utils.h src/sw/sppf.h src/sw/pnode.h src/sw/pnode.h \
 src/sw/vnode.h src/sw/from_http/token.h src/sw/from_http/mod_from_http.h \
 src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/from_http/tst_mfh_tokenize.cpp -o ./debug/src/tst_mfh_tokenize.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mfh_word.o: src/tst/from_http/tst_mfh_word.cpp \
 src/tst/from_http/tst_mod_from_http.h src/tst/tester.h \
 src/sw/non_terminals.h src/sw/symbol.h src/sw/word.h src/sw/error.h \
 src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/tst/compares.h src/tst/to_string.h \
 src/sw/parser/mod_parser.h src/sw/parser/parsing_grammar_adapter.h \
 src/sw/utils.h src/sw/sppf.h src/sw/pnode.h src/sw/pnode.h \
 src/sw/vnode.h src/sw/from_http/token.h src/sw/from_http/mod_from_http.h \
 src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/from_http/tst_mfh_word.cpp -o ./debug/src/tst_mfh_word.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mce_head.o: src/tst/check_errors/tst_mce_head.cpp \
 src/tst/check_errors/tst_mod_check_errors.h src/tst/tester.h \
 src/sw/non_terminals.h src/sw/symbol.h src/sw/word.h src/sw/error.h \
 src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/tst/compares.h src/tst/to_string.h \
 src/sw/parser/mod_parser.h src/sw/parser/parsing_grammar_adapter.h \
 src/sw/utils.h src/sw/sppf.h src/sw/pnode.h src/sw/pnode.h \
 src/sw/vnode.h src/sw/from_http/token.h \
 src/sw/check_errors/mod_check_errors.h

	g++ -std=c++20 ./src/tst/check_errors/tst_mce_head.cpp -o ./debug/src/tst_mce_head.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mce_rules.o: src/tst/check_errors/tst_mce_rules.cpp \
 src/tst/check_errors/tst_mod_check_errors.h src/tst/tester.h \
 src/sw/non_terminals.h src/sw/symbol.h src/sw/word.h src/sw/error.h \
 src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/tst/compares.h src/tst/to_string.h \
 src/sw/parser/mod_parser.h src/sw/parser/parsing_grammar_adapter.h \
 src/sw/utils.h src/sw/sppf.h src/sw/pnode.h src/sw/pnode.h \
 src/sw/vnode.h src/sw/from_http/token.h \
 src/sw/check_errors/mod_check_errors.h

	g++ -std=c++20 ./src/tst/check_errors/tst_mce_rules.cpp -o ./debug/src/tst_mce_rules.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mce_non_terminals.o: src/tst/check_errors/tst_mce_non_terminals.cpp \
 src/tst/check_errors/tst_mod_check_errors.h src/tst/tester.h \
 src/sw/non_terminals.h src/sw/symbol.h src/sw/word.h src/sw/error.h \
 src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/tst/compares.h src/tst/to_string.h \
 src/sw/parser/mod_parser.h src/sw/parser/parsing_grammar_adapter.h \
 src/sw/utils.h src/sw/sppf.h src/sw/pnode.h src/sw/pnode.h \
 src/sw/vnode.h src/sw/from_http/token.h \
 src/sw/check_errors/mod_check_errors.h

	g++ -std=c++20 ./src/tst/check_errors/tst_mce_non_terminals.cpp -o ./debug/src/tst_mce_non_terminals.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_mce_word.o: src/tst/check_errors/tst_mce_word.cpp \
 src/tst/check_errors/tst_mod_check_errors.h src/tst/tester.h \
 src/sw/non_terminals.h src/sw/symbol.h src/sw/word.h src/sw/error.h \
 src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h src/sw/head.h \
 src/sw/rules.h src/tst/compares.h src/tst/to_string.h \
 src/sw/parser/mod_parser.h src/sw/parser/parsing_grammar_adapter.h \
 src/sw/utils.h src/sw/sppf.h src/sw/pnode.h src/sw/pnode.h \
 src/sw/vnode.h src/sw/from_http/token.h \
 src/sw/check_errors/mod_check_errors.h

	g++ -std=c++20 ./src/tst/check_errors/tst_mce_word.cpp -o ./debug/src/tst_mce_word.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_visualize_grammar.o: \
 src/tst/visualize_grammar/tst_visualize_grammar.cpp \
 src/tst/visualize_grammar/tst_visualize_grammar.h \
 src/sw/visualize_grammar/mod_visualize_grammar.h src/sw/vnode.h \
 src/sw/symbol.h src/sw/grammar.h src/sw/utils.h src/sw/non_terminals.h \
 src/sw/head.h src/sw/rules.h src/tst/tester.h src/sw/non_terminals.h \
 src/sw/word.h src/sw/error.h src/tst/compares.h src/tst/to_string.h \
 src/sw/parser/mod_parser.h src/sw/parser/parsing_grammar_adapter.h \
 src/sw/utils.h src/sw/sppf.h src/sw/pnode.h src/sw/pnode.h \
 src/sw/from_http/token.h

	g++ -std=c++20 ./src/tst/visualize_grammar/tst_visualize_grammar.cpp -o ./debug/src/tst_visualize_grammar.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 

./debug/src/tst_http_to_errors.o: src/tst/http_to_errors/tst_http_to_errors.cpp \
 src/tst/http_to_errors/tst_http_to_errors.h \
 src/sw/from_http/mod_from_http.h src/sw/grammar.h src/sw/utils.h \
 src/sw/symbol.h src/sw/non_terminals.h src/sw/head.h src/sw/rules.h \
 src/sw/word.h src/sw/error.h src/sw/from_http/token.h \
 src/sw/check_errors/mod_check_errors.h src/sw/to_http/mod_to_http.h \
 src/sw/to_http/html_response.h src/sw/utils.h src/sw/vnode.h \
 src/sw/sppf.h src/sw/pnode.h

	g++ -std=c++20 ./src/tst/http_to_errors/tst_http_to_errors.cpp -o ./debug/src/tst_http_to_errors.o  -I ./src/sw/to_http -I ./src/tst -I ./src/tst/visualize_grammar -I ./src/sw/parser -I ./src/sw -I ./src/sw/from_http -I ./src/tst/to_http -I ./src/tst/check_errors -I ./src/tst/http_to_errors -I ./src/sw/visualize_grammar -I ./src/tst/parser -I ./src/tst/from_http -I ./src/sw/check_errors -c $(FLAGS) 


clean:
	rm -d -r debug
	mkdir debug
	mkdir debug/src
	mkdir debug/src/tst

