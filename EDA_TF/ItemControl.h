#pragma once
#include <iostream>
#include <string>
#include "AVL.h"
#include "Item.h"
#include "Lista.h"
#include "HeapSort.h"

class ItemControl
{
private:
	AVL<Item>* arbol;
    Lista<Item>* lista;

public:
	ItemControl(): arbol(new AVL<Item>()), lista(new Lista<Item>()){}
	~ItemControl(){
		delete arbol;
        delete lista;
	}

	void menu() {
        int opc;
        do
        {
            std::cout << "\n=== MENU ===\n";
            std::cout << "0. Agregar items aleatorios.\n";
            std::cout << "1. Agregar item manualmente.\n";
            std::cout << "2. Buscar item.\n";
            std::cout << "3. Mostrar items ordenados por precio.\n";
            std::cout << "4. Mostrar arbol de items por nombre.\n";
            std::cout << "5. Regresar.\n";
            std::cout << "\nDigite una opcion: "; std::cin >> opc;

            if (opc == 0) {
                agregarItemsAleatorios();
            }
            else if (opc == 1) {
                agregarItemManual();
            }
            else if (opc == 2) {
                std::cout << "\nemm\n";
            }
            else if (opc == 3) {
                mostrarListaOrdenada();
            }
            else if (opc == 4) {
                mostrarArbol();
            }
            else if (opc == 5) {
                std::cout << "\nHasta luego! :D\n";
            }

        } while (opc != 5);
	}
    void agregarItemsAleatorios() {
        int cantidad;
        std::cout << "\nDigite la cantidad de items a agregar: "; std::cin >> cantidad;
        
        auto agregarItemRandom = [this](int n) {
            while (n--) {
                Item nuevo = generarItemRandom();
                while (this->arbol->Buscar(nuevo) != nullptr) {
                    nuevo = generarItemRandom();
                }
                this->arbol->Insertar(nuevo);
                this->lista->AddLast(nuevo);
            }
            };
        agregarItemRandom(cantidad);
        std::cout << "Items agregados correctamente\n";
    }
	
    void agregarItemManual() {
        std::string nombre, descripcion;
        int precio;
        std::cin.ignore();
        std::cout << "\n++ Nuevo Item ++\n\n";
        std::cout << "Nombre: "; getline(std::cin, nombre);
        std::cout << "Descripcion: "; getline(std::cin, descripcion);
        std::cout << "Precio en gemas: "; std::cin >> precio;

        arbol->Insertar(Item(nombre, descripcion, precio));
        std::cout << "Item agregado correctamente\n";
    }
    void mostrarListaOrdenada() {
        vector<Item> aux = listaAVector(lista);
        auto comparadorPrecio = [](Item a, Item b) {
            return a.getPrecio() < b.getPrecio();
            };
        heapSortMenorAMayor(aux, comparadorPrecio);
        lista = vectorALista(aux);

        std::cout << "\n== LISTA DE ITEMS ==\n";
        lista->Print();
        std::cout << "\n";
    }

    void mostrarArbol() {
        std::cout << "\n== ARBOL DE ITEMS ==\n";
        arbol->ImprimirArbol();
        std::cout << "\n";
    }
};