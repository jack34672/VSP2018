/* (Code to submit starts here) */
function combinedLen(id) {
var div = document.getElementById(id);           // Get the <div> element with id="myDIV"
var nodelist = div.getElementsByTagName("P").length;

return nodelist;

}
/* (Code to submit ends here) */

window.onload = function() {
	var id = "one";
	var len = combinedLen(id);
	console.log("The combined length of the text of all text nodes that are descendants of one : " + len);
}
