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
	File studentfile("m_stu.dat");
	vector<StudentBean> students;
	students = studentfile.loadall<vector<StudentBean>, StudentBean>(students);
	studentfile.close();
	for (vector<StudentBean>::iterator i = students.begin(), e = students.end(); i != e; i++)
	{
		if (i->getid() == StudentForm::user.getsid())
		{
			m_info = (*i);
		}
	}
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
5. select corse\n\
6. return\n\
0. exit \n\
select a selection and press ENTER to continue:"; 
		switch (waitakey())
		{
		case '0':
			break;
		case '1':
			m_info.display();
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
