
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
	cout << "欢迎您：" << user.getname() << endl;
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
		cout << "[1] 显示我的信息\n\
[2] 修改我的信息\n\
[3] 修改密码\n\
[4] 课程管理\n\
[5] 上传成绩\n\
[6] 返回\n\
[0] 退出\n\
选择您要进行的操作按 ENTER 继续:";
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
	cout << "建设中..." << endl;
	// TODO: add edit my info
	system("pause");
}

void TeacherForm::changepassword()
{
	system("cls");
	string pass;
	cout << "请输入新密码:";
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
