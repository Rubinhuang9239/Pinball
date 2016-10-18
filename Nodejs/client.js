const net = require('net');
const client = net.connect("8080","172.22.151.124",function(){
	console.log("connected to server!");

	client.write('n=' + 'Rubin' +'\n');
	client.write('i');

	setInterval(function(){
		client.write('r');
	},2000);
});