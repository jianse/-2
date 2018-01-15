#pragma once
#include "Form.h"
#include "UserBean.h"
#include <vector>
#include "StudentBean.h"

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
	void editminfo();
	void changepassword();
	void selectcorse();
	UserBean user;
	StudentBean m_info;
};

