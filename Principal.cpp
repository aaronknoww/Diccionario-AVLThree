//#include "pch.h"
#include "Diccionario.h"
#include <iostream>
#include <stdlib.h>



using namespace std;


int main()
{

	Diccionario arbol;

	arbol.insertar(10, 12.48);
	arbol.insertar(7, 2.48);
	arbol.insertar(12, 2.48);
	arbol.insertar(9, 2.48);
	/*arbol.insertar(11, 2.48);
	arbol.insertar(13, 2.48);
	arbol.insertar(6, 2.48);
	arbol.insertar(8, 2.48);*/


	cout << "\n\n";

	arbol.mostarDiccionario();
	//arbol.eliminarNodo(8);
	//arbol.eliminarNodo(9);
	//arbol.eliminarNodo(6);
	/*arbol.eliminarNodo(11);
	cout << "\n\n"; cout << "\n\n";
	arbol.mostarDiccionario();
	arbol.eliminarNodo(13);
	cout << "\n\n"; cout << "\n\n";
	arbol.mostarDiccionario();*/
	
	//codo izquierdo debajo de un nodo
	/*arbol.insertar(10, 1.23);
	arbol.insertar(15, 2.48);
	arbol.insertar(8, 2.48);
	arbol.insertar(9, 2.48);
	arbol.insertar(20, 34.8);
	arbol.insertar(2, 1.23);
	arbol.insertar(13, 2.48);
	arbol.insertar(30, 2.48);

	arbol.insertar(1, 2.48);
	arbol.insertar(5, 2.48);
	arbol.insertar(6, 34.8);
	arbol.mostarDiccionario();
	arbol.eliminarNodo(8);
	arbol.eliminarNodo(9);
	arbol.eliminarNodo(6);
	arbol.eliminarNodo(18);
	arbol.eliminarNodo(2);
	arbol.eliminarNodo(5);
	arbol.mostarDiccionario();*/




	//codo izquierdo en la raiz
	/*arbol.insertar(20, 12.12);
	arbol.insertar(10, 14.12);
	arbol.insertar(25, 1.34);
	arbol.insertar(5, 3.23);
	arbol.insertar(15, 14.12);
	arbol.insertar(18, 1.34);
	arbol.insertar(14, 3.23);*/

	//arbol con codo derecho debajo de un nodo
	/*arbol.insertar(10, 1.23);
	arbol.insertar(15, 2.48);
	arbol.insertar(5, 2.48);
	arbol.insertar(6, 2.48);
	arbol.insertar(20, 34.8);
	arbol.insertar(3, 1.23);
	arbol.insertar(13, 2.48);

	arbol.insertar(19, 2.48);
	arbol.insertar(30, 2.48);
	arbol.insertar(2, 2.48);
	arbol.insertar(18, 34.8);*/

	//codo con la en la sima
	/*arbol.insertar(10, 12.12);
	arbol.insertar(5, 14.12);
	arbol.insertar(15, 1.34);
	arbol.insertar(20, 3.23);
	arbol.insertar(13, 14.12);
	arbol.insertar(12, 1.34);
	arbol.insertar(14, 3.23);*/

	
	//stick izquierdo
	/*arbol.insertar(10, 1.23);
	arbol.insertar(5, 2.48);
	arbol.insertar(4, 5.51);
	arbol.insertar(3, 5.51);*/

	// stick derecho
	/*arbol.insertar(10, 1.23);
	arbol.insertar(15, 2.48);
	arbol.insertar(20, 5.51);
	arbol.insertar(25, 5.51);*/
	


	/*arbol.insertar(3, 1.23);
	arbol.insertar(7, 2.48);
	arbol.insertar(2, 2.48);
	arbol.insertar(4, 1.23);
	arbol.insertar(6, 2.48);
	arbol.insertar(8, 34.8);

	arbol.insertar(13, 1.23);
	arbol.insertar(17, 2.48);
	arbol.insertar(12, 2.48);
	arbol.insertar(14, 1.23);
	arbol.insertar(16, 2.48);
	arbol.insertar(18, 34.8);*/
	
//	cout << "\n\n el balance es " << arbol._balnceCalculo() << endl;

	system("pause > null");
	return 0;
}