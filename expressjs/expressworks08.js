var express = require('express');
var app = express();
var fs = require('fs');

app.get('/books', function(req, res){
	var object = fs.readFile(process.argv[3], function(err, data){
		if(err){
			return console.log("error");
		}else{
			res.json(JSON.parse(data));
		}
	});	
});

app.listen(process.argv[2]);