#pragma once
#include "Bean.h"
class TeacherBean :
	public Bean
{
public:
	TeacherBean();
	TeacherBean(string id, string name, string dep, string gender, string des);
	~TeacherBean();
	friend istream &operator >> (istream & is, TeacherBean & data);
	friend ostream &operator << (ostream & ou, TeacherBean & data);
	bool operator==(TeacherBean &t2);
	TeacherBean & operator=(TeacherBean &t2);
	bool operator== (Bean &b2);
	Bean &operator=(Bean &b2);
	void display();
private:
	string id;		//��ʦid
	string name;	//��ʦ����
	string department;//��������
	string sex;		//�Ա�
	string description;//���
};

