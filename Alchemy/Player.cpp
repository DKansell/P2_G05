#include "Player.h"
#include <string>
#include <vector>
#include <iostream>



Player::Player() : 
	//Inicializamos score a 0 i inventario del jugador con los 4 elementos b�sicos
	playerScore(0),
	playerInventory({"Air", "Earth", "Fire", "Water"})
{
}

Player::~Player()
{
}

void Player::add(int elementPosition) //A�ade un elemento al inventario del jugador
{
	//Comprobaci�n para que no se pueda a�adir ningun elemento de posici�n mas grande que el size del inventario
	if (elementPosition <= playerInventory.size())
	{
		std::string aux = playerInventory[elementPosition];
		playerInventory.push_back(aux);
	}
}

void Player::addBasics() //A�ade los 4 elementos b�sicos al inventario del jugador
{
	playerInventory.push_back("Air");
	playerInventory.push_back("Earth");
	playerInventory.push_back("Fire");
	playerInventory.push_back("Water");
}

void Player::deleteElement(int elementPosition) //Elimina un elemento del inventario 
{
	//Comprobaci�n para que no se pueda eliminar ningun elemento de posici�n superior al size del inventario
	if (elementPosition <= playerInventory.size())
	{
	playerInventory.erase((playerInventory.begin()+elementPosition)-1);
	}
}

void Player::showInventory() //Imprime el inventario del jugador
{
	for (auto it = 0; it < playerInventory.size(); it++)
	{
		std::cout << it + 1 << ":" << playerInventory[it] << std::endl;
	}
}