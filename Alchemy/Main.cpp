#include "GameElements.h"
#include "Player.h"

#include <functional>
#include <utility>
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

	//Print cabecera del juego
	gameElements.help();

	//Variables importantes
	std::string userInput;
	std::string leftInstruction;
	std::string rightInstruction;
	std::size_t aux;
	int elementNumber1, elementNumber2;
	int Option = 0;

	//GAME LOOP
	do {

		std::cout << "\nYour current score: " << player.playerScore << std::endl;
		std::cout << "\nYou have these elements: " << std::endl;
		player.showInventory();

		std::cin.clear(); //clears all error state flags
						  //extracts characters from the input buffer and discards them
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		getline(std::cin, userInput); //Guardamos la instruccion del usuario dentro de una string

		system("cls"); //Borramos pantalla después del Input

		Option = 0;
		if (userInput == "help") Option = 1;
		if (userInput == "sort") Option = 2;
		if (userInput == "clean") Option = 3;
		aux = userInput.find(" ");
		if (aux != userInput.npos)
		{
			leftInstruction = userInput.substr(0, aux); //instruccion de la izquierda
			rightInstruction = userInput.substr(aux + 1); //instruccion de la derecha
			if (leftInstruction == "add" && rightInstruction == "basics")
			{
				Option = 4;
			}
			else {
				elementNumber1 = atoi(leftInstruction.c_str());
				if (leftInstruction == "add") Option = 5;
				if (leftInstruction == "delete") Option = 6;
				if (leftInstruction == "info") Option = 7;
				if (elementNumber1/*= atoi(leftInstruction.c_str())*/ > 0) Option = 8; //Només guarda elementNumber la 1a vegada.
				elementNumber2 = atoi(rightInstruction.c_str());
				if (elementNumber2 == 0) Option = 0;
			}
		}
		if (userInput == "exit") Option = 99;

		switch (Option)
		{
		case 0: break;	//ERROR INSTRUCTION
		case 1: gameElements.help();
			break;
		case 2: player.sortInventory();
			break;
		case 3: player.cleanInventory();
			break;
		case 4: player.addBasics();
			break;
		case 5: player.add(elementNumber2);
			break;
		case 6:	player.deleteElement(elementNumber2);
			break;
		case 7: player.searchInfo(elementNumber2);
			break;
		case 8: 
			//gameElements.search(elementNumber1, elementNumber2);
				//Buscar si existe la combinación
				//Añadir el nuevo elemento al Inventario y eliminar los anteriores  
			std::pair<std::string, std::string> key;
			key = std::make_pair(player.playerInventory[elementNumber1-1], player.playerInventory[elementNumber2-1]);
			auto got = gameElements.myElements.find(key);
			
			if (got == gameElements.myElements.end()) {
				key = std::make_pair(player.playerInventory[elementNumber2 - 1], player.playerInventory[elementNumber1 - 1]);
				auto got = gameElements.myElements.find(key);

				if (got == gameElements.myElements.end()) std::cout << "Element Not Found" << std::endl;
				else std::cout << got->second;
			}
			else
				std::cout << got->second;
				//Añadir el elemento al inventario y comprobar si esta descubierto para la puntuacion
			break;
		}
	} while (Option != 99);
}
	