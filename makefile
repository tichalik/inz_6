

FLAGS = 

./build/app : ./build/.o/sw_model.o ./build/.o/sw_utils.o ./build/.o/sw_main.o ./build/.o/sw_server.o ./build/.o/sw_sppf.o ./build/.o/sw_mod_to_http.o ./build/.o/sw_html_response.o ./build/.o/sw_mod_parser.o ./build/.o/sw_tokenizer.o ./build/.o/sw_mod_from_http.o ./build/.o/sw_mod_check_errors.o ./build/.o/sw_mod_visualize_grammar.o 
	g++ ./build/.o/sw_model.o ./build/.o/sw_utils.o ./build/.o/sw_main.o ./build/.o/sw_server.o ./build/.o/sw_sppf.o ./build/.o/sw_mod_to_http.o ./build/.o/sw_html_response.o ./build/.o/sw_mod_parser.o ./build/.o/sw_tokenizer.o ./build/.o/sw_mod_from_http.o ./build/.o/sw_mod_check_errors.o ./build/.o/sw_mod_visualize_grammar.o  -o ./build/app

./build/tests : ./build/.o/tst_compares.o ./build/.o/tst_to_string.o ./build/.o/tst_tests_main.o ./build/.o/tst_tester.o ./build/.o/tst_tst_html_response.o ./build/.o/tst_tst_mod_to_http.o ./build/.o/tst_tst_iterate_sppf.o ./build/.o/tst_tst_mp_complete_parser_tests.o ./build/.o/tst_tst_mfh_nonterminals.o ./build/.o/tst_tst_mfh_head.o ./build/.o/tst_tst_mfh_terminals.o ./build/.o/tst_tst_mfh_rules.o ./build/.o/tst_tst_mfh_tokenize.o ./build/.o/tst_tst_mfh_word.o ./build/.o/tst_tst_mce_head.o ./build/.o/tst_tst_mce_rules.o ./build/.o/tst_tst_mce_word.o ./build/.o/tst_tst_visualize_grammar.o ./build/.o/tst_tst_http_to_errors.o  ./build/.o/tst_model.o ./build/.o/tst_utils.o  ./build/.o/tst_server.o ./build/.o/tst_sppf.o ./build/.o/tst_mod_to_http.o ./build/.o/tst_html_response.o ./build/.o/tst_mod_parser.o ./build/.o/tst_tokenizer.o ./build/.o/tst_mod_from_http.o ./build/.o/tst_mod_check_errors.o ./build/.o/tst_mod_visualize_grammar.o 
	g++ ./build/.o/tst_compares.o ./build/.o/tst_to_string.o ./build/.o/tst_tests_main.o ./build/.o/tst_tester.o ./build/.o/tst_tst_html_response.o ./build/.o/tst_tst_mod_to_http.o ./build/.o/tst_tst_iterate_sppf.o ./build/.o/tst_tst_mp_complete_parser_tests.o ./build/.o/tst_tst_mfh_nonterminals.o ./build/.o/tst_tst_mfh_head.o ./build/.o/tst_tst_mfh_terminals.o ./build/.o/tst_tst_mfh_rules.o ./build/.o/tst_tst_mfh_tokenize.o ./build/.o/tst_tst_mfh_word.o ./build/.o/tst_tst_mce_head.o ./build/.o/tst_tst_mce_rules.o ./build/.o/tst_tst_mce_word.o ./build/.o/tst_tst_visualize_grammar.o ./build/.o/tst_tst_http_to_errors.o  ./build/.o/tst_model.o ./build/.o/tst_utils.o  ./build/.o/tst_server.o ./build/.o/tst_sppf.o ./build/.o/tst_mod_to_http.o ./build/.o/tst_html_response.o ./build/.o/tst_mod_parser.o ./build/.o/tst_tokenizer.o ./build/.o/tst_mod_from_http.o ./build/.o/tst_mod_check_errors.o ./build/.o/tst_mod_visualize_grammar.o  -o ./build/tests
	

tests: ./build/tests
	./build/tests > ./build/test_results.txt

./build/.o/sw_model.o: src/model.cpp src/model.h src/from_http/mod_from_http.h \
 src/grammar.h src/utils.h src/symbol.h src/non_terminals.h src/head.h \
 src/rules.h src/word.h src/error.h src/from_http/token.h \
 src/check_errors/mod_check_errors.h src/parser/mod_parser.h src/sppf.h \
 src/visualize_grammar/mod_visualize_grammar.h src/vnode.h ./build/.o
	g++ ./src/model.cpp -o ./build/.o/sw_model.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar  -c $(FLAGS) 

