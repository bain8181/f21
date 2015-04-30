/*
 * IceServer2.cpp
 *
 *  Created on: 2015年4月24日
 *      Author: hb
 */



//必须包含Ice.h文件，以支持Ice运行时
#include <Ice/Ice.h>
//必须包含Printer.h，以使用Slice规范
#include "Printer.h"

using namespace std;
using namespace Demo;

/*
 * 骨架类Printer根据Printer.ice定义由Slice2cpp编译器生成，
 * 它的printString纯虚方法，骨架类不能被实例化
 * 服务者PrintI类继承骨架类Printer,提供printString纯虚方法的实现
 * */
class PrinterI:public Printer
{
public:
	/*
	 * Ice::Current对象为服务器中操作的实现提供了有关当前执行请求的信息
	 * 如适配器、连接、标识、层面、操作、操作模式、上下文、请求ID等
	 * */
	virtual void printString(const string& s,const Ice::Current &)
	{
		cout<<s<<endl;
	}
};

class MyApp: public Ice::Application
{
public:
	virtual int run(int argc,char* argv[])
	{
		//this->main(argc,argv);
		Ice::CommunicatorPtr ic = communicator();
        //ic->getProperties()->parseCommandLineOptions("SimplePrinterAdapter",Ice::argsToStringSeq(argc,argv));
		Ice::ObjectAdapterPtr adapter = ic->createObjectAdapterWithEndpoints("SimplePrinterAdapter","default -p 10000");
		Ice::ObjectPtr object = new PrinterI();
		adapter->add(object,ic->stringToIdentity("SimplePrinter"));
		adapter->activate();
		ic->waitForShutdown();
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
