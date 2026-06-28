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

	//Metodo eliminar
	NodoAVL<T>* Eliminar(NodoAVL<T>* r, std::string nombre) {
		if (r == nullptr)
			return nullptr;

		// Buscar el nodo
		if (nombre < r->valor.getNombre()) {
			r->izquierda = Eliminar(r->izquierda, nombre);
		}
		else if (nombre > r->valor.getNombre()) {
			r->derecha = Eliminar(r->derecha, nombre);
		}
		else {
			// Caso 1: hoja
			if (r->izquierda == nullptr && r->derecha == nullptr) {
				delete r;
				return nullptr;
			}
			// Caso 2: solo hijo izquierdo
			else if (r->derecha == nullptr) {
				NodoAVL<T>* hijo = r->izquierda;
				delete r;
				return hijo;
			}
			// Caso 3: solo hijo derecho
			else if (r->izquierda == nullptr) {
				NodoAVL<T>* hijo = r->derecha;
				delete r;
				return hijo;
			}
			// Caso 4: dos hijos
			else {
				NodoAVL<T>* suc = minimo(r->derecha);

				while (suc->izquierda != nullptr)
					suc = suc->izquierda;

				r->valor = suc->valor;

				r->derecha = Eliminar(r->derecha, suc->valor.getNombre());
			}
		}

		if (r == nullptr)
			return nullptr;

		return Rebalancear(r);
	}

	//Metodo buscar por nombre

	NodoAVL<T>* Buscar(NodoAVL<T>* r, std::string nombre) {
		if (r == nullptr)
			return nullptr;

		if (nombre == r->valor.getNombre())
			return r;

		if (nombre < r->valor.getNombre())
			return Buscar(r->izquierda, nombre);

		return Buscar(r->derecha, nombre);
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

	template <typename Mostrar>
	void ImprimirSubarbol(NodoAVL<T>* nodo, const std::string& prefijo, bool esDerecha, Mostrar mostrarElemento) {
		if (nodo == nullptr)
			return;

		ImprimirSubarbol(nodo->derecha, prefijo + (esDerecha ? "    " : "|   "), true, mostrarElemento);

		std::cout << prefijo << "|---";
		mostrarElemento(nodo->valor);
		std::cout << std::endl;

		ImprimirSubarbol(nodo->izquierda, prefijo + (esDerecha ? "|   " : "    "), false, mostrarElemento);
	}

	template <typename Mostrar>
	void ImprimirArbol(Mostrar mostrarElemento) {
		if (raiz == nullptr) {
			std::cout << "Arbol vacio" << std::endl;
			return;
		}

		ImprimirSubarbol(raiz->derecha, "", true, mostrarElemento);

		mostrarElemento(raiz->valor);
		std::cout << std::endl;

		ImprimirSubarbol(raiz->izquierda, "", false, mostrarElemento);
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

	T Buscar(std::string nombre) {
		NodoAVL<T>* resultado = Buscar(raiz, nombre);

		if (resultado == nullptr)
			return T();

		return resultado->valor;
	}


	void Eliminar(std::string nombre) {
		raiz = Eliminar(raiz, nombre);
	}


    void Insertar(T valor) {
        raiz = Insertar(raiz, valor);
    }

	NodoAVL<T>* minimo(NodoAVL<T>* nodo) {
		NodoAVL<T>* actual = nodo ;

		while (actual->izquierda != nullptr)
			actual = actual->izquierda;

		return actual;
	}

	NodoAVL<T>* minimo() {
		if (raiz == nullptr)
			return nullptr;

		NodoAVL<T>* actual = raiz;

		while (actual->izquierda != nullptr)
			actual = actual->izquierda;

		return actual;
	}

	NodoAVL<T>* maximo() {
		if (raiz == nullptr)
			return nullptr;

		NodoAVL<T>* actual = raiz;

		while (actual->derecha != nullptr)
			actual = actual->derecha;

		return actual;
	}

    bool estaVacio() {
        return raiz == nullptr;
    }
};
