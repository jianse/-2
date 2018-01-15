#include "stdafx.h"
#include "StudentForm.h"


StudentForm::StudentForm(UserBean user)
{
	StudentForm::user = user;
}


StudentForm::~StudentForm()
{
}

void StudentForm::show()
{
	system("cls");
	cout << "Welcome " << user.getname() << endl;
	showmenu();
}

void StudentForm::showmenu()
{
	bool signal = true;
	do {
		cout << "1. \n\
0. exit \n\
select a selection and press ENTER to continue:"; 
		switch (waitakey())
		{
		case '0':
			break;
		default:
			break;
		}
	} while (signal);
}

char StudentForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}
