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
	string id;		//�γ�id
	string name;	//�γ���
	vector<TeacherBean> teacher; //���ν�ʦ
	bool issingal;		//��˫��
	int length;		//ѧʱ
	Date time;      //�Ͽ�ʱ��
	string description; //����
};

