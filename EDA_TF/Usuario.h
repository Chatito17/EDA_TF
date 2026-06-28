#pragma once
#include <iostream>
#include <string>
using namespace std;

class Usuario {
private:
	string id;
	string nombre;
	string idioma;
	int experiencia;
	int racha;

public:
	Usuario() {}
	Usuario(string id, string nombre, string idioma, int experiencia, int racha) {
		this->id = id;
		this->nombre = nombre;
		this->idioma = idioma;
		this->experiencia = experiencia;
		this->racha = racha;
	}

	string getID() const {
		return id;
	}
	string getNombre() const {
		return nombre;
	}
	string getIdioma() const {
		return idioma;
	}
	int getExperiencia() const {
		return experiencia;
	}
	int getRacha() const {
		return racha;
	}
	void setExperiencia(int xp) {
		this->experiencia = xp;
	}
	void setRacha(int racha) {
		this->racha = racha;
	}

	bool operator==(const Usuario& otro) const {
		return nombre == otro.nombre;
	}
};

