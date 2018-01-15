#pragma once
#include "Bean.h"
#include "SubjectBean.h"
#include <vector>
#include <map>
class StudentBean :
	public Bean
{
public:
	StudentBean();
	~StudentBean();
	friend istream &operator >> (istream& is, StudentBean &data);
	friend ostream &operator << (ostream& ou, StudentBean &data);
	bool operator==(StudentBean &s2);
	StudentBean & operator=(StudentBean &s2);
	bool operator== (Bean &b2);
	Bean &operator=(Bean &b2);
	void display();
	string getid();
	map<string, double>& getscoremap();
private:

	string id;			//学生id
	string name;		//学生姓名
	string sex;			//学生性别
	string classNO;		//班级
	int subjectcount;	//课程数
	map<string ,double> subjectsidandscore;		//课程id
	vector<SubjectBean> subjects;	//课程 该信息并不保存在学生信息中 只在必要时通过课程id进行检索填充
};

