
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
	cout << "��ӭ��: " << user.getname() << endl;
	showmenu();
}

void StudentForm::showmenu()
{
	bool signal = true;
	do {
		cout << "[1] ��ʾ�ҵ���Ϣ\n\
[2] �޸��ҵ���Ϣ\n\
[3] ��������\n\
[4] �鿴�ɼ�\n\
[5] ѡ��γ�\n\
[6] ����\n\
[0] �˳�\n\
ѡ����Ҫ���еĲ����� ENTER ����:"; 
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
			loadcourses();
			system("pause");
			break;
		case '5':
			selectcorse(); 
			system("pause");
			break;
		case '6':
			return;
			break;
		default:
			
			cout << "δ�����ѡ�� ������" << endl;
			system("pause");
			system("cls");
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
	cout << "������..." << endl;
	// TODO: add edit my info
	system("pause");
}

void StudentForm::changepassword()
{
	system("cls");
	string pass;
	cout << "������������:";
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
	userfile.override<vector<UserBean>,UserBean>(users);
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
		cout << "������γ�ID����ѡ��:";
		cin >> cid;
		for (vector<SubjectBean>::iterator i = subjects.begin(), e = subjects.end(); i != e; i++)
		{
			if (i->getid() == cid)
			{
				saveable = true;
				m_info.addsubject(cid);
				save();
				break;
			}
		}
		if (!saveable)
		{
			cout << "����ȷ�Ŀγ�ID" << endl;
		}
		cout << "[0] �˳� ������������" << endl;
		if ('0' == waitakey())
		{
			signal = false;
		}
	} while (signal);
	
}

void StudentForm::save()
{	
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
	
	studentfile.override<vector<StudentBean>, StudentBean>(students);
}

void StudentForm::loadcourses()
{
	vector<SubjectBean> allsubjects;
	File subjectsFile("m_sub.dat");
	allsubjects = subjectsFile.loadall<vector<SubjectBean>, SubjectBean>(allsubjects);

}
