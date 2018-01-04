#pragma once
#include "Bean.h"
#include "TeacherBean.h"
#include "Date.h"
#include <vector>

class SubjectBean :
	public Bean
{
public:
	SubjectBean();
	~SubjectBean();
	bool operator==(SubjectBean &s2);
	SubjectBean & operator=(SubjectBean &s2);
private:
	string id;		//课程id
	string name;	//课程名
	vector<TeacherBean> teacher; //开课教师
	bool issingal;		//单双周
	int length;		//学时
	Date time;      //上课时间
	string description; //描述
};

