#include "stdafx.h"
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
	cout <<"Welcome "<< user.getname()<<endl;
}
