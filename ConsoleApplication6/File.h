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
	bool recreate();
	template<typename V, typename B>
	void write(V data);
	template<typename B>
	void write(B data);
	template<typename T1,typename T2>
	 T1 &loadall(T1 &vc);
	~File();
private:
	string path;
};

template<typename V,typename B>
inline void File::write(V data)
{
	for (vector<B>::iterator i = data.begin(), end = data.end(); i != end; ++i)
	{
		this->out << (*i);
	}
}

template<typename B>
inline void File::write(B data)
{
	this->out << data;
}

template<typename T1, typename T2>
inline T1 & File::loadall(T1 & vc)
{
	T2 temp;
	while (!(this->in.eof()))
	{
		this->in >> temp;
		vc.push_back(temp);
	}
	return vc;
}
