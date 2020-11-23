#ifndef PARCIAL_2_PROG_III_DATO2_H
#define PARCIAL_2_PROG_III_DATO2_H

#include <string>
#include <ostream>

using namespace std;

class Dato2 {
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
    Dato2(const string &id, const string &sexo, int edad, const string &pais, const string &provincia,
         const string &departamento, const string &pcarga, const string &fechainicio, const string &fechaapertura,
         const string &sepi, const string &fechainternacion, const string &cuidadosIntensivos,
         const string &fechacuidado, const string &fallecido, const string &fechafallecido,
         const string &asistenciarespiratoria, const string &cargaprovincia, const string &financiamiento,
         const string &clasificacion, const string &clasificacionr, const string &residenciaprovinciaid,
         const string &fechadiagnostico, const string &resideciadepartamentoid, const string &ultimaactualizacion);

    Dato2(const string &id, const string &sexo, const string &edadcadena, const string &pais, const string &provincia,
         const string &departamento, const string &pcarga, const string &fechainicio, const string &fechaapertura,
         const string &sepi, const string &fechainternacion, const string &cuidadosIntensivos,
         const string &fechacuidado, const string &fallecido, const string &fechafallecido,
         const string &asistenciarespiratoria, const string &cargaprovincia, const string &financiamiento,
         const string &clasificacion, const string &clasificacionr, const string &residenciaprovinciaid,
         const string &fechadiagnostico, const string &resideciadepartamentoid, const string &ultimaactualizacion);


    bool operator<(const Dato2 &rhs) const;

    bool operator>(const Dato2 &rhs) const;

    bool operator<=(const Dato2 &rhs) const;

    bool operator>=(const Dato2 &rhs) const;

    friend ostream &operator<<(ostream &os, const Dato2 &dato2);

    const string &getFechacuidado() const;

    void setFechacuidado(const string &fechacuidado);

};

Dato2::Dato2(const string &id, const string &sexo, int edad, const string &pais, const string &provincia,
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

Dato2::Dato2(const string &id, const string &sexo, const string &edadcadena, const string &pais, const string &provincia,
           const string &departamento, const string &pcarga, const string &fechainicio, const string &fechaapertura,
           const string &sepi, const string &fechainternacion, const string &cuidadosIntensivos,
           const string &fechacuidado, const string &fallecido, const string &fechafallecido,
           const string &asistenciarespiratoria, const string &cargaprovincia, const string &financiamiento,
           const string &clasificacion, const string &clasificacionr, const string &residenciaprovinciaid,
           const string &fechadiagnostico, const string &resideciadepartamentoid, const string &ultimaactualizacion)
        : id(id), sexo(sexo), edadcadena(edadcadena), pais(pais), provincia(provincia), departamento(departamento),
          pcarga(pcarga), fechainicio(fechainicio), fechaapertura(fechaapertura), sepi(sepi),
          fechainternacion(fechainternacion), cuidados_intensivos(cuidadosIntensivos), fechacuidado(fechacuidado),
          fallecido(fallecido), fechafallecido(fechafallecido), asistenciarespiratoria(asistenciarespiratoria),
          cargaprovincia(cargaprovincia), financiamiento(financiamiento), clasificacion(clasificacion),
          clasificacionr(clasificacionr), residenciaprovinciaid(residenciaprovinciaid),
          fechadiagnostico(fechadiagnostico), resideciadepartamentoid(resideciadepartamentoid),
          ultimaactualizacion(ultimaactualizacion) {}

bool Dato2::operator<(const Dato2 &rhs) const {
    return fechacuidado < rhs.fechacuidado;
}

bool Dato2::operator>(const Dato2 &rhs) const {
    return rhs < *this;
}

bool Dato2::operator<=(const Dato2 &rhs) const {
    return !(rhs < *this);
}

bool Dato2::operator>=(const Dato2 &rhs) const {
    return !(*this < rhs);
}

ostream &operator<<(ostream &os, const Dato2 &dato2) {
    os << "id: " << dato2.id << " sexo: " << dato2.sexo << " edad: " << dato2.edadcadena << " pais: "
       << dato2.pais << " provincia: " << dato2.provincia << " departamento: " << dato2.departamento << " pcarga: "
       << dato2.pcarga << " fechainicio: " << dato2.fechainicio << " fechaapertura: " << dato2.fechaapertura
       << " sepi: " << dato2.sepi << " fechainternacion: " << dato2.fechainternacion << " cuidados_intensivos: "
       << dato2.cuidados_intensivos << " fechacuidado: " << dato2.fechacuidado << " fallecido: " << dato2.fallecido
       << " fechafallecido: " << dato2.fechafallecido << " asistenciarespiratoria: " << dato2.asistenciarespiratoria
       << " cargaprovincia: " << dato2.cargaprovincia << " financiamiento: " << dato2.financiamiento
       << " clasificacion: " << dato2.clasificacion << " clasificacionr: " << dato2.clasificacionr
       << " residenciaprovinciaid: " << dato2.residenciaprovinciaid << " fechadiagnostico: " << dato2.fechadiagnostico
       << " resideciadepartamentoid: " << dato2.resideciadepartamentoid << " ultimaactualizacion: "
       << dato2.ultimaactualizacion;
    return os;
}

const string &Dato2::getFechacuidado() const {
    return fechacuidado;
}

void Dato2::setFechacuidado(const string &fechacuidado) {
    Dato2::fechacuidado = fechacuidado;
}

#endif //PARCIAL_2_PROG_III_DATO2_H