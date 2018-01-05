#pragma once
#include "Bean.h"
#include <string>

class UserBean :
	public Bean
{
public:
	UserBean();
	UserBean(string username, string password);
	~UserBean();
	friend istream &operator >> (istream &is,UserBean &data);
	friend ostream &operator << (ostream & ou,UserBean &data);
	bool operator==(UserBean &u2);
	bool operator==(Bean &b2);
	UserBean &operator=(UserBean &u2);
	Bean &operator=(Bean &b2);
	bool ispass(UserBean &u2);
	string getname();
	void setrank(int rank);
	int getrank();
private:
	string username;
	string password;
	int rank;
};

