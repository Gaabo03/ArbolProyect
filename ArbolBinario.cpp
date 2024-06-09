#include "ArbolBinario.h"

// Constructor de la clase ArbolBinario. Inicializa la raiz del arbol a NULL.
ArbolBinario::ArbolBinario(){
    raiz = NULL;
}

// Función para insertar un nuevo nodo en el arbol. Si el árbol esta vacío, crea un nuevo nodo y lo asigna a la raiz. 
// Si el arbol no está vacío, compara el valor con el nodo actual y decide si insertarlo a la izquierda o a la derecha.
void ArbolBinario::insertar(Nodo*& nodo,const char* valor) {
    if (nodo == NULL) {
        nodo = new Nodo;
        nodo->elemento = new char[strlen(valor) + 1];
        strcpy(nodo->elemento, valor);
        nodo->izquierda = NULL;
        nodo->derecha = NULL;
    } else if (strcmp(valor, nodo->elemento) < 0) {
        insertar(nodo->izquierda, valor);
    } else if (strcmp(valor, nodo->elemento) > 0) {
        insertar(nodo->derecha, valor);
    }
}

void ArbolBinario::insertar(const char* valor) {
    insertar(raiz, valor);
}

// Funcion para buscar un valor en el arbol. Si el arbol esta vacio, devuelve false. 
// Si no, compara el valor con el nodo actual y decide si buscar a la izquierda o a la derecha.
bool ArbolBinario::buscar(Nodo* nodo, char* valor) {
    if (nodo == NULL) { 
        return false;
    }

    if (strcmp(valor, nodo->elemento) == 0) {
        return true;
    } else if (strcmp(valor, nodo->elemento) < 0) { 
        return buscar(nodo->izquierda, valor);
    } else {
        return buscar(nodo->derecha, valor);
    }
}

bool ArbolBinario::buscar(char* valor) {
    return buscar(raiz, valor);
}

// Funciones para recorrer el arbol en preorden, inorden y postorden.
void ArbolBinario::recorridoPreOrden(Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }

    std::cout << nodo->elemento << " ";
    recorridoPreOrden(nodo->izquierda);
    recorridoPreOrden(nodo->derecha);
}

void ArbolBinario::recorridoPreOrden() {
    recorridoPreOrden(raiz);
    std::cout << std::endl;
}

void ArbolBinario::recorridoInOrden(Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }

    recorridoInOrden(nodo->izquierda);
    std::cout << nodo->elemento << " ";
    recorridoInOrden(nodo->derecha);
}

void ArbolBinario::recorridoInOrden() {
    recorridoInOrden(raiz);
    std::cout << std::endl;
}

void ArbolBinario::recorridoPostOrden(Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }

    recorridoPostOrden(nodo->izquierda);
    recorridoPostOrden(nodo->derecha);
    std::cout << nodo->elemento << " ";
}

void ArbolBinario::recorridoPostOrden() {
    recorridoPostOrden(raiz);
    std::cout << std::endl;
}

// Funcion para calcular la altura del arbol.
int ArbolBinario::altura(Nodo* nodo) {
    if (nodo == NULL) {
        return 0;
    } else {
        int alturaIzquierda = altura(nodo->izquierda);
        int alturaDerecha = altura(nodo->derecha);

        return std::max(alturaIzquierda, alturaDerecha) + 1;
    }
}

int ArbolBinario::altura() {
    return altura(raiz);
}

// Funcion para calcular el nivel de un nodo en el arbol.
int ArbolBinario::nivel(Nodo* nodo, char* valor, int nivelActual) {
    if (nodo == NULL) {
        return -1;
    }

    if (strcmp(valor, nodo->elemento) == 0) {
        return nivelActual;
    }

    int nivelIzquierdo = nivel(nodo->izquierda, valor, (nivelActual + 1));
    if (nivelIzquierdo != -1) {
        return nivelIzquierdo;
    } else {
        return nivel(nodo->derecha, valor, nivelActual + 1);
    }
}

int ArbolBinario::nivel(char* valor) {
    return nivel(raiz, valor, 1);
}

// Funcion para obtener todos los nodos hoja del arbol.
void ArbolBinario::nodosHoja(Nodo* nodo, std::vector<char*>& hojas) {
    if (nodo == NULL) {
        return;
    }

    if (nodo->izquierda == NULL && nodo->derecha == NULL) {
        hojas.push_back(nodo->elemento);
    } else {
        nodosHoja(nodo->izquierda, hojas);
        nodosHoja(nodo->derecha, hojas);
    }
}

std::vector<char*> ArbolBinario::nodosHoja() {
    std::vector<char*> hojas;
    nodosHoja(raiz, hojas);
    return hojas;
}

int valorAbsoluto(int x) {
    return (x < 0) ? -x : x;
}

// Funcion para verificar si el arbol esta equilibrado.
bool ArbolBinario::esEquilibrado(Nodo* nodo) {
    if (nodo == NULL) {
        return true;
    }

    int alturaIzquierda = altura(nodo->izquierda);
    int alturaDerecha = altura(nodo->derecha);

    if (valorAbsoluto(alturaIzquierda - alturaDerecha) <= 1 &&
        esEquilibrado(nodo->izquierda) &&
        esEquilibrado(nodo->derecha)) {
        return true;
    }

    return false;
}


bool ArbolBinario::esEquilibrado() {
    return esEquilibrado(raiz);
}

// Funcion para eliminar un nodo del arbol.
void ArbolBinario::eliminar(Nodo*& nodo, char* valor) {
    if (nodo == NULL) {
        return;
    }

    if (strcmp(valor, nodo->elemento) < 0) {
        eliminar(nodo->izquierda, valor);
    } else if (strcmp(valor, nodo->elemento) > 0) {
        eliminar(nodo->derecha, valor);
    } else {
        if (nodo->izquierda == NULL && nodo->derecha == NULL) {
            delete[] nodo->elemento;
            delete nodo;
            nodo = NULL;
        } else if (nodo->izquierda == NULL) {
            Nodo* temp = nodo->derecha;
            delete[] nodo->elemento;
            delete nodo;
            nodo = temp;
        } else if (nodo->derecha == NULL) {
            Nodo* temp = nodo->izquierda;
            delete[] nodo->elemento;
            delete nodo;
            nodo = temp;
        } else {
            Nodo* temp = maximoNodo(nodo->izquierda);

            delete[] nodo->elemento;
            nodo->elemento = new char[strlen(temp->elemento) + 1];
            strcpy(nodo->elemento, temp->elemento);

            eliminar(nodo->izquierda, temp->elemento);
        }
    }
}

void ArbolBinario::eliminar(char* valor) {
    eliminar(raiz, valor);
}

// Funcion para obtener el nodo con el valor maximo en el arbol.
ArbolBinario::Nodo* ArbolBinario::maximoNodo(Nodo* nodo) { 
	Nodo* actual = nodo;
	while (actual && actual->derecha != NULL)
	    actual = actual->derecha;
	
	return actual;
}

// Funcion para vaciar el arbol.
void ArbolBinario::vaciar(Nodo*& nodo) {
    if (nodo != NULL) {
        vaciar(nodo->izquierda);
        vaciar(nodo->derecha);

        delete nodo;
        nodo = NULL;
    }
}

void ArbolBinario::vaciar() {
    vaciar(raiz);
}
