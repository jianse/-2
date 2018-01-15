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

char TeacherManageForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}
