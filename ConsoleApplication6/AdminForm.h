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
	UserBean user;
};

