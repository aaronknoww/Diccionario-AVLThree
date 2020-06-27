//#include "pch.h"
#include"Diccionario.h"
#include <iostream>
#include <cmath>

using namespace std;

bool Diccionario::_insertarAux(nodoArbol*& nodo, int elem, float dato)
{
	if (nodo != nullptr)
	{
		if (nodo->key > elem)//moverse a la izquierda en el arbol
		{		
			_insertarAux(nodo->izq, elem, dato);//<--- Despues de ejecutar esta linea se empieza a regresar el puntero
			_corregirNodo(nodo);
		}
		else if (nodo->key < elem) //moverse a la derecha en el arbol
		{
			_insertarAux(nodo->der, elem, dato);
			_corregirNodo(nodo);
		}
		else// si el dato es igual entonces no se puede insterar
			return(false);
	}
	else
	{
		nodo = new nodoArbol(elem,dato);
		return true;

	}
	
}

void Diccionario::_mostrarAux(nodoArbol*& raiz, int cont)
{

	if (raiz != nullptr)// Verifica que el arbol no este vacio. 
	{
		_mostrarAux(raiz->der, cont + 1); // Se imprime primero la parte dercha del arbol 
		for (int e = 0; e < cont; e++)// El contador es para saber cuantos espacios imprimir
			cout << "     ";
		cout << raiz->key << endl;
		//cout << raiz->key<<"->" << raiz->dato << endl; por si se requiere mostrar el dato del nodo
		_mostrarAux(raiz->izq, cont + 1); // Imprimir parte izquirda del arbol

	}
	else
	{
		return; // Si esta vacio el arbol no se imprime nada
	}
	
}

int Diccionario::_balnceCalculo(nodoArbol *& nodo)// Funcion para saber si el nodo esta balanceado b
{
	int cder = 0;
	int cizq = 0;
	cder = _calcularAltura(nodo->der, 0,0,0);
	cizq = _calcularAltura(nodo->izq, 0,0,0);
	nodo->balance = cder - cizq;// Guarda el balance en el nodo solicitado;
	return cder-cizq;

}

int Diccionario::_calcularAltura(nodoArbol*& lado,int contador, int contaizq, int contader)// Calcular la altura del sub arbol recibido.
{ 
	if (lado == nullptr)
		return contador;
	else if (lado->der && lado ->izq)// Para saber si el nodo tiene dos hijos
	{
		contaizq = _calcularAltura(lado->izq, contador + 1, contaizq + 1, contader);// Recorre primero todo lo que esta a la izquierda del nodo.
		contador = 0;//<------------------------------------------------------------ Reinicio la varible para que no afecte el valor cuando regrese el caso de salida linea 104.
		contader = _calcularAltura(lado->der, contador + 1, contaizq, contader + 1);// Recorre todo lo que esta en el hijo derecho del nodo.
		if (contaizq >= contader)
			return contaizq;
		else
			return contader;
		
	}
	else if(lado->der)
	{
		contader = _calcularAltura(lado->der, contador + 1, contaizq, contader + 1);
		contador = contader;
				
	}
	else if(lado->izq)
	{
		contaizq = _calcularAltura(lado->izq, contador + 1, contaizq + 1, contader);
		contador = contaizq;
	}
	else
	{
		return contador+1;
	}
	return contador;
}

void Diccionario::_rotacionIzquierda(nodoArbol*& nodo)
{
	nodoArbol* anterior = _anteriorBus(p_inicio, nodo->key);// Se neceista el nodo anterior para poder hacer la concexion con el resto del arbol

	if (anterior==nodo)// En el caso que no haya nodo anterior
	{
		nodoArbol* aux = nodo->der;
		nodo->der = aux->izq;
		aux->izq = nodo;
		p_inicio = aux; // Para volver el auxilar en el nodo raiz

	}
	else
	{
		
		nodoArbol* aux = anterior->der;
		anterior->der = aux->der; // Conecta el resto del arbol con el nodo que va arreglar el problema
		aux->der = aux->der->izq; // Conecta el el hijo derecho del nodo en conflicto con el hijo izquierdo del nodo solucion.
		anterior->der->izq = aux; // Transforma en nodo hijo izquierdo al nodo en conflicto.
		return;

	}
	
}

