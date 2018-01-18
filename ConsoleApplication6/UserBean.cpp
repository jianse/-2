
#include "UserBean.h"


UserBean::UserBean()
{
}

UserBean::UserBean(string username, string password)
{
	UserBean::username = username;
	UserBean::password = password;
	UserBean::rank = 5;
}


UserBean::~UserBean()
{
}

bool UserBean::operator==(UserBean & u2)
{
	if (this->username == u2.username)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool UserBean::operator==(Bean & b2)
{
	return false;
}

UserBean &UserBean::operator=(UserBean & u2)
{
	username = u2.username;
	password = u2.password;
	rank = u2.rank;
	Sid = u2.Sid;
	return *this;
}

Bean & UserBean::operator=(Bean & b2)
{
	return *this;
}

void UserBean::display()
{
	cout << "用户名\t:" << username << endl;
	cout << "密码\t:" << password << endl;
	cout << "信息id\t:" << Sid << endl;
}

bool UserBean::ispass(UserBean & u2)
{
	if ((this->username == u2.username) && (this->password == u2.password))
	{
		return true;
	}
	else
	{
		return false;
	}
}

string UserBean::getname()
{
	return username;
}

void UserBean::setpassword(string npass)
{
	password = npass;
}

void UserBean::setrank(int rank)
{
	UserBean::rank = rank;
}

int UserBean::getrank()
{
	return rank;
}

string UserBean::getsid()
{
	return Sid;
}

void UserBean::setsid(string sid)
{
	UserBean::Sid = sid;
}

istream & operator >> (istream & is, UserBean & data)
{
	is >> setw(12) >> data.username >> setw(18) >> data.password >> setw(2) >> data.rank>> setw(12)>>data.Sid;
	return is;
}

ostream & operator<<(ostream & ou, UserBean & data)
{
	ou << setw(12) << data.username << setw(18) << data.password << setw(2) << data.rank << setw(12) << data.Sid << endl;
	return ou;
}
