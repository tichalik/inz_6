from bs4 import BeautifulSoup

text = """
<!DOCTYPE html>
<html><head>
<meta http-equiv="content-type" content="text/html; charset=windows-1252">

<style>
 .expandable{
	margin: 10px;
	border: solid 2px black;
 }
 
 .tree{
	margin 10px;
	border: solid 2px green;
 }
</style>

<script>
	<!-- function for toggling children -->
	<!-- obj is the object which was clicked on  -->
	function toggle_children(obj){
	
	  <!-- just to show something's happening -->
	  <!-- console.log("somethings happening!"); -->
	
	    <!-- for each child of the element -- it contains only one -->
    	for (const child of obj.children) {
		  <!-- toggle between "none" for invisivle and "block" for visible -->
		  if (child.style.display != "none"){
			child.style.display = "none";
		  }
		  else {
		    child.style.display = "block";
		  }
		}
	}
	
	<!-- show that code embeded directly in the  -->
	<!-- script is executed upon loading the page -->
	console.log("somehting");
	
	<!-- yet it is done before the page elements are created  -->
	<!-- -- therefore this will not do anything -->
	console.log(document.getElementsByClassName("expandable").length);
	
	<!-- packing the script for adding the onclick events -->
	<!-- so that is can be called upon loading the page -->
	function add_events(){
	
		<!-- get all the elements of this class -->
		for (expandable of document.getElementsByClassName("expandable")){
		
		<!-- add the event to be called on click -->
		  expandable.addEventListener("click", 
		    <!-- a lambda function -->
			function(event){
			  
			  <!-- get the object which was clicked on -->
			  let caller = event.caller || event.srcElement
			  
			  <!-- call the toggling function -->
			  toggle_children(caller);
			  
			  <!-- withouth this all the parent elements of the element  -->
			  <!-- which was clicked on will also reveive the evevnt -->
			  event.stopPropagation();
			});
		  
		  <!-- just show that it works -->
		  <!-- console.log("added!"); -->
		}
	}
</script>


</head>

<body onload="add_events()">
	<!-- action is the url that is put in the http message-box
		 method is what kind of message it is -- by default GET-->
	<form action="/done" method="post">
		<fieldset>
		<legend> grammar </legend>
			<div> enter terminals separated by a whitespace </div>
			<textarea id="terminals" name="terminals">A - </textarea>
			<label for="terminals"> terminals </label>
			
			
			<div> enter nonterminals separated by a whitespace </div>
			<textarea id="nonterminals" name="nonterminals">a</textarea>
			<label for="nonterminals"> nonterminals </label>
			
			
			<div> enter head</div>
			<input type="text" name="head" id="head" ,="" value="a">
			<label for="head"> head </label>
			
			<div> enter rules in form LHS -&gt; RHS1 RHS2 separated by a newline</div>
			<textarea id="rules" name="rules">a -&gt; A -
a -&gt; a A
a -&gt; a -</textarea>
			<label for="rules"> rules </label>
			
		</fieldset>	
		<fieldset>
		<legend> input </legend>
			<div> enter input</div>
			<textarea id="input" name="input">A - A - A - A - A</textarea>
			<label for="input"> input </label>
		</fieldset>
		
		<input type="submit" value="submit">
	</form>
	
	<div id="errors">

	</div>
	
	<div id="results">
<div class="tree"><div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 A
</div>
<span class="node-folded">A</span>
</div>
<div class="node">
<div class="node-expanded">
 -
</div>
<span class="node-folded">-</span>
</div>
</div>
<span class="node-folded">a[A -]</span>
</div>
<div class="node">
<div class="node-expanded">
 A
</div>
<span class="node-folded">A</span>
</div>
</div>
<span class="node-folded">a[a[A -] A]</span>
</div>
<div class="node">
<div class="node-expanded">
 -
</div>
<span class="node-folded">-</span>
</div>
</div>
<span class="node-folded">a[a[a[A -] A] -]</span>
</div>
<div class="node">
<div class="node-expanded">
 A
</div>
<span class="node-folded">A</span>
</div>
</div>
<span class="node-folded">a[a[a[a[A -] A] -] A]</span>
</div>
<div class="node">
<div class="node-expanded">
 -
</div>
<span class="node-folded">-</span>
</div>
</div>
<span class="node-folded">a[a[a[a[a[A -] A] -] A] -]</span>
</div>
<div class="node">
<div class="node-expanded">
 A
</div>
<span class="node-folded">A</span>
</div>
</div>
<span class="node-folded">a[a[a[a[a[a[A -] A] -] A] -] A]</span>
</div>
<div class="node">
<div class="node-expanded">
 -
</div>
<span class="node-folded">-</span>
</div>
</div>
<span class="node-folded">a[a[a[a[a[a[a[A -] A] -] A] -] A] -]</span>
</div>
<div class="node">
<div class="node-expanded">
 A
</div>
<span class="node-folded">A</span>
</div>
</div>
<span class="node-folded">a[a[a[a[a[a[a[a[A -] A] -] A] -] A] -] A]</span>
</div>
</div>
<br>
<div class="tree"><div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 A
</div>
<span class="node-folded">A</span>
</div>
<div class="node">
<div class="node-expanded">
 -
</div>
<span class="node-folded">-</span>
</div>
</div>
<span class="node-folded">a[A -]</span>
</div>
<div class="node">
<div class="node-expanded">
 A
</div>
<span class="node-folded">A</span>
</div>
</div>
<span class="node-folded">a[a[A -] A]</span>
</div>
<div class="node">
<div class="node-expanded">
 -
</div>
<span class="node-folded">-</span>
</div>
</div>
<span class="node-folded">a[a[a[A -] A] -]</span>
</div>
<div class="node">
<div class="node-expanded">
 A
</div>
<span class="node-folded">A</span>
</div>
</div>
<span class="node-folded">a[a[a[a[A -] A] -] A]</span>
</div>
<div class="node">
<div class="node-expanded">
 -
</div>
<span class="node-folded">-</span>
</div>
</div>
<span class="node-folded">a[a[a[a[a[A -] A] -] A] -]</span>
</div>
<div class="node">
<div class="node-expanded">
 A
</div>
<span class="node-folded">A</span>
</div>
</div>
<span class="node-folded">a[a[a[a[a[a[A -] A] -] A] -] A]</span>
</div>
</div>
<br>
<div class="tree"><div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 A
</div>
<span class="node-folded">A</span>
</div>
<div class="node">
<div class="node-expanded">
 -
</div>
<span class="node-folded">-</span>
</div>
</div>
<span class="node-folded">a[A -]</span>
</div>
<div class="node">
<div class="node-expanded">
 A
</div>
<span class="node-folded">A</span>
</div>
</div>
<span class="node-folded">a[a[A -] A]</span>
</div>
<div class="node">
<div class="node-expanded">
 -
</div>
<span class="node-folded">-</span>
</div>
</div>
<span class="node-folded">a[a[a[A -] A] -]</span>
</div>
<div class="node">
<div class="node-expanded">
 A
</div>
<span class="node-folded">A</span>
</div>
</div>
<span class="node-folded">a[a[a[a[A -] A] -] A]</span>
</div>
</div>
<br>
<div class="tree"><div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 a
<div class="node">
<div class="node-expanded">
 A
</div>
<span class="node-folded">A</span>
</div>
<div class="node">
<div class="node-expanded">
 -
</div>
<span class="node-folded">-</span>
</div>
</div>
<span class="node-folded">a[A -]</span>
</div>
<div class="node">
<div class="node-expanded">
 A
</div>
<span class="node-folded">A</span>
</div>
</div>
<span class="node-folded">a[a[A -] A]</span>
</div>
</div>
<br>

	</div>
	
	


</body></html>
"""

soup = BeautifulSoup(text, "html.parser")
print(soup.prettify())