#pragma once
//Recursos a utilizar 
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>


class Componente;
class Entidad;

//Clase que contiene todos los componentes
//Se declara un ID para los componentes que se van a utilizar 
using ComponenteID = std::size_t;

inline  ComponenteID getComponenteTipoID()
{
	static ComponenteID lastID = 0;
	//Se aumenta cada vez que se llama
	return lastID++;

}

template <typename T> inline ComponenteID getComponenteTipoID() noexcept
{
	static ComponenteID tipoID = getComponenteTipoID();
	return tipoID;
}

//Verficar si una entidad tiene un componente relacionado
constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset <maxComponents>;
using ComponentArray = std::array<Componente*, maxComponents>;

//Para saber si un  tiene una seleccion de componentes se compara si los tiene o no, se pasa
//por parametro y si es igual a las entidades se sabe que tiene los componentes necesarios 

class Componente
{
public:
	Entidad* entidad;
	virtual void iniciar() {}
	virtual void actualizar() {}
	virtual void dibujar() {}

	virtual ~Componente() {}
};

class Entidad
{
private:

	bool activo = true;
	std::vector<std::unique_ptr< Componente >> componentes;

	ComponentArray componenteArreglo;
	ComponentBitSet componenteBitSet;

public:
	void actualizar()
	{
		for (auto& c : componentes) c->actualizar();
		for (auto& c : componentes) c->dibujar();
	}

	void dibujar() {}
	bool estaActivo() const { return activo; }
	void destroy() { activo = false; }

	template <typename T> bool hasComponente() const
	{
		return componenteBitSet[getComponenteTipoID<T>];
	}

	template <typename T, typename... TArgs>
	T& agregarComponente(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entidad = this;
		std::unique_ptr<Componente> uPtr{ c };
		componentes.emplace_back(std::move(uPtr));

		//Cuando se agregue una pocision de componente se pondra al lado del arreglo
		componenteArreglo[getComponenteTipoID<T>()] = c;
		componenteBitSet[getComponenteTipoID<T>()] = true;

		c->iniciar();
		return *c;
	}

	template <typename T> T& getComponente() const
	{
		auto ptr(componenteArreglo[getComponenteTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

};

//Clase que contiene todas las entidades
class Administrador
{
private:
	std::vector<std::unique_ptr<Entidad>> entidades;

public:
	void actualizar()
	{
		for (auto& e : entidades) e->actualizar();
	}
	void dibujar() 
	{
		for (auto& e : entidades) e->dibujar();
	}
	void refrescar()
	{
		entidades.erase(std::remove_if(std::begin(entidades), std::end(entidades),
			[](const std::unique_ptr<Entidad>& mEntidad)
			{
				return !mEntidad->estaActivo();
			}),
			std::end(entidades));
	}

	Entidad& agregarEntidad()
	{
		Entidad* e = new Entidad();
		std::unique_ptr <Entidad > uPtr{ e };
		entidades.emplace_back(std::move(uPtr));
		return *e;

	}
};



