#include "stdafx.h"
#include "AdminForm.h"

AdminForm::AdminForm(UserBean user)
{
	AdminForm::user = user;
}

AdminForm::~AdminForm()
{
}

void AdminForm::show()
{
	system("cls");
	cout <<"Welcome "<< user.getname()<<endl;
	showmenu();
}

void AdminForm::showmenu()
{
	bool signal = true;
	do {
		cout << "1. admin management \n\
2. teacher management \n\
3. student management \n\
4. course managemnet \n\
5. change password \n\
0. exit \n\
select a selection and press ENTER to continue:";
		switch (waitakey())
		{
		case '0':
			return;
			break;
		case '1':
			showadminmanage();
			break;
		case '2':
			showteachermanage();
			break;
		case '3':
			showstudentmanage();
			break;
		case '4':
			showcoursemanage();
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

char AdminForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}

void AdminForm::showadminmanage()
{
	AdminManageForm amf;
	amf.show();
}

void AdminForm::showteachermanage()
{
	TeacherManageForm tmf;
	tmf.show();
}

void AdminForm::showstudentmanage()
{
}

void AdminForm::showcoursemanage()
{
}
