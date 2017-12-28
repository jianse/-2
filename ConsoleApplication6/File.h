#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class File
{
public:
	File(string path);
	bool close();
	~File();
private:
	string path;
	ifstream in;
	ofstream out;
};

