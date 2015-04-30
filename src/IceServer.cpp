/*
 * IceServer.cpp
 *
 *  Created on: 2015年4月15日
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


#ifdef ICE_TEST
int main(int argc,char* argv[])
{
	int status =0;
	Ice::CommunicatorPtr ic;
	try
	{
		//初始化Ice,获取通讯器，智能指针
		ic = Ice::initialize(argc,argv);


		//在通讯器ic上创建对象适配器SimplePrinterAdapater
		//缺省协议（TCP），在端口10000上监听
		Ice::ObjectAdapterPtr adapter = ic->createObjectAdapterWithEndpoints("SimplePrinterAdapter","default  -h 0.0.0.0 -p 10000");

		//创建服务类PrintI的实例
		Ice::ObjectPtr object = new PrinterI();

		//将服务者类PrinterI的实例加入到适配器，服务者类的名称是"SimplePrinter",
		//客户端必须使用此名称的请求标识来请求服务者的操作。
		adapter->add(object,ic->stringToIdentity("SimplePrinter"));

		//激活对象适配器，客户端请求现在可以分派给服务者实例PrintI
		adapter->activate();

		//挂起当前主函数所有线程，等待通讯器关闭
		ic->waitForShutdown();
	}
	catch(const Ice::Exception& e) //捕捉Ice运行时抛出的异常
	{
		cerr<<e<<endl;
		status = 1 ;
	}
	catch(const char* msg) //捕捉致命错误，输出错误串
	{
		cerr<<msg<<endl;
		status =1;
	}

	//通讯器必须出生化过，否则不能调用destroy
	if (ic)
	{
		try
		{
			ic->destroy();  //销毁通讯器
		}
		catch(const Ice::Exception& e)
		{
			cerr<<e<<endl;
			status =1;
		}
	}

	return status;
}
#endif
