#include "stdafx.h"
#include "UserBean.h"


UserBean::UserBean()
{
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
