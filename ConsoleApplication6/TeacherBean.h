#pragma once
#include "Bean.h"
class TeacherBean :
	public Bean
{
public:
	TeacherBean();
	~TeacherBean();
	bool operator==(TeacherBean &t2);
	TeacherBean & operator=(TeacherBean &t2);
	bool operator== (Bean &b2);
	Bean &operator=(Bean &b2);
private:
	string id;		//教师id
	string name;	//教师姓名
	string department;//工作部门
	string sex;		//性别
	string description;//简介
};

