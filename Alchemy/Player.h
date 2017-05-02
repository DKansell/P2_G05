#pragma once
#include <vector>
#include <string>

class Player
{
public:
	//Contructor y destructor
	Player();
	~Player();

	//Métodos
	void add(int elementPosition); //Añade un elemento al inventario del jugador
	void addBasics(); //Añade los 4 elementos básicos al inventario del jugador
	void deleteElement(int elementPosition); //Elimina un elemento del inventario
	void showInventory(); //Imprime el inventario del jugador
	void searchInfo(int elementPosition); //Busca información del elemento en internet
	void sortInventory(); //Ordena el inventario alfabéticamente
	void cleanInventory(); //Elimina los elementos duplicados
	void updateScore(std::string element); //Actualiza la puntuación del jugador
	void updateInventory(std::string element, int pos1, int pos2); //Actualiza el inventario del jugador

	//Atributos
	int playerScore; //Puntuación
	std::vector <std::string> playerInventory; //Inventario del jugador
	std::vector <std::string> discoveredElements; //Vector que almacena los elementos ya descubiertos 
};

