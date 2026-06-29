#pragma once
#include "Lista.h"
template <typename T>
class TablaHash {
    int tam;
   
    Lista<T>* tabla;   // arreglo de listas enlazadas

    // polynomial rolling hash, potencia de 31
    // Ejemplo "Jose"
    // "J" * 31 ^ 3 + "o" * 31 ^ 2 + "s" * 31 ^ 1 + "e" * 31 ^ 0 -> número disperso que se puede hacer módulo
    int hash(const string& clave) {
        unsigned long h = 0;
        for (char c : clave)
            h = h * 31 + c;
        return h % tam;
    }

public:
    TablaHash(int tam) : tam(tam) {
        tabla = new Lista<T>[tam];  // arreglo dinámico de listas enlazadas
    }

    ~TablaHash() {
        for (int i = 0; i < tam; i++)
            tabla[i].~Lista();
        delete[] tabla;
    }

    void insertar(T p) {
        int idx = hash(p.getNombre());
        tabla[idx].AddLast(p);
        cout << "  [guardado] " << p.getNombre()
            << " en tabla[" << idx << "]\n";
    }

    string buscar(const string& nombre) {
        int idx = hash(nombre);
        return tabla[idx].buscar(nombre);
    }

    bool eliminar(const string& nombre) {
        int idx = hash(nombre);
        return tabla[idx].eliminar(nombre);
    }

    template<typename Mostrar>
    void imprimir(Mostrar mostrarElemento) {
        cout << "\n--- Agenda ---\n";
        for (int i = 0; i < tam; i++) {
            if (tabla[i].estaVacio()) continue;
            cout << "tabla[" << i << "]: ";
            tabla[i].imprimir(mostrarElemento);
            cout << "\n";
        }
        cout << "--------------\n";
    }
};