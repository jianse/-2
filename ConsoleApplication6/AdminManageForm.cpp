#include "AdminManageForm.h"



AdminManageForm::AdminManageForm()
{
}


AdminManageForm::~AdminManageForm()
{
}

void AdminManageForm::show()
{
	bool signal = true;
	do 
	{
		system("cls");
		cout << "1. add an admin\n\
2. delete an admin\n\
3. find an admin\n\
4. return \n\
0. exit\n\
select a selection and press ENTER to continue:";
		switch (waitakey())
		{
		case '0':
			break;
		case '1':
		{
			bool saveable = true;;
			string username, password;
			cout << "Username:";
			cin >> username;
			cout << "Password:";
			cin >> password;
			UserBean user(username, password), luser;
			user.setrank(0);
			user.setsid("0");
			File userfile("m_user.dat");
			while (!(userfile.in.eof()))
			{
				userfile.in >> luser;
				if (user == luser)
				{
					saveable = false;
					cout << "already exsit";

					system("pause");
					break;
				}
			}
			if (saveable)
			{
				userfile.out << user;
			}
			break;
		}
		case '2':
		{
			string username;
			cout << "Please input username will be deleted:";
			cin >> username;
			File userfile("m_user.dat");
			vector<UserBean> users;
			UserBean user(username,"0"),luser;
			users = userfile.loadall<vector<UserBean>, UserBean>(users);
			for (vector<UserBean>::iterator i = users.begin(), end = users.end(); i != end; i++)
			{
				if (*i == luser)
				{
					users.erase(i);
				}
			}
			userfile.recreate();
			userfile.write<vector<UserBean>, UserBean>(users);
			break;
		}
			
		case '3':
		{
			bool found = false;
			string username;
			cout << "Please input username:";
			cin >> username;
			File userfile("m_user.dat");
			UserBean user(username, "0"), luser;
			vector<UserBean> users;
			users = userfile.loadall<vector<UserBean>, UserBean>(users);
			for (vector<UserBean>::iterator i = users.begin(), end = users.end(); i != end; i++)
			{
				if (*i == user)
				{
					i->display();
					found = true;
				}
			}
			if (!found)
			{
				cout << "not found" << endl;
			}
			system("pause");
			break;
		}
			
		case '4':
			return;
			break;
		default:
			cout << "undifined selection please retry" << endl;
			system("pause");
			break;
		}
	}
	while (signal);
}

char AdminManageForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}
