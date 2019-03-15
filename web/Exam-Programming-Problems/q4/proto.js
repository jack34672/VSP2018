// Solution to q4 - class hierarchy

// Write your code for 4.1 and 4.2 here
var Triangle = function(edge1, edge2, edge3){
	this.edge1 = edge1;
	this.edge2 = edge2;
	this.edge3 = edge3;
	this.area =  function(){
		var perimeter = (edge1+edge2+edge3)/2;
		return  Math.sqrt(perimeter*((perimeter-edge1)*(perimeter-edge2)*(perimeter-edge3)));
	}
	this.volume = function(){return 0;}
}

var TriangularPrism = function(edge1, edge2, edge3, edge4){
	this.edge1 = edge1;
	this.edge2 = edge2;
	this.edge3 = edge3;
	this.edge4 = edge4;
	this.area =  function(){
		var perimeter = (edge1+edge2+edge3)/2;
		var s1 =  Math.sqrt(perimeter*((perimeter-edge1)*(perimeter-edge2)*(perimeter-edge3)));
		var s2 = edge4*(edge1+edge2+edge3);
		return s1+s1+s2;
	}
	this.volume = function(){
		var perimeter = (edge1+edge2+edge3)/2;
		var s1 =  Math.sqrt(perimeter*((perimeter-edge1)*(perimeter-edge2)*(perimeter-edge3)));
		return s1*edge4;
	}
}

/* (Code to submit EXCLUDES the following test cases) */


var triangle = new Triangle(3,4,5);
var prism = new TriangularPrism(3,4,5,2);
console.log( triangle.area() ); // Prints 6
console.log( triangle.volume() ); // Prints 0
console.log( prism.area() ); // Prints 36
console.log( prism.volume() ); // Prints 12
