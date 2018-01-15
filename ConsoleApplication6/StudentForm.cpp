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
		cout << "1. show my info\n\
2. edit my info\n\
3. change password\n\
4. explorer score\n\
5. select score\n\
6. return\n\
0. exit \n\
select a selection and press ENTER to continue:"; 
		switch (waitakey())
		{
		case '0':
			break;
		case '1':

			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			return;
			break;
		default:
			system("cls");
			cout << "undifined selection please retry" << endl;
			showmenu();
			break;
		}
		system("cls");
	} while (signal);
}

char StudentForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}
