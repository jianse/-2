#pragma once
#include <iostream>
#include <iomanip> 

using namespace std;
class Bean
{
public:
	virtual bool operator== (Bean &b2)=0;
	virtual Bean &operator= (Bean &b2)=0;
private:

};

