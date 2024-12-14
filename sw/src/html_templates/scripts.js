function fold_expand(button){

	if (button.innerText == "+"){
		//expand the node

		button.innerText = "-";
		
		//the expanded node header
		button.parentElement.children[1].style.display = "inline";
		//the folded node header
		button.parentElement.children[2].style.display = "none"; 
		
		//the node body
		button.parentElement.parentElement.children[1].style.display = "block";
	}
	else {
		//collapse the node

		button.innerText = "+";
		
		//the expanded node header
		button.parentElement.children[1].style.display = "none";
		//the folded node header
		button.parentElement.children[2].style.display = "inline"; 
		
		//the node body
		button.parentElement.parentElement.children[1].style.display = "none";
	}

}

example_tab = {  
	"ex-abc-1":{
		"input": "a a b b b c c",
		"terminals": "a b c",
		"nonterminals": "<a> <b> <c> <abc>",
		"head": "<abc>",
		"rules": 
			"<a> ::= a \n"
			+"<a> ::= <a> a\n"
			+"<b> ::= b \n"
			+"<b> ::= <b> b\n"
			+"<c> ::= <c> c\n"
			+"<c> ::= c \n"
			+"<abc> ::= <a> <b> <c>\n"
	},
		
	"ex-abc-2":{
		"input": "a a b b b c c",
		"terminals": "a b c",
		"nonterminals": "<a>  <ab> <abc>",
		"head": "<abc>",
		"rules": 
			"<a> ::= a  \n"
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
			"<c> ::= c \n"
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
			+"<a> ::= a \n"
			+"<a> ::= <b> \n"
			+"<b> ::= <b> a\n"
			+"<b> ::= a \n"
	},
		
}


function load_example(ex_id){
	ex = example_tab[ex_id];
	for (x in ex){
		document.getElementById(x).value = ex[x];
	}
}


