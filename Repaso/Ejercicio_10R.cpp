//Escribir un programa utilizando punteros y funciones en la cual se desea load en un vector con las ventas diarias
//de un negocio, 10 como máximo. La carga finaliza cuando el amount igual a cero. Además, se pide:
//
//Cantidad de ventas cargadas.
//
//Calcular la recaudación del día.
//
//Guardar los datos en un archivo.
//
//Utilizar funciones y punteros en este ejercicio.


#include <iostream>
#include <fstream>

#define TAM 10

using namespace std;

int menu();

void load(int []);

void quantity(int []);

void collection(int []);

void save(int []);

int main() {

    int bills[TAM] = {0};
    int option;

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                load(bills);
                break;
            case 2:
                quantity(bills);
                break;
            case 3:
                collection(bills);
                break;
            case 4:
                save(bills);
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
    } while (option != 0);


    return 0;
}

int menu() {
    int op = 0;
    cout << "Ingrese la opcion a realizar" << endl;
    cout << "1. Cargar factura" << endl;
    cout << "2. Mostrar cantidad de ventas cargadas" << endl;
    cout << "3. Calcular recaudacion total" << endl;
    cout << "4. Guardar los datos en un archivo" << endl;
    cout << "0. Salir" << endl;
    cin >> op;
    return op;
}

void load(int b[]) {
    int amount = 0;
    int counter = 0;
    do {
        cout << "Ingrese el amount de la factura" << endl;
        cin >> amount;
        b[counter] = amount;
        counter++;
    } while (amount != 0);
}

void quantity(int b[]) {
    int counter = 0;
    for (int i = 0; i < TAM; ++i) {
        if (b[i] != 0) {
            counter++;
        }
    }
    cout << "Cantidad de facturas cargadas: " << counter << endl;
}

void collection(int b[]) {
    int collection = 0;
    for (int i = 0; i < TAM; ++i) {
        collection = collection + b[i];
    }
    cout << "La recaudacion total del dia fue de: " << collection << endl;
}

void save (int b []){
    ofstream Bills;
    Bills.open("Facturas_dia.txt",ios::app);
    for (int i = 0; i < TAM; ++i) {
        if(b[i] != 0){
            Bills << "Factura "<< i<< ": " << b[i] << endl;
        }
    }
    Bills.close();
}