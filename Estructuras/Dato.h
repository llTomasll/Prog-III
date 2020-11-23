#ifndef PARCIAL_2_PROG_III_DATO_H
#define PARCIAL_2_PROG_III_DATO_H

#include <string>
#include <ostream>

using namespace std;

class Dato {
private:
    string id;
    string sexo;
    int edad;
    string edadcadena;
    string pais;
    string provincia;
    string departamento;
    string pcarga;
    string fechainicio;
    string fechaapertura;
    string sepi;
    string fechainternacion;
    string cuidados_intensivos;
    string fechacuidado; //
    string fallecido; //
    string fechafallecido;
    string asistenciarespiratoria;
    string cargaprovincia;
    string financiamiento;
    string clasificacion;
    string clasificacionr; //
    string residenciaprovinciaid;
    string fechadiagnostico;
    string resideciadepartamentoid;
    string ultimaactualizacion;

public:

    Dato(const string &id, const string &sexo, int edad, const string &pais, const string &provincia,
         const string &departamento, const string &pcarga, const string &fechainicio, const string &fechaapertura,
         const string &sepi, const string &fechainternacion, const string &cuidadosIntensivos,
         const string &fechacuidado, const string &fallecido, const string &fechafallecido,
         const string &asistenciarespiratoria, const string &cargaprovincia, const string &financiamiento,
         const string &clasificacion, const string &clasificacionr, const string &residenciaprovinciaid,
         const string &fechadiagnostico, const string &resideciadepartamentoid, const string &ultimaactualizacion);

    bool operator<(const Dato &rhs) const;

    bool operator>(const Dato &rhs) const;

    bool operator<=(const Dato &rhs) const;

    bool operator>=(const Dato &rhs) const;

    friend ostream &operator<<(ostream &os, const Dato &dato);
};


bool Dato::operator<(const Dato &rhs) const {
    return provincia < rhs.provincia;
}

bool Dato::operator>(const Dato &rhs) const {
    return rhs < *this;
}

bool Dato::operator<=(const Dato &rhs) const {
    return !(rhs < *this);
}

bool Dato::operator>=(const Dato &rhs) const {
    return !(*this < rhs);
}

Dato::Dato(const string &id, const string &sexo, int edad, const string &pais, const string &provincia,
           const string &departamento, const string &pcarga, const string &fechainicio, const string &fechaapertura,
           const string &sepi, const string &fechainternacion, const string &cuidadosIntensivos,
           const string &fechacuidado, const string &fallecido, const string &fechafallecido,
           const string &asistenciarespiratoria, const string &cargaprovincia, const string &financiamiento,
           const string &clasificacion, const string &clasificacionr, const string &residenciaprovinciaid,
           const string &fechadiagnostico, const string &resideciadepartamentoid, const string &ultimaactualizacion)
        : id(id), sexo(sexo), edad(edad), pais(pais), provincia(provincia), departamento(departamento), pcarga(pcarga),
          fechainicio(fechainicio), fechaapertura(fechaapertura), sepi(sepi), fechainternacion(fechainternacion),
          cuidados_intensivos(cuidadosIntensivos), fechacuidado(fechacuidado), fallecido(fallecido),
          fechafallecido(fechafallecido), asistenciarespiratoria(asistenciarespiratoria),
          cargaprovincia(cargaprovincia), financiamiento(financiamiento), clasificacion(clasificacion),
          clasificacionr(clasificacionr), residenciaprovinciaid(residenciaprovinciaid),
          fechadiagnostico(fechadiagnostico), resideciadepartamentoid(resideciadepartamentoid),
          ultimaactualizacion(ultimaactualizacion) {}

ostream &operator<<(ostream &os, const Dato &dato) {
    os << "id: " << dato.id << " sexo: " << dato.sexo << " edad: " << dato.edad << " pais: " << dato.pais
       << " provincia: " << dato.provincia << " departamento: " << dato.departamento << " pcarga: " << dato.pcarga
       << " fechainicio: " << dato.fechainicio << " fechaapertura: " << dato.fechaapertura << " sepi: " << dato.sepi
       << " fechainternacion: " << dato.fechainternacion << " cuidados_intensivos: " << dato.cuidados_intensivos
       << " fechacuidado: " << dato.fechacuidado << " fallecido: " << dato.fallecido << " fechafallecido: "
       << dato.fechafallecido << " asistenciarespiratoria: " << dato.asistenciarespiratoria << " cargaprovincia: "
       << dato.cargaprovincia << " financiamiento: " << dato.financiamiento << " clasificacion: " << dato.clasificacion
       << " clasificacionr: " << dato.clasificacionr << " residenciaprovinciaid: " << dato.residenciaprovinciaid
       << " fechadiagnostico: " << dato.fechadiagnostico << " resideciadepartamentoid: " << dato.resideciadepartamentoid
       << " ultimaactualizacion: " << dato.ultimaactualizacion;
    return os;
}

#endif //PARCIAL_2_PROG_III_DATO_H