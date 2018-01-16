#include "stdafx.h"
#include "TeacherManageForm.h"


TeacherManageForm::TeacherManageForm()
{
	
}

TeacherManageForm::~TeacherManageForm()
{
}

void TeacherManageForm::show()
{
	bool signal = true;
	do 
	{
		system("cls");
		cout << "1. add a teacher\n\
2. remove a teacher\n\
3. find a teacher\n\
4. modify teacher info\n\
5. return\n\
0. exit\n\
select a selection and press ENTER to continue:";
		switch (waitakey())
		{
		case'0':
			addateacher();
			break;
		case'1':
			break;
		case'2':
			break;
		case'3':
			break;
		case'4':
			break;
		case'5':
			return;
			break;
		default:
			cout << "undifined selection please retry" << endl;
			system("pause");
			break;
		}
	} while (signal);
}

void TeacherManageForm::addateacher()
{
	string id, name, dep, gender, des;
	cout << "id:";
	cin >> id;
	cout << "name:";
	cin >> name;
	cout << "department:";
	cin >> dep;
	cout << "gender:";
	cin >> gender;
	cout << "memo:";
	cin >> des;
	TeacherBean tea(id, name, dep, gender, des);
	UserBean user(id, "123456");
	user.setrank(1);
	user.setsid(0);
	File teachersfile("m_tea.dat");
	teachersfile.write(tea);
	File userfile("m_user.dat");
	userfile.write(user);
	cout << "success!" << endl;
	system("pause");
}

char TeacherManageForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}
