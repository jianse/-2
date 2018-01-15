#pragma once
#include "Form.h"
#include "UserBean.h"
#include "StudentBean.h"

class StudentManageForm :
	public Form
{
public:
	StudentManageForm();
	~StudentManageForm();
	void show();
private:
	char waitakey();
	void addastudent();
};

