// hello.cc
#include <node.h>
#include <iostream>
#include <fstream>
#include <string>

namespace demo {

	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Number;
	using v8::Object;
	using v8::String;
	using v8::Value;
	using namespace std;
	
	void CreateObject(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();

		Local<Object> obj = Object::New(isolate);
		obj->Set(String::NewFromUtf8(isolate, "msg"), args[0]->ToString());

		args.GetReturnValue().Set(obj);
	}

	void Method(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Visikol, a Super Clearing Agent!"));
		
		string message = "heck";
		  ofstream myfile;
		  myfile.open ("example.txt");
		  myfile << message;
		  myfile.close();
	}

	void init(Local<Object> exports, Local<Object> module) {
		NODE_SET_METHOD(exports, "visikol", Method);
		NODE_SET_METHOD(module, "exports", CreateObject);

	}

	NODE_MODULE(addon, init)

}  // namespace demo