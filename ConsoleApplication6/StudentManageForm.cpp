
#include "StudentManageForm.h"


StudentManageForm::StudentManageForm()
{
}


StudentManageForm::~StudentManageForm()
{
}

void StudentManageForm::show()
{
	bool signal = true;
	do 
	{
		system("cls");
		cout << "[1] 添加一名学生\n\
[2] 删除一名学生\n\
[3] 查找学生信息\n\
[4] 修改学生信息\n\
[5] 返回\n\
[0] 退出\n\
选择您要进行的操作按 ENTER 继续:";
		switch (waitakey())
		{
		case '0':
			break;
		case '1':
			system("cls");
			addastudent();
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
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

char StudentManageForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}

void StudentManageForm::addastudent()
{
	bool saveable = true;
	string id, name, gender, classNO;
	cout << "学生ID:";
	cin >> id;
	cout << "姓名:";
	cin >> name;
	cout << "性别:";
	cin >> gender;
	cout << "班号:";
	cin >> classNO;

	StudentBean stu(id, name, gender, classNO);
	UserBean u(id, "123456");
	u.setrank(2);
	u.setsid(id);
	File userfile("m_user.dat");
	vector<UserBean> vu;
	vu = userfile.loadall<vector<UserBean>, UserBean>(vu);
	userfile.close();
	for (vector<UserBean>::iterator i = vu.begin(), e = vu.end(); i != e; i++)
	{
		if (i->getname() == id)
		{
			saveable = false;
			cout << "已经存在的学生信息！" << endl;
			system("pause");
			break;
		}
	}
	if (saveable)
	{
		File user("m_user.dat");
		user.write(u);
		File studentsfile("m_stu.dat");
		studentsfile.write(stu);
		cout << "创建成功！" << endl;
		user.close();
		studentsfile.close();
		system("pause");
	}

}
