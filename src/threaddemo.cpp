/*
 * threaddemo.cpp
 *
 *  Created on: 2015年4月13日
 *      Author: hb
 */
#include <thread>
#include <iostream>
#include <chrono>
#include "threaddemo.h"

thread_demo::thread_demo() {
	this->m_ctl.b_Contrl = true;
	this->m_ctl.b_State = false;
	std::thread t(thread_fun,&(this->m_ctl));
	t.detach();
}

thread_demo::~thread_demo() {
}

void thread_demo::stop()
{
	this->m_ctl.b_Contrl = false;
}

///thread funtion
void thread_demo::thread_fun(thread_ctl* pCtl)
{
	if (pCtl != nullptr)
	{
		pCtl->b_State = true;
		std::cout<<std::this_thread::get_id()<<" running.\n";
		while(pCtl->b_Contrl)
		{
			std::this_thread::sleep_for(std::chrono::microseconds(1));
		}
		pCtl->b_State = true;
		std::cout<<std::this_thread::get_id()<<" stopped.\n";
	}
}
