#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

class Item {
private:
    std::string nombre;
    std::string descripcion;
    int precio;

public:
    Item() {
        nombre = "nada";
        descripcion = "nada";
        precio = -1;
    }
    Item(std::string nombre, std::string descripcion, int precio) : nombre(nombre), descripcion(descripcion), precio(precio) {}

    void setNombre(std::string nuevo) { nombre = nuevo; }
    void setDescripcion(std::string nuevo) { descripcion = nuevo; }
    void setPrecio(int nuevo) { precio = nuevo; }

    std::string getNombre() { return nombre; }
    std::string getDescripcion() { return descripcion; }
    int getPrecio() { return precio; }

    friend std::ostream& operator<<(std::ostream& os, const Item& item) {
        os << item.nombre << " (" << item.precio << " G)";
        return os;
    }

    bool operator<(const Item& otro) const {
        if (nombre != otro.nombre) {
            return nombre < otro.nombre;
        }
        return precio < otro.precio;
    }
    bool operator>(const Item& otro) const {
        if (nombre != otro.nombre) {
            return nombre > otro.nombre;
        }
        return precio > otro.precio;
    }

    bool operator==(const Item& otro) const {
        return nombre == otro.nombre && precio == otro.precio;
    }

    bool operator!=(const Item& otro) const {
        return !(nombre == otro.nombre && precio == otro.precio);
    }
};

