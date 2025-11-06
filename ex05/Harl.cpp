#include "Harl.hpp"
#include <iostream>

void Harl::complain(std::string level)
{
	std::string list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info,
		&Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (level == list[i])
		{
			(*this.*functions[i])();
			return ;
		}
	}
	std::cout << "Invalid level" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-\
ketchup burger.I really do !";
}
void Harl::info(void)
{
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put\
enough bacon in my burger! If you did, I wouldn’t be asking for more!";
}
void Harl::warning(void)
{
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for\
years, whereas you started working here just last month.";
}
void Harl::error(void)
{
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now.";
}