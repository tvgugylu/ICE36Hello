#include <Ice/Ice.h>
#include "HelloI.h"

using namespace std;

class HelloServer : public Ice::Application
{
public:
	virtual int run(int argc, char*[]) override
	{
		if (argc <= 1)
		{
			Ice::ObjectAdapterPtr adapter = communicator()->createObjectAdapter("Hello");
			Demo::HelloPtr hello = new HelloI;
			adapter->add(hello, communicator()->stringToIdentity("hello"));
			adapter->activate();
			communicator()->waitForShutdown();
			return EXIT_SUCCESS;
		}
		else
		{
			return EXIT_FAILURE;
		}
	}
};

int main(int argc, char* argv[])
{
	HelloServer app;
	return app.main(argc, argv, "config.server");
}