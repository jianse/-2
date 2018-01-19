
#include "AdminForm.h"

AdminForm::AdminForm(UserBean user)
{
	AdminForm::user = user;
}

AdminForm::~AdminForm()
{
}

void AdminForm::show()
{
	system("cls");
	cout <<"欢迎您："<< user.getname()<<endl;
	showmenu();
}

void AdminForm::showmenu()
{
	bool signal = true;
	do {
		cout << "[1] 管理员管理\n\
[2] 教师管理 \n\
[3] 学生管理 \n\
[4] 课程管理 \n\
[5] 修改密码 \n\
[6] 返回\n\
[0] 退出\n\
选择您要进行的操作按 ENTER 继续:";
		switch (waitakey())
		{
		case '0':
			return;
			break;
		case '1':
			showadminmanage();
			break;
		case '2':
			showteachermanage();
			break;
		case '3':
			showstudentmanage();
			break;
		case '4':
			showcoursemanage();
			break;
		case '5':
			break;
		case '6':
			return;
			break;
		default:
			system("cls");
			cout << "未定义的选项 请重试" << endl;
			showmenu();
			break;
		}
		system("cls");
	} while (signal);
	
}

char AdminForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}

void AdminForm::showadminmanage()
{
	AdminManageForm amf;
	amf.show();
}

void AdminForm::showteachermanage()
{
	TeacherManageForm tmf;
	tmf.show();
}

void AdminForm::showstudentmanage()
{
	StudentManageForm smf;
	smf.show();
}

void AdminForm::showcoursemanage()
{
	CourseManageForm cmf;
	cmf.show();
}
