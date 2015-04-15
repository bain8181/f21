#include <boost/bimap.hpp>
#include <iostream>
#include <string>

using namespace boost;

void test_boost_bimap()
{
	bimap<int,std::string> bm;
	bm.left.insert(std::pair<int,std::string>(1,"111"));
	bm.left.insert(std::pair<int,std::string>(2,"222"));
	bm.right.insert(std::pair<std::string,int>("string",10));
	bm.right.insert(std::pair<std::string,int>("bimap",20));

	for(auto pos = bm.left.begin();
			pos != bm.left.end();
			++pos)
	{
		std::cout<<"left[" << pos->first<<"]="<<pos->second<<std::endl;
	}

}
