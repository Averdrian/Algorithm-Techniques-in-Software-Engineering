#include <iostream>
#include <vector>

/*
Algoritmo que reconoce el patron que se repite en una pila de elementos
No se asegura que la ultima aparicion del patron este completa
*/

bool resuelveCaso() {

	//Declaracion y entrada de datos (por consola)
	int nDatos;
	std::cin >> nDatos;
	if (nDatos <= 0) return false;
	std::vector<int> datos(nDatos);
	for (int i = 0; i < datos.size(); ++i)
		std::cin >> datos.at(i);
	
	//Inicializamos el tamaño del patron con un minimo de un elemento y el pivote al primer elemento
	int tamPatron = 1;
	int pivote = datos.at(0);

	//O(n) n => nº elementos del vector
	for (int i = 1; i < datos.size(); ++i) {
		if (datos.at(i) != pivote) ++tamPatron;
		//Cuando encuentra un elemento igual al primer elemento del patron busca si lo cumple
		else {
			bool encontrado = false;
			int auxRecorrido = -1;
			//Si coinciden elemento a elemento se mantendra en el while hasta que descubra que no es patron o se acaben los elementos
			while (!encontrado &&  i < datos.size()) {
				if (datos.at(i) == datos.at(++auxRecorrido % tamPatron)) ++i;
				else {
					tamPatron = i + 1;
					encontrado = true;
				}
			}
		}

	}
	
	//Salida (por consola) de los elementos del patron
	for (int i = 0; i < tamPatron; ++i) {
		std::cout << datos.at(i) << " ";
	}
	std::cout << "\n";

	return true;
}


void main() {
	while (resuelveCaso());
}