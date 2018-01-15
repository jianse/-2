#pragma once
#include "Form.h"
#include "UserBean.h"
class TeacherForm :
	public Form
{
public:
	TeacherForm(UserBean user);
	~TeacherForm();
	void show();
private:
	UserBean user;
};

