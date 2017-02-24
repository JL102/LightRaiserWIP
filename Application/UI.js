var isSlow = false, isZ = false,
keyDown,
lastKeyDown,
arrowSVG,
xArray, yArray, zArray,
value, obj = {}, d, lastSliderChange = 0;


function ui(){
	xArray = document.getElementsByClassName("x");
	yArray = document.getElementsByClassName("y");
	zArray = document.getElementsByClassName("z");
		

	doSlider();
	doButtons();
}

function doSlider(){
	
	$( "#slider" ).slider({
		value: 0,
		animate: settings.UI.slider.animate,
		min: settings.UI.slider.min,
		max: settings.UI.slider.max
	});
	
	$( "#slider" ).on( "slidechange", function( event, ui ) { //Creates event onSlidechange to update device.
		
		obj.d = new Date(); //Creates date to grab time
		
		//If last slider press was more than (a customized time) ms ago, don't send it 
		if( obj.d.getTime() > lastSliderChange + settings.UI.slider.deltaTime ){
			value = $( "#slider" ).slider( "option", "value" );
			console.log(value);
			lastSliderChange = obj.d.getTime();
		}
		//Delete object to save memory
		delete obj.d;
	} );
}

function doButtons(){
	//Load arrow thing.
	loadFile(function(error){
		console.erorr(erorr);
	}, function(response) {
		  	// Parse XML string into object
		    var xml = response;
		    var parser = new DOMParser();
		    var object = parser.parseFromString(xml, "text/xml");
		    
		    arrowSVG = object.children[0];
		    arrowSVG.id = "arrowsvg";
		    $("#arrowsvg-container")[0].appendChild(arrowSVG);
		    
		    //Deal with events AFTER COMPLETE
		    doArrowEvents();
	}, "arrows.min.svg");
	
	loadFile(function(error){
		console.erorr(erorr);
	}, function(response) {
	  	// Parse XML string into object
	    var xml = response;
	    var parser = new DOMParser();
	    var object = parser.parseFromString(xml, "text/xml");
	    
	    arrowSVG = object.children[0];
	    arrowSVG.id = "lasersvg";
	    $("#lasersvg-container")[0].appendChild(arrowSVG);
	    
	    //Deal with events AFTER COMPLETE
	    doLaserEvents();
	}, "laser2.svg");
}

function doArrowEvents(){
	
	//When keys are pressed or released, check for: arrow keys and ctrl key.
	document.addEventListener("keydown", function(e){
		switch(e.keyCode){
		case 37://Left
			doArrow("arrleft",true); break;
		case 38://Up
			doArrow("arrup",true); break;
		case 39://Right
			doArrow("arrright",true); break;
		case 40://Down
			doArrow("arrdown",true); break;
		case 17://Ctrl
			isSlow = true;
			break;
		case 16://Shift
			//If doZ has already been done, no need to do it again
			if(!isZ) doZ(1);
			break;
		}
	});
	document.addEventListener("keyup", function(e){
		switch(e.keyCode){
		case 37://Left
			doArrow("arrleft",false); break;
		case 38://Up
			doArrow("arrup",false); break;
		case 39://Right
			doArrow("arrright",false); break;
		case 40://Down
			doArrow("arrdown",false); break;
		case 17://Ctrl
			isSlow = false; 
			break;
		case 16://Shift
			if(isZ) doZ(0);
			break;
		}
	});
}

function doLaserEvents(){
	
	//Creates click thing and submits "l" + id number (1 to 3) to serial for angle
	laserArray = [];
	laserArray = document.getElementsByClassName("laser_group");
	for( var i = 0; i < laserArray.length; i++ ){
		var obj = laserArray[i];
		obj.onclick = function(){
			var path = this.children[0];
			var id = path.id;
			writeToPort(eval("settings.UI.laser."+ id));
		}
	}
	
}

function doZ(value){
	//Function is for arrowSVG, toggling between Z mode.
	//Set isZ to param input
	isZ = (value == 1) ? true : false;
	//Toggle between active/inactive or shown/hidden if Z is active.
	
	if(isZ){
		for(var i = 0; i < xArray.length; i++){
			xArray[i].className.baseVal = xArray[i].className.baseVal.replace("active", "inactive");
		}
		for(var i = 0; i < yArray.length; i++){
			yArray[i].className.baseVal = yArray[i].className.baseVal.replace("shown", "hidden");
		}
		for(var i = 0; i < zArray.length; i++){
			zArray[i].className.baseVal = zArray[i].className.baseVal.replace("hidden", "shown");
		}
	}else{
		for(var i = 0; i < xArray.length; i++){
			xArray[i].className.baseVal = xArray[i].className.baseVal.replace("inactive", "active");
		}
		for(var i = 0; i < yArray.length; i++){
			yArray[i].className.baseVal = yArray[i].className.baseVal.replace("hidden", "shown");
		}
		for(var i = 0; i < zArray.length; i++){
			zArray[i].className.baseVal = zArray[i].className.baseVal.replace("shown", "hidden");
		}
	}
}

function doArrow(id,isDown){
	var elem = document.getElementById(id);
	if(!( isZ && elem.classList[1] == "x")){
		if(isDown){//If key is being pressed down, highlight; otherwise, unhighlight. 
			elem.className.baseVal = elem.className.baseVal.replace( "st0", isSlow ? "" : "st1");
			keyDown = id;
			if(keyDown != lastKeyDown) writeToPort(sendKey(id, false));
			lastKeyDown = id;
		}else{
			elem.className.baseVal = elem.className.baseVal.replace( isSlow ? "" : "st1", "st0");
			lastKeyDown = null;
			writeToPort(sendKey(id, true));
		}
	}
	//Change arrow of x id. If key is not pressed, stylize arrow norm. If pressed and slow, stylize slow. If pressed and not slow, stylize fast.
	//document.getElementById(id).className.baseVal = isDown ? isSlow ? "sts" : "stf" : "st0";

}

function sendKey(id, stop){
			switch(id){
			case "arrleft"://Minus x. If x is disabled, this function wouldn't be called.
				return stop ? settings.UI.dir.x.stop : settings.UI.dir.x.minus;
				
			case "arrup": //if Z is enabled use Z otherwise Y
				return isZ ? 
						stop ? settings.UI.dir.z.stop : settings.UI.dir.z.plus : 
							stop ? settings.UI.dir.y.stop : settings.UI.dir.y.plus;
				
			case "arrright":
				return stop ? settings.UI.dir.x.stop : settings.UI.dir.x.plus;
				
			case "arrdown":
				return isZ ? 
						stop ? settings.UI.dir.z.stop : settings.UI.dir.z.minus : 
							stop ? settings.UI.dir.y.stop : settings.UI.dir.y.minus;
			}
		}