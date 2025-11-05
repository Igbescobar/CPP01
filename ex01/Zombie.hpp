#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie
{
  public:
	Zombie();
	Zombie(const std::string &name);

	void announce(void);
	void setName(std::string name);
	std::string getName(void);
	~Zombie();

  private:
	std::string _name;
	int _id;

	static int _createdCount;
	static int _aliveCount;
};

Zombie	*zombieHorde(int N, std::string name);
#endif