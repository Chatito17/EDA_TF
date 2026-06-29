#pragma once
#include "GeneradorDataSet.h"
#include "Lista.h"
#include "TablaHash.h"

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
                agregarPreguntasAleatorias();
            }
            else if (opc == 1) {
                agregarPregunta();
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
    void agregarPreguntasAleatorias() {
        int cantidad;
        std::cout << "\nDigite la cantidad de Preguntas a agregar: "; std::cin >> cantidad;

        auto agregarPreguntaRandom = [this](int n) {
            while (n--) {
                Pregunta nuevo = generarPreguntaAleatoria();
                while (!(listaPregunta->Buscar(nuevo.getNombre()) == nuevo))
                {
                    nuevo = generarPreguntaAleatoria();
                }
                this->tablaPregunta->insertar(nuevo);
                this->listaPregunta->AddLast(nuevo);
            }
            };
        agregarPreguntaRandom(cantidad);
        std::cout << "Preguntas agregados correctamente\n";
    }

    void agregarPregunta() {
        std::string enunciado, respuesta;
        int diff;
        std::cin.ignore();
        std::cout << "\n++ Nueva Pregunta ++\n\n";
        std::cout << "Enciado: "; getline(std::cin, enunciado);
        std::cout << "Respuesta: "; getline(std::cin, respuesta);
        std::cout << "Dificultad: "; std::cin >> diff;

        listaPregunta->AddFirst(Pregunta(enunciado, diff, respuesta ));
        tablaPregunta->insertar(Pregunta(enunciado, diff, respuesta));
        std::cout << "Item agregado correctamente\n";
    }
    void mostrarListaOrdenada() {
        vector<Pregunta> aux = listaAVector(listaPregunta);
        auto comparadorDificultad = [](Pregunta a, Pregunta b) {
            return a.getDificultad() < b.getDificultad();
            };
        heapSortMenorAMayor(aux, comparadorDificultad);
        listaPregunta = vectorALista(aux);

        std::cout << "\n== LISTA DE ITEMS ==\n";
        auto imprimirPregunta = [](Pregunta pregunta) {
            cout << pregunta.getNombre() << " " << pregunta.getDificultad() << " " << pregunta.getRespuesta();
            };
        listaPregunta->imprimir(imprimirPregunta);
        std::cout << "\n";
    }

    void mostrarTabla() {
        std::cout << "\n== TABLA DE PREGUNTAS==\n";
        auto imprimirPregunta = [](Pregunta pregunta) {
            cout << pregunta.getNombre() << " " << pregunta.getDificultad() << " " << pregunta.getRespuesta();
            };
        tablaPregunta->imprimir(imprimirPregunta);
        std::cout << "\n";
    }
};