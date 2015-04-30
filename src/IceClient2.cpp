/*
 * IceClient2.cpp
 *
 *  Created on: 2015年4月24日
 *      Author: hb
 */




#include <Ice/Ice.h>
#include "Printer.h"

using namespace std;
using namespace Demo;

class MyApp: public Ice::Application
{
public:
	virtual int run(int argc,char* argv[])
	{
		//this->main(argc,argv);
		Ice::CommunicatorPtr ic = communicator();
		//ic->getProperties()->parseCommandLineOptions("SimplePrinterAdapter",Ice::argsToStringSeq(argc,argv));
		Ice::ObjectPrx base = ic->stringToProxy("SimplePrinter:default -p 10000");
		PrinterPrx printer = PrinterPrx::checkedCast(base);
		if (!printer)
			throw "Invalid Proxy!";
		printer->printString("Hello world!");
		return 0;
	}

};


#ifdef ICE_TEST
int main(int argc,char* argv[])
{
	MyApp app;
	return app.main(argc,argv);
}
#endif