./build/.o/sw_utils.o: src/utils.cpp src/utils.h ./build/.o
	g++ ./src/utils.cpp -o ./build/.o/sw_utils.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar  -c $(FLAGS) 

./build/.o/sw_main.o: src/main.cpp src/server.h src/httplib.h src/to_http/mod_to_http.h \
 src/error.h src/to_http/html_response.h src/utils.h src/vnode.h \
 src/symbol.h src/sppf.h src/rules.h src/utils.h \
 src/to_http/html_response.h src/model.h src/from_http/mod_from_http.h \
 src/grammar.h src/non_terminals.h src/head.h src/word.h \
 src/from_http/token.h src/check_errors/mod_check_errors.h \
 src/parser/mod_parser.h src/visualize_grammar/mod_visualize_grammar.h ./build/.o
	g++ ./src/main.cpp -o ./build/.o/sw_main.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar  -c $(FLAGS) 

./build/.o/sw_server.o: src/server.cpp src/server.h src/httplib.h \
 src/to_http/mod_to_http.h src/error.h src/to_http/html_response.h \
 src/utils.h src/vnode.h src/symbol.h src/sppf.h src/rules.h src/utils.h \
 src/to_http/html_response.h src/model.h src/from_http/mod_from_http.h \
 src/grammar.h src/non_terminals.h src/head.h src/word.h \
 src/from_http/token.h src/check_errors/mod_check_errors.h \
 src/parser/mod_parser.h src/visualize_grammar/mod_visualize_grammar.h ./build/.o
	g++ ./src/server.cpp -o ./build/.o/sw_server.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar  -c $(FLAGS) 

./build/.o/sw_sppf.o: src/sppf.cpp src/sppf.h src/rules.h src/utils.h src/symbol.h ./build/.o
	g++ ./src/sppf.cpp -o ./build/.o/sw_sppf.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar  -c $(FLAGS) 

./build/.o/sw_mod_to_http.o: src/to_http/mod_to_http.cpp src/to_http/mod_to_http.h \
 src/error.h src/to_http/html_response.h src/utils.h src/vnode.h \
 src/symbol.h src/sppf.h src/rules.h src/utils.h ./build/.o
	g++ ./src/to_http/mod_to_http.cpp -o ./build/.o/sw_mod_to_http.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar  -c $(FLAGS) 

./build/.o/sw_html_response.o: src/to_http/html_response.cpp \
 src/to_http/html_response.h src/utils.h ./build/.o
	g++ ./src/to_http/html_response.cpp -o ./build/.o/sw_html_response.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar  -c $(FLAGS) 

./build/.o/sw_mod_parser.o: src/parser/mod_parser.cpp src/parser/mod_parser.h \
 src/grammar.h src/utils.h src/symbol.h src/non_terminals.h src/head.h \
 src/rules.h src/error.h src/word.h src/sppf.h ./build/.o
	g++ ./src/parser/mod_parser.cpp -o ./build/.o/sw_mod_parser.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar  -c $(FLAGS) 

./build/.o/sw_tokenizer.o: src/from_http/tokenizer.cpp src/from_http/mod_from_http.h \
 src/grammar.h src/utils.h src/symbol.h src/non_terminals.h src/head.h \
 src/rules.h src/word.h src/error.h src/from_http/token.h ./build/.o
	g++ ./src/from_http/tokenizer.cpp -o ./build/.o/sw_tokenizer.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar  -c $(FLAGS) 

./build/.o/sw_mod_from_http.o: src/from_http/mod_from_http.cpp \
 src/from_http/mod_from_http.h src/grammar.h src/utils.h src/symbol.h \
 src/non_terminals.h src/head.h src/rules.h src/word.h src/error.h \
 src/from_http/token.h ./build/.o
	g++ ./src/from_http/mod_from_http.cpp -o ./build/.o/sw_mod_from_http.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar  -c $(FLAGS) 

./build/.o/sw_mod_check_errors.o: src/check_errors/mod_check_errors.cpp \
 src/check_errors/mod_check_errors.h src/grammar.h src/utils.h \
 src/symbol.h src/non_terminals.h src/head.h src/rules.h src/word.h \
 src/error.h ./build/.o
	g++ ./src/check_errors/mod_check_errors.cpp -o ./build/.o/sw_mod_check_errors.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar  -c $(FLAGS) 

