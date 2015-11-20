var http = require('http');
var fs = require('fs');
var portNum = process.argv[2];
var file = process.argv[3];

//basic server setup takes request, response as arg
var server = http.createServer(function (request, response){
	fs.createReadStream(file).pipe(response);
});

//to allow a certain port
server.listen(portNum);

//learnyounode verify program.js