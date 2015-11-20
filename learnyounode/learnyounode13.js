var http = require('http');
var url = require('url');
var portNum = process.argv[2];
var parsePath = "/api/parsetime";
var unixPath = "/api/unixtime";
//this function returns a standard time
var sTime = function(){
	x = new Date(parsedUrl.query.iso);
	hour = x.getHours();
	minute = x.getMinutes();
	second = x.getSeconds();
	return {hour, minute, second};	
};
//this function returns unix time
var uTime = function(){
	x = new Date(parsedUrl.query.iso).getTime();
	return {unixtime: x};
};


//basic server setup takes request, response as arg
var server = http.createServer(function (request, response){
	//if there is a request
	if(request){
		response.writeHead(200, {"Content-Type":"application/json"});
		//parsed url from the request object
		parsedUrl = url.parse(request.url, true);
		//take out the path for ease of if statements
		path = parsedUrl.pathname;
		//if the url requests standard time
		if(path === parsePath){
			value = sTime();
			response.end(JSON.stringify(value));
		}
		//if the url requests unix time
		if(path === unixPath){
			value = uTime();
			response.end(JSON.stringify(value));
		};
	}else{
		response.writeHead(404);
		response.end();
	}
});

//to allow a certain port
server.listen(portNum);

//learnyounode verify program.js