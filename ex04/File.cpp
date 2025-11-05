#include "File.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

File::File(const std::string &input,
	const Replacer &replacer) : _inputPath(input), _replacer(replacer)
{
}

std::string File::_outPutPath() const
{
	return (_inputPath + ".replace");
}

static std::string readFileToString(const std::string &path, std::string &err)
{
	std::ifstream ifs(path);
	if (!ifs)
	{
		err = "Failed to open input file: " + path;
		return (std::string());
	}
	std::ostringstream outString;
	outString << ifs.rdbuf();
	if (ifs.fail() || !ifs.eof())
	{
		err = "Failed to read from file: " + path;
		return (std::string());
	}
	return (outString.str());
}

static std::string writeStringToFile(const std::string &string,
	const std::string &content, std::string &err)
{
	std::ofstream ofs()
}

void File::run(void) const
{
	std::string err;
	std::string input = readFileToString(_inputPath, err);
	if (input.empty() && !err.empty())
	{
		std::cerr << err << std::endl;
		return ;
	}
}
