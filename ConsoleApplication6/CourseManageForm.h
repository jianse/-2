#pragma once
#include "Form.h"
class CourseManageForm :
	public Form
{
public:
	CourseManageForm();
	~CourseManageForm();
	void show();
private:
	char waitakey();
};

