//1. Crear en c�digo c++ una clase Veh�culo y luego un vector de dos objetos.

#include <iostream>
#include "vehicle.h"

using namespace std;

int main(int argc, char *argv[]) {
    vehicle v[2];
    string ty = " ";
    string en = " ";
    string co = " ";
    int ca = 0;
    int ii = 0;
    for (ii = 0; ii < 2; ii++) {
        cout << "Ingrese el tipo de vehiculo presente" << endl;
        cin >> ty;
        v[ii].set_type(ty);
        cout << "Ingrese la patente del vehiculo" << endl;
        cin >> en;
        v[ii].set_enrollment(en);
        cout << "Ingrese el color del vehiculo" << endl;
        cin >> co;
        v[ii].set_colour(co);
        cout << "Ingrese la capacidad del vehiculo" << endl;
        cin >> ca;
        v[ii].set_capacity(ca);
    }
    cout << endl;
    for (ii = 0; ii < 2; ii++) {
        cout << "Los datos del vehiculo son" << endl;
        cout << "Tipo: " << v[ii].get_type() << endl;
        cout << "Patente: " << v[ii].get_enrollment() << endl;
        cout << "Color: " << v[ii].get_colour() << endl;
        cout << "Capacidad: " << v[ii].get_capacity() << endl;
    }


    return 0;
}


