#pragma once
#include "Bean.h"
#include "SubjectBean.h"
#include <vector>
class StudentBean :
	public Bean
{
public:
	StudentBean();
	~StudentBean();
	bool operator==(StudentBean &s2);
	StudentBean & operator=(StudentBean &s2);
private:

	string id;			//学生id
	string name;		//学生姓名
	string sex;			//学生性别
	string classNO;		//班级
	int subjectcount;	//课程数
	vector<SubjectBean> subjects;	//课程
};

