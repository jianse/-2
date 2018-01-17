
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
			addateacher();
			break;
		case'2':
			removeateacher();
			break;
		case'3':
			findateacher();
			break;
		case'4':
			modifyateacher();
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

void TeacherManageForm::addateacher()
{
	string id, name, dep, gender, des;
	cout << "id:";
	cin >> id;
	cout << "name:";
	cin >> name;
	cout << "department:";
	cin >> dep;
	cout << "gender:";
	cin >> gender;
	cout << "memo:";
	cin >> des;
	TeacherBean tea(id, name, dep, gender, des);
	UserBean user(id, "123456");
	user.setrank(1);
	user.setsid("0");
	File teachersfile("m_tea.dat");
	teachersfile.write(tea);
	File userfile("m_user.dat");
	userfile.write(user);
	cout << "success!" << endl;
	system("pause");
}

void TeacherManageForm::removeateacher()
{
	system("cls");
	string tid;
	bool found = false;
	cout << "Please input a teacher id to remove a teacher:";
	cin >> tid;
	File teachersfile("m_tea.dat");
	vector<TeacherBean> teachers;
	teachers = teachersfile.loadall<vector<TeacherBean>, TeacherBean>(teachers);
	for (vector<TeacherBean>::iterator i = teachers.begin(), e = teachers.end(); i != e; i++)
	{
		if (i->getid() == tid)
		{
			found = true;
			teachers.erase(i);
			cout << "success!" << endl;
			system("pause");
			break;
		}
	}
	if (!found)
	{
		cout << "not found" << endl;
		system("pause");
	}
}

void TeacherManageForm::findateacher()
{
	system("cls");
	string tid;
	bool found = false;
	cout << "Please input a teacher id to find a teacher:";
	cin >> tid;
	File teachersfile("m_tea.dat");
	vector<TeacherBean> teachers;
	teachers = teachersfile.loadall<vector<TeacherBean>, TeacherBean>(teachers);
	for (vector<TeacherBean>::iterator i = teachers.begin(), e = teachers.end(); i != e; i++)
	{
		if (i->getid() == tid)
		{
			found = true;
			i->display();
			system("pause");
			break;
		}
	}
	if (!found)
	{
		cout << "not found" << endl;
		system("pause");
	}
}

void TeacherManageForm::modifyateacher()
{
	system("cls");
	string tid;
	bool found = false;
	cout << "Please input a teacher id will be modifyed:";
	cin >> tid;
	File teachersfile("m_tea.dat");
	vector<TeacherBean> teachers;
	teachers = teachersfile.loadall<vector<TeacherBean>, TeacherBean>(teachers);
	for (vector<TeacherBean>::iterator i = teachers.begin(), e = teachers.end(); i != e; i++)
	{
		if (i->getid() == tid)
		{
			found = true;
			i->display();
			string name, dep, gender, dsc;
			cout << "new name:";
			cin >> name;
			cout << "new deprtment:";
			cin >> dep;
			cout << "new gender:";
			cin >> gender;
			cout << "new memo:";
			cin >> dsc;
			TeacherBean tea(i->getid(),name,dep,gender,dsc);
			*i = tea;
			teachersfile.override<vector<TeacherBean>,TeacherBean>(teachers);
			cout << "success! new teacher info :" << endl;
			i->display();
			system("pause");
			break;
		}
	}
	if (!found)
	{
		cout << "not found" << endl;
		system("pause");
	}
}

char TeacherManageForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}
