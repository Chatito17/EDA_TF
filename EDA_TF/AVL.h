#pragma once
#include <iostream>

template<typename T>
class NodoAVL {
public:
    T valor;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    int altura;

    NodoAVL(T v) : valor(v), izquierda(nullptr), derecha(nullptr), altura(1) {}
};

template<typename T>
class AVL {
private:
    NodoAVL<T>* raiz;

    NodoAVL<T>* RotarDerecha(NodoAVL<T>* b) {
        NodoAVL<T>* a = b->izquierda;
        NodoAVL<T>* T2 = a->derecha;

        a->derecha = b;
        b->izquierda = T2;

        ActualizarAltura(b);
        ActualizarAltura(a);
        return a;
    }

    NodoAVL<T>* RotarIzquierda(NodoAVL<T>* a) {
        NodoAVL<T>* b = a->derecha;
        NodoAVL<T>* T2 = b->izquierda;

        b->izquierda = a;
        a->derecha = T2;

        ActualizarAltura(a);
        ActualizarAltura(b);
        return b;
    }

    NodoAVL<T>* Rebalancear(NodoAVL<T>* nodo) {
        ActualizarAltura(nodo);
        int balance = FactorBalance(nodo);

        if (balance < -1) {
            if (FactorBalance(nodo->izquierda) > 0)
                nodo->izquierda = RotarIzquierda(nodo->izquierda);
            return RotarDerecha(nodo);
        }
        if (balance > 1) {
            if (FactorBalance(nodo->derecha) < 0)
                nodo->derecha = RotarDerecha(nodo->derecha);
            return RotarIzquierda(nodo);
        }
        return nodo;
    }

    NodoAVL<T>* Insertar(NodoAVL<T>* nodo, T valor) {
        if (nodo == nullptr) {
            return new NodoAVL<T>(valor);
        }
        if (valor < nodo->valor) {
            nodo->izquierda = Insertar(nodo->izquierda, valor);
        }
        else if (valor > nodo->valor) {
            nodo->derecha = Insertar(nodo->derecha, valor);
        }
        else {
            // En este ejemplo no se inserta repetidos.
            return nodo;
        }
        return Rebalancear(nodo);
    }

    NodoAVL<T>* Buscar(NodoAVL<T>* nodo, T valor) {
        if (nodo == nullptr) {
            return nullptr;
        }
        if (nodo->valor == valor) {
            return nodo;
        }
        if (valor < nodo->valor) {
            return Buscar(nodo->izquierda, valor);
        }
        else {
            return Buscar(nodo->derecha, valor);
        }
    }
    void DestruirArbol(NodoAVL<T>* nodo) {
        if (nodo == nullptr)
            return;
        DestruirArbol(nodo->izquierda);
        DestruirArbol(nodo->derecha);
        delete nodo;
    }

public:
    AVL() : raiz(nullptr) {}
    ~AVL() {
        DestruirArbol(raiz);
    }

    void ImprimirSubarbol(NodoAVL<T>* nodo, const std::string& prefijo, bool esDerecha) {
        if (nodo == nullptr) return;

        ImprimirSubarbol(nodo->derecha, prefijo + (esDerecha ? "    " : "|   "), true);

        std::cout << prefijo << "|---" << nodo->valor << "\n";

        ImprimirSubarbol(nodo->izquierda, prefijo + (esDerecha ? "|   " : "    "), false);
    }
    void ImprimirArbol() {
        if (raiz == nullptr) {
            std:: cout << "Arbol vacio\n";
            return;
        }
        ImprimirSubarbol(raiz->derecha, "", true);
        std::cout << raiz->valor << "\n";
        ImprimirSubarbol(raiz->izquierda, "", false);
    }
    int Altura(NodoAVL<T>* nodo) {
        return (nodo == nullptr) ? 0 : nodo->altura;
    }

    void ActualizarAltura(NodoAVL<T>* nodo) {
        int hi = Altura(nodo->izquierda);
        int hd = Altura(nodo->derecha);
        nodo->altura = 1 + (hi > hd ? hi : hd);
    }

    int FactorBalance(NodoAVL<T>* nodo) {
        if (nodo == nullptr) return 0;
        return Altura(nodo->derecha) - Altura(nodo->izquierda);
    }

    NodoAVL<T>* Buscar(T valor) {
        return Buscar(raiz, valor);
    }

    void Insertar(T valor) {
        raiz = Insertar(raiz, valor);
    }

    NodoAVL<T>* minimo() {
        if (raiz == nullptr) return nullptr;
        NodoAVL<T>* actual = raiz;
        while (actual->izquierda != nullptr)
            actual = actual->izquierda;
        return actual;
    }

    NodoAVL<T>* maximo() {
        if (raiz == nullptr) return nullptr;
        NodoAVL<T>* actual = raiz;
        while (actual->derecha != nullptr)
            actual = actual->derecha;
        return actual;
    }

    bool estaVacio() {
        return raiz == nullptr;
    }
};
