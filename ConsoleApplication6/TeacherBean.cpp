#include "stdafx.h"
#include "TeacherBean.h"


TeacherBean::TeacherBean()
{
}


TeacherBean::~TeacherBean()
{
}

bool TeacherBean::operator==(TeacherBean & t2)
{
	if (this->id == t2.id)
	{
		return true;
	}
	else
	{
		return false;
	}
}

TeacherBean & TeacherBean::operator=(TeacherBean & t2)
{
	this->id = t2.id;
	this->name = t2.id;
	this->department = t2.department;
	this->sex = t2.sex;
	this->description = t2.description;
	return *this;
}
