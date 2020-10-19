#pragma once
#include "Game.hpp"

class GameObject {
public:
	GameObject(const char* texturesheet, int x, int y,int z, int a);
	~GameObject();

	void actualizar(); //Update
	void Render();

private:
	int xpos;
	int ypos;
	int zpos;
	int apos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	

};
