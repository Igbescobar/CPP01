#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
# include <string>

class HumanA
{
  public:
	HumanA(const std::string &name, Weapon &weapon);

	void attack(void) const;
	std::string getName(void) const;
	Weapon getWeapon(void) const;

  private:
	std::string _name;
	Weapon &_weapon;
};

#endif