#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include "cola_prioridad.h"

using namespace std;

int main(int argc, char *argv[]) {
	
	ColaPrioridad cola(6);
	cola.insertar(5);
	cola.insertar(7);
	cola.insertar(8);
	cola.insertar(2);
	cola.insertar(3);
	//cola.insertar(1);
	cola.imprimirArreglo();
    system("PAUSE");
    return EXIT_SUCCESS;
}
