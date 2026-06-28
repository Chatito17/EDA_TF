#pragma once
#include <iostream>
#include <string>
#include "AVL.h"
#include "Item.h"
#include "Lista.h"
#include "HeapSort.h"
#include "GeneradorDataSet.h"

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
            std::cout << "\n=== MENU DE ITEMS ===";
            std::cout << "\n0. Generar items aleatorios.";
            std::cout << "\n1. Agregar item manualmente.";
            std::cout << "\n2. Buscar item.";
            std::cout << "\n3. Eliminar item.";
            std::cout << "\n4. Mostrar items ordenados por precio.";
            std::cout << "\n5. Mostrar arbol de items por nombre.";
            std::cout << "\n6. Regresar.";
            std::cout << "\n\nDigite una opcion: "; std::cin >> opc;

            if (opc == 0) {
                agregarItemsAleatorios();
            }
            else if (opc == 1) {
                agregarItemManual();
            }
            else if (opc == 2) {
                buscarItem();
            }
            else if (opc == 3) {
                eliminarItem();
            }
            else if (opc == 4) {
                mostrarListaOrdenada();
            }
            else if (opc == 5) {
                mostrarArbol();
            }
            else if (opc == 6) {
                std::cout <<"\nRedirigiendo...\n";
            }

        } while (opc != 6);
	}
    void agregarItemsAleatorios() {
        int cantidad;
        std::cout << "\nDigite la cantidad de items a agregar: "; std::cin >> cantidad;
        
        auto agregarItemRandom = [this](int n) {
            while (n--) {
                Item nuevo = generarItemAleatorio();
                while (this->arbol->Buscar(nuevo.getNombre()) != Item())
                {
                    nuevo = generarItemAleatorio();
                }
                this->arbol->Insertar(nuevo);
                this->lista->AddLast(nuevo);
            }
        };
        agregarItemRandom(cantidad);
        std::cout << "Items agregados correctamente" << std::endl;
    }
	
    void agregarItemManual() {
        std::string nombre, descripcion;
        int precio;
        std::cin.ignore();
        std::cout << std::endl << "++ Nuevo Item ++" << std::endl << std::endl;
        std::cout << "Nombre: "; getline(std::cin, nombre);
        std::cout << "Descripcion: "; getline(std::cin, descripcion);
        std::cout << "Precio en gemas: "; std::cin >> precio;

        arbol->Insertar(Item(nombre, descripcion, precio));
        lista->AddLast(Item(nombre, descripcion, precio));
        std::cout << "Item agregado correctamente" << std::endl;
    }
    void eliminarItem() {
        std::string nombre;
        std::cin.ignore();
        std::cout << std::endl << "Digite el nombre del item: "; std::getline(std::cin, nombre);
        Item busca = this->arbol->Buscar(nombre);
        if (busca == Item()) {
            std::cout << "Item no he encontrado :c" << std::endl;
            return;
        }
        std::cout << "Item encontrado" << std::endl;
        std::cout << "== Datos de Item ==" << std::endl;
        std::cout << "Nombre: " << busca.getNombre() << std::endl;
        std::cout << "Descripcion: " << busca.getDescripcion() << std::endl;
        std::cout << "Precio: " << busca.getPrecio() << std::endl;

        char opc;
        do{
            std::cout << std::endl << "Esta seguro de eliminar el Item? (Y/N): "; std::cin >> opc;
            opc = toupper(opc);
        } while (!(opc == 'Y' || opc == 'N'));

        if (opc == 'Y') {
            arbol->Eliminar(busca.getNombre());
            lista->eliminar(busca.getNombre());
            std::cout << std::endl << "Se borro satisfactoriamente :D" << std::endl;
        }
        else {
            std::cout << std::endl << "No se hizo algun cambio" << std::endl;
        }
    }
    void buscarItem() {
        std::string nombre;
        std::cin.ignore();
        std::cout << std::endl << "Digite el nombre del item: "; std::getline(cin, nombre);
        Item busca = this->arbol->Buscar(nombre);
        if (busca == Item()) {
            std::cout << "Item no he encontrado :c" << std::endl;
            return;
        }
        std::cout << "Item encontrado" << std::endl;
        std::cout << "== Datos de Item ==" << std::endl;
        std::cout << "Nombre: " << busca.getNombre() << std::endl;
        std::cout << "Descripcion: " << busca.getDescripcion() << std::endl;
        std::cout << "Precio: " << busca.getPrecio() << std::endl;
    }
    void mostrarListaOrdenada() {
        std::vector<Item> aux = listaAVector(lista);
        auto comparadorPrecio = [](Item a, Item b) {
            return a.getPrecio() < b.getPrecio();
            };
        heapSortMenorAMayor(aux, comparadorPrecio);
        lista = vectorALista(aux);

        std::cout << std::endl << "== LISTA DE ITEMS =="<< std::endl;
        auto imprimirItem = [](Item item) {
            std::cout << item.getNombre() << " " << item.getDescripcion() << " " << item.getPrecio();
            };
        lista->imprimir(imprimirItem);
        std::cout << std::endl;
    }

    void mostrarArbol() {
        std::cout << std::endl << "== ARBOL DE ITEMS ==" << std::endl;
        auto imprimirItem = [](Item item) {
            std::cout << item.getNombre() << " " << item.getDescripcion() << " " << item.getPrecio();
            };
        arbol->ImprimirArbol(imprimirItem);
        std::cout << std::endl;
    }
};