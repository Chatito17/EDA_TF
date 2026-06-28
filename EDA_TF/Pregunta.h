#pragma once
class Pregunta
{
private:
    string enunciado = "";
    int Dificultad = 0;
    string Respuesta = "";

public:
    Pregunta(){}
    Pregunta(string _enunciado, int diff, string rpta) : enunciado(_enunciado), Dificultad(diff), Respuesta(rpta) {}
    string getNombre() {
        return enunciado;
    }
    bool operator==(const Pregunta& otro) const {
        return enunciado == otro.enunciado && Dificultad == otro.Dificultad;
    }
};
