#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(){
	int N = 3;
	Zombie *horde = zombieHorde(N, "Zombies");

	if(!horde){
		std::cerr << "Failed to create horde." << std::endl;
		return 1;
	}

	for(int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}