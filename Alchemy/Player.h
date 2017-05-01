#pragma once
#include <vector>
#include <string>

class Player
{
public:
	Player();
	~Player();
private:
	int playerScore;
	std::vector <std::string> playerInventory;
};

