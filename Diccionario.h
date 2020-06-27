#pragma once

class Diccionario
{
public:
	Diccionario();
	~Diccionario();
	bool insertar(int, float);
	bool eliminarNodo(int);
	void mostarDiccionario();
	


private:
	class nodoArbol
	{
	public:

		nodoArbol(int key, float dato) : key(key), dato(dato), izq(nullptr), der(nullptr), balance(0) {}
		//~nodoArbol();

		int key; // sirve para moverse en el diccionario, es la clave de los nodos.
		float dato;// Puede ser cualquier tipo de dato o clase.
		int balance;
		nodoArbol* izq;
		nodoArbol* der;

	private:

	};

	nodoArbol* p_inicio;
		
	//---------------FUNCIONES AUXILIARES NO DIPONIBLES PARA EL USUARIO--------------------------////
	bool _insertarAux(nodoArbol*&, int, float);
	void _mostrarAux( nodoArbol*&, int);
	int _balnceCalculo(nodoArbol*&);
	int _calcularAltura(nodoArbol*&,int, int, int);// Para analizar un lado del sub arbol y regresa su altura.
	void _rotacionDerecha(nodoArbol*&);
	void _rotacionIzquierda(nodoArbol*&);
	void _rotacionDerechaIzq(nodoArbol*&);
	void _rotacionIzquierdaDer(nodoArbol*&);
	void _corregirNodo(nodoArbol*&);//<-------- Mantiene balanceado el AVL arbol solo cuando inserta.
	nodoArbol*& _anteriorBus(nodoArbol*&,int);
	nodoArbol*& _preDecEnOrden(nodoArbol *&);
	bool _eliminarAux(nodoArbol*&, int);
	bool _corregirDiccionario(nodoArbol*&, int);
	void _seekAndDestroy(nodoArbol *&); // Para liberar toda la memoria dinamica

};

