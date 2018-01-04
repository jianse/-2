#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class File
{
public:
	File(string path);
	ifstream in;
	ofstream out;
	bool close();
	~File();
private:
	string path;
	
};

