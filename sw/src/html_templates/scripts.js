function on_click_expanded(event){
	<!-- get the object which was clicked on -->
	let caller = event.caller || event.srcElement

	<!-- hide this object -->
	caller.style.display="none";
	<!-- show the folded node which is the next sibling -->
	caller.nextElementSibling.style.display="block";

	<!-- withouth this all the parent elements of the element  -->
	<!-- which was clicked on will also reveive the evevnt -->
	event.stopPropagation();
}

function on_click_folded(event){
	<!-- get the object which was clicked on -->
	let caller = event.caller || event.srcElement
	
	<!-- hide this object -->
	caller.style.display="none";
	<!-- show the expanded node which is the previous sibling -->
	caller.previousElementSibling.style.display="block";
	
	<!-- withouth this all the parent elements of the element  -->
	<!-- which was clicked on will also reveive the evevnt -->
	event.stopPropagation();
}

function filter_trees(){
	complete_only = document.getElementById("complete_only").checked;
	head_ok_only = document.getElementById("head_ok_only").checked;
	for (tree of document.getElementsByClassName("ptree")){
		if(
		complete_only && !tree.classList.contains("complete")
		|| head_ok_only && !tree.classList.contains("head_ok")
		){
			tree.style.display = "none";
		}
		else {
			tree.style.display = "block";
		}
	}
}

<!-- packing the script for adding the onclick events -->
<!-- so that is can be called upon loading the page -->
function add_events(){

	<!-- get all the elements of this class -->
	for (node of document.getElementsByClassName("node-expanded")){
		<!-- add the event to be called on click -->
		node.addEventListener("click", on_click_expanded);
	}
	
	<!-- get all the elements of this class -->
	for (node of document.getElementsByClassName("node-folded")){
		<!-- add the event to be called on click -->
		node.addEventListener("click", on_click_folded);
		<!-- hide the element -->
		node.style.display = "none";
	}
}

example_tab = {  
	"ex-abc-1":{
		"input": "a a b b b c c",
		"terminals": "a b c",
		"nonterminals": "<a> <b> <c> <abc>",
		"head": "<abc>",
		"rules": 
			"<a> ::= a a\n"
			+"<a> ::= <a> a\n"
			+"<b> ::= b b\n"
			+"<b> ::= <b> b\n"
			+"<c> ::= <c> c\n"
			+"<c> ::= c c\n"
			+"<abc> ::= <a> <b> <c>\n"
	},
		
	"ex-abc-2":{
		"input": "a a b b b c c",
		"terminals": "a b c",
		"nonterminals": "<a>  <ab> <abc>",
		"head": "<abc>",
		"rules": 
			"<a> ::= a a \n"
			+"<a> ::= <a> a\n"
			+"<ab> ::= <a> b\n"
			+"<ab> ::= <ab> b\n"
			+"<abc> ::= <ab> c \n"
			+"<abc> ::= <abc> c\n"
	},
		
	"ex-abc-3":{
		"input": "a a b b b c c",
		"terminals": "a b c",
		"nonterminals": "<c> <bc> <abc>",
		"head": "<abc>",
		"rules": 
			"<c> ::= c c \n"
			+"<c> ::= c <c>\n"
			+"<bc> ::= b <c>\n"
			+"<bc> ::= b <bc>\n"
			+"<abc> ::= a <bc> \n"
			+"<abc> ::= a <abc>\n"
	},
		
		
	"ex-a-amb":{
		"input": "a a a a a",
		"terminals": "a",
		"nonterminals": "<a> <b>",
		"head": "<a>",
		"rules": 
			"<a> ::= a <a> \n"
			+"<a> ::= a a\n"
			+"<b> ::= <b> a\n"
			+"<b> ::= a a\n"
	},
		
}


function load_example(ex_id){
	ex = example_tab[ex_id];
	for (x in ex){
		document.getElementById(x).value = ex[x];
	}
}


