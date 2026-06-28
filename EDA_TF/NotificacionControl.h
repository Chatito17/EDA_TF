#pragma once
#include <iostream>
#include <string>
#include "GeneradorDataSet.h"
#include "Notificacion.h"
#include "Pila.h"

class NotificacionControl
{
private:
    Pila<Notificacion>* pila;
    int cantidad;

public:
    NotificacionControl() : pila(new Pila<Notificacion>()), cantidad(1) {}
    ~NotificacionControl() {
        delete pila;
    }

    void menu() {
        int opc;
        do
        {
            std::cout << std::endl << "=== MENU DE NOTIFICACIONES ===" << std::endl;
            std::cout << "0. Generar notificaciones aleatorias." << std::endl;
            std::cout << "1. Agregar notificacion manualmente." << std::endl;
            std::cout << "2. Buscar notificacion por nombre." << std::endl;
            std::cout << "3. Eliminar ultima notificacion." << std::endl;
            std::cout << "4. Mostrar notificaciones." << std::endl;
            std::cout << "5. Regresar." << std::endl;
            std::cout << "\nDigite una opcion: "; std::cin >> opc;

            if (opc == 0) {
                agregarNotificacionesAleatorias();
            }
            else if (opc == 1) {
                agregarNotificacionManual();
            }
            else if (opc == 2) {
                buscarNotificacion();
            }
            else if (opc == 3) {
                eliminarNotificacion();
            }
            else if (opc == 4) {
                mostrarNotificaciones();
            }
            else if (opc == 5) {
                std::cout << std::endl << "Redirigiendo..." << std::endl;
            }

        } while (opc != 6);
    }
    void agregarNotificacionesAleatorias() {
        int cantidad;
        std::cout << std::endl << "Digite la cantidad de notificaciones a agregar: "; std::cin >> cantidad;

        auto agregarNotificacionAleatoria = [this](int n) {
            while (n--) {
                Notificacion nuevo = generarNotificacionAleatoria(this->cantidad);
                while (this->pila->buscar(nuevo.getNombre()) != Notificacion())
                {
                    nuevo = generarNotificacionAleatoria(this->cantidad);
                }
                this->pila->push(nuevo);
                this->cantidad++;
            }
            };
        agregarNotificacionAleatoria(cantidad);
        std::cout << "Notificaciones agregadas correctamente" << std::endl;
    }

    void agregarNotificacionManual() {
        std::string nombre, descripcion, id;
        id = "U" + std::to_string(cantidad);
        std::cin.ignore();
        std::cout << std::endl << "++ Nueva Notificacion ++" << std::endl << std::endl;
        std::cout << "Nombre: "; getline(std::cin, nombre);
        std::cout << "Descripcion: "; getline(std::cin, descripcion);
        std::cout << "ID: " << id;

        pila->push(Notificacion(nombre, descripcion, id));
        std::cout << "Notificacion agregada correctamente" << std::endl;
    }
    void eliminarNotificacion() {
        Notificacion busca = pila->top();
        if (busca == Notificacion())
        {
            std::cout << "No hay notificaciones..." << std::endl;
        }
        std::cout << "== Datos de la ultima Notificacion ==" << std::endl;
        std::cout << "Nombre: " << busca.getNombre() << std::endl;
        std::cout << "Descripcion: " << busca.getDescripcion() << std::endl;
        std::cout << "ID: " << busca.getId() << std::endl;

        char opc;
        do {
            std::cout << std::endl << "Esta seguro de eliminar la notificacion? (Y/N): "; std::cin >> opc;
            opc = toupper(opc);
        } while (!(opc == 'Y' || opc == 'N'));

        if (opc == 'Y') {
            pila->pop();
            std::cout << std::endl << "Se borro satisfactoriamente :D" << std::endl;
        }
        else {
            std::cout << std::endl << "No se hizo algun cambio" << std::endl;
        }
    }
    void buscarNotificacion() {
        std::string nombre;
        std::cin.ignore();
        std::cout << std::endl << "Digite el nombre de la notificacion: "; std::getline(cin, nombre);
        Notificacion busca = pila->buscar(nombre);
        if (busca == Notificacion()) {
            std::cout << "Notificacion no he encontrada :c" << std::endl;
            return;
        }
        std::cout << "Notificacion encontrada" << std::endl;
        std::cout << "== Datos de la Notificacion ==" << std::endl;
        std::cout << "Nombre: " << busca.getNombre() << std::endl;
        std::cout << "Descripcion: " << busca.getDescripcion() << std::endl;
        std::cout << "ID: " << busca.getId() << std::endl;
    }
    void mostrarNotificaciones() {
        std::cout << std::endl << "== PILA DE NOTIFICACIONES ==" << std::endl;
        auto imprimirNotificacion = [](Notificacion notificacion) {
            std::cout << notificacion.getNombre() << " " << notificacion.getDescripcion() << " " << notificacion.getId();
            };
        pila->imprimir(imprimirNotificacion);
        std::cout << std::endl;
    }
};