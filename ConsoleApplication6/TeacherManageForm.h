#pragma once
#include "Form.h"
#include "UserBean.h"
#include "TeacherBean.h"

class TeacherManageForm :
	public Form
{
public:
	TeacherManageForm();
	~TeacherManageForm();
	void show();
private:
	void addateacher();
	char waitakey();
	
};

