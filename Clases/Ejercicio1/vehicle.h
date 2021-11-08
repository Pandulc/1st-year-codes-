//1. Crear en c�digo c++ una clase Veh�culo y luego un vector de dos objetos.

#include <string>

using namespace std;

//Definicion de la clase
class vehicle {
private:
    string type;
    int capacity;
    string enrollment;
    string colour;
public:
    vehicle();

    void set_type(string);

    string get_type();

    void set_capacity(int);

    int get_capacity();

    void set_enrollment(string);

    string get_enrollment();

    void set_colour(string);

    string get_colour();

};

//Definicion de las funciones
vehicle::vehicle() {
}

void vehicle::set_type(string t) {
    type = t;
}

string vehicle::get_type() {
    return type;
}

void vehicle::set_capacity(int c) {
    capacity = c;
}

int vehicle::get_capacity() {
    return capacity;
}

void vehicle::set_enrollment(string e) {
    enrollment = e;
}

string vehicle::get_enrollment() {
    return enrollment;
}

void vehicle::set_colour(string c) {
    colour = c;
}

string vehicle::get_colour() {
    return colour;
}

