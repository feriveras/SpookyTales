#include "GameObject.h"
#include "AdministadorTexturas.h"

//Constructor de la clase
GameObject::GameObject(const char* texturesheet, int x, int y) 
{
	objTexture = TextureManager::cargarTextura(texturesheet);

	//Se declara la posicion inicial del objeto
	xpos = x;
	ypos = y;

}
//Facilita la creacion de objetos
void GameObject::actualizar()
{
	//Coloca al personaje en pantalla

	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

}
void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}