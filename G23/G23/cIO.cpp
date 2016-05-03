#include "cIO.h"


void cMouse::initilize(int _x, int _y)
{
	x = _x - GAME_WIDTH / 2;
	y = -(_y - GAME_HEIGHT / 2);
}
string replaceAll(const string &str, const string &pattern, const string &replace)
{
	string result = str;
	string::size_type pos = 0;
	string::size_type offset = 0;

	while ((pos = result.find(pattern, offset)) != string::npos)
	{
		result.replace(result.begin() + pos, result.begin() + pos + pattern.size(), replace);
		offset = pos + replace.size();
	}

	return result;
}
dataClass cData::loadMap(string fileName)
{
	dataClass res;
	fstream stream;
	stream.open(fileName, std::ios::in);
	if (!stream.is_open())
	{
		cout << "error: there are no main.xml in level" << endl;
		return res;
	}
	stream.seekg(ios::beg);
	string temp, nowTag, type;
	while (!stream.eof())
	{
		stream >> temp;
		if (temp.size() > 1 && temp[1] == '/')
			continue;
		else if (temp.front() == '<')
			nowTag = temp.substr(1, temp.size());
		else if (temp.back() == '>')
			nowTag = "";
		else if (!nowTag.compare("object"))
		{
			__data__object__ __object__;
			for (;;)
			{
				stream >> temp;
				if (temp.back() == '>')
					break;
				else
				{
					string lvalue, rvalue;
					lvalue = temp.substr(0, temp.find('='));
					rvalue = temp.substr(temp.find('=') + 1);

					if (!lvalue.compare("name"))
						__object__.name = rvalue;
					else if (!lvalue.compare("texture"))
						__object__.texture = rvalue;
					else if (!lvalue.compare("x"))
						__object__.x = atoi(rvalue.c_str());
					else if (!lvalue.compare("y"))
						__object__.y = atoi(rvalue.c_str());
				}
			}

			res.objects.push_back(__object__);
		}
		else
		{
			string lvalue, rvalue;
			lvalue = temp.substr(0, temp.find('='));
			rvalue = temp.substr(temp.find('=') + 1);

			if (!lvalue.compare("title"))
				res.title = rvalue;
			else if (!lvalue.compare("mission"))
				res.mission = rvalue;
			else if (!lvalue.compare("size"))
			{
				if (!nowTag.compare("info"))
					res.size = atoi(rvalue.c_str());
				else if (!nowTag.compare("astroids"))
					res.astroids.size = atoi(rvalue.c_str());
			}
			else if (!lvalue.compare("texture"))
			{
				if (!nowTag.compare("astroids"))
				{
					res.astroids.texture = rvalue;
				}
			}
			else if (!lvalue.compare("count"))
				res.astroids.count = atoi(rvalue.c_str());
		}
	}

	stream.close();
	return res;
}
