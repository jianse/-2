#pragma once
#include "Form.h"
#include "SubjectBean.h"
#include <vector>

class CourseManageForm :
	public Form
{
public:
	CourseManageForm();
	~CourseManageForm();
	void show();
private:
	void addacourse();
	void modifyacourse();
	char waitakey();
};

