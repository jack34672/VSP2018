// Function to calculate the sum of all integers between 0 and x, both with and without memoization

// Assume x is always an integer >= 0
function sum(x) {
	if (x==0)
		return 0;
	else {
		return x + sum(x-1);
    }
}

/* (Code to submit starts here) */
/*function msum(x){
    var counters =  [];
    for(var i=0; i<x; i++){
    	var val = i;
    	counters[i] = {
    		increment: function(){val++},
    		get: function(){return val;},
    		reset: function(){val = i;}
    	}
    }
    return counters;
}*/
/* (Code to submit ends here) */

function adder(num1) {
  return function(num2) {
    return num1 + num2;
  }
}

var adder5 = adder(5);
var adder10 = adder(10);

console.log (adder5);
console.log (adder10);

console.log( "sum(5) = " + sum(5) );
//var msum = memsum();
console.log( "Memo-Sum(5) = " + msum(5) );
console.log( "Memo-Sum(6) = " + msum(6) );
