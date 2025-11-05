#ifndef FILE_HPP
# define FILE_HPP
# include "Replacer.hpp"
# include <string>

class File
{
  public:
	File(const std::string &inputPath, const Replacer &replacer);
	void run() const;

  private:
	std::string _inputPath;
	Replacer _replacer;
	std::string _outPutPath() const;
};
#endif