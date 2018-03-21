#include <node.h>
#include <node_buffer.h>
#include <nan.h>

#include "phi1612.h"

using v8::Exception;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Phi1612(const Nan::FunctionCallbackInfo<Value>& args) {
 
  if(args.Length() < 1) {
    Nan::ThrowTypeError("1 argument expected");
    return;
  }  

  Local<Object> target = args[0]->ToObject();

  if(!node::Buffer::HasInstance(target)) {
    Nan::ThrowTypeError("Function expects buffer as input");
    return;
  }

  char* input = node::Buffer::Data(target);
  char* output = new char[32];

  Phi1612(input, output);
  
  args.GetReturnValue().Set(Nan::NewBuffer(output, 32).ToLocalChecked());
}


void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("Phi1612").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Phi1612)->GetFunction());
}

NODE_MODULE(folmcoinhash, Init)
