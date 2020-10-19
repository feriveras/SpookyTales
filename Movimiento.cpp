#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <string>


int main(int argc, char** argv)
{
	//se definen variables por usar
	int i = 10, posy = 0, posyV = 0;
	bool salir = false;
	SDL_Event event;


	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	//Se crea la ventana para ubicar los personajes y renderer para renderizarlos
	SDL_Window* window = SDL_CreateWindow("Movimiento Jugadores", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 480, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	//Se crea la textura de los personajes, se carga la imagen  luego se le brinda la textura
	SDL_Surface* Fernanda = IMG_Load("Fer.png");
	SDL_Texture* texturaFernanda = SDL_CreateTextureFromSurface(renderer, Fernanda);

	SDL_Surface* Marco = IMG_Load("Marco.png");
	SDL_Texture* texturaMarco = SDL_CreateTextureFromSurface(renderer, Marco);

	SDL_Surface* Belen = IMG_Load("Belen.png");
	SDL_Texture* texturaBelen = SDL_CreateTextureFromSurface(renderer, Belen);

	SDL_Surface* Enemigo1 = IMG_Load("Enemigo1.png");
	SDL_Texture* texturaEnemigo1 = SDL_CreateTextureFromSurface(renderer, Enemigo1);

	SDL_Surface* Enemigo2 = IMG_Load("Enemigo2.png");
	SDL_Texture* texturaEnemigo2 = SDL_CreateTextureFromSurface(renderer, Enemigo2);

	SDL_Surface* Enemigo3 = IMG_Load("Enemigo3.png");
	SDL_Texture* texturaEnemigo3 = SDL_CreateTextureFromSurface(renderer, Enemigo3);

	//Se le da un color a la ventana
	SDL_SetRenderDrawColor(renderer, 100, 0, 0, 100);
	SDL_RenderClear(renderer);

	//posiciones de inicio de los personajes
	int posxF = 32;
	int posyF = 64;
	int posxM = 64;
	int posyM = 64;
	int posxB = 96;
	int posyB = 64;
	int posxV1 = 128;
	int posyV1 = 128;
	int posxV2 = 160;
	int posyV2 = 190;
	int posxV3 = 200;
	int posyV3 = 300;

	while (!salir)
	{
		//Obtiene los ticks del reloj para asi darle movimiento al personaje ya que siempre esta en costante cambio
		Uint32 ticks = SDL_GetTicks();
		Uint32 sprite = (ticks / 250) % 3;

		//Define el origen y destino y con estos poder recortar la imagen y dar el efecto del movimeinto del personaje

		SDL_Rect origenF = { sprite * 32, posy, 32, 32 };
		SDL_Rect destinoF = { posxF, posyF, 32, 32 };

		SDL_Rect origenM = { sprite * 32, posy, 32, 32 };
		SDL_Rect destinoM = { posxM, posyM, 32, 32 };

		SDL_Rect origenB = { sprite * 32, posy, 32, 32 };
		SDL_Rect destinoB = { posxB, posyB, 32, 32 };

		SDL_Rect origenV1 = { sprite * 32, posyV, 32, 32 };
		SDL_Rect destinoV1 = { posxV1, posyV1, 32, 32 };

		SDL_Rect origenV2 = { sprite * 32, posyV, 32, 32 };
		SDL_Rect destinoV2 = { posxV2, posyV2, 32, 32 };

		SDL_Rect origenV3 = { sprite * 32, posyV, 32, 32 };
		SDL_Rect destinoV3 = { posxV3, posyV3, 32, 32 };


		while (SDL_PollEvent(&event) != NULL)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				salir = true;
				break;
			case SDL_KEYDOWN: //Recibe cuando se utilizan las entradas de teclado RIGHT, LEFT, DOWN y UP, controla el movimiento del personaje

				if (event.key.keysym.sym == SDLK_RIGHT) {
					posxF += 3; //Cambia la posicion del personaje 
					posy = 64;

				}
				if (event.key.keysym.sym == SDLK_LEFT) {
					posxF -= 3;
					posy = 32;

				}
				if (event.key.keysym.sym == SDLK_UP) {
					posyF -= 3;
					posy = 96;

				}
				if (event.key.keysym.sym == SDLK_DOWN) {
					posyF += 3;
					posy = 0;

				}
				break;

			}
		}

		//Actualizar la visualización de la ventana conforme los personajes y villanos se muevan 

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texturaFernanda, &origenF, &destinoF);
		SDL_RenderCopy(renderer, texturaMarco, &origenM, &destinoM);
		SDL_RenderCopy(renderer, texturaBelen, &origenB, &destinoB);
		SDL_RenderCopy(renderer, texturaEnemigo1, &origenV1, &destinoV1);
		SDL_RenderCopy(renderer, texturaEnemigo2, &origenV2, &destinoV2);
		SDL_RenderCopy(renderer, texturaEnemigo3, &origenV3, &destinoV3);
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 150, 100, 200, 255);
		SDL_RenderClear(renderer);
	}

	//Cerrar todo

	SDL_DestroyTexture(texturaFernanda);
	SDL_FreeSurface(Fernanda);
	SDL_DestroyTexture(texturaMarco);
	SDL_FreeSurface(Marco);
	SDL_DestroyTexture(texturaBelen);
	SDL_FreeSurface(Belen);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}