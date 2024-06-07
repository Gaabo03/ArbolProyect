#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "ArbolBinario.h"

void menu(int &);
void cargarArchivo(std::vector<ArbolBinario> &, bool&);
void alturaArbol();
void hojasArbol();
void equilibrioArbol();

int main(int argc, char** argv) {
	std::vector<ArbolBinario> arboles;
	int resp;
	bool archLoad=false;
	
	do{
		menu(resp);
		switch(resp){
			case 1:
				cargarArchivo(arboles, archLoad);
				break;
			case 2:
				if (archLoad) {
				    alturaArbol();
				} else {
				    std::cout << "No se ha cargado el archivo!!!" << std::endl;
				    system("PAUSE");
				}
				break;
			case 3:
				hojasArbol();
				break;
			case 4:
				equilibrioArbol();
				break;
			case 5:
				equilibrioArbol();
				break;
			default:
				break;
		}
	} while(resp != 6);
	
	
	return 0;
}

bool archivoExiste(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo.c_str());
    bool existe = archivo.good();
    archivo.close();
    return existe;
}

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

void dividirLineaEnPalabras(const std::string& linea, std::vector<std::string>& palabras){
    int inicio = 0;
    int fin = 0;
    while ((fin = linea.find(' ', inicio)) != std::string::npos) {
        if (fin != inicio) {
            palabras.push_back(linea.substr(inicio, fin - inicio));
        }
        inicio = fin + 1;
    }
    if (inicio < linea.size()) {
        palabras.push_back(linea.substr(inicio));
    }
}

void cargarArchivo(std::vector<ArbolBinario> &arboles, bool& _archLoad) {
    system("cls");
    std::cout << "------------- PROCESO DE CARGA -------------" << std::endl;
    
    std::string nombreArchivo = "arbol.txt";
    char opcion;

    do {
        if (archivoExiste(nombreArchivo)) {
            std::ifstream archivo(nombreArchivo.c_str());
            if (archivo.is_open()) {
                std::string linea;
                while (std::getline(archivo, linea)) {
                    ArbolBinario arbol;
                    
                    std::vector<std::string> palabras;
                    dividirLineaEnPalabras(linea, palabras);

                    for(int i = 0; i < palabras.size(); i++){
                    	char* palabraChar = new char[palabras[i].length() + 1];
					    std::strcpy(palabraChar, palabras[i].c_str());
					    arbol.insertar(palabraChar);
					    delete[] palabraChar;
					    std::cout << "a" << std::endl;
					}
                    arboles.push_back(arbol);
                }
                archivo.close();
                std::cout << "El archivo se ha cargado correctamente." << std::endl;
                system("PAUSE");
                _archLoad=true;
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
                return;
            } else {
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
            }
        }
    } while (true);
}

void alturaArbol(){
}

void hojasArbol(){
}

void equilibrioArbol(){
}




