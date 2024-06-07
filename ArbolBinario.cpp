#include "ArbolBinario.h"

ArbolBinario::ArbolBinario(){
    raiz = NULL;
}

void ArbolBinario::insertar(Nodo*& nodo, char* valor) {
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

void ArbolBinario::insertar(char* valor) {
    insertar(raiz, valor);
}

bool ArbolBinario::buscar(Nodo* nodo, char* valor) {
    if (nodo == NULL) { // Fin del arbol
        return false;
    }

    if (strcmp(valor, nodo->elemento) == 0) { // Se encuentra
        return true;
    } else if (strcmp(valor, nodo->elemento) < 0) { // El valor es menor que el del nodo
        return buscar(nodo->izquierda, valor);
    } else { // El valor es mayor que el del nodo
        return buscar(nodo->derecha, valor);
    }
}

bool ArbolBinario::buscar(char* valor) {
    return buscar(raiz, valor);
}

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

int ArbolBinario::altura(Nodo* nodo) {
    if (nodo == NULL) {
        // La altura de un árbol vacío es 0
        return 0;
    } else {
        // Calcula la altura de cada subárbol
        int alturaIzquierda = altura(nodo->izquierda);
        int alturaDerecha = altura(nodo->derecha);

        // La altura del árbol es el máximo de las alturas de los subárboles, más 1
        return std::max(alturaIzquierda, alturaDerecha) + 1;
    }
}

int ArbolBinario::altura() {
    return altura(raiz);
}

int ArbolBinario::nivel(Nodo* nodo, char* valor, int nivelActual) {
    if (nodo == NULL) {
        // El elemento no se encuentra en el árbol
        return -1;
    }

    if (strcmp(valor, nodo->elemento) == 0) {
        // Hemos encontrado el elemento
        return nivelActual;
    }

    int nivelIzquierdo = nivel(nodo->izquierda, valor, (nivelActual + 1));
    if (nivelIzquierdo != -1) {
        // El elemento se encuentra en el subárbol izquierdo
        return nivelIzquierdo;
    } else {
        // El elemento se encuentra en el subárbol derecho (o no está en el árbol)
        return nivel(nodo->derecha, valor, nivelActual + 1);
    }
}

int ArbolBinario::nivel(char* valor) {
    return nivel(raiz, valor, 1);
}


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
ArbolBinario::Nodo* ArbolBinario::maximoNodo(Nodo* nodo) { 
	Nodo* actual = nodo;
	// Encuentra el nodo más a la derecha
	while (actual && actual->derecha != NULL)
	    actual = actual->derecha;
	
	return actual;
}
void ArbolBinario::eliminar(char* valor) {
    eliminar(raiz, valor);
}

void ArbolBinario::vaciar(Nodo*& nodo) {
    if (nodo != NULL) {
        // Vacía los subárboles izquierdo y derecho
        vaciar(nodo->izquierda);
        vaciar(nodo->derecha);

        // Borra el nodo
        delete nodo;
        nodo = NULL;
    }
}

void ArbolBinario::vaciar() {
    vaciar(raiz);
}
