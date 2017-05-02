#include "Player.h"
#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <algorithm>



Player::Player() : 
	//Inicializamos score a 0 i inventario del jugador con los 4 elementos básicos
	playerScore(0),
	playerInventory({"Air", "Earth", "Water", "Fire"})
{
}

Player::~Player()
{
}

void Player::add(int elementPosition) //Añade un elemento al inventario del jugador
{
	//Comprobación para que no se pueda añadir ningun elemento de posición mas grande que el size del inventario
	if (elementPosition <= playerInventory.size())
	{
		std::string aux = playerInventory[elementPosition-1];
		playerInventory.push_back(aux);
	}
}

void Player::addBasics() //Añade los 4 elementos básicos al inventario del jugador
{
	playerInventory.push_back("Air");
	playerInventory.push_back("Earth");
	playerInventory.push_back("Fire");
	playerInventory.push_back("Water");
}

void Player::deleteElement(int elementPosition) //Elimina un elemento del inventario 
{
	//Comprobación para que no se pueda eliminar ningun elemento de posición superior al size del inventario
	if (elementPosition <= playerInventory.size())
	{
	playerInventory.erase((playerInventory.begin()+elementPosition)-1);
	}
}

void Player::showInventory() //Imprime el inventario del jugador
{
	for (auto it = 0; it < playerInventory.size(); it++)
	{
		std::cout << it + 1 << ": " << playerInventory[it] << std::endl;
	}
}

void Player::searchInfo(int elementPosition) //Busca información de un elemento en internet
{
	if (elementPosition <= playerInventory.size())
	{
		std::string link = "https://en.wikipedia.org/wiki/" + playerInventory[elementPosition - 1]; //"Suma" de dos strings : "url wikipedia" + "nombre elemento"
		ShellExecuteA(nullptr, "open", link.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
	}
}

void Player::sortInventory() //Ordena inventari en ordre alfabetic
{
	std::sort(playerInventory.begin(), playerInventory.end());
}

void Player::cleanInventory() //Elimina elementos repetidos del inventario
{
	//Vector auxiliar para comprobar repetidos i variable para identificar repeticiones
	std::vector<std::string> aux; 
	bool duplicate = false; 

	for (std::vector<std::string>::iterator it = playerInventory.begin(); it != playerInventory.end(); ++it)
	{
		duplicate = false;
		for (std::vector<std::string>::iterator j = aux.begin(); j != aux.end(); ++j)
		{
			if (*it == *j) //Si encuentra un duplicado salimos del bucle y no lo guardamos
			{
				duplicate = true; 
				break;
			}
		}
		if (duplicate == false) aux.push_back(*it); //Copia un elemento en caso de no estar repetido
	}
	//Copiamos el vector auxiliar sin duplicados al vector inventario
	playerInventory = aux;
	
	//Ordenamos el vector final sin duplicados
	Player::sortInventory();
}

void Player::updateScore(std::string element) {

	bool isDiscovered = false;

	for (std::vector<std::string>::iterator it = discoveredElements.begin(); it != discoveredElements.end(); ++it)
	{
			if (*it == element) 
			{
				isDiscovered = true;
				break;
			}
	}
		
	if (!isDiscovered) 
	{
		playerScore++;
		discoveredElements.push_back(element);
	}
}

void Player::updateInventory(std::string element, int pos1, int pos2)
{
	playerInventory.erase((playerInventory.begin() + pos1) - 1);
	playerInventory.erase((playerInventory.begin() + pos2) - 1);
	playerInventory.push_back(element);
}
