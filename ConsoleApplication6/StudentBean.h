#pragma once
#include "Bean.h"
class StudentBean :
	public Bean
{
public:
	StudentBean();
	~StudentBean();
	bool operator==(StudentBean &s2);
	StudentBean & operator=(StudentBean &s2);
private:

};

