// hello.js
const addon = require('./hello/build/Release/addon');

console.log(addon.visikol()); // 'world'


/*
var ref = require('ref');
var ffi = require('ffi');

// typedef
var sqlite3 = ref.types.void; // we don't know what the layout of "sqlite3" looks like
var sqlite3Ptr = ref.refType(sqlite3);
var sqlite3PtrPtr = ref.refType(sqlite3Ptr);
var stringPtr = ref.refType(ref.types.CString);

// binding to a few "libsqlite3" functions...
var libsqlite3 = ffi.Library('libsqlite3', {
  'sqlite3_open': [ 'int', [ 'string', sqlite3PtrPtr ] ],
  'sqlite3_close': [ 'int', [ sqlite3Ptr ] ],
  'sqlite3_exec': [ 'int', [ sqlite3Ptr, 'string', 'pointer', 'pointer', stringPtr ] ],
  'sqlite3_changes': [ 'int', [ sqlite3Ptr ]]
});

// now use them:
var dbPtrPtr = ref.alloc(sqlite3PtrPtr);
libsqlite3.sqlite3_open("test.sqlite3", dbPtrPtr);
var dbHandle = dbPtrPtr.deref();
*/

function sliceBlob(blob, start, end, type) {

    type = type || blob.type;

    if (blob.mozSlice) {
        return blob.mozSlice(start, end, type);
    } else if (blob.webkitSlice) {
        return blob.webkitSlice(start, end, type);
    } else {
        throw new Error("This doesn't work!");
    }
}

function dang(){
	
	var xhr = new XMLHttpRequest();
	xhr.open("GET", "visikol_no_shadow.png");
	xhr.responseType = "blob";
	xhr.onload = response;
	xhr.send();
	
	function response(e) {

		   console.log(this);
		   x = this.response;
			  Promise.all([
			   		    createImageBitmap(this.response),
			   		    console.log("Creating")
			   		    
			  ]).then(function(sprites) {
			   		    ctx.drawImage(sprites[0], 0, 0, 400, 225);
			   		    console.log("Drawing");
			  });
		}
	
	canvas = document.getElementById("canvas");
	ctx = canvas.getContext('2d'),
	
	ctx.fillStyle = "white";
	ctx.fillRect(0,0,400,225)
	
	//image = new Image();
	
	//image.onload = function() {
		
	//	blob = new Blob([this], {type: "image/jpeg"});
		

	//	}

	//image.src = 'visikol_no_shadow.png';
	
	
	
}

var http = require('http');