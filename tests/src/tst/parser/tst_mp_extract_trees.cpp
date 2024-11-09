#include "tst_mod_parser.h"

// void TST_mod_parser::_test_extract_trees_from_parsing_table(
//	 PTable & parsing_table,
//	 const PTrees & expected_ptrees
// )
// {
//	 //create the module with dummy arguments
//	 Grammar grammar;
//	 Word word;
//	 Mod_parser mod_parser(grammar, word);
//	
//	 //call the tested method
//	 mod_parser.extract_trees_from_parsing_table(parsing_table);
//	
//	 //compare results
//	 bool ok = compare(expected_ptrees, mod_parser.parse_trees, "result trees");
//	 if (ok)
//	 {
//		 std::cout << "OK" << std::endl;
//	 }
//	 else
//	 { 
//		 std::cout << __FILE__ << "\tFAIL" << std::endl;
//	 }
//		
// }
//	
// void TST_mod_parser::test_extract_trees_from_parsing_table()
// {
//	
//	 
//	std::cout  << "===============================================================" << std::endl;
//	std::cout  << " degraded Word: A, trees: A" << std::endl;
//	std::cout  << "===============================================================" << std::endl;
//	{
//		
//		 Word degraded_word;
//		 degraded_word.push_back("a");
//		 PTable ptable(degraded_word);
//		
//		 PTrees expected_ptrees;
//		 PTree tree;
//		 tree.root.tag = "a";
//		
//		 expected_ptrees.push_back(tree);
//		
//		
//		 _test_extract_trees_from_parsing_table(
//			 ptable, 
//			 expected_ptrees
//		 );
//	 }
//	
//	 
//	std::cout  << "===============================================================" << std::endl;
//	std::cout  << " simplest case -- 2 symbols, 3 nodes " << std::endl;
//	std::cout  << " Word: A B, trees: a[A B]" << std::endl;
//	{
//		 std::cout << "===============================================================" << std::endl;
//		
//		 Word word;
//		 word.push_back("A");
//		 word.push_back("B");
//		
//		 PTable ptable(word);
//		
//		 PTable_entry ptable_entry;
//		 ptable_entry.tag = "a";
//		 ptable_entry.visited = false;
//		
//		 {
//			 PTable_reference child;
//			 child.x = 0;
//			 child.y = 0;
//			 child.list_index = 0;
//			 ptable_entry.children.push_back(child);
//		 }
//		 {
//			 PTable_reference child;
//			 child.x = 1;
//			 child.y = 0;
//			 child.list_index = 0;
//			 ptable_entry.children.push_back(child);
//		 }
//		
//		 ptable.tab[1][0].push_back(ptable_entry);
//		
//		
//		 PTrees expected_ptrees;
//		 PTree tree;
//		 tree.root.tag = "a";
//		
//		 {
//			 PNode node;
//			 node.tag = "A";
//			 tree.root.children.push_back(node);
//		 }
//		 {
//			 PNode node;
//			 node.tag = "B";
//			 tree.root.children.push_back(node);
//		 }
//		
//		 expected_ptrees.push_back(tree);
//
//		 _test_extract_trees_from_parsing_table(
//			 ptable, 
//			 expected_ptrees
//		 );
//	 }
//	
//	 
//	std::cout  << "===============================================================" << std::endl;
//	std::cout  << " simplest ambiguity -- 2 symbols, 2 rules" << std::endl;
//	std::cout  << " Word: A B, trees: a[A B], b[A B]" << std::endl;
//	{
//		 std::cout << "===============================================================" << std::endl;
//		
//		 Word word;
//		 word.push_back("A");
//		 word.push_back("B");
//		
//		 PTable ptable(word);
//		 PTable_reference child1;
//		 child1.x = 0;
//		 child1.y = 0;
//		 child1.list_index = 0;
//	
//		 PTable_reference child2;
//		 child2.x = 1;
//		 child2.y = 0;
//		 child2.list_index = 0;
//	
//		
//		 {
//			 PTable_entry ptable_entry;
//			 ptable_entry.tag = "a";
//			 ptable_entry.visited = false;
//			
//			 ptable_entry.children.push_back(child1);
//			 ptable_entry.children.push_back(child2);
//			 ptable.tab[1][0].push_back(ptable_entry);
//		 }
//		
//		
//		 {
//			 PTable_entry ptable_entry;
//			 ptable_entry.tag = "b";
//			 ptable_entry.visited = false;
//			
//			 ptable_entry.children.push_back(child1);
//			 ptable_entry.children.push_back(child2);
//			 ptable.tab[1][0].push_back(ptable_entry);
//		 }
//		
//		
//		 PTrees expected_ptrees;
//		
//		 PNode node1;
//		 node1.tag = "A";
//		 PNode node2;
//		 node2.tag = "B";
//		
//		 {
//			 PTree tree;
//			 tree.root.tag = "a";
//			 tree.root.children.push_back(node1);
//			 tree.root.children.push_back(node2);
//			 expected_ptrees.push_back(tree);
//		 }
//		 {
//			 PTree tree;
//			 tree.root.tag = "b";
//			 tree.root.children.push_back(node1);
//			 tree.root.children.push_back(node2);
//			 expected_ptrees.push_back(tree);
//		 }
//		
//		
//		
//		 _test_extract_trees_from_parsing_table(
//			 ptable, 
//			 expected_ptrees
//		 );
//	 }
//	
//	 
//	std::cout  << "===============================================================" << std::endl;
//	std::cout  << " 3 symbols, 2 rules, left first" << std::endl;
//	std::cout  << " Word: A B C, trees: b[a[A B] C], " << std::endl;
//	{
//		 std::cout << "===============================================================" << std::endl;
//		
//		 Word word;
//		 word.push_back("A");
//		 word.push_back("B");
//		 word.push_back("C");
//		
//		 PTable ptable(word);
//		
//		 {
//			 PTable_entry ptable_entry;
//			 ptable_entry.tag = "a";
//			 ptable_entry.visited = false;
//				
//			
//			 PTable_reference child1;
//			 child1.x = 0;
//			 child1.y = 0;
//			 child1.list_index = 0;
//
//			 PTable_reference child2;
//			 child2.x = 1;
//			 child2.y = 0;
//			 child2.list_index = 0;
//
//			
//			 ptable_entry.children.push_back(child1);
//			 ptable_entry.children.push_back(child2);
//			 ptable.tab[1][0].push_back(ptable_entry);
//		 }
//		 {
//			 PTable_entry ptable_entry;
//			 ptable_entry.tag = "b";
//			 ptable_entry.visited = false;
//			
//			
//			 PTable_reference child1;
//			 child1.x = 0;
//			 child1.y = 1;
//			 child1.list_index = 0;
//
//			 PTable_reference child2;
//			 child2.x = 2;
//			 child2.y = 0;
//			 child2.list_index = 0;
//
//			
//			 ptable_entry.children.push_back(child1);
//			 ptable_entry.children.push_back(child2);
//			 ptable.tab[2][0].push_back(ptable_entry);
//		 }
//		
//		
//		 PTrees expected_ptrees;
//		
//		 PNode node1;
//		 node1.tag = "A";
//		 PNode node2;
//		 node2.tag = "B";
//		 PNode node3;
//		 node3.tag = "C";
//		
//		 PTree tree;
//		
//		 PNode leaf;
//		 leaf.tag = "a";
//		 leaf.children.push_back(node1);
//		 leaf.children.push_back(node2);
//		
//		 tree.root.tag = "b";
//		 tree.root.children.push_back(leaf);
//		 tree.root.children.push_back(node3);
//		
//		 expected_ptrees.push_back(tree);
//
//
//		 _test_extract_trees_from_parsing_table(
//			 ptable, 
//			 expected_ptrees
//		 );
//	 }
//	
//	 
//	std::cout  << "===============================================================" << std::endl;
//	std::cout  << " 3 symbols, 2 rules, right first" << std::endl;
//	std::cout  << " Word: A B C, trees: b[C a[A B]], " << std::endl;
//	{
//		 std::cout << "===============================================================" << std::endl;
//		
//		 Word word;
//		 word.push_back("C");
//		 word.push_back("A");
//		 word.push_back("B");
//		
//		 PTable ptable(word);
//		
//		 {
//			 PTable_entry ptable_entry;
//			 ptable_entry.tag = "a";
//			 ptable_entry.visited = false;
//				
//			
//			 PTable_reference child1;
//			 child1.x = 1;
//			 child1.y = 0;
//			 child1.list_index = 0;
//
//			 PTable_reference child2;
//			 child2.x = 2;
//			 child2.y = 0;
//			 child2.list_index = 0;
//
//			
//			 ptable_entry.children.push_back(child1);
//			 ptable_entry.children.push_back(child2);
//			 ptable.tab[1][1].push_back(ptable_entry);
//		 }
//		 {
//			 PTable_entry ptable_entry;
//			 ptable_entry.tag = "b";
//			 ptable_entry.visited = false;
//			
//			
//			 PTable_reference child1;
//			 child1.x = 0;
//			 child1.y = 0;
//			 child1.list_index = 0;
//
//			 PTable_reference child2;
//			 child2.x = 1;
//			 child2.y = 1;
//			 child2.list_index = 0;
//
//			
//			 ptable_entry.children.push_back(child1);
//			 ptable_entry.children.push_back(child2);
//			 ptable.tab[2][0].push_back(ptable_entry);
//		 }
//		
//		
//		 PTrees expected_ptrees;
//		
//		 PNode node1;
//		 node1.tag = "A";
//		 PNode node2;
//		 node2.tag = "B";
//		 PNode node3;
//		 node3.tag = "C";
//		
//		 PTree tree;
//		
//		 PNode leaf;
//		 leaf.tag = "a";
//		 leaf.children.push_back(node1);
//		 leaf.children.push_back(node2);
//		
//		 tree.root.tag = "b";
//		 tree.root.children.push_back(node3);
//		 tree.root.children.push_back(leaf);
//		
//		 expected_ptrees.push_back(tree);
//
//
//		
//		
//		 _test_extract_trees_from_parsing_table(
//			 ptable, 
//			 expected_ptrees
//		 );
//	 }
//	
//	 
//	std::cout  << "===============================================================" << std::endl;
//	std::cout  << " 3 symbols, 2 rules + 1 that produces incomplete parse" << std::endl;
//	std::cout  << " Word: A B C, trees: b[C a[A B]], d[A B] " << std::endl;
//	{
//		 std::cout << "===============================================================" << std::endl;
//		
//		 Word word;
//		 word.push_back("C");
//		 word.push_back("A");
//		 word.push_back("B");
//		
//		 PTable ptable(word);
//		
//		 {
//			 PTable_entry ptable_entry;
//			 ptable_entry.tag = "a";
//			 ptable_entry.visited = false;
//				
//			
//			 PTable_reference child1;
//			 child1.x = 1;
//			 child1.y = 0;
//			 child1.list_index = 0;
//
//			 PTable_reference child2;
//			 child2.x = 2;
//			 child2.y = 0;
//			 child2.list_index = 0;
//
//			
//			 ptable_entry.children.push_back(child1);
//			 ptable_entry.children.push_back(child2);
//			 ptable.tab[1][1].push_back(ptable_entry);
//		 }
//		
//		 {
//			 PTable_entry ptable_entry;
//			 ptable_entry.tag = "d";
//			 ptable_entry.visited = false;
//				
//			
//			 PTable_reference child1;
//			 child1.x = 1;
//			 child1.y = 0;
//			 child1.list_index = 0;
//
//			 PTable_reference child2;
//			 child2.x = 2;
//			 child2.y = 0;
//			 child2.list_index = 0;
//
//			
//			 ptable_entry.children.push_back(child1);
//			 ptable_entry.children.push_back(child2);
//			 ptable.tab[1][1].push_back(ptable_entry);
//		 }
//		
//		
//		 {
//			 PTable_entry ptable_entry;
//			 ptable_entry.tag = "b";
//			 ptable_entry.visited = false;
//			
//			
//			 PTable_reference child1;
//			 child1.x = 0;
//			 child1.y = 0;
//			 child1.list_index = 0;
//
//			 PTable_reference child2;
//			 child2.x = 1;
//			 child2.y = 1;
//			 child2.list_index = 0;
//
//			
//			 ptable_entry.children.push_back(child1);
//			 ptable_entry.children.push_back(child2);
//			 ptable.tab[2][0].push_back(ptable_entry);
//		 }
//		
//		
//		 PTrees expected_ptrees;
//		
//		 PNode node1;
//		 node1.tag = "A";
//		 PNode node2;
//		 node2.tag = "B";
//		 PNode node3;
//		 node3.tag = "C";
//		
//		 {
//			 PTree tree;
//			
//			 PNode leaf;
//			 leaf.tag = "a";
//			 leaf.children.push_back(node1);
//			 leaf.children.push_back(node2);
//			
//			 tree.root.tag = "b";
//			 tree.root.children.push_back(node3);
//			 tree.root.children.push_back(leaf);
//			
//			 expected_ptrees.push_back(tree);
//		 }
//		
//		 {
//			 PTree tree;
//			 tree.root.tag = "d";
//			 tree.root.children.push_back(node1);
//			 tree.root.children.push_back(node2);
//			 expected_ptrees.push_back(tree);
//		 }
//
//		
//		 _test_extract_trees_from_parsing_table(
//			 ptable, 
//			 expected_ptrees
//		 );
//	 }
//	
//	 
//	std::cout  << "===============================================================" << std::endl;
//	std::cout  << " 2 complete parse trees as a result" << std::endl;
//	std::cout  << " Word: A A A, trees: a[a[A A] A], a[A a[A A]] " << std::endl;
//	{
//		 std::cout << "===============================================================" << std::endl;
//		
//		 Word word;
//		 word.push_back("A");
//		 word.push_back("A");
//		 word.push_back("A");
//		
//		 PTable ptable(word);
//		
//		 {
//			 PTable_entry ptable_entry;
//			 ptable_entry.tag = "a";
//			 ptable_entry.visited = false;
//				
//			
//			 PTable_reference child1;
//			 child1.x = 0;
//			 child1.y = 0;
//			 child1.list_index = 0;
//
//			 PTable_reference child2;
//			 child2.x = 1;
//			 child2.y = 0;
//			 child2.list_index = 0;
//
//			
//			 ptable_entry.children.push_back(child1);
//			 ptable_entry.children.push_back(child2);
//			 ptable.tab[1][0].push_back(ptable_entry);
//		 }
//		
//		 {
//			 PTable_entry ptable_entry;
//			 ptable_entry.tag = "a";
//			 ptable_entry.visited = false;
//				
//			
//			 PTable_reference child1;
//			 child1.x = 1;
//			 child1.y = 0;
//			 child1.list_index = 0;
//
//			 PTable_reference child2;
//			 child2.x = 2;
//			 child2.y = 0;
//			 child2.list_index = 0;
//
//			
//			 ptable_entry.children.push_back(child1);
//			 ptable_entry.children.push_back(child2);
//			 ptable.tab[1][1].push_back(ptable_entry);
//		 }
//		
//		 {
//			 PTable_entry ptable_entry;
//			 ptable_entry.tag = "a";
//			 ptable_entry.visited = false;
//				
//			
//			 PTable_reference child1;
//			 child1.x = 0;
//			 child1.y = 0;
//			 child1.list_index = 0;
//
//			 PTable_reference child2;
//			 child2.x = 1;
//			 child2.y = 1;
//			 child2.list_index = 0;
//
//			
//			 ptable_entry.children.push_back(child1);
//			 ptable_entry.children.push_back(child2);
//			 ptable.tab[2][0].push_back(ptable_entry);
//		 }
//		
//		 {
//			 PTable_entry ptable_entry;
//			 ptable_entry.tag = "a";
//			 ptable_entry.visited = false;
//				
//			
//			 PTable_reference child1;
//			 child1.x = 0;
//			 child1.y = 1;
//			 child1.list_index = 0;
//
//			 PTable_reference child2;
//			 child2.x = 2;
//			 child2.y = 0;
//			 child2.list_index = 0;
//
//			
//			 ptable_entry.children.push_back(child1);
//			 ptable_entry.children.push_back(child2);
//			 ptable.tab[2][0].push_back(ptable_entry);
//		 }
//		
//		
//		 PTrees expected_ptrees;
//		
//		 PNode node1;
//		 node1.tag = "A";
//		
//		 {
//			 PTree tree;
//			
//			 PNode leaf;
//			 leaf.tag = "a";
//			 leaf.children.push_back(node1);
//			 leaf.children.push_back(node1);
//			
//			 tree.root.tag = "a";
//			 tree.root.children.push_back(node1);
//			 tree.root.children.push_back(leaf);
//			
//			 expected_ptrees.push_back(tree);
//		 }
//		
//		 {
//			 PTree tree;
//			
//			 PNode leaf;
//			 leaf.tag = "a";
//			 leaf.children.push_back(node1);
//			 leaf.children.push_back(node1);
//			
//			 tree.root.tag = "a";
//			 tree.root.children.push_back(leaf);
//			 tree.root.children.push_back(node1);
//			
//			 expected_ptrees.push_back(tree);
//		 }
//		
//		
//		
//		 _test_extract_trees_from_parsing_table(
//			 ptable, 
//			 expected_ptrees
//		 );
//	 }
//	
//	
// }
//
