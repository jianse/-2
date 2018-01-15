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
			editminfo();
			break;
		case '3':
			changepassword();
			break;
		case '4':
			loadcourses();
			break;
		case '5':
			selectcorse();
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

void StudentForm::editminfo()
{
	system("cls");
	cout << "Buiding..." << endl;
	// TODO: add edit my info
	system("pause");
}

void StudentForm::changepassword()
{
	system("cls");
	string pass;
	cout << "Please input new password:";
	cin >> pass;
	user.setpassword(pass);
	File userfile("m_user.dat");
	vector<UserBean> users;
	users = userfile.loadall<vector<UserBean>, UserBean>(users);
	for (vector<UserBean>::iterator i = users.begin(), e = users.end(); i != e; i++)
	{
		if ((*i) == user)
		{
			*i = user;
		}
	}
	userfile.recreate();
	userfile.write<vector<UserBean>,UserBean>(users);
}

void StudentForm::selectcorse()
{
	system("cls");
	bool signal = true;
	File subjectsfile("m_sub.dat");
	vector<SubjectBean> subjects;
	subjects = subjectsfile.loadall<vector<SubjectBean>,SubjectBean>(subjects);
	do{
		for (vector<SubjectBean>::iterator i = subjects.begin(), e = subjects.end(); i != e; i++)
		{
			i->display();
		}
		string cid;
		bool saveable = false;
		cout << "Please input subjectid to select a course:";
		cin >> cid;
		for (vector<SubjectBean>::iterator i = subjects.begin(), e = subjects.end(); i != e; i++)
		{
			if (i->getid() == cid)
			{
				saveable = true;
				addcouse(cid);
				break;
			}
		}
		if (!saveable)
		{
			cout << "incrrect course id" << endl;
		}
		cout << "0.quit anykey continue" << endl;
		if ('0' == waitakey())
		{
			signal = false;
		}
	} while (signal);
	
}

void StudentForm::addcouse(string cid)
{
	m_info.getscoremap().insert(make_pair(cid, -1));
	
	vector<StudentBean> students;
	File studentfile("m_stu.dat");
	students = studentfile.loadall<vector<StudentBean>, StudentBean>(students);
	for (vector<StudentBean>::iterator i = students.begin(), e = students.end(); i != e; i++)
	{
		if (i->getid() == m_info.getid())
		{
			*i = m_info;
			break;
		}
	}
	studentfile.recreate();
	studentfile.write<vector<StudentBean>, StudentBean>(students);
}

void StudentForm::loadcourses()
{
	vector<SubjectBean> allsubjects;
	File subjectsFile("m_sub.dat");
	allsubjects = subjectsFile.loadall<vector<SubjectBean>, SubjectBean>(allsubjects);

}
