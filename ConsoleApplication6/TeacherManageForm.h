#pragma once
#include <vector>
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
	void removeateacher();
	void findateacher();
	char waitakey();
	
};

