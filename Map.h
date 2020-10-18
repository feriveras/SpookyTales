#pragma once

#include "Game.hpp"

//Clase Mapa
class Map
{
public:
	Map();
	~Map();

	void cargarMapa(int arr[20][25]);
	void dibujarMapa();


private:
	SDL_Rect src, dest;

	SDL_Texture* tierra;
	SDL_Texture* cesped;
	SDL_Texture* agua;

	int map[20][25];
};