./build/.o/sw_mod_visualize_grammar.o: src/visualize_grammar/mod_visualize_grammar.cpp \
 src/visualize_grammar/mod_visualize_grammar.h src/vnode.h src/symbol.h \
 src/grammar.h src/utils.h src/non_terminals.h src/head.h src/rules.h ./build/.o
	g++ ./src/visualize_grammar/mod_visualize_grammar.cpp -o ./build/.o/sw_mod_visualize_grammar.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar  -c $(FLAGS) 



./build/.o/tst_compares.o: tests/compares.cpp tests/compares.h tests/to_string.h \
 src/non_terminals.h src/symbol.h src/word.h src/error.h src/grammar.h \
 src/utils.h src/non_terminals.h src/head.h src/rules.h \
 src/parser/mod_parser.h src/sppf.h src/vnode.h src/from_http/token.h ./build/.o
	g++ ./tests/compares.cpp -o ./build/.o/tst_compares.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_to_string.o: tests/to_string.cpp tests/to_string.h src/non_terminals.h \
 src/symbol.h src/word.h src/error.h src/grammar.h src/utils.h \
 src/non_terminals.h src/head.h src/rules.h src/parser/mod_parser.h \
 src/sppf.h src/vnode.h src/from_http/token.h ./build/.o
	g++ ./tests/to_string.cpp -o ./build/.o/tst_to_string.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tests_main.o: tests/tests_main.cpp tests/tester.h src/non_terminals.h \
 src/symbol.h src/word.h src/error.h src/grammar.h src/utils.h \
 src/non_terminals.h src/head.h src/rules.h src/sppf.h tests/compares.h \
 tests/to_string.h src/parser/mod_parser.h src/vnode.h \
 src/from_http/token.h tests/check_errors/tst_mod_check_errors.h \
 tests/tester.h src/check_errors/mod_check_errors.h \
 tests/from_http/tst_mod_from_http.h src/from_http/mod_from_http.h \
 src/from_http/token.h tests/to_http/tst_mod_to_http.h \
 src/to_http/mod_to_http.h src/to_http/html_response.h src/utils.h \
 tests/parser/tst_mod_parser.h tests/tst_html_response.h \
 src/to_http/html_response.h \
 tests/visualize_grammar/tst_visualize_grammar.h \
 src/visualize_grammar/mod_visualize_grammar.h ./build/.o
	g++ ./tests/tests_main.cpp -o ./build/.o/tst_tests_main.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tester.o: tests/tester.cpp tests/tester.h src/non_terminals.h \
 src/symbol.h src/word.h src/error.h src/grammar.h src/utils.h \
 src/non_terminals.h src/head.h src/rules.h src/sppf.h tests/compares.h \
 tests/to_string.h src/parser/mod_parser.h src/vnode.h \
 src/from_http/token.h ./build/.o
	g++ ./tests/tester.cpp -o ./build/.o/tst_tester.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_html_response.o: tests/tst_html_response.cpp \
 tests/tst_html_response.h tests/tester.h src/non_terminals.h \
 src/symbol.h src/word.h src/error.h src/grammar.h src/utils.h \
 src/non_terminals.h src/head.h src/rules.h src/sppf.h tests/compares.h \
 tests/to_string.h src/parser/mod_parser.h src/vnode.h \
 src/from_http/token.h src/to_http/html_response.h src/utils.h ./build/.o
	g++ ./tests/tst_html_response.cpp -o ./build/.o/tst_tst_html_response.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_mod_to_http.o: tests/to_http/tst_mod_to_http.cpp \
 tests/to_http/tst_mod_to_http.h src/to_http/mod_to_http.h src/error.h \
 src/to_http/html_response.h src/utils.h src/vnode.h src/symbol.h \
 src/sppf.h src/rules.h src/utils.h tests/tester.h src/non_terminals.h \
 src/word.h src/grammar.h src/non_terminals.h src/head.h tests/compares.h \
 tests/to_string.h src/parser/mod_parser.h src/from_http/token.h ./build/.o
	g++ ./tests/to_http/tst_mod_to_http.cpp -o ./build/.o/tst_tst_mod_to_http.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_iterate_sppf.o: tests/to_http/tst_iterate_sppf.cpp \
 tests/to_http/tst_mod_to_http.h src/to_http/mod_to_http.h src/error.h \
 src/to_http/html_response.h src/utils.h src/vnode.h src/symbol.h \
 src/sppf.h src/rules.h src/utils.h tests/tester.h src/non_terminals.h \
 src/word.h src/grammar.h src/non_terminals.h src/head.h tests/compares.h \
 tests/to_string.h src/parser/mod_parser.h src/from_http/token.h ./build/.o
	g++ ./tests/to_http/tst_iterate_sppf.cpp -o ./build/.o/tst_tst_iterate_sppf.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_mp_complete_parser_tests.o: \
 tests/parser/tst_mp_complete_parser_tests.cpp \
 tests/parser/tst_mod_parser.h tests/tester.h src/non_terminals.h \
 src/symbol.h src/word.h src/error.h src/grammar.h src/utils.h \
 src/non_terminals.h src/head.h src/rules.h src/sppf.h tests/compares.h \
 tests/to_string.h src/parser/mod_parser.h src/vnode.h \
 src/from_http/token.h ./build/.o
	g++ ./tests/parser/tst_mp_complete_parser_tests.cpp -o ./build/.o/tst_tst_mp_complete_parser_tests.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_mfh_nonterminals.o: tests/from_http/tst_mfh_nonterminals.cpp \
 tests/from_http/tst_mod_from_http.h tests/tester.h src/non_terminals.h \
 src/symbol.h src/word.h src/error.h src/grammar.h src/utils.h \
 src/non_terminals.h src/head.h src/rules.h src/sppf.h tests/compares.h \
 tests/to_string.h src/parser/mod_parser.h src/vnode.h \
 src/from_http/token.h src/from_http/mod_from_http.h \
 src/from_http/token.h ./build/.o
	g++ ./tests/from_http/tst_mfh_nonterminals.cpp -o ./build/.o/tst_tst_mfh_nonterminals.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_mfh_head.o: tests/from_http/tst_mfh_head.cpp \
 tests/from_http/tst_mod_from_http.h tests/tester.h src/non_terminals.h \
 src/symbol.h src/word.h src/error.h src/grammar.h src/utils.h \
 src/non_terminals.h src/head.h src/rules.h src/sppf.h tests/compares.h \
 tests/to_string.h src/parser/mod_parser.h src/vnode.h \
 src/from_http/token.h src/from_http/mod_from_http.h \
 src/from_http/token.h ./build/.o
	g++ ./tests/from_http/tst_mfh_head.cpp -o ./build/.o/tst_tst_mfh_head.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_mfh_terminals.o: tests/from_http/tst_mfh_terminals.cpp \
 tests/from_http/tst_mod_from_http.h tests/tester.h src/non_terminals.h \
 src/symbol.h src/word.h src/error.h src/grammar.h src/utils.h \
 src/non_terminals.h src/head.h src/rules.h src/sppf.h tests/compares.h \
 tests/to_string.h src/parser/mod_parser.h src/vnode.h \
 src/from_http/token.h src/from_http/mod_from_http.h \
 src/from_http/token.h ./build/.o
	g++ ./tests/from_http/tst_mfh_terminals.cpp -o ./build/.o/tst_tst_mfh_terminals.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_mfh_rules.o: tests/from_http/tst_mfh_rules.cpp \
 tests/from_http/tst_mod_from_http.h tests/tester.h src/non_terminals.h \
 src/symbol.h src/word.h src/error.h src/grammar.h src/utils.h \
 src/non_terminals.h src/head.h src/rules.h src/sppf.h tests/compares.h \
 tests/to_string.h src/parser/mod_parser.h src/vnode.h \
 src/from_http/token.h src/from_http/mod_from_http.h \
 src/from_http/token.h ./build/.o
	g++ ./tests/from_http/tst_mfh_rules.cpp -o ./build/.o/tst_tst_mfh_rules.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_mfh_tokenize.o: tests/from_http/tst_mfh_tokenize.cpp \
 tests/from_http/tst_mod_from_http.h tests/tester.h src/non_terminals.h \
 src/symbol.h src/word.h src/error.h src/grammar.h src/utils.h \
 src/non_terminals.h src/head.h src/rules.h src/sppf.h tests/compares.h \
 tests/to_string.h src/parser/mod_parser.h src/vnode.h \
 src/from_http/token.h src/from_http/mod_from_http.h \
 src/from_http/token.h ./build/.o
	g++ ./tests/from_http/tst_mfh_tokenize.cpp -o ./build/.o/tst_tst_mfh_tokenize.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_mfh_word.o: tests/from_http/tst_mfh_word.cpp \
 tests/from_http/tst_mod_from_http.h tests/tester.h src/non_terminals.h \
 src/symbol.h src/word.h src/error.h src/grammar.h src/utils.h \
 src/non_terminals.h src/head.h src/rules.h src/sppf.h tests/compares.h \
 tests/to_string.h src/parser/mod_parser.h src/vnode.h \
 src/from_http/token.h src/from_http/mod_from_http.h \
 src/from_http/token.h ./build/.o
	g++ ./tests/from_http/tst_mfh_word.cpp -o ./build/.o/tst_tst_mfh_word.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_mce_head.o: tests/check_errors/tst_mce_head.cpp \
 tests/check_errors/tst_mod_check_errors.h tests/tester.h \
 src/non_terminals.h src/symbol.h src/word.h src/error.h src/grammar.h \
 src/utils.h src/non_terminals.h src/head.h src/rules.h src/sppf.h \
 tests/compares.h tests/to_string.h src/parser/mod_parser.h src/vnode.h \
 src/from_http/token.h src/check_errors/mod_check_errors.h ./build/.o
	g++ ./tests/check_errors/tst_mce_head.cpp -o ./build/.o/tst_tst_mce_head.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_mce_rules.o: tests/check_errors/tst_mce_rules.cpp \
 tests/check_errors/tst_mod_check_errors.h tests/tester.h \
 src/non_terminals.h src/symbol.h src/word.h src/error.h src/grammar.h \
 src/utils.h src/non_terminals.h src/head.h src/rules.h src/sppf.h \
 tests/compares.h tests/to_string.h src/parser/mod_parser.h src/vnode.h \
 src/from_http/token.h src/check_errors/mod_check_errors.h ./build/.o
	g++ ./tests/check_errors/tst_mce_rules.cpp -o ./build/.o/tst_tst_mce_rules.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_mce_word.o: tests/check_errors/tst_mce_word.cpp \
 tests/check_errors/tst_mod_check_errors.h tests/tester.h \
 src/non_terminals.h src/symbol.h src/word.h src/error.h src/grammar.h \
 src/utils.h src/non_terminals.h src/head.h src/rules.h src/sppf.h \
 tests/compares.h tests/to_string.h src/parser/mod_parser.h src/vnode.h \
 src/from_http/token.h src/check_errors/mod_check_errors.h ./build/.o
	g++ ./tests/check_errors/tst_mce_word.cpp -o ./build/.o/tst_tst_mce_word.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_visualize_grammar.o: \
 tests/visualize_grammar/tst_visualize_grammar.cpp \
 tests/visualize_grammar/tst_visualize_grammar.h \
 src/visualize_grammar/mod_visualize_grammar.h src/vnode.h src/symbol.h \
 src/grammar.h src/utils.h src/non_terminals.h src/head.h src/rules.h \
 tests/tester.h src/non_terminals.h src/word.h src/error.h src/sppf.h \
 tests/compares.h tests/to_string.h src/parser/mod_parser.h \
 src/from_http/token.h src/to_http/mod_to_http.h \
 src/to_http/html_response.h src/utils.h ./build/.o
	g++ ./tests/visualize_grammar/tst_visualize_grammar.cpp -o ./build/.o/tst_tst_visualize_grammar.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tst_http_to_errors.o: tests/http_to_errors/tst_http_to_errors.cpp \
 tests/http_to_errors/tst_http_to_errors.h src/from_http/mod_from_http.h \
 src/grammar.h src/utils.h src/symbol.h src/non_terminals.h src/head.h \
 src/rules.h src/word.h src/error.h src/from_http/token.h \
 src/check_errors/mod_check_errors.h src/to_http/mod_to_http.h \
 src/to_http/html_response.h src/utils.h src/vnode.h src/sppf.h ./build/.o
	g++ ./tests/http_to_errors/tst_http_to_errors.cpp -o ./build/.o/tst_tst_http_to_errors.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 


