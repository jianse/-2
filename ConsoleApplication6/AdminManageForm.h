
#include "Form.h"
#include "UserBean.h"
#include <vector>
class AdminManageForm :
	public Form
{
public:
	AdminManageForm();
	~AdminManageForm();
	void show();
private:
	char waitakey();
};
