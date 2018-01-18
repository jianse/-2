
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
		cout << "[1] 添加一名教师\n\
[2] 移除一名教师\n\
[3] 查找教师信息\n\
[4] 修改教师信息\n\
[5] 返回\n\
[0] 退出\n\
选择您要进行的操作按 ENTER 继续:";
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
			cout << "未定义的选项 请重试" << endl;
			system("pause");
			break;
		}
	} while (signal);
}

void TeacherManageForm::addateacher()
{
	string id, name, dep, gender, des;
	cout << "教师ID:";
	cin >> id;
	cout << "姓名:";
	cin >> name;
	cout << "部门:";
	cin >> dep;
	cout << "性别:";
	cin >> gender;
	cout << "简介:";
	cin >> des;
	TeacherBean tea(id, name, dep, gender, des);
	UserBean user(id, "123456");
	user.setrank(1);
	user.setsid("0");
	File teachersfile("m_tea.dat");
	teachersfile.write(tea);
	File userfile("m_user.dat");
	userfile.write(user);
	cout << "添加成功!" << endl;
	system("pause");
}

void TeacherManageForm::removeateacher()
{
	system("cls");
	string tid;
	bool found = false;
	cout << "请输入教师ID进行删除:";
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
			cout << "删除成功!" << endl;
			system("pause");
			break;
		}
	}
	if (!found)
	{
		cout << "未找到！" << endl;
		system("pause");
	}
}

void TeacherManageForm::findateacher()
{
	system("cls");
	string tid;
	bool found = false;
	cout << "请输入要查询的教师ID:";
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
		cout << "未找到！" << endl;
		system("pause");
	}
}

void TeacherManageForm::modifyateacher()
{
	system("cls");
	string tid;
	bool found = false;
	cout << "请输入要修改的教师ID：";
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
			cout << "新姓名:";
			cin >> name;
			cout << "新部门:";
			cin >> dep;
			cout << "新性别:";
			cin >> gender;
			cout << "新简介:";
			cin >> dsc;
			TeacherBean tea(i->getid(),name,dep,gender,dsc);
			*i = tea;
			teachersfile.override<vector<TeacherBean>,TeacherBean>(teachers);
			cout << "修改成功 新信息如下:" << endl;
			i->display();
			system("pause");
			break;
		}
	}
	if (!found)
	{
		cout << "未找到！" << endl;
		system("pause");
	}
}

char TeacherManageForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}
