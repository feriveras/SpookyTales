#include "Game.hpp"
//Loop principal del juego, cuando este se deje de ejecutar o el persona muera

Game* game = nullptr;

int main(int argc, char* argv[]) {

	//Defincion de FPS
	const int FPS = 60; 
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Spooky Tales", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	
	while (game -> ejecutando()) {

		frameStart = SDL_GetTicks();

		game -> eventos();
		game -> actualizar();
		game -> render();
		
		//Nos da el tiempo de cuanto tarda renderizar el objeto
		frameTime = SDL_GetTicks() - frameStart; 
		
		//El personaje se mueve mas lento en pantalla
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime); 
		}

	}

	//Si es false para salir del juego
	game -> limpiar(); 

	return 0;
}