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
	SubjectBean(string id, string name, int teachernum, vector<string> teachersid, bool singel, int length, string des);
	~SubjectBean();
	friend istream &operator >> (istream & is, SubjectBean& data);
	friend ostream &operator << (ostream & ou, SubjectBean& data);
	bool operator==(SubjectBean &s2);
	SubjectBean & operator=(SubjectBean &s2);
	bool operator== (Bean &b2);
	Bean &operator=(Bean &b2);
	void display();
	string getid();
private:
	string id;		//课程id
	string name;	//课程名
	int teachernum;		//教师数量
	vector<string> teachersid;	//开课教师id
	vector<TeacherBean> teacher; //开课教师
	bool issingal;		//单双周
	int length;		//学时
	Date time;      //上课时间
	string description; //描述
};

