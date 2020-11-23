#include <iostream>
#include <string>
#include <string.h>
#include "Estructuras/Dato.h"
#include "Estructuras/List.h"
#include "Estructuras/rangodeedad.h"
#include "Estructuras/AVLTree.h"
#include "Estructuras/provinciacomp.h"
#include "Estructuras/Dato2.h"

using namespace std;

int main(int argc, char *argv[]) //Para argumentos
{
    if (argc < 3 || argc > 4) { //Verifica que la cantida de arguentos este entre 3 y 4
        cout << "Argumentos ingresados incorrectamente" << endl;
        return 0;
    }
    char *esArchivoCsv = NULL;
    esArchivoCsv = strstr(argv[argc - 1], ".csv"); //Se asegura que uno de los argumentos sea .csv
    if (!esArchivoCsv) {
        cout << "No se especifico el archivo csv" << endl; // Si el archivo no es .csv
        return 0;
    }

    string myText;
    std::string Archivocsv = std::string(argv[argc - 1]);
    ifstream MyReadFile;
    MyReadFile.open("Covid19Casos-1000.csv", ios::app); //Apertura del excel
    if (MyReadFile.fail()) {
        cout << "Error al leer el archivo" << endl;
        return 0;
    }

    if (strcmp(argv[1], "-estad") == 0) { //Verifica que el arguemento haya sido -estad
        List<Dato> Lista; //Declaracion de lista
        AVLTree<rangodeedad> treeinfectados, treemuertos; //Declaracion de arbol
        int edad, casos = 0, infectados = 0, muertes = 0;
        while (getline(MyReadFile, myText, ',')) {
            casos++;
            getline(MyReadFile, myText, ',');

            getline(MyReadFile, myText, '"');
            getline(MyReadFile, myText, '"'); //Linea de edad
            try {
                edad = std::stoi(myText); //Verificacion si la edad esta puesta
            } catch (...) {
                edad = 0; //En caso de no tener edad
            }
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            if (myText == "\"Meses\"") { //Si la edad es en meses
                edad = 0;
            }
            int minrango = (edad / 10) * 10;
            int maxrango = minrango + 9;
            rangodeedad rangoetario(minrango, maxrango, 1);

            getline(MyReadFile, myText, ','); //Pais
            getline(MyReadFile, myText, ','); //Provincia
            getline(MyReadFile, myText, ','); //Departamento
            getline(MyReadFile, myText, ','); //Provincia de testeo
            getline(MyReadFile, myText, ','); //Inicio de sintomas
            getline(MyReadFile, myText, ','); //Fecha de consulta
            getline(MyReadFile, myText, ','); //Semana de la consulta
            getline(MyReadFile, myText, ','); //Fecha de interacion
            getline(MyReadFile, myText, ','); //CUI
            getline(MyReadFile, myText, ','); //Fecha de CUI
            getline(MyReadFile, myText, ','); //Muerte

            if (myText == "\"SI\"") {
                muertes++;
                try {
                    treemuertos.put(rangoetario);
                } catch (...) {
                    treemuertos.search(rangoetario).anadirCaso();
                }
            }
            getline(MyReadFile, myText, ','); //Fecha de muerte
            getline(MyReadFile, myText, ','); //Asistencia respiratoria
            getline(MyReadFile, myText, ','); //Codigo Provincia ingreso
            getline(MyReadFile, myText, ','); //Financiamiento
            getline(MyReadFile, myText, ','); //Estado
            getline(MyReadFile, myText, ','); //Resumen
            if (myText == "\"Confirmado\"") {
                infectados++;
                try {
                    treeinfectados.put(rangoetario);
                } catch (...) {
                    treeinfectados.search(rangoetario).anadirCaso();
                }
            }
            getline(MyReadFile, myText, ','); //ID Provincia
            getline(MyReadFile, myText, ','); //Fecha diagnostico
            getline(MyReadFile, myText, ','); //ID Departamento
            getline(MyReadFile, myText); //Ultima actualizacion
        }
        cout << "Cantidad total de muestras: " << casos << "\n";
        cout << "Cantidad total de infectados: " << infectados << "\n";
        cout << "Cantidad total de muertes: " << muertes << "\n";
        cout << "% de infectados: " << (infectados * 100 / casos) << "%\n";
        cout << "% de fallecidos: " << (muertes * 100 / infectados) << "%\n";
        cout << "Cantidad de infectados por rango etario\n";
        treeinfectados.print();
        cout << "Cantidad de muertes por rango etario\n";
        treemuertos.print();
    }

    if (strcmp(argv[1], "-p_casos") == 0) {//Verifica que el arguemento haya sido -p_casos
        int n = 0;
        string provincia;
        try {
            n = stoi(argv[2]);
        }
        catch (...) {
            n = 0;
        }
        List<provinciacomp> provinciasconfirm;
        getline(MyReadFile, myText); //salto la primera linea
        while (getline(MyReadFile, myText, ',')) {
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, provincia, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            if (myText == "\"Confirmado\"") {
                provinciacomp casoconfirmado(provincia);
                provinciasconfirm.start();
                while (!provinciasconfirm.isEnd()) {
                    if (provinciasconfirm.getRef()->getData().getNombreprovincia() == provincia) {
                        provinciasconfirm.getRef()->getData().anadirCaso();
                        provinciasconfirm.end();
                    } else {
                        provinciasconfirm.next();
                        if (provinciasconfirm.isEnd())
                            provinciasconfirm.push_front(provincia);
                    }
                }
                if (provinciasconfirm.isEmpty())
                    provinciasconfirm.push_front(casoconfirmado);
            }
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText);
        }
        for (int i = 1; i < provinciasconfirm.getSize(); i++) {
            provinciacomp temp = provinciasconfirm.get(i);
            int j = i - 1;
            while (j > -1) {
                if (provinciasconfirm.get(j) > temp) {
                    provinciacomp temp2 = provinciasconfirm.get(j);
                    provinciasconfirm.remove(j);
                    provinciasconfirm.insert(j + 1, temp2);
                }
                j--;
                if (j < 0)
                    break;
            }
        }
        if (n != 0) {
            provinciasconfirm.printn(n);
            return 0;
        }
        provinciasconfirm.print();
        return 0;
    }

    if (strcmp(argv[1], "-p_muertes") == 0) { //Verifica que el arguemento haya sido -p_muertes
        int n = 0;
        string provincia;
        try {
            n = stoi(argv[2]);
        }
        catch (...) {
            n = 0;
        }
        List<provinciacomp> provinciasconfirm;
        int edad;
        while (getline(MyReadFile, myText, ',')) {
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, '"');
            getline(MyReadFile, myText, '"');

            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');

            getline(MyReadFile, myText, ',');
            getline(MyReadFile, provincia, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            if (myText == "\"SI\"") {
                provinciacomp casoconfirmado(provincia);
                provinciasconfirm.start();
                while (!provinciasconfirm.isEnd()) {
                    if (provinciasconfirm.getRef()->getData().getNombreprovincia() == provincia) {
                        provinciasconfirm.getRef()->getData().anadirCaso();
                        provinciasconfirm.end();

                    } else {
                        provinciasconfirm.next();
                        if (provinciasconfirm.isEnd())
                            provinciasconfirm.push_front(provincia);
                    }
                }
                if (provinciasconfirm.isEmpty())
                    provinciasconfirm.push_front(casoconfirmado);
            }
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText);
        }
        for (int i = 1; i < provinciasconfirm.getSize(); i++) {
            provinciacomp temp = provinciasconfirm.get(i);
            int j = i - 1;
            while ((provinciasconfirm.get(j) > temp) && (j >= 0)) {
                provinciacomp temp2 = provinciasconfirm.get(j);
                provinciasconfirm.remove(j);
                provinciasconfirm.insert(j + 1, temp2);
                j--;
                if (j < 0)
                    break;
            }
        }
        if (n != 0) {
            provinciasconfirm.printn(n);
            return 0;
        }
        provinciasconfirm.print();
        return 0;
    }

    if (strcmp(argv[1], "-casos_edad") == 0) { //Verifica que el arguemento haya sido -casos_edad
        int n = 0;
        try {
            n = stoi(argv[2]);
        }
        catch (...) {
            cout << "No se ingreso edad" << endl;
            return 1;
        }
        List<Dato> casos;
        int edad;
        string id, sexo, pais, provincia, departamento, pcarga, fechainicio, fechaapertura, sepi, fechainternacion,
                cuidados_intensivos, fechacuidado, fallecido, fechafallecido, asistenciarespiratoria, cargaprovincia,
                financiamiento, clasificacion, clasificacionr, residenciaprovinciaid, fechadiagnostico, resideciadepartamentoid,
                ultimaactualizacion;
        while (getline(MyReadFile, id, ',')) {
            getline(MyReadFile, sexo, ',');
            getline(MyReadFile, myText, '"');
            getline(MyReadFile, myText, '"');
            try {
                edad = std::stoi(myText);
            } catch (...) {
                edad = 0;
            }
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            if (myText == "\"Meses\"") {
                edad = 0;
            }
            getline(MyReadFile, pais, ',');
            getline(MyReadFile, provincia, ',');
            getline(MyReadFile, departamento, ',');
            getline(MyReadFile, pcarga, ',');
            getline(MyReadFile, fechainicio, ',');
            getline(MyReadFile, fechaapertura, ',');
            getline(MyReadFile, sepi, ',');
            getline(MyReadFile, fechainternacion, ',');
            getline(MyReadFile, cuidados_intensivos, ',');
            getline(MyReadFile, fechacuidado, ',');
            getline(MyReadFile, fallecido, ',');
            getline(MyReadFile, fechafallecido, ',');
            getline(MyReadFile, asistenciarespiratoria, ',');
            getline(MyReadFile, cargaprovincia, ',');
            getline(MyReadFile, financiamiento, ',');
            getline(MyReadFile, clasificacion, ',');
            getline(MyReadFile, clasificacionr, ',');
            getline(MyReadFile, residenciaprovinciaid, ',');
            getline(MyReadFile, fechadiagnostico, ',');
            getline(MyReadFile, resideciadepartamentoid, ',');
            getline(MyReadFile, ultimaactualizacion);
            Dato Caso(id, sexo, edad, pais, provincia, departamento, pcarga, fechainicio, fechaapertura,
                      sepi, fechainternacion, cuidados_intensivos, fechacuidado, fallecido, fechafallecido,
                      asistenciarespiratoria, cargaprovincia, financiamiento, clasificacion, clasificacionr,
                      residenciaprovinciaid, fechadiagnostico, resideciadepartamentoid, ultimaactualizacion);
            if (edad == n) {
                casos.push_front(Caso);
            }
        }
        for (int i = 1; i < casos.getSize(); i++) {
            Dato temp = casos.get(i);
            int j = i - 1;
            while ((casos.get(j) > temp) && (j >= 0)) {
                Dato temp2 = casos.get(j);
                casos.remove(j);
                casos.insert(j + 1, temp2);
                j--;
            }
        }
        casos.print();
    }
    if (strcmp(argv[1], "-casos_cui") == 0) { //Verifica que el arguemento haya sido -casos_cui
        string n;
        try {
            n = argv[2];
            string x = argv[3];
        }
        catch (...) {
            n = "1970-01-01";
        }
        List<Dato2> casos;
        string edad;
        string id, sexo, pais, provincia, departamento, pcarga, fechainicio, fechaapertura, sepi, fechainternacion,
                cuidados_intensivos, fechacuidado, fallecido, fechafallecido, asistenciarespiratoria, cargaprovincia,
                financiamiento, clasificacion, clasificacionr, residenciaprovinciaid, fechadiagnostico, resideciadepartamentoid,
                ultimaactualizacion;
        while (getline(MyReadFile, id, ',')) {
            getline(MyReadFile, sexo, ',');
            getline(MyReadFile, myText, '"');
            getline(MyReadFile, myText, '"');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, myText, ',');
            getline(MyReadFile, pais, ',');
            getline(MyReadFile, provincia, ',');
            getline(MyReadFile, departamento, ',');
            getline(MyReadFile, pcarga, ',');
            getline(MyReadFile, fechainicio, ',');
            getline(MyReadFile, fechaapertura, ',');
            getline(MyReadFile, sepi, ',');
            getline(MyReadFile, fechainternacion, ',');
            getline(MyReadFile, cuidados_intensivos, ',');
            getline(MyReadFile, fechacuidado, ',');
            getline(MyReadFile, fallecido, ',');
            getline(MyReadFile, fechafallecido, ',');
            getline(MyReadFile, asistenciarespiratoria, ',');
            getline(MyReadFile, cargaprovincia, ',');
            getline(MyReadFile, financiamiento, ',');
            getline(MyReadFile, clasificacion, ',');
            getline(MyReadFile, clasificacionr, ',');
            getline(MyReadFile, residenciaprovinciaid, ',');
            getline(MyReadFile, fechadiagnostico, ',');
            getline(MyReadFile, resideciadepartamentoid, ',');
            getline(MyReadFile, ultimaactualizacion);
            Dato2 Caso(id, sexo, edad, pais, provincia, departamento, pcarga, fechainicio, fechaapertura,
                       sepi, fechainternacion, cuidados_intensivos, fechacuidado, fallecido, fechafallecido,
                       asistenciarespiratoria, cargaprovincia, financiamiento, clasificacion, clasificacionr,
                       residenciaprovinciaid, fechadiagnostico, resideciadepartamentoid, ultimaactualizacion);
            if (cuidados_intensivos == "\"SI\"") {
                casos.push_front(Caso);
            }
        }
        for (int i = 1; i < casos.getSize(); i++) {
            Dato2 temp = casos.get(i);
            int j = i - 1;
            while ((casos.get(j) > temp) && (j >= 0)) {
                Dato2 temp2 = casos.get(j);
                casos.remove(j);
                casos.insert(j + 1, temp2);
                j--;
                if (j < 0)
                    break;
            }
        }
        if (n == "1970-01-01") {
            casos.print();
            return 0;
        }
        casos.printf(n);
    }


// Close the file
    MyReadFile.close();
    return 0;
}