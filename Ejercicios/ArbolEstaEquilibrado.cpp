#include "bintree.h"

struct tDatos {
	tDatos() : altura(0), esEquilibrado(true) {};
	tDatos(const int &altura, const bool &esEquilibrado) : altura(altura), esEquilibrado(esEquilibrado){};
	short int altura = 0;
	bool esEquilibrado = true;
};


template<typename T>
tDatos datosArbol(bintree<T>const & arbol) {
	if (arbol.left().empty() && arbol.right().empty()) return { 1,true };
	tDatos iz, dr,sol;
	if (!arbol.left().empty()) iz = datosArbol(arbol.left());
	if (!arbol.right().empty()) dr = datosArbol(arbol.right());
	
	sol.altura = (iz.altura > dr.altura) ? iz.altura + 1 : dr.altura + 1;
	int diferencia = iz.altura - dr.altura;
	sol.esEquilibrado = iz.esEquilibrado && dr.esEquilibrado && (diferencia <= 1 && diferencia >= -1);

	return sol;
}

void main() {
	int nCasos;
	std::cin >> nCasos;
	for (int i = 0; i < nCasos; ++i) {
		bintree<char> arbol = leerArbol('.');
		if (arbol.empty() || datosArbol(arbol).esEquilibrado) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
}