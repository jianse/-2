#include "stdafx.h"
#include "SubjectBean.h"


SubjectBean::SubjectBean()
{
}


SubjectBean::~SubjectBean()
{
}

bool SubjectBean::operator==(SubjectBean & s2)
{
	if (SubjectBean::id == s2.id)
	{
		return true;
	}
	else
	{
		return false;
	}
}

SubjectBean & SubjectBean::operator=(SubjectBean & s2)
{
	this->id = s2.id;
	this->name = s2.name;
	this->teacher = s2.teacher;
	this->issingal = s2.issingal;
	this->length = s2.length;
	this->time = s2.time;
	this->description = s2.description;
	return *this;
}
