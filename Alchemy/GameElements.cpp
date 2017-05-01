#include "GameElements.h"
#include <iostream>



GameElements::GameElements()
{
	std::ifstream elementList;
	elementList.open("elements.dat");

	std::string line; 
	std::size_t aux1;
	std::size_t aux2;
	std::string elementValue, key1, key2;

	//Si no se carga correctamente interrumpimos el programa
	if (elementList.fail())
	{
		system("pause");
	}
	else
	{
		while (!elementList.eof())
	{
			std::getline(elementList, line);

			aux1 = line.find(" =");
			aux2 = line.find(" +");

			elementValue = line.substr(0, aux1);
			key1 = line.substr(aux1 + 3, aux2 - (aux1 + 3));
			key2 = line.substr(aux2 + 3);

			myElements[elementValue] = {key1, key2};
		}
	}
	elementList.close();
}

GameElements::~GameElements()
{
}

void GameElements::help()
{
	std::cout << "- Enter two numbers of your elements list to combine them." << std::endl;
	std::cout << "- Enter the word 'add' and the number of an element to add another copy of this element to your inventory" << std::endl;
	std::cout << "- Enter 'add basics' to add a new copy of the 4 basic elements to your inventory." << std::endl;
	std::cout << "- Enter the word 'delete' and the number of an element to erase it from your inventory." << std::endl;
	std::cout << "- Enter the word 'info' and the number of an element to get information about it." << std::endl;
	std::cout << "- Enter the word 'sort' to sort your inventory by alphabetical order." << std::endl;
	std::cout << "- Enter the word 'clean' to delete all the repeated elements." << std::endl;
	std::cout << "- Enter the word 'help' to show this tutorial." << std::endl;
}
