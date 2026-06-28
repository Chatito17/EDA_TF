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

    void insertar(const T& p) {
        int idx = hash(p.enunciado);
        tabla[idx].AddFirst(p);
        cout << "  [guardado] " << p.enunciado
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

    void imprimir() {
        cout << "\n--- Agenda ---\n";
        for (int i = 0; i < tam; i++) {
            if (!tabla[i].cabeza) continue;
            cout << "tabla[" << i << "]: ";
            tabla[i].imprimir();
            cout << "\n";
        }
        cout << "--------------\n";
    }
};