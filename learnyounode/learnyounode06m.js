var fs = require('fs');
var path = require('path');

//assign the function to module.export. function takes directory, extension & callback
module.exports = function(tgtDir, filtExt, callback){
	
	//read the directory and check for read errors
	fs.readdir(tgtDir, function(err, data){
		//if there's a read error, feed that error to program.js callback
		if(err){
			return callback(err);
		}
		//filter the data by true/false check vs. desired extension
		data = data.filter(function(file){
			return path.extname(file) === "." + filtExt; 
		})

	//call the program.js function without an error if everything is good
	callback(null, data);	
	})
}
	