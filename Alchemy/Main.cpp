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

	int i = 0;

	//GAME LOOP
	/*do {*/

		std::cout << "\nYour current score: " << player.playerScore << std::endl;
		std::cout << "\nYou have these elements: " << std::endl;
		player.showInventory();
		getline(std::cin, userInput); //Guardamos la instruccion del usuario dentro de una string

		aux = userInput.find(" ");
		leftInstruction = userInput.substr(0, aux); //instruccion de la izquierda
		//rightInstruction = userInput.substr(aux + 1); //instruccion de la derecha

		std::cout << aux;

		system("cls"); //Borramos la pantalla despues del input

		if (leftInstruction == "add" && rightInstruction == "basics") player.addBasics();
		if (leftInstruction == "add" && rightInstruction != "basics")
		{
			int elementNumber = atoi(rightInstruction.c_str()); 
			player.add(elementNumber);
		}
		if (leftInstruction == "help") gameElements.help();
		if (leftInstruction == "delete") 
		{
			int elementNumber = atoi(rightInstruction.c_str());
			player.deleteElement(elementNumber);
		}
		if (leftInstruction == "info") 
		{
			int elementNumber = atoi(rightInstruction.c_str());
			player.searchInfo(elementNumber);
		}
		if (leftInstruction == "sort") player.sortInventory();
		if (leftInstruction == "clean") player.cleanInventory();



		player.showInventory();
		/*std::cin.clear(); //clears all error state flags
		//extracts characters from the input buffer and discards them
		std::cin.ignore(std::cin.rdbuf()->in_avail());*/

	/*} while (i < 1);*/
}