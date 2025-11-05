#include "Zombie.hpp"

int	main(void)
{
	randomChump("Pedro");
	Zombie *myZombie = newZombie("Manolo");
	myZombie->announce();
	delete myZombie;
	return (0);
}