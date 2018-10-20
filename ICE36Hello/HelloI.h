#pragma once
#include <Hello.h>

using namespace Demo;
using namespace std;

class HelloI :
	public Hello
{
public:
	virtual void sayHello(::Ice::Int, const ::Ice::Current& = ::Ice::Current()) override;
	virtual void shutdown(const ::Ice::Current& = ::Ice::Current()) override;

};

