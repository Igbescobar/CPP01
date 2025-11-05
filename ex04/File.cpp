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
	std::ifstream ifs(path.c_str());
	if (!ifs)
	{
		err = "Failed to open input file: " + path;
		return (std::string());
	}
	std::ostringstream outString;
	outString << ifs.rdbuf();
	if (ifs.bad())
	{
		err = "Failed to read from file: " + path;
		return (std::string());
	}
	return (outString.str());
}

static bool	writeStringToFile(const std::string &path,
		const std::string &content, std::string &err)
{
	std::ofstream ofs(path.c_str(), std::ios::out | std::ios::trunc);
	if (!ofs)
	{
		err = "Faild to open output file " + path;
		return (false);
	}
	ofs << content;
	if (!ofs.good())
	{
		err = "Failed to write to file " + path;
		return (false);
	}
	return (true);
}

bool File::run(void) const
{
	std::string err;
	std::string input = readFileToString(_inputPath, err);
	if (input.empty() && !err.empty())
	{
		std::cerr << err << std::endl;
		return (false);
	}
	std::string outContent = _replacer.replaceIn(input);
	std::string outPath = _outPutPath();

	if (!writeStringToFile(outPath, outContent, err))
	{
		std::cerr << err << std::endl;
		return (false);
	}
	std::cout << "Wrote replaced content to " << outPath << std::endl;
	return (true);
}
