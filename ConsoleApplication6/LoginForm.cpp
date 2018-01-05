#include "LoginForm.h"
#include "AdminForm.h"
LoginForm::LoginForm()
{
}


LoginForm::~LoginForm()
{
}

void LoginForm::show()
{	
	login();
}

void LoginForm::login()
{
	File userfile("user.dat");
	
	string username, password;
	if (userfile.isempty())
	{
		setadmin();
	}
	else
	{
		cout << menu;
		cout << "UserName:";
		cin >> username;
		cout << "Password:";
		cin >> password;
		UserBean user(username,password), luser;
		while (!(userfile.in.eof()))
		{
			userfile.in >> luser;
			if (user==luser)
			{
				if (user.ispass(luser))
				{
					switch (luser.getrank())
					{
					case 0:
						showadminform(luser);
						break;
					case 1:
						showteacherform(luser);
						break;
					case 2:
						showstudentform(luser);
						break;
					default:
						break;
					}
					break;
				}
				else
				{
					cout << "password error" << endl;
					break;
				}
			}
			
		}
		cout << "no such user\n";
	}
	userfile.close();
	return;
}

void LoginForm::setadmin()
{
	string pwd;
	cout << "before use this system you must set your admin password\n";
	cin >> pwd;
	UserBean user("admin", pwd);
	user.setrank(0);
	File userfile("user.dat");
	userfile.out << user;
	userfile.close();
	login();
}

void LoginForm::showadminform(UserBean user)
{
	AdminForm adminform(user);
	adminform.show();
}

void LoginForm::showteacherform(UserBean user)
{
}

void LoginForm::showstudentform(UserBean user)
{
}

