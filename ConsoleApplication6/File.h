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
	bool isempty();
	template<typename V, typename B>
	void override(V data);
	template<typename V, typename B>
	void write(V data);
	template<typename B>
	void write(B data);
	template<typename T1,typename T2>
	 T1 &loadall(T1 &vc);
	~File();
private:
	ifstream in;
	ofstream out;
	void resetpos();
	string path;
};

template<typename V, typename B>
inline void File::override(V data)
{
	out.close();
	out.open(path, ios_base::trunc);
	for (vector<B>::iterator i = data.begin(), end = data.end(); i != end; ++i)
	{
		this->out << (*i);
	}
}

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
	while (this->in >> temp)
	{
		vc.push_back(temp);
	}
	this->resetpos();
	return vc;
}
