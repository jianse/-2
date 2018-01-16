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
			addacourse();
			break;
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			modifyacourse();
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


void CourseManageForm::addacourse()
{
	string id, name, des;
	int teachernum, length;
	bool singel;
	vector<string> tids;
	cout << "id:";
	cin >> id;
	cout << "name:";
	cin >> name;
	cout << "teachernum:";
	cin >> teachernum;
	for (int i = 1; i <= teachernum; i++)
	{
		string tid;
		cout << "teacherid " << i << ":";
		cin >> tid;
		tids.push_back(tid);
	}
	cout << "singel:";
	cin >> singel;
	cout << "length:";
	cin >> length;
	cout << "memo:";
	cin >> des;
	SubjectBean subject(id, name, teachernum, tids, singel, length, des);
	File subjectsfile("m_sub.dat");
	subjectsfile.write(subject);
	cout << "success!" << endl;
	system("pause");
}

void CourseManageForm::modifyacourse()
{
	system("cls");
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
	}
}

char CourseManageForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}
