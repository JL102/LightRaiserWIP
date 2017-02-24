var port = false;

function serial(num){
	
	var serialport = require('serialport');
	SerialPort = serialport.SerialPort;
	if(num){
		portName = "COM" + num;
	}else{
		portName = "COM3";
	}
	
	port = new SerialPort(portName, {
		   baudRate: 9600,
		   // look for return and newline at the end of each data packet:
		   parser: serialport.parsers.readline("\n")
	});
	port.on('open', showPortOpen);
	port.on('data', sendSerialData);
	port.on('close', showPortClose);
	port.on('error', showError);
	
}

function writeToPort(string){
	if(port == true)	port.write(string);
	else console.log("Port isn't open!"); return "Port isn't open ya dingus!"; 
}

function showPortOpen() {
	console.log('Port open. Data rate: ' + port.options.baudRate);
	port = true;
}
 
function sendSerialData(data) {
   console.log(data);
}
 
function showPortClose() {
   console.log('port closed.');
}
 
function showError(error) {
   console.log('Serial port error: ' + error);
}

function log(string){
	console.log(string);
	document.getElementById("log").innerHTML += string+"<br/>";
}