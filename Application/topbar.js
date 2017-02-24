onload = function(){

	//Get elements and variables:
	// Load native UI library
	var gui = require('nw.gui'); //or global.window.nwDispatcher.requireNwGui() (see https://github.com/rogerwang/node-webkit/issues/707)

	// Get the current window
	var win = gui.Window.get();

	var exit = document.getElementById("exit");
	var minimize = document.getElementById("minimize");
	
	//Set up functions
	minimize.onclick = function(){
		win.minimize();
	};
	exit.onclick = function(){
		win.close();
	};
}
//Entire thing is broken, pls fix later