#pragma once
#include <vector>
#include "Lista.h"
#include "Usuario.h"
#include "MergeSort.h"

class Ranking {
private:
public:
	void ordenarRankingPorXP(Lista<Usuario>* listaUsuarios) {
		//Trasladar de lista enlazada a vector
		std::vector<Usuario> tempVector = listaAVector(listaUsuarios);

		//Lambda
		auto criterioXP = [](const Usuario& a, const Usuario& b) {
			return a.getExperiencia() >= b.getExperiencia();
			};

		if (!tempVector.empty()) {
			mergeSort(tempVector, 0, tempVector.size() - 1, criterioXP);
		}

		//listaUsuarios = vectorALista(tempVector);
		//Reconstruir la lista enlazada con los usuarios ordenados
		while (!listaUsuarios->estaVacio()) {
			listaUsuarios->RemoveFirst();
		}

		for (const Usuario& usuario : tempVector) {
			listaUsuarios->AddLast(usuario);
		}
	}
};