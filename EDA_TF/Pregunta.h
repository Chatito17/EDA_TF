#pragma once
class Pregunta
{
private:
    std::string enunciado = "";
    int Dificultad = 0;
    std::string Respuesta = "";

public:
    Pregunta(){}
    Pregunta(std::string _enunciado, int diff, std::string rpta) : enunciado(_enunciado), Dificultad(diff), Respuesta(rpta) {}
    std::string getNombre() {
        return enunciado;
    }
    bool operator==(const Pregunta& otro) const {
        return enunciado == otro.enunciado && Dificultad == otro.Dificultad;
    }
    std::string getRespuesta() { return Respuesta; }
    int getDificultad() { return Dificultad; }
};