void Diccionario::_rotacionDerecha(nodoArbol*&nodo)
{
	nodoArbol* anterior = _anteriorBus(p_inicio, nodo->key);// Se neceista el nodo anterior para poder hacer la concexion con el resto del arbol

	if (anterior == nodo)// En el caso que no haya nodo anterior
	{
		nodoArbol* aux = nodo->izq;
		nodo->izq = aux->der;
		aux->der = nodo;
		p_inicio = aux; // Para volver el auxilar en el nodo raiz

	}
	else
	{
		nodoArbol* aux = anterior->izq;
		anterior->izq = aux->izq;
		aux->izq = aux->izq->der;
		anterior->izq->der = aux;
		return;
	}
	
}

void Diccionario::_rotacionDerechaIzq(nodoArbol*& nodo) // Funcion para arreglar un codo.
{
	nodoArbol* anterior = _anteriorBus(p_inicio, nodo->key);
	
	if(anterior==nodo)
	{
		nodoArbol* aux = nodo->der;
		nodo->der = aux->izq;
		aux->izq = aux->izq->der;
		nodo->der->der = aux;
		_rotacionIzquierda(nodo);
	}
	else
	{
		
		nodoArbol* aux = anterior->der->der;// Avanzo dos lugaraes al nodo para no perder la direccion del que voy a deconetar. 
		anterior->der->der = aux->izq;
		aux->izq = aux->izq->der;
		anterior->der->der->der = aux;
		_rotacionIzquierda(anterior->der);

	}
	
	return;
}

void Diccionario::_rotacionIzquierdaDer(nodoArbol*& nodo)
{
	nodoArbol* anterior = _anteriorBus(p_inicio, nodo->key);

	if (anterior == nodo)
	{
		nodoArbol* aux = nodo->izq;
		nodo->izq = aux->der;
		aux->der = aux->der->izq;
		nodo->izq->izq = aux;
		_rotacionDerecha(nodo);
	}
	else
	{
		
		nodoArbol* aux = anterior->izq->izq;
		anterior->izq->izq = aux->der;
		aux->der = aux->der->izq;
		anterior->izq->izq->izq = aux;
		_rotacionDerecha(anterior->izq);
	}

	return;
}

void Diccionario::_corregirNodo(nodoArbol*& nodo)
{
	
		
	if (abs(_balnceCalculo(nodo)) < 2)// Al llamar la funcion _balanceCalculo, ahi mismo se asigna el balance al nodo
		return;
	else if(nodo->balance>0)//nodo se va a trabajar por el hijo derecho
	{
		_balnceCalculo(nodo->der);// Esta llamada a esta fincion es necesaria para que funcione _corregirdiccionario
		switch (nodo->der->balance)
		{
		case 1://caso 2, 1 
			_rotacionIzquierda(nodo); 
			return;
			break;
		case -1: // 2, -1 se necesita arregalar un codo
			_rotacionDerechaIzq(nodo);
			return;
			break;
		case 0:
			_rotacionDerechaIzq(nodo);
		default:
			break;
		}		
	}
	else// trabajar el hijo izquierdo del nodo
	{
		_balnceCalculo(nodo->izq);// Esta llamada a esta fincion es necesaria para que funcione _corregirdiccionario
		
		switch (nodo->izq->balance)
		{
		case -1://caso -2	-1
			_rotacionDerecha(nodo);
			return;
			break;
		case 1://-2,1
			_rotacionIzquierdaDer(nodo);
			return;
			break;
		case 0:
			_rotacionIzquierdaDer(nodo);
		default:
			break;
		}

	}
	return;
}

