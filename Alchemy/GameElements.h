#pragma once
#include <unordered_map>
#include <fstream>
#include <string>



class GameElements
{
public:
	GameElements();
	~GameElements();
	std::unordered_map <std::string, std::pair<std::string, std::string>> myElements;
};

