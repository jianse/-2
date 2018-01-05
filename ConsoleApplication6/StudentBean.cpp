#include "stdafx.h"
#include "StudentBean.h"


StudentBean::StudentBean()
{
}


StudentBean::~StudentBean()
{
}

bool StudentBean::operator==(StudentBean & s2)
{
	return false;
}

StudentBean & StudentBean::operator=(StudentBean & s2)
{
	this->id = s2.id;
	this->name = s2.name;
	this->classNO = s2.classNO;
	this->sex = s2.sex;
	this->subjectcount = s2.subjectcount;
	this->subjects = s2.subjects;
	return *this;
}

bool StudentBean::operator==(Bean & b2)
{
	return false;
}

Bean & StudentBean::operator=(Bean & b2)
{
	return *this;
}
