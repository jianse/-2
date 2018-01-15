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

	string id;			//ѧ��id
	string name;		//ѧ������
	string sex;			//ѧ���Ա�
	string classNO;		//�༶
	int subjectcount;	//�γ���
	map<string ,double> subjectsidandscore;		//�γ�id
	vector<SubjectBean> subjects;	//�γ� ����Ϣ����������ѧ����Ϣ�� ֻ�ڱ�Ҫʱͨ���γ�id���м������
};

