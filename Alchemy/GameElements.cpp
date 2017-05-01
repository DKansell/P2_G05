#include "GameElements.h"



GameElements::GameElements()
{
	std::ifstream elementList;
	elementList.open("elements.dat");

	std::string line;
	std::size_t aux1;
	std::size_t aux2;
	std::string elementValue, key1, key2;

	
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
