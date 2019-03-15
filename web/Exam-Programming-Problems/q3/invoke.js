// Question 3

/* (Code to submit starts here) */
function invoke(f, initial, interval) {
	//	setTimeout(f, initial);
		initial = initial+interval;
		while((initial-interval)>=0){
				initial = initial - interval;
				setTimeout(f, initial);
		}
}
/* (Code to submit ends here) */


var setup = function() {
	console.log("Calling invoke ");		
	var foo = function() { 
		console.log("time: " + Date.now()); 
	}
	invoke( foo,
		 2000,	// initial
		 1000 	// interval
	);
}
