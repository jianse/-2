#pragma once
#include <vector>
#include "Form.h"
#include "UserBean.h"
#include "TeacherBean.h"
#include "CourseManageForm.h"

class TeacherForm :
	public Form
{
public:
	TeacherForm(UserBean user);
	~TeacherForm();
	void show();
private:
	char waitakey();
	void showmenu();
	void editminfo();
	void changepassword();
	void cousemenagment();
	void uploadscore();
	UserBean user;
	TeacherBean m_info;
};

