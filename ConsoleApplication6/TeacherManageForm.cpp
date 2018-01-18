
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
		cout << "[1] ���һ����ʦ\n\
[2] �Ƴ�һ����ʦ\n\
[3] ���ҽ�ʦ��Ϣ\n\
[4] �޸Ľ�ʦ��Ϣ\n\
[5] ����\n\
[0] �˳�\n\
ѡ����Ҫ���еĲ����� ENTER ����:";
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
			cout << "δ�����ѡ�� ������" << endl;
			system("pause");
			break;
		}
	} while (signal);
}

void TeacherManageForm::addateacher()
{
	string id, name, dep, gender, des;
	cout << "��ʦID:";
	cin >> id;
	cout << "����:";
	cin >> name;
	cout << "����:";
	cin >> dep;
	cout << "�Ա�:";
	cin >> gender;
	cout << "���:";
	cin >> des;
	TeacherBean tea(id, name, dep, gender, des);
	UserBean user(id, "123456");
	user.setrank(1);
	user.setsid("0");
	File teachersfile("m_tea.dat");
	teachersfile.write(tea);
	File userfile("m_user.dat");
	userfile.write(user);
	cout << "��ӳɹ�!" << endl;
	system("pause");
}

void TeacherManageForm::removeateacher()
{
	system("cls");
	string tid;
	bool found = false;
	cout << "�������ʦID����ɾ��:";
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
			cout << "ɾ���ɹ�!" << endl;
			system("pause");
			break;
		}
	}
	if (!found)
	{
		cout << "δ�ҵ���" << endl;
		system("pause");
	}
}

void TeacherManageForm::findateacher()
{
	system("cls");
	string tid;
	bool found = false;
	cout << "������Ҫ��ѯ�Ľ�ʦID:";
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
		cout << "δ�ҵ���" << endl;
		system("pause");
	}
}

void TeacherManageForm::modifyateacher()
{
	system("cls");
	string tid;
	bool found = false;
	cout << "������Ҫ�޸ĵĽ�ʦID��";
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
			cout << "������:";
			cin >> name;
			cout << "�²���:";
			cin >> dep;
			cout << "���Ա�:";
			cin >> gender;
			cout << "�¼��:";
			cin >> dsc;
			TeacherBean tea(i->getid(),name,dep,gender,dsc);
			*i = tea;
			teachersfile.override<vector<TeacherBean>,TeacherBean>(teachers);
			cout << "�޸ĳɹ� ����Ϣ����:" << endl;
			i->display();
			system("pause");
			break;
		}
	}
	if (!found)
	{
		cout << "δ�ҵ���" << endl;
		system("pause");
	}
}

char TeacherManageForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}