Diccionario::nodoArbol*& Diccionario::_anteriorBus(nodoArbol*& anterior, int elem)//Debe de recibir el puntero inicio de la clase
{
	if (anterior == nullptr)// Para saber si el arbol esta vacio
		return anterior;
	else if (anterior->key == elem)// Indica que el dato buscado por el usuario si se encontro
		return anterior;
	else if (anterior->key > elem)// estas ultimas linas son para saber por que lado se debe buscar
	{
		if (anterior->izq->key == elem)
			return anterior;
		else
			_anteriorBus(anterior->izq, elem);//moverse por la izquierda
	}
	else
	{
		if (anterior->der->key == elem)
			return anterior;
		else
			_anteriorBus(anterior->der, elem);//moverse por la derecha
	}
	
}

Diccionario::nodoArbol*& Diccionario::_preDecEnOrden(nodoArbol*& predecesor) // Debe recibir el hijo izquierdo del nodo a borrar
{
	if (predecesor == nullptr)
		return predecesor;
	else if(predecesor->der)
	{		
		return _preDecEnOrden(predecesor->der);	
		
	}
	else
	{
		return predecesor;
	}
	
}

bool Diccionario::_eliminarAux(nodoArbol*&nodo, int elemento)
{
	if (nodo == nullptr)
		return false;
	else if (nodo->key == elemento)// Ya se encontro el elemento
	{
		if (nodo->izq && nodo->der)// En el caso de que el nodo tenga dos hijos
		{
			
			nodoArbol* pre = _preDecEnOrden(nodo->izq);
			nodoArbol* ant = _anteriorBus(p_inicio, pre->key);
			
			if (ant->key > pre->key)// Para conectar al hijo izquierdo con el siguiente nodo
			{
				nodo->key = pre->key;
				nodo->dato = pre->dato;
				ant->izq = pre->izq;
				delete pre;
				pre = nullptr;
				return true;
			}
			else // Para conectar con el hiko derecho
			{
				nodo->key = pre->key;
				nodo->dato = pre->dato;
				ant->der = pre->izq;
				delete pre;
				pre = nullptr;
				return true;
			}
			_corregirDiccionario(p_inicio, ant->key);
			
		}
		else if (nodo->izq)// El nodo solo tiene hijo izquierdo
		{
			nodo->key = nodo->izq->key;
			nodo->dato = nodo->izq->dato;
			delete nodo->izq;
			nodo->izq = nullptr;
			_corregirDiccionario(p_inicio, nodo->key);
			return true;
		}
		else if (nodo->der)//El nodo solo tiene hijo derecho
		{
			nodo->key = nodo->der->key;
			nodo->dato = nodo->der->dato;
			delete nodo->der;
			nodo->der = nullptr;
			return true;
			_corregirDiccionario(p_inicio, nodo->key);
		}
		else
		{
			nodoArbol* ant = _anteriorBus(p_inicio, elemento);

			if (ant == nodo)// Se borra el nodo raiz del arbol
			{
				delete nodo;
				nodo = nullptr;
				return true;
			}
			else // Se borra un nodo hoja
			{
				if (ant->key > nodo->key)
					ant->izq = nullptr;// Para no generar error al borrar el hijo izquierdo del nodo
				else
					ant->der = nullptr;// Para no generar error al borrar el hijo derecho del nodo
				nodo = nullptr;
				_corregirDiccionario(p_inicio, ant->key);
				return true;
			}

		}		
			
	}
	else if (nodo->key>elemento)
	{
		_eliminarAux(nodo->izq, elemento);
	}
	else if(nodo->key<elemento)
	{
		_eliminarAux(nodo->der, elemento);
	}
	else
	{
		return false; // No se encontro el elemento o pudes mandar una excepcion.
	}
}

bool Diccionario::_corregirDiccionario(nodoArbol*& reparar,int key)// Recibe el dato llave del nodo anterior al nodo que se borro y el puntero incio.
{
	if (reparar==nullptr)
		return false;
	else if (reparar->key==key)
	{
		_corregirNodo(reparar);
		return true;
	}
	else if (key>reparar->key)
	{
		_corregirDiccionario(reparar->izq, key);
		_corregirNodo(reparar);
		return true;
	}
	else
	{
		_corregirDiccionario(reparar->der, key);
		_corregirNodo(reparar);
		return true;
	}	
	
}

// typename Dictionary<K, D>::TreeNode*& Dictionary<K, D>::_find(

