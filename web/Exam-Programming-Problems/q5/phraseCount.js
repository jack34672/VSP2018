//Reads a stream and counts the number of phrases in it 

var fs = require('fs');
var fileName = "sample.txt";
var readStream = fs.createReadStream(fileName);

			var length = 0;

readStream.on("data", function(blob) {
	var str = blob.toString();
	var i;
   for(i=0; i<= str.length; i++){
		//console.log(str[i]);
		if((str[i] == '?')||(str[i] == '.')||(str[i] == '!')){
			if(str[i+1]==' '){
				length++;
			}
		}
	}
	length++;
} );

readStream.on("end", function() {
	console.log("Total number of $$ phrases $$ read = " + length);
} );

readStream.on("error", function() {
     console.log("Error occurred when reading from file " + fileName);
} );
