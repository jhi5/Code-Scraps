var express = require('express');
var app = express();

app.get('/books', function(req, res){
	var info = req.query;
	res.send(info);
});

app.listen(process.argv[2]);