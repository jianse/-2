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

	string id;			//ѧ��id
	string name;		//ѧ������
	string sex;			//ѧ���Ա�
	string classNO;		//�༶
	int subjectcount;	//�γ���
	vector<SubjectBean> subjects;	//�γ�
};

