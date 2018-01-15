#include "stdafx.h"
#include "StudentManageForm.h"


StudentManageForm::StudentManageForm()
{
}


StudentManageForm::~StudentManageForm()
{
}

void StudentManageForm::show()
{
	bool signal = true;
	do 
	{
		system("cls");
		cout << "1. add a student\n\
2. remove a student\n\
3. find a student\n\
4. modify a student info\n\
5. return\n\
0. exit\n\
select a selection and press ENTER to continue:";
		switch (waitakey())
		{
		case '0':
			break;
		case '1':
			system("cls");
			addastudent();
			
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			return;
			break;
		default:
			cout << "undifined selection please retry" << endl;
			system("pause");
			break;
		}
	} while (signal);
}

char StudentManageForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}

void StudentManageForm::addastudent()
{
	bool saveable = true;
	string id, name, gender, classNO;
	cout << "id:";
	cin >> id;
	cout << "name:";
	cin >> name;
	cout << "gender:";
	cin >> gender;
	cout << "calssNO:";
	cin >> classNO;

	StudentBean stu(id, name, gender, classNO);
	UserBean u(id, "123456");
	u.setrank(2);
	u.setsid(id);
	File userfile("m_user.dat");
	vector<UserBean> vu;
	vu = userfile.loadall<vector<UserBean>, UserBean>(vu);
	userfile.close();
	for (vector<UserBean>::iterator i = vu.begin(), e = vu.end(); i != e; i++)
	{
		if (i->getname() == id)
		{
			saveable = false;
			cout << "already exsit!" << endl;
			system("pause");
			break;
		}
	}
	if (saveable)
	{
		File user("m_user.dat");
		user.write(u);
		File studentsfile("m_stu.dat");
		studentsfile.write(stu);
		cout << "success!" << endl;
		system("pause");
	}

}
