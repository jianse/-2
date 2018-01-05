#pragma once
#include "Form.h"
class AdminForm :
	public Form
{
public:
	AdminForm(UserBean user);
	~AdminForm();
private:
	UserBean user;
	string menu = 
""
};

