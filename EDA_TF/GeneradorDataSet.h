#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Usuario.h"
#include "Item.h"

std::vector<std::string> nombresBase = {
	"Juan", "Maria", "Carlos", "Ana", "Luis",
	"Lucia", "Pedro", "Elena", "Jorge", "Sofia",
	"Diego", "Laura", "Mateo", "Valentina", "Andres",
	"Camila", "Daniel", "Fernanda", "Miguel", "Paula",
	"Sebastian", "Gabriela", "Ricardo", "Patricia", "Alejandro",
	"Natalia", "Fernando", "Carmen", "Alberto", "Daniela",
	"Adrian", "Isabel", "Oscar", "Rosa", "Hector",
	"Andrea", "Emilio", "Melissa", "Raul", "Noelia",
	"Kevin", "Renata", "Victor", "Claudia", "Martin",
	"Brenda", "Julio", "Fiorella", "Marco", "Angela"
};

std::vector<std::string> apellidosBase = {
	"Perez", "Gomez", "Rodriguez", "Lopez", "Garcia",
	"Martinez", "Sanchez", "Diaz", "Torres", "Flores",
	"Ramirez", "Cruz", "Benitez", "Alvarez", "Castro",
	"Rojas", "Vargas", "Morales", "Herrera", "Silva",
	"Navarro", "Mendoza", "Paredes", "Campos", "Salazar",
	"Reyes", "Espinoza", "Chavez", "Ortega", "Vega",
	"Aguilar", "Guerrero", "Valdez", "Delgado", "Cordero",
	"Fuentes", "Suarez", "Cabrera", "Medina", "Montoya",
	"Quispe", "Huaman", "Mamani", "Condori", "Palacios",
	"Carrasco", "Romero", "Leiva", "Acosta", "Bravo"
};

std::vector<std::string> idiomasBase = {
	"Ingles", "Frances", "Aleman", "Italiano", "Portugues", "Japones"
};

std::vector<std::string> nombresItem = {
	"DobleEXP", "VidaExtra", "Traje", "Protector"
};
std::vector<std::string> descripcionesItem = {
	"Duplica ganancia de exp ", "Aumenta una vida", "Protege del frio", "Protege la racha por un dia"
};

Usuario generarUsuarioAleatorio(int consecutivo) {
	std::string id = "U" + std::to_string(1000 + consecutivo);
	std::string nombreCompleto = nombresBase[rand() % nombresBase.size()] + " " + apellidosBase[rand() % apellidosBase.size()];
	std::string idioma = idiomasBase[rand() % idiomasBase.size()];
	int xp = rand() % 5000;
	int racha = rand() % 100;
	return Usuario(id, nombreCompleto, idioma, xp, racha);
}

Item generarItemAleatorio() {
	int ind = rand() % 4;
	std::string nombre = nombresItem[ind];
	std::string desc = descripcionesItem[ind];
	int precio = rand() % 100 + 1;

	return Item(nombre, desc, precio);
}