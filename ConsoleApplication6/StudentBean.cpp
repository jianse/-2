
#include "StudentBean.h"


StudentBean::StudentBean()
{
}

StudentBean::StudentBean(string id, string name, string gender, string classNO)
{
	StudentBean::id = id;
	StudentBean::name = name;
	StudentBean::gender = gender;
	StudentBean::classNO = classNO;
	StudentBean::subjectcount = 0;
}


StudentBean::~StudentBean()
{
}

bool StudentBean::operator==(StudentBean & s2)
{
	if (id == s2.id)
	{
		return true;
	}
	return false;
}

StudentBean & StudentBean::operator=(StudentBean & s2)
{
	this->id = s2.id;
	this->name = s2.name;
	this->classNO = s2.classNO;
	this->gender = s2.gender;
	this->subjectcount = s2.subjectcount;
	this->subjectsidandscore = s2.subjectsidandscore;
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

void StudentBean::display()
{
	cout << "id\t:" << StudentBean::id << endl;
	cout << "name\t:" << StudentBean::name << endl;
	cout << "sex\t:" << StudentBean::gender << endl;
	cout << "classNO\t:" << StudentBean::classNO << endl;

}

string StudentBean::getid()
{
	return id;
}

map<string, double> & StudentBean::getscoremap()
{
	return this->subjectsidandscore;
}

void StudentBean::addsubject(string cid)
{
	subjectcount++;
	subjectsidandscore.insert(make_pair(cid, -1));
}

istream & operator >> (istream & is, StudentBean & data)
{
	is >> setw(12) >> data.id >> setw(12) >> data.name >> setw(4) >> data.gender >> setw(10) >> data.classNO >> setw(3) >> data.subjectcount;
	for (int i = 0; i < data.subjectcount; i++)
	{
		string key;
		double value;
		is >> setw(12) >> key >> setw(10) >> value;
		data.subjectsidandscore.insert(make_pair(key, value));
	}
	return is;
}

ostream & operator << (ostream & ou, StudentBean & data)
{
	ou << setw(12) << data.id << setw(12) << data.name << setw(4) << data.gender << setw(10) << data.classNO << setw(3) << data.subjectcount;
	for (map<string, double>::iterator i = data.subjectsidandscore.begin(), e = data.subjectsidandscore.end(); i != e; i++)
	{
		ou << setw(12) << i->first << setw(10) << i->second;
	}
	ou << endl;
	return ou;
}
