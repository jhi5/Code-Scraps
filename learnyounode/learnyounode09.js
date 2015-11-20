var bl = require('bl');
var http = require('http');
var url1 = process.argv[2];
var url2 = process.argv[3];
var url3 = process.argv[4];
//the indicator allows you to asynch easily
var indicator = 0;
//store the values in the order you want via the array
var array = [];
//shortcut function for printing each array val in order
function printAll(){
	for(i=0; i<array.length; i++){
		console.log(array[i]);
	}
};

http.get(url1, function(response){
		response.pipe(bl(function(err,data){
		if(err){
			return console.log(err);
		}
		//assign order without waiting for other calls
		array[0] = data.toString();
		//increment up to note the completion of the process
		indicator++;
		//should be 3 if all 3 are finished
		if(indicator === 3){
			printAll();
		}
	}));
});

http.get(url2, function(response){
	response.pipe(bl(function(err,data){
		if(err){
			return console.log(err);
		}
		array[1] = data.toString();
		indicator++;
		if(indicator === 3){
			printAll();
		}
	}));
});

http.get(url3, function(response){
	response.pipe(bl(function(err,data){
		if(err){
			return console.log(err);
		}
		array[2] = data.toString();
		indicator++;
		if(indicator === 3){
			printAll();
		}
	}));
});

