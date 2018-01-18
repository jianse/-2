
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
		cout << "[1]. ���һ�ſγ�\n\
[2] ɾ��һ�ſγ�\n\
[3] ���ҿγ�\n\
[4] �޸Ŀγ���Ϣ\n\
[5] ����\n\
[0] �˳�\n\
ѡ����Ҫ���еĲ����� ENTER ����:";
		switch (waitakey())
		{
		case '0':
			
			break;
		case '1':
			addacourse();
			break;
		case '2':
			removeacourse();
			break;
		case '3':
			findacourse();
			break;
		case '4':
			modifyacourse();
			break;
		case '5':
			return;
			break;
		default:
			cout << "δ�����ѡ�� ������" << endl;
			system("pause");
			break;
		}
	} while (signal);
}


void CourseManageForm::addacourse()
{
	string id, name, des;
	int teachernum, length;
	bool singel;
	vector<string> tids;
	cout << "ID:";
	cin >> id;
	cout << "�γ���:";
	cin >> name;
	cout << "��ʦ����:";
	cin >> teachernum;
	for (int i = 1; i <= teachernum; i++)
	{
		string tid;
		cout << "��ʦID: " << i << ":";
		cin >> tid;
		tids.push_back(tid);
	}
	cout << "��˫��[0]˫[1]��:";
	cin >> singel;
	cout << "ѧʱ:";
	cin >> length;
	cout << "����:";
	cin >> des;
	SubjectBean subject(id, name, teachernum, tids, singel, length, des);
	File subjectsfile("m_sub.dat");
	subjectsfile.write(subject);
	cout << "��ӳɹ�:" << endl;
	system("pause");
}

void CourseManageForm::removeacourse()
{
	system("cls");
	string cid;
	bool found = false;
	cout << "������Ҫ�Ƴ��γ̵�ID:";
	cin >> cid;
	File subjectsfile("m_sub.dat");
	vector<SubjectBean> subjects;
	subjects = subjectsfile.loadall<vector<SubjectBean>, SubjectBean>(subjects);
	for (vector<SubjectBean>::iterator i = subjects.begin(), e = subjects.end(); i != e; i++)
	{
		if (i->getid() == cid)
		{
			found = true;
			subjects.erase(i);
			cout << "�Ƴ��ɹ�!" << endl;
			system("pause");
			break;
		}
	}
	if (!found)
	{
		cout << "δ�ҵ���Ӧ�γ�!" << endl;
		system("pause");
	}
}

void CourseManageForm::findacourse()
{
	system("cls");
	string cid;
	bool found = false;
	cout << "������Ҫ���ҵĿγ�ID:";
	cin >> cid;
	File subjectsfile("m_sub.dat");
	vector<SubjectBean> subjects;
	subjects = subjectsfile.loadall<vector<SubjectBean>, SubjectBean>(subjects);
	for (vector<SubjectBean>::iterator i = subjects.begin(), e = subjects.end(); i != e; i++)
	{
		if (i->getid() == cid)
		{
			found = true;
			i->display();
			system("pause");
			break;
		}
	}
	if (!found)
	{
		cout << "δ�ҵ���Ӧ�γ�!" << endl;
		system("pause");
	}
}

void CourseManageForm::modifyacourse()
{

	cout << "������..." << endl;
	system("pause");
	/*system("cls");
	string sid;
	bool found = false;
	cout << "Please input a subject id will be modifyed:";
	cin >> sid;
	File subjectsfile("m_sub.dat");
	vector<SubjectBean> subjects;
	subjects = subjectsfile.loadall<vector<SubjectBean>, SubjectBean>(subjects);
	for (vector<SubjectBean>::iterator i = subjects.begin(), e = subjects.end(); i != e; i++)
	{
		if (i->getid() == sid)
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
			TeacherBean tea(i->getid(), name, dep, gender, dsc);
			*i = tea;
			subjectsfile.override<vector<SubjectBean>, SubjectBean>(subjects);
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
	}*/
}

char CourseManageForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}
