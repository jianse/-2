
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
	cout <<"��ӭ����"<< user.getname()<<endl;
	showmenu();
}

void AdminForm::showmenu()
{
	bool signal = true;
	do {
		cout << "[1] ����Ա����\n\
[2] ��ʦ���� \n\
[3] ѧ������ \n\
[4] �γ̹��� \n\
[5] �޸����� \n\
[6] ����\n\
[0] �˳�\n\
ѡ����Ҫ���еĲ����� ENTER ����:";
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
			cout << "δ�����ѡ�� ������" << endl;
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
