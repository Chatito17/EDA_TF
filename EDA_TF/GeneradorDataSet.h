#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Usuario.h"
#include "Item.h"
#include "Notificacion.h"
#include "Pregunta.h"

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

std::vector<std::string> enunciado = {
    "Hola",
    "Buenos días",
    "Buenas noches",
    "¿Cómo estás?",
    "Estoy bien",
    "Gracias",
    "De nada",
    "¿Cuál es tu nombre?",
    "Mi nombre es John",
    "Mucho gusto",

    "¿De dónde eres?",
    "Soy de Perú",
    "¿Cuántos años tienes?",
    "Tengo veinte años",
    "¿Hablas inglés?",
    "Sí, hablo un poco",
    "No entiendo",
    "¿Puedes repetir?",
    "Habla más despacio",
    "Lo siento",

    "Tengo hambre",
    "Tengo sed",
    "Quiero agua",
    "Quiero comer",
    "¿Dónde está el baño?",
    "¿Cuánto cuesta?",
    "Es muy caro",
    "Es barato",
    "Necesito ayuda",
    "Llama a la policía",

    "Hoy hace calor",
    "Hoy hace frío",
    "Está lloviendo",
    "Me gusta estudiar",
    "Estoy aprendiendo inglés",
    "Voy a la escuela",
    "Él es mi amigo",
    "Ella es mi hermana",
    "Tenemos un perro",
    "Ellos viven aquí",

    "Abre la puerta",
    "Cierra la ventana",
    "Siéntate",
    "Levántate",
    "Escucha con atención",
    "Lee este libro",
    "Escribe tu nombre",
    "¿Qué hora es?",
    "Son las ocho",
    "Hasta luego"
};

std::vector<std::string> respuestas = {
    "Hello",
    "Good morning",
    "Good night",
    "How are you?",
    "I am fine",
    "Thank you",
    "You're welcome",
    "What is your name?",
    "My name is John",
    "Nice to meet you",

    "Where are you from?",
    "I am from Peru",
    "How old are you?",
    "I am twenty years old",
    "Do you speak English?",
    "Yes, I speak a little",
    "I don't understand",
    "Can you repeat?",
    "Speak more slowly",
    "I'm sorry",

    "I am hungry",
    "I am thirsty",
    "I want water",
    "I want to eat",
    "Where is the bathroom?",
    "How much does it cost?",
    "It is very expensive",
    "It is cheap",
    "I need help",
    "Call the police",

    "It is hot today",
    "It is cold today",
    "It is raining",
    "I like studying",
    "I am learning English",
    "I go to school",
    "He is my friend",
    "She is my sister",
    "We have a dog",
    "They live here",

    "Open the door",
    "Close the window",
    "Sit down",
    "Stand up",
    "Listen carefully",
    "Read this book",
    "Write your name",
    "What time is it?",
    "It is eight o'clock",
    "See you later"
};

std::vector<std::string> nombresNotificacion = {
	"Alumno Expulsado", "Actualizacion grande", "Correccion de bugs", "Nuevos features"
};
std::vector<std::string> descripcionesNotificacion = {
	"Se reporto al usuario Marvans por hacker", "La nueva aplicacion de Duolingo necesitara 1 gb de almacenamiento", "Se corrigieron bugs visuales", "Ahora se pueden adquirir trajes"
};

Usuario generarUsuarioAleatorio(int consecutivo) {
	std::string id = "U" + std::to_string(1000 + consecutivo);
	std::string nombreCompleto = nombresBase[rand() % nombresBase.size()] + " " + apellidosBase[rand() % apellidosBase.size()];
	std::string idioma = idiomasBase[rand() % idiomasBase.size()];
	int xp = rand() % 5000;
	int racha = rand() % 100;
	return Usuario(id, nombreCompleto, idioma, xp, racha);
}

Notificacion generarNotificacionAleatoria(int consecutivo) {
	std::string id = "N" + std::to_string(1000 + consecutivo);
	int aux = rand() % 4;
	std::string nombre = nombresNotificacion[aux];
	std::string descripcion = descripcionesNotificacion[aux];

	return Notificacion(nombre, descripcion, id);
}

Item generarItemAleatorio() {
	int ind = rand() % 4;
	std::string nombre = nombresItem[ind];
	std::string desc = descripcionesItem[ind];
	int precio = rand() % 100 + 1;

	return Item(nombre, desc, precio);
}

Pregunta generarPreguntaAleatoria() {
	int ind = rand() % 4;
	std::string enun = enunciado[ind];
	std::string rpta = respuestas[ind];
	int diff = rand() % 10 + 1;

	return Pregunta(enun, diff, rpta);
}