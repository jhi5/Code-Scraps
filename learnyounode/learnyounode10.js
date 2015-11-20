var net = require('net');
var portNum = process.argv[2];

//basic server setup takes socket as arg
var server = net.createServer(function(socket){
	var date = new Date();
	var year = date.getFullYear().toString();
	var month = date.getMonth().toString();
	if(month === "10"){
		month = "11";
	}
	var day = date.getDate().toString();
	var hour = date.getHours().toString(); 
	var minutes = date.getMinutes().toString();
	if(minutes.length < 2){
		minutes = "0" + minutes;
	}
	var finished = year + "-" + month + "-" + day + " " + hour + ":" + minutes;
	socket.end(finished);
});

//to allow a certain port
server.listen(portNum);

//learnyounode verify program.js