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
		cout << "[1] ���һ������Ա\n\
[2] �Ƴ�һ������Ա\n\
[3] ���ҹ���Ա��Ϣ\n\
[4] ���� \n\
[0] �˳�\n\
ѡ����Ҫ���еĲ����� ENTER ����:";
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
			vector<UserBean> users;
			File userfile("m_user.dat");
			users = userfile.loadall<vector<UserBean>, UserBean>(users);
			for (vector<UserBean>::iterator i = users.begin(), e = users.end(); i != e; i++)
			{
				if (*i == user)
				{
					saveable = false;
					cout << "�Ѿ����ڵ��û���" << endl;
					system("pause");
					break;
				}
			}
			if (saveable)
			{
				userfile.write(user);
				cout << "��ӹ���Ա�ɹ���" << endl;
				system("pause");
			}
			break;
		}
		case '2':
		{
			string username;
			cout << "������Ҫ�Ƴ����û�����:";
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
			userfile.override<vector<UserBean>, UserBean>(users);
			break;
		}
			
		case '3':
		{
			bool found = false;
			string username;
			cout << "������Ҫ���ҵ��û���:";
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
					break;
				}
			}
			if (!found)
			{
				cout << "δ�ҵ���" << endl;
			}
			system("pause");
			break;
		}
			
		case '4':
			return;
			break;
		default:
			cout << "δ�����ѡ�� ������" << endl;
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
