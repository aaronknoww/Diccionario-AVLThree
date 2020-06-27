#include "Diccionario.h"

Diccionario::Diccionario()
{
	p_inicio = nullptr;
	return;
}

Diccionario::~Diccionario()
{
	_seekAndDestroy(p_inicio);
	p_inicio = nullptr;
	return;
}

bool Diccionario::insertar(int key, float dato)
{
	return _insertarAux(p_inicio, key, dato);
	
}

bool Diccionario::eliminarNodo(int elemento)
{

	return _eliminarAux(p_inicio, elemento);
	
}

void Diccionario::mostarDiccionario()
{
	int cont = 0;
	_mostrarAux(p_inicio,cont);
	return;
}
void Diccionario::_seekAndDestroy(nodoArbol*& borrar)
{
	if (borrar == nullptr)
	{
		return;
	}
	else
	{
		_seekAndDestroy(borrar->izq);
		_seekAndDestroy(borrar->der);
		borrar->izq = nullptr;// Para que ningun puntero se quede apuntando a direcciones vacias
		borrar->der = nullptr;
		delete borrar;
		return;
	}
	return;
}
