#pragma once
#include "Form.h"
#include "UserBean.h"

class StudentForm :
	public Form
{
public:
	StudentForm(UserBean user);
	~StudentForm();
	void show();
private:
	void showmenu();
	char waitakey();
	UserBean user;
};

