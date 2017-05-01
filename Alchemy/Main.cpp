#include "GameElements.h"
#include "Player.h"

#include <string.h>
#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <cstdlib>



void main() {

	//Creación objetos del juego
	GameElements gameElements;
	Player player;

	//Print cabezera del juego
	gameElements.help(); //Muestra la lista de comandos 

	//Variables importantes
	std::string userInput;
	std::string leftInstruction;
	std::size_t aux;
	std::string rightInstruction;

	bool playing = true;

	//GAME LOOP
	do {

		std::cout << "\nYour current score: " << player.playerScore << std::endl;
		std::cout << "\nYou have these elements: " << std::endl;
		player.showInventory();
		getline(std::cin, userInput); //Guardamos la instruccion del usuario dentro de una string
		aux = userInput.find(" ");

		if (aux != std::string::npos) {
			leftInstruction = userInput.substr(0, aux); //instruccion de la izquierda
			rightInstruction = userInput.substr(aux + 1); //instruccion de la derecha
		}

		else leftInstruction = userInput;

		system("cls"); //Borramos la pantalla despues del input

		if (leftInstruction == "add" && rightInstruction == "basics") player.addBasics();
		else if (leftInstruction == "add" && rightInstruction != "basics")
		{
			int elementNumber = atoi(rightInstruction.c_str()); 
			player.add(elementNumber);
		}
		else if (leftInstruction == "help") gameElements.help();
		else if (leftInstruction == "delete") 
		{
			int elementNumber = atoi(rightInstruction.c_str());
			player.deleteElement(elementNumber);
		}
		else if (leftInstruction == "info") 
		{
			int elementNumber = atoi(rightInstruction.c_str());
			player.searchInfo(elementNumber);
		}
		else if (leftInstruction == "sort") player.sortInventory();
		else if (leftInstruction == "clean") player.cleanInventory();

		else 
		{
			int key1 = atoi(leftInstruction.c_str());
			int key2 = atoi(rightInstruction.c_str());

			std::string newElement = gameElements.myElements

		}


		/*std::cin.clear(); //clears all error state flags
		//extracts characters from the input buffer and discards them
		std::cin.ignore(std::cin.rdbuf()->in_avail());*/

	}while (playing);
}