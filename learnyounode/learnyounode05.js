var fs = require('fs');
var path = require('path');
var extension = "." + process.argv[3];

file = fs.readdir(process.argv[2], function(err, data){
	for(i=0; i<data.length; i++){
		if(extension === path.extname(data[i])){
			console.log(data[i]);
		}
	}
});

