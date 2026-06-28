#pragma once
#include <iostream>
#include <string>

class Notificacion {
private:
    std::string nombre;
    std::string descripcion;
    std::string id;

public:
    Notificacion() {
        nombre = "nada";
        descripcion = "nada";
        id = "U000";
    }
    Notificacion(std::string nombre, std::string descripcion, std::string id) : nombre(nombre), descripcion(descripcion), id(id) {}

    void setNombre(std::string nuevo) { nombre = nuevo; }
    void setDescripcion(std::string nuevo) { descripcion = nuevo; }
    void setId(std::string nuevo) { id = nuevo; }

    std::string getNombre() { return nombre; }
    std::string getDescripcion() { return descripcion; }
    std::string getId() { return id; }

    bool operator<(const Notificacion& otro) const {
        if (nombre != otro.nombre) {
            return nombre < otro.nombre;
        }
        return id < otro.id;
    }
    bool operator>(const Notificacion& otro) const {
        if (nombre != otro.nombre) {
            return nombre > otro.nombre;
        }
        return id > otro.id;
    }

    bool operator==(const Notificacion& otro) const {
        return nombre == otro.nombre && id == otro.id;
    }

    bool operator!=(const Notificacion& otro) const {
        return !(nombre == otro.nombre && id == otro.id);
    }
};

