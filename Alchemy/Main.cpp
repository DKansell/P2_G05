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

	player.showInventory();

	system("pause");
}