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



int main() {

	//Creación objetos del juego
	GameElements gameElements;
	Player player;

	//Print cabecera del juego
	gameElements.help();

	//Variables importantes para el input del jugador
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
		std::cin.ignore(std::cin.rdbuf()->in_avail());  //extracts characters from the input buffer and discards them

		getline(std::cin, userInput); //Guardamos la instruccion del usuario dentro de una string

		system("cls"); //Borramos pantalla después del Input

		Option = 0;
		//Determinamos que instrucción ha introducido el jugador: ordenes simples
		if (userInput == "help") Option = 1;
		if (userInput == "sort") Option = 2;
		if (userInput == "clean") Option = 3;
		//Determinamos que instrucción ha introducido el jugador: ordenes compuestas por mas de una palabra
		aux = userInput.find(" ");
		if (aux != userInput.npos)
		{
			leftInstruction = userInput.substr(0, aux); //separamos instrucción de la izquierda
			rightInstruction = userInput.substr(aux + 1); //separamos instrucción de la derecha
			if (leftInstruction == "add" && rightInstruction == "basics")
			{
				Option = 4;
			}
			else { //En caso de que la instrucción contenga algun número
				elementNumber1 = atoi(leftInstruction.c_str()); //Guarda key1
				if (leftInstruction == "add") Option = 5;
				if (leftInstruction == "delete") Option = 6;
				if (leftInstruction == "info") Option = 7;
				if (elementNumber1 > 0) Option = 8; //Ya que no puede existir key1 = 0 
				elementNumber2 = atoi(rightInstruction.c_str()); //Guarda key2
				if (elementNumber2 == 0) Option = 0; //Comprobación, ya que no puede existir key2 = 0 
			}
		}
		if (userInput == "exit") Option = 99; //Input para salir del juego

		switch (Option)
		{
		case 0: break;	//INSTRUCCIÓN NULA
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
			//Comprobamos que los valores de las keys esten contenidos dentro del inventario, y que no sean iguales entre si.
			if (elementNumber1 > 0 && elementNumber1 <= player.playerInventory.size() && elementNumber2 > 0 && elementNumber2 <= player.playerInventory.size() && elementNumber1 != elementNumber2)
			{
				//Llama a la función para buscar y recorrer el mapa
				std::string newElement = gameElements.checkMap(player.playerInventory[elementNumber1 - 1], player.playerInventory[elementNumber2 - 1]);
				//Si la combinación existe:
				if (newElement != "NotFound")
				{
					std::cout << "Congratulations! You found: " << newElement << std::endl;
					player.updateScore(newElement);
					player.updateInventory(newElement, elementNumber1, elementNumber2);
				}
				//Alerta de error si la combinación no existe:
				else std::cout << "Can't combine those elements." << std::endl;
			}
			//Alerta de error si las keys no están dentro del inventario:
			else std::cout << "Can't combine those elements." << std::endl;
		}
	} while (Option != 99);

	system("exit");
	return 0;
}
	