#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : _name(name)
{
}

std::string HumanB::getName(void) const
{
	return (_name);
}

Weapon *HumanB::getWeapon(void) const
{
	return (_weapon);
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void) const
{
	if (_weapon)
		std::cout << getName() << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << getName() << " has no weapon" << std::endl;
}