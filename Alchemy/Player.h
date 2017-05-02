#pragma once
#include <vector>
#include <string>

class Player
{
public:
	friend class GameElements;
	//Contructor y destructor
	Player();
	~Player();

	//M�todos
	void add(int elementPosition);
	void addBasics();
	void deleteElement(int elementPosition);
	void showInventory(); //Imprime el inventario del jugador
	void searchInfo(int elementPosition);
	void sortInventory();
	void cleanInventory();

	//Atributos
	int playerScore; //Puntuaci�n
public:
	std::vector <std::string> playerInventory; //Inventario del jugador
};

