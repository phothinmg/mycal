#include <node.h>
#include "jdn.cpp"

namespace julian
{
    using v8::Exception;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object; // Include Object header
    using v8::String;
    using v8::Value;

    /**
     * Calculate the Julian Day Number (JDN) for a given year, month, day, and calendar type.
     * @param {Number} y The year for which to calculate the JDN.
     * @param {Number} m The month for which to calculate the JDN.
     * @param {Number} d The day for which to calculate the JDN.
     * @param {Number} ct The calendar type. ct = 0 for Julian, ct = 1 for British, and ct = 2 for Gregorian.
     * @returns {Number} The JDN for the given year, month, and day.
     */
    void ToJulian(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        if (args.Length() < 4)
        {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
            return;
        }
        int y = args[0]->NumberValue(isolate->GetCurrentContext()).ToChecked();
        int m = args[1]->NumberValue(isolate->GetCurrentContext()).ToChecked();
        int d = args[2]->NumberValue(isolate->GetCurrentContext()).ToChecked();
        int ct = args[3]->NumberValue(isolate->GetCurrentContext()).ToChecked();
        int value = jdn(y, m, d, ct);
        Local<Number> _jdn = Number::New(isolate, value);
        args.GetReturnValue().Set(_jdn);
    }
    void Init(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "toJdn", ToJulian);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}