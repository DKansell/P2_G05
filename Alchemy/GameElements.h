#pragma once
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"

template<>
struct std::hash<std::pair<std::string, std::string>> {
	size_t operator()(const std::pair<std::string, std::string> &p) const
	{
		return((hash<std::string>()(p.first)
			^ (hash<std::string>()(p.second) << 1)) >> 1);
	}
};

class GameElements
{
public:
	//Constructor y Destructor
	GameElements();
	~GameElements();

	//Métodos
	void help();
	std::string checkMap(std::string key1, std::string key2);

	//Atributos
	//mapa de las combinaciones
	std::unordered_map <std::pair<std::string, std::string>, std::string> myElements;
};

