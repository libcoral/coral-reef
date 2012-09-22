/*
 * Native class adapter template for 'stubs.StringNativeClass'.
 * WARNING: remember to copy this file to your project dir before you begin to change it.
 * Generated by the Coral Compiler v0.7.0 on Thu Mar 01 15:35:26 2012.
 */

#include "StringNativeClass_Adapter.h"

namespace stubs {

const std::string& StringNativeClass_Adapter::getValue( stubs::StringNativeClass& instance )
{
	return instance.data;
}

void StringNativeClass_Adapter::setValue( stubs::StringNativeClass& instance, const std::string& value )
{
	instance.data = value;
}

} // namespace stubs
