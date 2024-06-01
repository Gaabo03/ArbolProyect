#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <cstring>

class ArbolBinario{

public:
	struct Nodo{
		char* elemento;
		Nodo *izquierda;
		Nodo *derecha;
	};
	
	Nodo *raiz;
	
	ArbolBinario();
    void insertar(char* valor);
    void insertar(Nodo*& nodo, char* valor);
    bool buscar(char* valor);
    bool buscar(Nodo* nodo, char* valor);
    void recorridoPreOrden();
    void recorridoPreOrden(Nodo* nodo);
    void recorridoInOrden();
    void recorridoInOrden(Nodo* nodo);
    void recorridoPostOrden();
    void recorridoPostOrden(Nodo* nodo);
    void imprimir();
    int altura();
    int altura(Nodo* nodo);
    int nivel(char* valor);
    int nivel(Nodo* nodo, char* valor, int nivelActual);
	void eliminar(char* valor);
    void eliminar(Nodo*& nodo, char* valor);
    Nodo* maximoNodo(Nodo* nodo); 
    void vaciar(Nodo*& nodo);
    void vaciar();
};

#endif
