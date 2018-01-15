#pragma once
#include "Form.h"
class StudentManageForm :
	public Form
{
public:
	StudentManageForm();
	~StudentManageForm();
	void show();
private:
	char waitakey();
};

