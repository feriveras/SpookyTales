#include "Game.hpp"
#include "AdministadorTexturas.h"
#include "GameObject.h"
#include "Map.h"
//#include "ECS.h"
//#include "Components.h"



//Se declaran los nuevos objetos
GameObject* jugador1;
GameObject* villano1;
GameObject* villano2;
GameObject* villano3;
Map* mapa;


SDL_Renderer* Game::renderer = nullptr;

//Administrador administrador;
//auto& nuevoJugador(administrador.agregarEntidad());


//Funcione
Game::Game()
{}

Game::~Game()
{}
void Game::init(const char *title, int xpos, int ypos,int zpos, int apos, int width, int height, bool fullscreen)
{
	//Se crea variable flags para determinar la pantalla completa por medio de valores booleanos
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		//Creando la ventana declarada en Game.hpp
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			
		}

		ejecutandose = true;
	
	}

	//Cargando la textura del personaje llamando al metodo
	jugador1 = new GameObject("Assets/jugador1.png", 0,0,0,0);
	villano1 = new GameObject("Assets/villano1.png", 50, 50,50,50);
	villano2 = new GameObject("Assets/villano2.png", 100, 100,100,100);
	villano3 = new GameObject("Assets/villano3.png", 150, 150, 150,150);
	mapa = new Map();

	//nuevoJugador.agregarComponente<picisionComponente>();

}

void Game::eventos()
//Detiene que el juego ejecute el siguiente loop
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		ejecutandose = false;
		break;
	default:
		break;
	}
}

void Game::actualizar()
{
	//Se  cargan los objetos
	jugador1 -> actualizar();
	villano1->actualizar();
	villano2->actualizar();
	villano3->actualizar();
	//administrador.actualizar();
	//std::cout << nuevoJugador.getComponente<picisionComponente>().x() << "," <<
		//nuevoJugador.getComponente<picisionComponente>().y() << std::endl;

}

void Game::render()
//Renderizar objetos
{	
	//Limpiar el buffer que esta en el render 
	SDL_RenderClear(renderer);
	//Dibujar el mapa
	mapa -> dibujarMapa();
	//Renderizar los personajes
	jugador1 -> Render();
	villano1 ->Render();
	villano2->Render();
	villano3->Render();
	SDL_RenderPresent(renderer);

}

void Game::limpiar()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

}




