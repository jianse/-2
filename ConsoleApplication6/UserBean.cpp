#include "stdafx.h"
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
	return *this;
}

Bean & UserBean::operator=(Bean & b2)
{
	return *this;
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

void UserBean::setrank(int rank)
{
	UserBean::rank = rank;
}

int UserBean::getrank()
{
	return rank;
}


istream & operator >> (istream & is, UserBean & data)
{
	is >> setw(12) >> data.username >> setw(18) >> data.password >> setw(2) >> data.rank;
	return is;
}

ostream & operator<<(ostream & ou, UserBean & data)
{
	ou << setw(12)<< data.username << setw(18) << data.password << setw(2) << data.rank << endl;
	return ou;
}
