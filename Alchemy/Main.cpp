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

	//Creaci�n objetos del juego
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

		getline(std::cin, userInput); //Guardamos la instruccion del usuario dentro de una string

		system("cls"); //Borramos pantalla despu�s del Input

		

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
				if (elementNumber1/*= atoi(leftInstruction.c_str())*/ > 0) Option = 8; //Nom�s guarda elementNumber la 1a vegada.
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
		case 8: /*std::cout << "element num 1: " << elementNumber1 << " ele 2: " << elementNumber2 << std::endl;*/ //Para comprovar los valores
			//gameElements.search(elementNumber1, elementNumber2);
				//Buscar si existe la combinaci�n
				//A�adir el nuevo elemento al Inventario y eliminar los anteriores  
			std::unordered_map <std::string, std::pair<std::string, std::string>>::const_iterator got = gameElements.myElements.find(player.playerInventory[elementNumber1], player.playerInventory[elementNumber2]);
			/*if (got == gameElements.myElements.end())
				std::cout << "not found";
			else
				std::cout << got->first << " is " << got->second;*/
			break;
		}

	} while (Option != 99);

	std::cin.clear(); //clears all error state flags
					  //extracts characters from the input buffer and discards them
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}
	
	/*//Creaci�n objetos del juego
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
		std::cin.ignore(std::cin.rdbuf()->in_avail());

	}while (playing);
}*/