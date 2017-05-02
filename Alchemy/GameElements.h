#pragma once
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"

//Funcion Hash para usar pair de strings como key del unordered_map.
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
	void help(); //Muestra el tutorial al jugador
	std::string checkMap(std::string key1, std::string key2); //Busca si una combinación de elementos existe

	//Atributos
	std::unordered_map <std::pair<std::string, std::string>, std::string> myElements; //mapa de las combinaciones
};

