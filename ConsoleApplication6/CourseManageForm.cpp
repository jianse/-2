#include "stdafx.h"
#include "CourseManageForm.h"


CourseManageForm::CourseManageForm()
{
}


CourseManageForm::~CourseManageForm()
{
}


void CourseManageForm::show()
{
	bool signal = true;
	do
	{
		system("cls");
		cout << "1. add a course\n\
2. remove a course\n\
3. find a course info\n\
4. edit a course info\n\
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


char CourseManageForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}
