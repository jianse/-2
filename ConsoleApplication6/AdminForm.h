#pragma once
#include "Form.h"
#include "UserBean.h"
#include "AdminManageForm.h"
#include "TeacherManageForm.h"
#include "StudentManageForm.h"

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

