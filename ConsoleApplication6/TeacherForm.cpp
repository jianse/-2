
#include "TeacherForm.h"

TeacherForm::TeacherForm(UserBean user)
{
	TeacherForm::user = user;
}

TeacherForm::~TeacherForm()
{
}

void TeacherForm::show()
{
	File teacherfile("m_tea.dat");
	vector<TeacherBean> teachers;
	teachers = teacherfile.loadall<vector<TeacherBean>, TeacherBean>(teachers);
	teacherfile.close();
	for (vector<TeacherBean>::iterator i = teachers.begin(), e = teachers.end(); i != e; i++)
	{
		if (i->getid() == user.getname())
		{
			m_info = (*i);
		}
	}
	system("cls");
	cout << "Welcome " << user.getname() << endl;
	showmenu();
}

char TeacherForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}

void TeacherForm::showmenu()
{
	bool signal = true;
	do {
		system("cls");
		cout << "1. show my info\n\
2. edit my info\n\
3. change password\n\
4. course management\n\
5. upload score\n\
6. return\n\
0. exit\n\
select a selection and press ENTER to continue:";
		switch (waitakey())
		{
		case '0':
			break;
		case '1':
			m_info.display();
			system("pause");
			break;
		case '2':
			editminfo();
			system("pause");
			break;
		case '3':
			changepassword();
			system("pause");
			break;
		case '4':
			cousemenagment();
			system("pause");
			break;
		case '5':
			uploadscore();
			system("pause");
			break;
		case '6':
			return;
			break;
		default:
			break;
		}
	} while (signal);
}

void TeacherForm::editminfo()
{
	system("cls");
	cout << "Buiding..." << endl;
	// TODO: add edit my info
	system("pause");
}

void TeacherForm::changepassword()
{
	system("cls");
	string pass;
	cout << "Please input new password:";
	cin >> pass;
	user.setpassword(pass);
	File userfile("m_user.dat");
	vector<UserBean> users;
	users = userfile.loadall<vector<UserBean>, UserBean>(users);
	userfile.close();
	for (vector<UserBean>::iterator i = users.begin(), e = users.end(); i != e; i++)
	{
		if ((*i) == user)
		{
			*i = user;
			break;
		}
	}
	userfile.override<vector<UserBean>, UserBean>(users);
}

void TeacherForm::cousemenagment()
{
	CourseManageForm cmf;
	cmf.show();
}

void TeacherForm::uploadscore()
{
}
