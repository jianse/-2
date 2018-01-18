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
		cout << "[1] 添加一个管理员\n\
[2] 移除一个管理员\n\
[3] 查找管理员信息\n\
[4] 返回 \n\
[0] 退出\n\
选择您要进行的操作按 ENTER 继续:";
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
					cout << "已经存在的用户！" << endl;
					system("pause");
					break;
				}
			}
			if (saveable)
			{
				userfile.write(user);
				cout << "添加管理员成功！" << endl;
				system("pause");
			}
			break;
		}
		case '2':
		{
			string username;
			cout << "请输入要移除的用户名：:";
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
			cout << "请输入要查找的用户名:";
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
				cout << "未找到！" << endl;
			}
			system("pause");
			break;
		}
			
		case '4':
			return;
			break;
		default:
			cout << "未定义的选项 请重试" << endl;
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
