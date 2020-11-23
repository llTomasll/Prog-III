#ifndef RANGODEEDAD_H
#define RANGODEEDAD_H

#include <ostream>

class rangodeedad {
private:
    int minimo;
    int maximo;
    int cantidad;
public:
    rangodeedad(int minimo, int maximo, int cantidad) : minimo(minimo), maximo(maximo), cantidad(cantidad) {}

public:
    int getCantidad() const {
        return cantidad;
    }

    void setCantidad(int cantidad) {
        rangodeedad::cantidad = cantidad;
    }

    void anadirCaso(){
        int a=rangodeedad::cantidad;
        a++;
        rangodeedad::cantidad=a;
    }

    bool operator<(const rangodeedad &rhs) const {
        if (minimo < rhs.minimo)
            return true;
        if (rhs.minimo < minimo)
            return false;
        return maximo < rhs.maximo;
    }

    bool operator>(const rangodeedad &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const rangodeedad &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const rangodeedad &rhs) const {
        return !(*this < rhs);
    }

    bool operator==(const rangodeedad &rhs) const {
        return minimo == rhs.minimo &&
               maximo == rhs.maximo;
    }

    bool operator!=(const rangodeedad &rhs) const {
        return !(rhs == *this);
    }

    friend ostream &operator<<(ostream &os, const rangodeedad &rangodeedad) {
        os << "minimo: " << rangodeedad.minimo << " maximo: " << rangodeedad.maximo << " cantidad: "
           << rangodeedad.cantidad;
        return os;
    }
};

#endif //RANGODEEDAD_H
