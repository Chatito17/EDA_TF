#pragma once
#include <string>

template<typename T>
class NodoPila {
public:
	T dato;
	NodoPila<T>* siguiente;
	NodoPila(T valor) {
		dato = valor;
		siguiente = nullptr;
	}
};

template<typename T>
class Pila {
private:
	NodoPila<T>* cima;
public:
	Pila() {
		cima = nullptr;
	}

	template<typename Mostrar>
	void imprimir(Mostrar mostrarElemento) {
		NodoPila<T>* aux = cima;
		while (aux != nullptr) {
			std::cout << "- ";
			mostrarElemento(aux->dato);
			std::cout << std::endl;
			aux = aux->siguiente;
		}
	}

	void push(T valor) {
		NodoPila<T>* nuevo = new NodoPila<T>(valor);
		nuevo->siguiente = cima;
		cima = nuevo;
	}

	void pop() {
		if (cima == nullptr) return;
		NodoPila<T>* temp = cima;
		cima = cima->siguiente;
		delete temp;
	}

	T buscar(std::string nombre) {
		NodoPila<T>* temp = cima;
		while (temp != nullptr) {
			if (temp->dato.getNombre() == nombre) {
				return temp->dato;
				break;
			}
			temp = temp->siguiente;
		}
		return T();
	}

	T top() {
		return !estaVacio() ? cima->dato : T();
	}

	bool estaVacio() {
		return cima == nullptr;
	}
};