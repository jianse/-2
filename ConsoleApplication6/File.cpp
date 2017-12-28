#include "stdafx.h"
#include "File.h"


File::File(string path)
{
	File::path = path;
	in.open(path, ios_base::binary);
	out.open(path, ios_base::binary);
}

bool File::close()
{
	if (!in || !out)
	{
		in.close();
		out.close();
		return true;
	}
	return true;
}

File::~File()
{
	this->close();
}
