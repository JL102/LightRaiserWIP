// addon.cc
#include <node.h>

namespace demo {

using v8::Function;
using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Null;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;
	
	void CreateObject(const FunctionCallbackInfo<Value>& args){
		Isolate* isolate = args.GetIsolate();
		
		Local<Object> obj = Object::New(isolate);
		obj->Set(String::NewFromUtf8(isolate, "msg"), args[0]->ToString());
		
		args.GetReturnValue().Set(obj);
	}
	
	void init(Local<Object> exports, Local<Object> module){
		
		NODE_SET_METHOD(module, "exports", CreateObject);
	}
	
	NODE_MODULE(addon, init);
}