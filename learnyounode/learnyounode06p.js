//call the require to utilize the function
var module = require('./learnyounode6m.js');

//store in variables consistent through files
var tgtDir = process.argv[2];
var filtExt = process.argv[3];

//callback in the module is a short-hand for the actual function here
module(tgtDir, filtExt, function(err, data){
	
	//if there is an error with recalling the module
	if(err){
		return console.log(err);
	}
	//print all entries
	data.forEach(function(file){
		console.log(file);
	});
});

