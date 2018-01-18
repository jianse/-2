
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
		cout << "[1]. 添加一门课程\n\
[2] 删除一门课程\n\
[3] 查找课程\n\
[4] 修改课程信息\n\
[5] 返回\n\
[0] 退出\n\
选择您要进行的操作按 ENTER 继续:";
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
			cout << "未定义的选项 请重试" << endl;
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
	cout << "课程名:";
	cin >> name;
	cout << "教师数量:";
	cin >> teachernum;
	for (int i = 1; i <= teachernum; i++)
	{
		string tid;
		cout << "教师ID: " << i << ":";
		cin >> tid;
		tids.push_back(tid);
	}
	cout << "单双周[0]双[1]单:";
	cin >> singel;
	cout << "学时:";
	cin >> length;
	cout << "介绍:";
	cin >> des;
	SubjectBean subject(id, name, teachernum, tids, singel, length, des);
	File subjectsfile("m_sub.dat");
	subjectsfile.write(subject);
	cout << "添加成功:" << endl;
	system("pause");
}

void CourseManageForm::removeacourse()
{
	system("cls");
	string cid;
	bool found = false;
	cout << "请输入要移除课程的ID:";
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
			cout << "移除成功!" << endl;
			system("pause");
			break;
		}
	}
	if (!found)
	{
		cout << "未找到对应课程!" << endl;
		system("pause");
	}
}

void CourseManageForm::findacourse()
{
	system("cls");
	string cid;
	bool found = false;
	cout << "请输入要查找的课程ID:";
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
		cout << "未找到对应课程!" << endl;
		system("pause");
	}
}

void CourseManageForm::modifyacourse()
{

	cout << "建设中..." << endl;
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
