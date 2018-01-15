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
	return 0;
}
