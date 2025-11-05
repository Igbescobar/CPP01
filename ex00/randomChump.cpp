#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie myZombie = Zombie(name);
	myZombie.announce();
}