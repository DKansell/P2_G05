#pragma once
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"



class GameElements
{
public:
	//Constructor y Destructor
	GameElements();
	~GameElements();

	//Métodos


	//Atributos
	//mapa de las combinaciones
	std::unordered_map <std::string, std::pair<std::string, std::string>> myElements; 
};

