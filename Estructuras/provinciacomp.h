#ifndef PROVINCIACOMP_H
#define PROVINCIACOMP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

class provinciacomp {
private:
    string nombreprovincia;
    int cantidad;
public:
    const string &getNombreprovincia() const;

    void setNombreprovincia(const string &nombreprovincia);

public:
    provinciacomp(const string &nombreprovincia) : nombreprovincia(nombreprovincia) { cantidad = 1; }

    void anadirCaso() {
        int a = provinciacomp::cantidad;
        a++;
        provinciacomp::cantidad = a;
    }

    bool operator<(const provinciacomp &rhs) const;

    bool operator>(const provinciacomp &rhs) const;

    bool operator<=(const provinciacomp &rhs) const;

    bool operator>=(const provinciacomp &rhs) const;

    friend ostream &operator<<(ostream &os, const provinciacomp &provinciacomp);

};

const string &provinciacomp::getNombreprovincia() const {
    return nombreprovincia;
}

void provinciacomp::setNombreprovincia(const string &nombreprovincia) {
    provinciacomp::nombreprovincia = nombreprovincia;
}

bool provinciacomp::operator<(const provinciacomp &rhs) const {
    return nombreprovincia < rhs.nombreprovincia;
}

bool provinciacomp::operator>(const provinciacomp &rhs) const {
    return rhs < *this;
}

bool provinciacomp::operator<=(const provinciacomp &rhs) const {
    return !(rhs < *this);
}

bool provinciacomp::operator>=(const provinciacomp &rhs) const {
    return !(*this < rhs);
}

ostream &operator<<(ostream &os, const provinciacomp &provinciacomp) {
    os << "nombreprovincia: " << provinciacomp.nombreprovincia << " cantidad: " << provinciacomp.cantidad;
    return os;
}

#endif //PROVINCIACOMP_H
