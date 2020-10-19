#pragma once
#include "ECS.h"

class picisionComponente : public Componente
{
//Se declaran las pocisiones
private:
	int xpos;
	int ypos;
	int zpos;
	int apos;

public:
	int x() { return xpos; }
	int y() { return ypos; }
	int z() { return zpos; }
	int a() { return apos; }

	void iniciar() override 
	{
		xpos = 0;
		ypos = 0;
		zpos = 0;
		apos = 0;
	}

	//Se actualizan las pocisiones incrementandolas
	void actualizar() override
	{
		xpos++;
		ypos++;
		zpos++;
		apos++;
	}

	void setPosc(int x, int y, int z, int a)
	{
		xpos = x;
		ypos = y;
		zpos = z;
		apos = a;
	}
};
