#include "GameElements.h"
#include "Player.h"

#include <string.h>
#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <conio.h>



void main() {

	//Creación objetos del juego
	GameElements gameElements;
	Player player;

	//Print cabezera del juego
	gameElements.help(); //Muestra la lista de comandos 

	//Variables importantes
	std::string userInput;
	std::string instruction;
	std::size_t aux;
	std::string subInstruction;

	int i = 0;

	//GAME LOOP
	/*do {*/

		std::cout << "\nYour current score: " << player.playerScore << std::endl;
		std::cout << "\nYou have these elements: " << std::endl;
		player.showInventory();
		std::cin >> userInput;

		aux = userInput.find(" ");
		instruction = userInput.substr(0, aux);
		subInstruction = userInput.substr(aux + 1);

		std::cout << instruction << " " << subInstruction;

		//if (instruction == "add" && parameter == "basics") player.addBasics();
		//if (instruction == "add" )


		/*std::cin.clear(); //clears all error state flags
		//extracts characters from the input buffer and discards them
		std::cin.ignore(std::cin.rdbuf()->in_avail());*/

	/*} while (i < 1);*/


}