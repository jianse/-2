
#include "Form.h"
#include "UserBean.h"
#include "File.h"
class LoginForm :
	public Form
{
public:
	LoginForm();
	
	~LoginForm();
	void show();
private:
	bool login();
	string menu = 
		"==========================================  \n \
Welcome please login: \n\
";

	
};
