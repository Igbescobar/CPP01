#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
# include <string>

class HumanB
{
  public:
	HumanB(const std::string &name);

	void attack(void) const;
	void setWeapon(Weapon &weapon);
	std::string getName(void) const;
	Weapon *getWeapon(void) const;

  private:
	std::string _name;
	Weapon *_weapon;
};

#endif