var settings = {}, parser, xmlDoc;

onload = function(){ //Opens when page loads. First function call.
	
	loadFile(function(error){ //Load settings.
		console.error(error); 
		
	},function(response) {
		  // Parse JSON string into object
			    settings = JSON.parse(response);
		    	begin();
	}, "settings.json");
	//begin();
}

function begin(){ //Starts things.
	ui();
	serial();
	dang();
}

function loadFile(error, callback, file) {   //Function loads a file and returns it as text.

    var xobj = new XMLHttpRequest();
        xobj.overrideMimeType("application/json");
    xobj.open('GET', file, true); // 
    xobj.onreadystatechange = function () {
          if (xobj.readyState == 4 && xobj.status == "200") {
            // Required use of an anonymous callback as .open will NOT return a value but simply returns undefined in asynchronous mode
            callback(xobj.responseText);
          }else if(xobj.status == "404"){
        	  error("404 error");
          }
    };
    xobj.send(null);  
 }

function append(elem, callback){ //Append element to HTML. Used for UI... sometimes
	try{
		if(typeof(elem) != "object"){
			throw "Not an object!"
		}else{
			document.getElementById("main").appendChild(elem);
			callback(elem);
		}
	}catch(err){
		console.error("Error: " + err);
	}
}