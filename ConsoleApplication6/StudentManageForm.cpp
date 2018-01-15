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
		cout<<"select a selection and press ENTER to continue:";
		switch (waitakey())
		{
		case '0':
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
