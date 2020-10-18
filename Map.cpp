#include "Map.h"
#include "AdministadorTexturas.h"

//Se define la estructura del mapa 
int nivel1[20][25] = {

	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0},
	{0,0,0,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,2,2,2,2,2},
	{0,0,0,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,2,1,0,0,0},
	{0,0,0,1,1,1,1,2,0,0,0,0,2,1,0,0,0,0,0,0,2,1,0,0,0},
	{0,0,0,1,1,1,1,2,0,0,0,0,2,1,1,1,1,1,1,1,2,1,0,0,0},
	{0,0,0,1,2,2,2,2,0,0,0,0,2,2,2,2,2,2,2,2,2,1,0,0,0},
	{0,0,0,1,2,1,1,2,0,0,0,0,2,1,1,1,1,1,1,1,2,1,0,0,0},
	{0,0,0,1,2,1,1,2,0,0,0,0,2,1,0,0,0,0,0,0,2,1,0,0,0},
	{0,0,0,1,2,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,2,1,0,0,0},
	{0,0,0,1,2,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,2,1,0,0,0},
	{0,0,0,1,2,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,2,1,0,0,0},
	{0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0},
	{0,0,0,1,2,0,0,0,0,2,2,1,1,1,1,1,1,1,1,1,2,1,0,0,0},
	{0,0,0,1,2,0,0,0,0,2,2,1,1,1,1,1,1,1,1,1,2,1,0,0,0},
	{0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0},
	{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

};

Map::Map()
{
	tierra = TextureManager::cargarTextura("Assets/tierra.png");
	cesped = TextureManager::cargarTextura("Assets/cesped.png");
	agua = TextureManager::cargarTextura("Assets/agua.png");

	//Se carga el mapa del primer nivel
	cargarMapa(nivel1);
	
	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;

	dest.x = dest.y = 0;
}

void Map::cargarMapa(int arr[20][25])
{
	for (int fila = 0; fila < 20; fila++)
	{
		for (int columna = 0; columna <25; columna++)
		{
			map[fila][columna] = arr[fila][columna];
		}
	}
}

void Map::dibujarMapa()
{
	int tipo = 0;

	for (int fila = 0; fila < 20; fila++)
	{
		for (int columna = 0; columna < 25; columna++)
		{
			tipo = map[fila][columna];

			dest.x = columna * 32;
			dest.y = fila * 32;

			switch (tipo)
			{
			case 0:
				TextureManager::dibujar(agua, src, dest);
				break;
			case 1:
				TextureManager::dibujar(cesped, src, dest);
				break;
			case 2:
				TextureManager::dibujar(tierra, src, dest);
				break;

			default:
				break;
			}
		}
	}
}