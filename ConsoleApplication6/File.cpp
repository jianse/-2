
#include "File.h"


File::File(string path)
{
	File::path = path;
	in.open(path, ios_base::app);
	out.open(path, ios_base::app);
}

bool File::close()
{
		in.close();
		out.close();
		return true;
}

bool File::isempty()
{
	string str;
	in >> str;
	if (str.empty())
	{
		return true;
	}
	in.seekg(-(int)str.size(), std::ios::cur);
	return false;
}

void File::resetpos()
{
	this->close();
	in.open(path, ios_base::app);
	out.open(path, ios_base::app);
}



File::~File()
{
	this->close();
}

