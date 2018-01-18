
#include "TeacherBean.h"


TeacherBean::TeacherBean()
{
}

TeacherBean::TeacherBean(string id, string name, string dep, string gender, string des)
{
	TeacherBean::id = id;
	TeacherBean::name = name;
	TeacherBean::department = dep;
	TeacherBean::sex = gender;
	TeacherBean::description = des;
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
	this->name = t2.name;
	this->department = t2.department;
	this->sex = t2.sex;
	this->description = t2.description;
	return *this;
}

bool TeacherBean::operator==(Bean & b2)
{
	return false;
}

Bean & TeacherBean::operator=(Bean & b2)
{
	return *this;
}

void TeacherBean::display()
{
	cout << "教师ID\t:" << TeacherBean::id << endl;
	cout << "姓名\t:" << TeacherBean::name << endl;
	cout << "部门\t:" << TeacherBean::department << endl;
	cout << "性别\t:" << TeacherBean::sex << endl;
	cout << "简介\t:" << TeacherBean::description << endl;
}

string TeacherBean::getid()
{
	return id;
}

istream & operator >> (istream & is, TeacherBean & data)
{
	is >> setw(12) >> data.id >> setw(10) >> data.name >> setw(20) >> data.department >> setw(3) >> data.sex >> setw(30) >> data.description;
	return is;
}

ostream & operator<<(ostream & ou, TeacherBean & data)
{
	ou << setw(12) << data.id << setw(10) << data.name << setw(20) << data.department << setw(3) << data.sex << setw(30) << data.description << endl;
	return ou;
}
