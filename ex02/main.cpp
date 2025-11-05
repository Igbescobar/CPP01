#include <iostream>
#include <string>

int	main(void)
{
	std::string init = "HI THIS IS BRAIN";
	std::string *stringPTR = &init;
	std::string &stringREF = init;
	std::cout << "Memory address: " << &init << std::endl;
	std::cout << "Memory address held by stringPTR.: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF.: " << &stringREF << std::endl;
	std::cout << "The value: " << init << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
	return (0);
}
