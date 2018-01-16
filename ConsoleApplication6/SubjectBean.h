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
	string id;		//�γ�id
	string name;	//�γ���
	int teachernum;		//��ʦ����
	vector<string> teachersid;	//���ν�ʦid
	vector<TeacherBean> teacher; //���ν�ʦ
	bool issingal;		//��˫��
	int length;		//ѧʱ
	Date time;      //�Ͽ�ʱ��
	string description; //����
};

