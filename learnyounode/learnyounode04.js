var fs = require('fs');
file = fs.readFile(process.argv[2], function(err, data){
	console.log(data.toString().split('\n').length - 1);
});

//read a file, print # of \n