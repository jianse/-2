#pragma once
#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;
class Bean
{
public:
	virtual bool operator== (Bean &b2)=0;
	virtual Bean &operator= (Bean &b2)=0;
	virtual void display()=0;
private:

};