./build/.o/tst_model.o: src/model.cpp src/model.h src/from_http/mod_from_http.h \
 src/grammar.h src/utils.h src/symbol.h src/non_terminals.h src/head.h \
 src/rules.h src/word.h src/error.h src/from_http/token.h \
 src/check_errors/mod_check_errors.h src/parser/mod_parser.h src/sppf.h \
 src/visualize_grammar/mod_visualize_grammar.h src/vnode.h ./build/.o
	g++ ./src/model.cpp -o ./build/.o/tst_model.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_utils.o: src/utils.cpp src/utils.h ./build/.o
	g++ ./src/utils.cpp -o ./build/.o/tst_utils.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_main.o: src/main.cpp src/server.h src/httplib.h src/to_http/mod_to_http.h \
 src/error.h src/to_http/html_response.h src/utils.h src/vnode.h \
 src/symbol.h src/sppf.h src/rules.h src/utils.h \
 src/to_http/html_response.h src/model.h src/from_http/mod_from_http.h \
 src/grammar.h src/non_terminals.h src/head.h src/word.h \
 src/from_http/token.h src/check_errors/mod_check_errors.h \
 src/parser/mod_parser.h src/visualize_grammar/mod_visualize_grammar.h ./build/.o
	g++ ./src/main.cpp -o ./build/.o/tst_main.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_server.o: src/server.cpp src/server.h src/httplib.h \
 src/to_http/mod_to_http.h src/error.h src/to_http/html_response.h \
 src/utils.h src/vnode.h src/symbol.h src/sppf.h src/rules.h src/utils.h \
 src/to_http/html_response.h src/model.h src/from_http/mod_from_http.h \
 src/grammar.h src/non_terminals.h src/head.h src/word.h \
 src/from_http/token.h src/check_errors/mod_check_errors.h \
 src/parser/mod_parser.h src/visualize_grammar/mod_visualize_grammar.h ./build/.o
	g++ ./src/server.cpp -o ./build/.o/tst_server.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_sppf.o: src/sppf.cpp src/sppf.h src/rules.h src/utils.h src/symbol.h ./build/.o
	g++ ./src/sppf.cpp -o ./build/.o/tst_sppf.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_mod_to_http.o: src/to_http/mod_to_http.cpp src/to_http/mod_to_http.h \
 src/error.h src/to_http/html_response.h src/utils.h src/vnode.h \
 src/symbol.h src/sppf.h src/rules.h src/utils.h ./build/.o
	g++ ./src/to_http/mod_to_http.cpp -o ./build/.o/tst_mod_to_http.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_html_response.o: src/to_http/html_response.cpp \
 src/to_http/html_response.h src/utils.h ./build/.o
	g++ ./src/to_http/html_response.cpp -o ./build/.o/tst_html_response.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_mod_parser.o: src/parser/mod_parser.cpp src/parser/mod_parser.h \
 src/grammar.h src/utils.h src/symbol.h src/non_terminals.h src/head.h \
 src/rules.h src/error.h src/word.h src/sppf.h ./build/.o
	g++ ./src/parser/mod_parser.cpp -o ./build/.o/tst_mod_parser.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_tokenizer.o: src/from_http/tokenizer.cpp src/from_http/mod_from_http.h \
 src/grammar.h src/utils.h src/symbol.h src/non_terminals.h src/head.h \
 src/rules.h src/word.h src/error.h src/from_http/token.h ./build/.o
	g++ ./src/from_http/tokenizer.cpp -o ./build/.o/tst_tokenizer.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_mod_from_http.o: src/from_http/mod_from_http.cpp \
 src/from_http/mod_from_http.h src/grammar.h src/utils.h src/symbol.h \
 src/non_terminals.h src/head.h src/rules.h src/word.h src/error.h \
 src/from_http/token.h ./build/.o
	g++ ./src/from_http/mod_from_http.cpp -o ./build/.o/tst_mod_from_http.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_mod_check_errors.o: src/check_errors/mod_check_errors.cpp \
 src/check_errors/mod_check_errors.h src/grammar.h src/utils.h \
 src/symbol.h src/non_terminals.h src/head.h src/rules.h src/word.h \
 src/error.h ./build/.o
	g++ ./src/check_errors/mod_check_errors.cpp -o ./build/.o/tst_mod_check_errors.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 

./build/.o/tst_mod_visualize_grammar.o: src/visualize_grammar/mod_visualize_grammar.cpp \
 src/visualize_grammar/mod_visualize_grammar.h src/vnode.h src/symbol.h \
 src/grammar.h src/utils.h src/non_terminals.h src/head.h src/rules.h ./build/.o
	g++ ./src/visualize_grammar/mod_visualize_grammar.cpp -o ./build/.o/tst_mod_visualize_grammar.o  -I ./src -I ./src/to_http -I ./src/parser -I ./src/from_http -I ./src/check_errors -I ./src/visualize_grammar -I ./tests -I ./tests/to_http -I ./tests/parser -I ./tests/from_http -I ./tests/check_errors -I ./tests/visualize_grammar -I ./tests/http_to_errors  -fno-access-control  -c $(FLAGS) 



clean: ./build ./build/.o
	rm ./build -r
	mkdir build
	mkdir build/.o
	
./build/.o: ./build
	mkdir -p ./build/.o

./build:
	mkdir -p ./build
	
