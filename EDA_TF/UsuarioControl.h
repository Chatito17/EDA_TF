#pragma once
#include <iostream>
#include <string>
#include "AVL.h"
#include "Lista.h"
#include "Ranking.h"
#include "GeneradorDataSet.h"
#include "Usuario.h"

class UsuarioControl
{
private:
	Lista<Usuario>* lista;
	AVL<Usuario>* arbol;
    Ranking ranking;
	
public:
    UsuarioControl() : arbol(new AVL<Usuario>()), lista(new Lista<Usuario>()) {}
    ~UsuarioControl() {
        delete arbol;
        delete lista;
    }

    void menu() {
        int opc;
        do
        {
            std::cout << "\n===== MENU USUARIOS =====\n";
            std::cout << "0. Agregar usuarios aleatorios\n";
            std::cout << "1. Agregar usuario manualmente\n";
            std::cout << "2. Buscar usuario por nombre\n";
            std::cout << "3. Eliminar usuario\n";
            std::cout << "4. Mostrar ranking por experiencia\n";
            std::cout << "5. Mostrar arbol AVL\n";
            std::cout << "6. Mostrar lista enlazada\n";
            std::cout << "7. Mostrar usuarios alfabeticamente\n";
            std::cout << "8. Regresar\n";
            std::cout << "\nDigite una opcion: ";
            std::cin >> opc;

            if (opc == 0) {
                agregarUsuariosAleatorios();
            }
            else if (opc == 1) {
                agregarUsuarioManual();
            }
            else if (opc == 2) {
                buscarUsuario();
                std::cout << "\nemm\n";
            }
            else if (opc == 3) {
                eliminarUsuario();
            }
            else if (opc == 4) {
                mostrarRankingXP();
            }
            else if (opc == 5) {
                mostrarArbol();
            }
            else if (opc == 6) {
                mostrarLista();
                std::cout << "\nHasta luego! :D\n";
            }
            else if (opc == 7) {
                mostrarUsuariosAlfabeticamente();

            }

        } while (opc != 8);
}
    void agregarUsuariosAleatorios() {
        int cantidad;
        std::cout << "\nDigite la cantidad de items a agregar :";
        std::cin >> cantidad;
        auto agregarUsuarioRandom = [this](int n) {
            int consecutivo = 1;
            while (n--) {
                Usuario nuevo = generarUsuarioAleatorio(consecutivo++);
                while (!(this->arbol->Buscar(nuevo.getNombre()) == Usuario())) {
                    nuevo = generarUsuarioAleatorio(consecutivo++);
                }
                this->arbol->Insertar(nuevo);
                this->lista->AddLast(nuevo);
            }
            };
        agregarUsuarioRandom(cantidad);
        std::cout << "Usuarios agregados correctamente.\n";
    }

    void agregarUsuarioManual() {

        std::string id, nombre, idioma;
        int experiencia, racha;

        std::cin.ignore();
        std::cout << "ID: "; getline(std::cin, id);
        std::cout << "Nombre: "; getline(std::cin, nombre);
        std::cout << "Idioma: "; getline(std::cin, idioma);
        std::cout << "Experiencia: "; std::cin >> experiencia;
        std::cout << "Racha: "; std::cin >> racha;

        Usuario nuevo(id, nombre, idioma, experiencia, racha);
        arbol->Insertar(nuevo);
        lista->AddLast(nuevo);
        std::cout << "Usuario agregado correctamente.\n";
    }

    void buscarUsuario() {
        std::cin.ignore();
        std::string nombre;
        std::cout << "Nombre: "; getline(std::cin, nombre);

        Usuario encontrado = arbol->Buscar(nombre);

        if (encontrado == Usuario()) {
            std::cout << "Usuario no encontrado.\n";
        }
        else {

            std::cout << "\nUsuario encontrado\n";
            std::cout << encontrado.getID() << " "
                << encontrado.getNombre() << " "
                << encontrado.getIdioma() << " "
                << encontrado.getExperiencia() << " "
                << encontrado.getRacha() << "\n";
        }
    }

    void eliminarUsuario() {

        std::cin.ignore();
        std::string nombre;
        std::cout << "Nombre: "; getline(std::cin, nombre);

        arbol->Eliminar(nombre);

        // FALTA:
        // eliminar también de la lista enlazada
        std::cout << "Usuario eliminado del AVL.\n";
    }

    void mostrarRankingXP() {
        ranking.ordenarRankingPorXP(lista);
        //Lambda
        auto imprimir = [](Usuario u) {
            std::cout << u.getNombre() << " " << u.getExperiencia() << "\n";
            };

        lista->imprimir(imprimir);
    }

    void mostrarArbol() {
        std::cout << "\n== ARBOL DE USUARIOS ==\n";
        auto imprimir = [](Usuario u) {
            std::cout << u.getNombre();
            };
        arbol->ImprimirArbol(imprimir);
        std::cout << "\n";
    }

    void mostrarLista() {
        auto imprimir = [](Usuario u) {
            std::cout
                << u.getNombre() << " "
                << u.getExperiencia();
            };
        lista->imprimir(imprimir);
    }
    void mostrarUsuariosAlfabeticamente(){
        std::vector<Usuario> aux = listaAVector(lista);
        auto comparar = [](Usuario a, Usuario b) {
            return a.getNombre() < b.getNombre();
            };
        mergeSort(aux, 0, aux.size() - 1, comparar);
        for (Usuario u : aux) {
            std::cout
                << u.getNombre() << " "
                << u.getExperiencia()
                << "\n";
        }
    }
};