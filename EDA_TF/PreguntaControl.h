#pragma once
#include "Lista.h"
#include "TablaHash.h"
struct Pregunta
{
    string enunciado = "";
    int Dificultad = 0;
    string Respuesta = "";
};
class PreguntaControl
{
private:
    TablaHash<Pregunta>* tablaPregunta;
    Lista <Pregunta> *listaPregunta;

public:
    PreguntaControl() : tablaPregunta(new TablaHash<Pregunta>(10)), listaPregunta(new Lista<Pregunta>()) {}
    ~PreguntaControl() {
        delete tablaPregunta;
        delete listaPregunta;
    }

    void menu() {
        int opc;
        do
        {
            std::cout << "\n=== MENU ===\n";
            std::cout << "0. Generar preguntas aleatorias.\n";
            std::cout << "1. Agregar pregunta manualmente.\n";
            std::cout << "2. Buscar pregunta.\n";
            std::cout << "3. Mostrar preguntas ordenadas por dificultad.\n";
            std::cout << "4. Mostrar tabla de preguntas por enunciado.\n";
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
                mostrarTabla();
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
        vector<Pregunta> aux = listaAVector(listaPregunta);
        auto comparadorDificultad = [](Pregunta a, Pregunta b) {
            return a.Dificultad < b.Dificultad;
            };
        heapSortMenorAMayor(aux, comparadorDificultad);
        listaPregunta = vectorALista(aux);

        std::cout << "\n== LISTA DE ITEMS ==\n";
        auto imprimirPregunta = [](Pregunta pregunta) {
            cout << pregunta.enunciado << " " << pregunta.Dificultad << " " << pregunta.Respuesta;
            };
        listaPregunta->imprimir(imprimirPregunta);
        std::cout << "\n";
    }

    void mostrarTabla() {
        std::cout << "\n== TABLA DE PREGUNTAS==\n";
        auto imprimirItem = [](Pregunta pregunta) {
            cout << pregunta.enunciado << " " << pregunta.Dificultad << " " << pregunta.Respuesta;
            };
        tablaPregunta->imprimir();
        std::cout << "\n";
    }
};