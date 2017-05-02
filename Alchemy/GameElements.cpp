#include "GameElements.h"
#include <iostream>



GameElements::GameElements()
{
	std::ifstream elementList;
	//Abrimos el archivo de datos que contiene las combinaciones
	elementList.open("elements.dat"); 

	std::string line; 
	std::size_t aux1;
	std::size_t aux2;
	std::string elementValue, key1, key2;
	//Si no se carga correctamente interrumpimos el programa
	if (elementList.fail())
	{
		system("exit");
	}
	else
	{
		while (!elementList.eof())
		{
			//Guardamos toda una linea
			std::getline(elementList, line);
			//Buscamos posición antes del "="
			aux1 = line.find(" =");
			//Buscamos posición antes del "+"
			aux2 = line.find(" +");
			//Guardamos (en substrings) según la posición el valor del mapa i las dos keys
			elementValue = line.substr(0, aux1);
			key1 = line.substr(aux1 + 3, aux2 - (aux1 + 3));
			key2 = line.substr(aux2 + 3);
			//Almacenamos el value y las keys en el mapa
			myElements[{key1, key2}] = elementValue;
		}
	}
	//Cerramos el archivo
	elementList.close();
}

GameElements::~GameElements()
{
}

void GameElements::help()
{
	std::cout << "----------------" << std::endl;
	std::cout << " ALCHEMIST GAME " << std::endl;
	std::cout << "----------------\n" << std::endl;
	std::cout << "- Enter two numbers of your elements list to combine them." << std::endl;
	std::cout << "- Enter the word 'add' and the number of an element to add another copy of this element to your inventory." << std::endl;
	std::cout << "- Enter 'add basics' to add a new copy of the 4 basic elements to your inventory." << std::endl;
	std::cout << "- Enter the word 'delete' and the number of an element to erase it from your inventory." << std::endl;
	std::cout << "- Enter the word 'info' and the number of an element to get information about it." << std::endl;
	std::cout << "- Enter the word 'sort' to sort your inventory by alphabetical order." << std::endl;
	std::cout << "- Enter the word 'clean' to delete all the repeated elements." << std::endl;
	std::cout << "- Enter the word 'help' to show this tutorial." << std::endl;
	std::cout << "\n- Type 'exit' to end the game." << std::endl;
}

std::string GameElements::checkMap(std::string key1, std::string key2) 
{
	std::pair<std::string, std::string> key; //Creamos variable como pair de dos strings 
	key = std::make_pair(key1, key2); //Asignamos las keys del mapa a la variable pair
	auto got = myElements.find(key); //Buscamos el valor correspondiente a la key dentro del mapa

	if (got == myElements.end()) { //En caso de no encontrarlo, invertimos las keys y volvemos a buscar
		key = std::make_pair(key2, key1);
		auto got = myElements.find(key);

		//Si de nuevo no lo encuentra, devolvemos NotFound:
		if (got == myElements.end()) return "NotFound";
		//Si existe valor asignado a esas keys, lo devolvemos:
		else return got->second;
	}
	//Si existe valor asignado a esas keys (primera iteración), lo devolvemos:
	else
		return got->second;
}