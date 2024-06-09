#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "ArbolBinario.h"


/*
Proyecto de arboles - 2024-1 - Estructura de datos
Gabriel Enrique Ulacio Rangel V-30443148
Gustavo Enrique Morillo Vetancourt V-30981606
*/

// Declaracion de funciones
void menu(int &);
void cargarArchivo(std::vector<ArbolBinario> &, bool&);
void imprimirArbol(std::vector<ArbolBinario>);
void alturaArbol(std::vector<ArbolBinario>);
void hojasArbol(std::vector<ArbolBinario>);
void equilibrioArbol(std::vector<ArbolBinario>);

int main(int argc, char** argv) {
    // Vector para almacenar los árboles binarios
    std::vector<ArbolBinario> arboles;
    int resp;
    bool archLoad=false; // Variable para verificar si se ha cargado el archivo
    
    // Bucle principal del programa
    do{
        menu(resp); // Muestra el menu y obtiene la respuesta del usuario
        switch(resp){
            case 1:
                cargarArchivo(arboles, archLoad); // Carga el archivo
                break;
            case 2:
                if (archLoad)
                    imprimirArbol(arboles); // Imprime los arboles
                else
                    std::cout << "No se ha cargado el archivo!!!" << std::endl;
                
                break;
            case 3:
                if (archLoad)
                    alturaArbol(arboles); // Muestra la altura de los arboles
                else
                    std::cout << "No se ha cargado el archivo!!!" << std::endl;
                break;
            case 4:
                if (archLoad)
                    hojasArbol(arboles); // Muestra los nodos hoja de los arboles
                else
                    std::cout << "No se ha cargado el archivo!!!" << std::endl;
                break;
            case 5:
                if (archLoad)
                    equilibrioArbol(arboles); // Verifica si los arboles estan equilibrados
                else
                    std::cout << "No se ha cargado el archivo!!!" << std::endl;
                break;
            default:
                break;
        }
        
        system("PAUSE"); // Pausa la ejecucion del programa
    } while(resp != 6); // Termina el programa si la respuesta es 6
    
    return 0;
}

// Función para verificar si un archivo existe
bool archivoExiste(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo.c_str());
    bool existe = archivo.good();
    archivo.close();
    return existe;
}

// Funcion para mostrar el menu y obtener la respuesta del usuario
void menu(int &resp){
    do{
        system("cls");
        std::cout << "	------------ PROYECTO DE ARBOL -------------" << std::endl;
        std::cout << "	1. Cargar archivo" << std::endl;
        std::cout << "	2. Imprimir Arboles" << std::endl;
        std::cout << "	3. Determinar altura de cada arbol" << std::endl;
        std::cout << "	4. Determinar nodos hojas de cada arbol" << std::endl;
        std::cout << "	5. Verificar equilibrio de cada arbol" << std::endl;
        std::cout << "	6. Salir del programa" << std::endl;
        std::cout << "	Respuesta: ";
        std::cin >> resp;
    } while(resp < 1 || resp > 6);
}

// Funcion para dividir una linea en palabras e insertarlas en un arbol binario
void dividirLineaEnPalabras(const std::string& linea, ArbolBinario& arbol){
    int inicio = 0;
    int fin = 0;
    while ((fin = linea.find(' ', inicio)) != std::string::npos) {
        if (fin != inicio) {
            arbol.insertar(linea.substr(inicio, fin - inicio).c_str());
        }
        inicio = fin + 1;
    }
    if (inicio < linea.size()) {
        arbol.insertar(linea.substr(inicio).c_str());
    }
}

// Funcion para cargar un archivo y almacenar su contenido en un vector de arboles binarios
void cargarArchivo(std::vector<ArbolBinario> &arboles, bool& _archLoad) {
    system("cls");
    std::cout << "------------- PROCESO DE CARGA -------------" << std::endl;
    
    std::string nombreArchivo = "arbol.txt";
    char opcion;

    do {
        if (archivoExiste(nombreArchivo)) {
            std::ifstream archivo(nombreArchivo.c_str());
            if (archivo.is_open()) {
                arboles.clear(); // Limpia el vector de arboles
                std::string linea;
                while (std::getline(archivo, linea)) {
                    ArbolBinario arbol;
                    dividirLineaEnPalabras(linea, arbol); // Divide la linea en palabras e inserta las palabras en el arbol
                    arboles.push_back(arbol); // Agrega el arbol al vector
                }
                archivo.close();
                std::cout << "El archivo se ha cargado correctamente." << std::endl;
                _archLoad=true; // Indica que el archivo se ha cargado correctamente
            }
            break;
        } else {
            std::cout << "El archivo " << nombreArchivo << " no existe." << std::endl;
            std::cout << "Desea ingresar otro nombre de archivo? (S/N): ";
            std::cin >> opcion;
            std::cin.ignore();

            if (opcion == 's' || opcion == 'S') {
                std::cout << "Ingrese el nombre del archivo: ";
                std::getline(std::cin, nombreArchivo);
            } else if (opcion == 'n' || opcion == 'N') {
                _archLoad=false; // Indica que el archivo no se ha cargado
                return;
            } else {
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
            }
        }
    } while (true);
}

// Funcion para imprimir los arboles
void imprimirArbol(std::vector<ArbolBinario> arboles){
    system("cls");
    std::cout << "------------- IMPRESION DE ARBOLES -------------" << std::endl;
    for(int i = 0; i < arboles.size(); i++){
        std::cout << "Arbol " << (i+1) <<": ";
        arboles[i].recorridoPostOrden(); // Imprime el arbol en recorrido postorden
    }
    std::cout << std::endl;
}

// Funcion para mostrar la altura de los arboles
void alturaArbol(std::vector<ArbolBinario> arboles){
    system("cls");
    std::cout << "------------- ALTURA DE ARBOLES -------------" << std::endl;
    for(int i = 0; i < arboles.size(); i++){
        std::cout << "Altura de Arbol " << (i+1) <<": " << arboles[i].altura() << std::endl;
        
    }
    std::cout << std::endl;
}

// Funcion para mostrar los nodos hoja de los arboles
void hojasArbol(std::vector<ArbolBinario> arboles){
    system("cls");
    std::cout << "------------- NODOS HOJA DE LOS ARBOLES -------------" << std::endl;
    for(int i = 0; i < arboles.size(); i++){
        std::cout << "Nodos hoja del Arbol " << (i+1) <<": ";
        std::vector<char*> nodosHoja = arboles[i].nodosHoja(); // Obtiene los nodos hoja del arbol
        for (int j = 0; j < nodosHoja.size(); j++){
            if (j < nodosHoja.size()-1){
                std::cout << nodosHoja[j] << ", ";
            } else{
                std::cout << nodosHoja[j] << ". "; 	
            }
            
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
}

// Funcion para verificar si los arboles estan equilibrados
void equilibrioArbol(std::vector<ArbolBinario> arboles){
    system("cls");
    std::cout << "------------- EQUILIBRIO DE ARBOLES -------------" << std::endl;
    for(int i = 0; i < arboles.size(); i++){
        std::cout << "Arbol " << (i+1) <<": ";
        if (arboles[i].esEquilibrado()) // Verifica si el arbol esta equilibrado
            std::cout << "Esta equilibrado" << std::endl;
        else
            std::cout << "No esta equilibrado" << std::endl;
    }
    std::cout << std::endl;
}

