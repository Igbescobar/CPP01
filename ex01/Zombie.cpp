#include "Zombie.hpp"
#include <iostream>

int Zombie::_createdCount = 0;
int Zombie::_aliveCount = 0;

Zombie::Zombie() : _name(""), _id(++_createdCount)
{
	++_aliveCount;
}

Zombie::Zombie(const std::string &name) : _name(name), _id(++_createdCount)
{
	++_aliveCount;
}

Zombie::~Zombie(void)
{
	--_aliveCount;
	std::cout << "Zombie #" << _id << " (" << _name << ") destroyed! " << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}

std::string Zombie::getName(void)
{
	return (_name);
}

void Zombie::announce(void)
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}