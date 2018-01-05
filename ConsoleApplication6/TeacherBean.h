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
	string id;		//��ʦid
	string name;	//��ʦ����
	string department;//��������
	string sex;		//�Ա�
	string description;//���
};

