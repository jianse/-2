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
	bool isempty();
	~File();
private:
	string path;
};

