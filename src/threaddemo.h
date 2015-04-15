/*
 * threaddemo.h
 *
 *  Created on: 2015年4月13日
 *      Author: hb
 */

#ifndef THREADDEMO_H_
#define THREADDEMO_H_

//thread_control
typedef struct _thread_ctl_{
	bool b_Contrl {false};
	bool b_State {false};
}thread_ctl,*pthread_ctl;

//c++11 thread_demo_test
class thread_demo {
public:
	thread_demo();
	virtual ~thread_demo();
	void stop();
protected:
	static void thread_fun(thread_ctl* pCtl);
private:
	thread_ctl m_ctl;
};

#endif /* THREADDEMO_H_ */
