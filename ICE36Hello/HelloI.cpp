#include <IceUtil/IceUtil.h>
#include <Ice/Ice.h>
#include "HelloI.h"

void HelloI::sayHello(::Ice::Int delay, const ::Ice::Current& /*= ::Ice::Current()*/)
{
	if (delay != 0)
	{
		IceUtil::ThreadControl::sleep(IceUtil::Time::milliSeconds(delay));
	}
	cout << "Hello World!" << endl;
}

void HelloI::shutdown(const ::Ice::Current& c)
{
	cout << "Shutting down..." << endl;
	c.adapter->getCommunicator()->shutdown();
}
