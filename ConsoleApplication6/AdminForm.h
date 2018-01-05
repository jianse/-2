#pragma once
#include "Form.h"
#include "UserBean.h"
class AdminForm :
	public Form
{
public:
	AdminForm(UserBean user);
	~AdminForm();
	void show();
private:
	void showmenu();
	char waitakey();
	void showadminmanage();
	void showteachermanage();
	void showstudentmanage();
	void showcoursemanage();
	UserBean user; 
};

