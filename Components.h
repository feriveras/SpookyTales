#pragma once
#include "ECS.h"

class picisionComponente : public Componente
{
//Se declaran las pocisiones
private:
	int xpos;
	int ypos;

public:
	int x() { return xpos; }
	int y() { return ypos; }

	void iniciar() override 
	{
		xpos = 0;
		ypos = 0;
	}

	//Se actualizan las pocisiones incrementandolas
	void actualizar() override
	{
		xpos++;
		ypos++;
	}

	void setPosc(int x, int y)
	{
		xpos = x;
		ypos = y;
	}


};
