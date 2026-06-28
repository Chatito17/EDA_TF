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

		//Lista enlazada nueva con usuarios ya ordenados
		//listaUsuarios = vectorALista(tempVector);
		//void ordenarRankingPorXP(Lista<Usuario>*listaUsuarios)
	}
};