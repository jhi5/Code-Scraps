var http = require('http');
var t2Map = require('through2-map');
var portNum = process.argv[2];
//pass transform through t2Map
var map = t2Map(function (data){
	//feed the actual transforming to the t2Map 
	return data.toString().toUpperCase();
});


//basic server setup takes request, response as arg
var server = http.createServer(function (request, response){
	//request has properties that can be called
	if(request.method === "POST"){
		//request.pipe to pass data through and pipe response to send to user
		request.pipe(map).pipe(response);
	}
});

//to allow a certain port
server.listen(portNum);

//learnyounode verify program.js