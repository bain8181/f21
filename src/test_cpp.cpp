//============================================================================
// Name        : test_cpp.cpp
// Author      : hb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <thread>
#include "main.h"
#include "threaddemo.h"
#include "boostdemo.h"

using namespace std;

int main(int argc,char* argv[]) {

	//test_json();
	test_boost_bimap();

	thread_demo demo;

	std::cout<<"Press any key to Continue.\n";
	std::cin.get();
	demo.stop();

	std::cout<<"Press any key to Exit.\n";
	std::cin.get();

	std::cout<<"Main thread : "<<std::this_thread::get_id()<<" Exit!\n";

	return 0;
}
