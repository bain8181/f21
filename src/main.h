/*
 * main.h
 *
 *  Created on: 2015年4月11日
 *      Author: hb
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <string>
#include <jsoncpp/json/json.h>

void test_json()
{
	Json::Value jvalue;
	//jvalue["lname"]="hou";
	//jvalue["fname"]="bing";
	//jvalue["age"]=34;
	//jvalue["salary"]=7000.3;
	//jvalue["zip"]="6100";


	jvalue["Id"] = 6;
	jvalue["Model"] = "Lumia 2011_kkk";
	jvalue["Manufacturer"] = "Nokia";
	jvalue["Owner"]["Id"] = 1;
	jvalue["Owner"]["Name"] = "OldOne";
	jvalue["Owner"]["SurName"] = "OldManSurname";
	jvalue["Owner"]["Age"] = 90;
	jvalue["Owner"]["Profession"] = "sportsmen";
	jvalue["Owner"]["Mails"].append("1@163.com");
	jvalue["Owner"]["Mails"].append("hb@msn.com");
	jvalue["Owner"]["Mails"].append("qq@qq.com");
	jvalue["Owner"]["Mails"].append("1312@mail.qwqe");

	Json::FastWriter writer;
	std::string out = writer.write(jvalue);
	std::cout<<out.data()<<std::endl;
	std::string json= jvalue.toStyledString();
	std::cout<<json.c_str()<<std::endl;

}

#endif /* MAIN_H_ */
