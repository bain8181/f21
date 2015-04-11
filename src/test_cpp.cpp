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
#include "main.h"

using namespace std;

int main(int argc,char* argv[]) {
	int a[]={1,2,3,4,5};
	vector<int> b = {1,2,3,4,5,6};
	for (auto& t: a)
		cout<<t<<endl;

	for (auto& t: b)
		cout<<t<<"\t";
	cout<<endl;

	map<int,string> c ={{1,"first"},{2,"second"},{3,"third"}};

	for (auto& t :c)
		cout<<t.first<<":"<<t.second<<endl;

	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	test_json();
	return 0;
}
