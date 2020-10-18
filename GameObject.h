#pragma once
#include "Game.hpp"

class GameObject {
public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	void actualizar(); //Update
	void Render();

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	

};
