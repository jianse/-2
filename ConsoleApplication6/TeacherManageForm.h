#pragma once
#include "Form.h"
#include "UserBean.h"
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

