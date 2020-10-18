#pragma once

#include "Game.hpp"


//Se crea la clase textura y su constructor
class TextureManager {

public:
	static SDL_Texture* cargarTextura(const char* fileName);
	static void dibujar(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

};

