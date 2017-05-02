#pragma once
#include <vector>
#include <string>

class Player
{
public:
	//Contructor y destructor
	Player();
	~Player();

	//M�todos
	void add(int elementPosition); //A�ade un elemento al inventario del jugador
	void addBasics(); //A�ade los 4 elementos b�sicos al inventario del jugador
	void deleteElement(int elementPosition); //Elimina un elemento del inventario
	void showInventory(); //Imprime el inventario del jugador
	void searchInfo(int elementPosition); //Busca informaci�n del elemento en internet
	void sortInventory(); //Ordena el inventario alfab�ticamente
	void cleanInventory(); //Elimina los elementos duplicados
	void updateScore(std::string element); //Actualiza la puntuaci�n del jugador
	void updateInventory(std::string element, int pos1, int pos2); //Actualiza el inventario del jugador

	//Atributos
	int playerScore; //Puntuaci�n
	std::vector <std::string> playerInventory; //Inventario del jugador
	std::vector <std::string> discoveredElements; //Vector que almacena los elementos ya descubiertos 
};

