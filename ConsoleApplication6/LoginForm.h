
#include "Form.h"
#include "UserBean.h"
#include "File.h"
#include "AdminForm.h"
#include "StudentForm.h"
#include "TeacherForm.h"

class LoginForm :
	public Form
{
public:
	LoginForm();
	
	~LoginForm();
	void show();
private:
	//void login();
	void setadmin();
	UserBean getuser();
	void showadminform(UserBean user);
	void showteacherform(UserBean user);
	void showstudentform(UserBean user);
	string menu = 
		"====================\n\
��ӭ�� ������¼; \n\
";

	
};
