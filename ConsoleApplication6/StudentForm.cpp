
#include "StudentForm.h"


StudentForm::StudentForm(UserBean user)
{
	StudentForm::user = user;
}


StudentForm::~StudentForm()
{
}

void StudentForm::show()
{
	File studentfile("m_stu.dat");
	vector<StudentBean> students;
	students = studentfile.loadall<vector<StudentBean>, StudentBean>(students);
	studentfile.close();
	for (vector<StudentBean>::iterator i = students.begin(), e = students.end(); i != e; i++)
	{
		if (i->getid() == StudentForm::user.getsid())
		{
			m_info = (*i);
		}
	}
	system("cls");
	cout << "欢迎您: " << user.getname() << endl;
	showmenu();
}

void StudentForm::showmenu()
{
	bool signal = true;
	do {
		cout << "[1] 显示我的信息\n\
[2] 修改我的信息\n\
[3] 更改密码\n\
[4] 查看成绩\n\
[5] 选择课程\n\
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
			loadcourses();
			system("pause");
			break;
		case '5':
			selectcorse(); 
			system("pause");
			break;
		case '6':
			return;
			break;
		default:
			
			cout << "未定义的选项 请重试" << endl;
			system("pause");
			system("cls");
			showmenu();
			break;
		}
		system("cls");
	} while (signal);
}

char StudentForm::waitakey()
{
	char ch;
	cin >> ch;
	return ch;
}

void StudentForm::editminfo()
{
	system("cls");
	cout << "建设中..." << endl;
	// TODO: add edit my info
	system("pause");
}

void StudentForm::changepassword()
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
	userfile.override<vector<UserBean>,UserBean>(users);
}

void StudentForm::selectcorse()
{
	system("cls");
	bool signal = true;
	File subjectsfile("m_sub.dat");
	vector<SubjectBean> subjects;
	subjects = subjectsfile.loadall<vector<SubjectBean>,SubjectBean>(subjects);
	do{
		for (vector<SubjectBean>::iterator i = subjects.begin(), e = subjects.end(); i != e; i++)
		{
			i->display();
		}
		string cid;
		bool saveable = false;
		cout << "请输入课程ID进行选课:";
		cin >> cid;
		for (vector<SubjectBean>::iterator i = subjects.begin(), e = subjects.end(); i != e; i++)
		{
			if (i->getid() == cid)
			{
				saveable = true;
				m_info.addsubject(cid);
				save();
				break;
			}
		}
		if (!saveable)
		{
			cout << "不正确的课程ID" << endl;
		}
		cout << "[0] 退出 其他按键继续" << endl;
		if ('0' == waitakey())
		{
			signal = false;
		}
	} while (signal);
	
}

void StudentForm::save()
{	
	vector<StudentBean> students;
	File studentfile("m_stu.dat");
	students = studentfile.loadall<vector<StudentBean>, StudentBean>(students);
	for (vector<StudentBean>::iterator i = students.begin(), e = students.end(); i != e; i++)
	{
		if (i->getid() == m_info.getid())
		{
			*i = m_info;
			break;
		}
	}
	
	studentfile.override<vector<StudentBean>, StudentBean>(students);
}

void StudentForm::loadcourses()
{
	vector<SubjectBean> allsubjects;
	File subjectsFile("m_sub.dat");
	allsubjects = subjectsFile.loadall<vector<SubjectBean>, SubjectBean>(allsubjects);

}
