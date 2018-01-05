#include "LoginForm.h"
LoginForm::LoginForm()
{
}


LoginForm::~LoginForm()
{
}

void LoginForm::show()
{
	cout << menu;
	if (login())
	{

	}
		
}

bool LoginForm::login()
{
	File userfile("user.dat");
	if (!(userfile.in))
	{
		setadmin();
	}
	UserBean userdata;
	string username, password;
	cout << "UserName:";
	cin >> username;
	cout << "Password:";
	cin >> password;
	File f_user("./user.dat");
	
	f_user.in >> userdata;
	return false;
}
