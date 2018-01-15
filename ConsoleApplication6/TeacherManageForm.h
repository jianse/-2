#pragma once
#include "Form.h"
class TeacherManageForm :
	public Form
{
public:
	TeacherManageForm();
	~TeacherManageForm();
	void show();
private:
	char waitakey();
};

