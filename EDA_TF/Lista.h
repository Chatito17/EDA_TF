#pragma once
#include <iostream>
#include <vector>

template <typename T>
class NodoLista {
public:
	T valor;
	NodoLista<T>* siguiente;

	NodoLista(T& valor) : valor(valor), siguiente(nullptr) {}
	NodoLista(T& valor, NodoLista<T>* siguiente) : valor(valor), siguiente(siguiente) {}
};


template <typename T>
class Lista {
private:
	NodoLista<T>* cabeza;
	int longitud;

	NodoLista<T>* NodeAt(int pos) {
		if (pos < 0|| pos >= longitud) {
			std::cout << "No existe posicion, debe ser menor al tamanio de la lista..." << std::endl;
			return nullptr;
		}

		int index = 0;
		NodoLista<T>* aux = cabeza;
	
		while (index < pos) {
			aux = aux->siguiente;
			index++;
		}
		return aux;
	}

public:
	Lista() : cabeza(nullptr), longitud(0) {}
	~Lista() {
		NodoLista<T>* aux = cabeza;
		NodoLista<T>* aux2;
		while (aux != nullptr) {
			aux2 = aux->siguiente;
			delete aux;
			aux = aux2;
		}
	}

	template <typename Mostrar>
	void imprimir(Mostrar mostrarElemento) {
		if (estaVacio()) {
			std::cout << "La lista enlazada esta Vacia..." << std::endl;
			return;
		}
		NodoLista<T>* aux = cabeza;
		while (aux != nullptr) {
			
			mostrarElemento(aux->valor);
			std::cout << " || "; //Lambda define como se imprime
			aux = aux->siguiente;
		}
		std::cout << std::endl;
	}

	int getLongitud() {
		return longitud;
	}

	bool estaVacio() {
		return longitud == 0;
	}

	void AddFirst(T valor) {
		NodoLista<T>* node = new NodoLista<T>(valor, estaVacio() ? nullptr : cabeza);
		cabeza = node;
		longitud++;
	}

	void AddPos(T valor, int pos) {
		if (pos == 0) 
			AddFirst(valor);
		else
		{
			NodoLista<T>* nodeBefore = NodeAt(pos - 1);
			NodoLista<T>* nodeAfter = nodeBefore->siguiente;
			NodoLista<T>* node = new NodoLista<T>(valor, nodeAfter);
			nodeBefore->siguiente = node;
		}
		longitud++;
	}

	void AddLast(T valor) {
		NodoLista<T>* node = new NodoLista<T>(valor);
		if (estaVacio()) {
			cabeza = node;
		}
		else {
			NodoLista<T>* nodeLast = NodeAt(longitud - 1);
			nodeLast->siguiente = node;
		}
		longitud++;
	}

	void ModifyFirst(T valor) {
		NodoLista<T>* nodo = NodeAt(0);
		if (nodo != nullptr) {
			nodo->valor = valor;
		}
	}

	void ModifyPos(T valor, int pos) {
		NodoLista<T>* nodo = NodeAt(pos);
		if (nodo != nullptr) {
			nodo->valor = valor;
		}
	}

	void ModifyLast(T valor) {
		NodoLista<T>* nodo = NodeAt(longitud - 1);
		if (nodo != nullptr) {
			nodo->valor = valor;
		}
	}

	void RemoveFirst() {
		if (estaVacio()) {
			std::cout << "No se puede eliminar un nodo en una lista enlazada vacía" << std::endl;
			return;
		}
		NodoLista<T>* aux = cabeza;
		cabeza = cabeza->siguiente;
		delete aux;
		longitud--;
	}

	void RemovePos(int pos) {
		if (estaVacio()) {
			std::cout << "No se puede eliminar un nodo en una lista enlazada vacía" << std::endl;
			return;
		}
		if (pos == 0)
			RemoveFirst();
		else {
			NodoLista<T>* nodeBefore = NodeAt(pos - 1);
			NodoLista<T>* nodeErase = NodeAt(pos);
			if (nodeBefore != nullptr && nodeErase != nullptr) {
				nodeBefore->siguiente = nodeErase->siguiente;
				delete nodeErase;
				longitud--;
			}
		}
	}

	void RemoveLast() {
		if (estaVacio()) {
			std::cout << "No se puede eliminar un nodo en una lista enlazada vacía" << std::endl;
			return;
		}
		if (longitud == 1) {
			NodoLista<T>* aux = cabeza;
			cabeza = nullptr;
			delete aux;
			longitud--;
		}
		else {
			NodoLista<T>* nodePreviousLast = NodeAt(longitud - 2);
			if (nodePreviousLast != nullptr) {
				NodoLista<T>* nodeLast = nodePreviousLast->siguiente;
				nodePreviousLast->siguiente = nullptr;
				delete nodeLast;
				longitud--;
			}
		}
	}

	T buscar(std::string nombre) {
		NodoLista<T>* temp = cabeza;

		while (temp != nullptr) {
			if (temp->valor.getNombre() == nombre) {
				return temp->valor;
				break;
			}
			temp = temp->siguiente;
		}
		return T();
	}

	void eliminar(std::string nombre) {
		NodoLista<T>* aux = cabeza;
		int pos = 1;
		
		while (aux != nullptr && aux->valor.getNombre() != nombre) {
			aux = aux->siguiente;
			pos++;
		}
		if (aux != nullptr) {
			RemovePos(pos);
		}
	}

	T GetFirst() {
		NodoLista<T>* first = NodeAt(0);
		return first;
	}

	T GetPos(int pos) {
		NodoLista<T>* node = NodeAt(pos);
		return node != nullptr ? node->valor : T();
	}

	T GetLast() {
		NodoLista<T>* last = NodeAt(longitud - 1);
		return last != nullptr ? last->valor : T();
	}

	T Buscar(std::string nombre) {
		NodoLista<T>* temp = cabeza;

		while (temp != nullptr) {
			if (temp->valor.getNombre() == nombre) {
				return temp->valor;
				break;
			}
			temp = temp->siguiente;
		}
		return T();
	}
};

template<typename T>
std::vector<T> listaAVector(Lista<T>* lista) {
	std::vector<T> vec;

	if (lista == nullptr || lista->estaVacio()) {
		return vec;
	}

	int len = lista->getLongitud();
	for (int i = 0; i < len; ++i) {
		vec.push_back(lista->GetPos(i));
	}

	return vec;
}

//Antes servía porque reconstruían una lista nueva
//pero ahora lo que realmente necesitas es mantener 
//la misma lista que ya usa todo el programa.
template<typename T>
Lista<T>* vectorALista(std::vector<T>& vec) {
	Lista<T>* lista = new Lista<T>();

	for (T& elemento : vec) {
		lista->AddLast(elemento);
	}

	return lista;

}
