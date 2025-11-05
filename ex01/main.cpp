#include "Zombie.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	std::size_t N;
	std::string name;

	std::cout << "Number of zombies you want in your horde: " << std::endl;
	if (!(std::cin >> N))
		return (1);
	std::cout << "Name of the zombies: " << std::endl;
	if (!(std::cin >> name))
		return (1);

	Zombie *horde = zombieHorde(N, name);
	if (horde == NULL)
	{
		std::cout << "No zombies created." << std::endl;
		return (0);
	}
	for (std::size_t i = 0; i < N; i++)
	{
		std::cout << "[" << i << "]";
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}