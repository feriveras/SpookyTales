#ifndef Game_hpp
#define Game_hpp
#include <SDL.h>
#include <iostream>
#include "SDL_image.h"


//Creacion de la clase "game"
class Game {
public:
	Game();
	~Game();

	//Se definen las clases

	void init(const char* title, int xpos, int ypos, int width, int heigh, bool fullscreen);
	
	void eventos();    //handleEvents
	void actualizar(); //update
	void render(); 
	void limpiar();    //clean

	//si es true se ejecuta el juego otra vez y se actualiza render
	bool ejecutando() { return ejecutandose; } //running
	
	static SDL_Renderer* renderer;

private:
	int cont = 0; //cnt

	bool ejecutandose; //isRunning
	SDL_Window* window;
};

#endif /*Game_hpp*/



