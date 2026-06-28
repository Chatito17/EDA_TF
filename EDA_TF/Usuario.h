#pragma once
#include <iostream>
#include <string>

class Usuario {
private:
	std::string id;
	std::string nombre;
	std::string idioma;
	int experiencia;
	int racha;

public:
	Usuario() {}
	Usuario(std::string id, std::string nombre, std::string idioma, int experiencia, int racha) {
		this->id = id;
		this->nombre = nombre;
		this->idioma = idioma;
		this->experiencia = experiencia;
		this->racha = racha;
	}

	std::string getID() const {
		return id;
	}
	std::string getNombre() const {
		return nombre;
	}
	std::string getIdioma() const {
		return idioma;
	}
	int getExperiencia() const {
		return experiencia;
	}
	int getRacha() const {
		return racha;
	}
	void setExperiencia(int xp) {
		experiencia = xp;
	}
	void setRacha(int racha) {
		this->racha = racha;
	}
};

