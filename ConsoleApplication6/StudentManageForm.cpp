
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
		cout << "[1] ���һ��ѧ��\n\
[2] ɾ��һ��ѧ��\n\
[3] ����ѧ����Ϣ\n\
[4] �޸�ѧ����Ϣ\n\
[5] ����\n\
[0] �˳�\n\
ѡ����Ҫ���еĲ����� ENTER ����:";
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
			cout << "δ�����ѡ�� ������" << endl;
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
	cout << "ѧ��ID:";
	cin >> id;
	cout << "����:";
	cin >> name;
	cout << "�Ա�:";
	cin >> gender;
	cout << "���:";
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
			cout << "�Ѿ����ڵ�ѧ����Ϣ��" << endl;
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
		cout << "�����ɹ���" << endl;
		user.close();
		studentsfile.close();
		system("pause");
	}

}
