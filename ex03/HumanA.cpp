#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name),
	_weapon(weapon)
{
}

std::string HumanA::getName(void) const
{
	return (_name);
}

Weapon HumanA::getWeapon(void) const
{
	return (_weapon);
}

void HumanA::attack(void) const
{
	std::cout << getName() << " attacks with their " << _weapon.getType() << std::endl;
}