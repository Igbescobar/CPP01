#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <string1> <strin2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string str1 = argv[2];
	std::string str2 = argv[3];
	if (filename.empty() || str1.empty())
	{
		std::cerr << "<filename> and <string1> can not be empty>" << std::endl;
		return (1);
	}

	return (0);
}