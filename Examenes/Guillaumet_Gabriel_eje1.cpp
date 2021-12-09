#include <iostream>
#include <string>
#include <fstream>

#define TAM  3
using namespace std;

struct Celular {
    int codigo;
    string marca;
    float precio_lista;
    float precio_publico;
    int stock;
};

int menu();

void carga_datos(Celular *);

void mostrar_listado_completo(Celular *);

void mostrar_listado_noStock(Celular *);

void calcula_precio(Celular *);

void ordena_porPrecio(Celular *);

int main() {

    int opcion = 0;
    Celular celulares[TAM];
    carga_datos(celulares);
    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                mostrar_listado_completo(celulares);
                break;
            case 2:
                mostrar_listado_noStock(celulares);
                break;
            case 3:
                calcula_precio(celulares);
                break;
            case 4:
                ordena_porPrecio(celulares);
                break;
        }
    } while (opcion != 0);


    return 0;
}

int menu() {
    int op = 0;

    cout << "Ingrese la opcion a realizar" << endl;
    cout << "1. show el listado completo de celulares." << endl;
    cout
            << "2. show el listado completo de celulares que no hay Stock. Y generar un archivo para enviar al proveedor."
            << endl;
    cout << "3. Calcular precio al publico." << endl;
    cout << "4. Ordenar por precio al publico." << endl;
    cout << "0. Salir." << endl;
    cin >> op;

    return op;
}

void carga_datos(Celular *c) {

    c[0].codigo = 1;
    c[0].marca = "Samsung";
    c[0].precio_lista = 600;
    c[0].precio_publico = 0;
    c[0].stock = 0;
    c[1].codigo = 2;
    c[1].marca = "Apple";
    c[1].precio_lista = 1000;
    c[1].precio_publico = 0;
    c[1].stock = 3;
    c[2].codigo = 3;
    c[2].marca = "Nokia";
    c[2].precio_lista = 300;
    c[2].precio_publico = 0;
    c[2].stock = 4;
}

void mostrar_listado_completo(Celular *c) {

    cout << "Listado Completo" << endl;
    for (int ii = 0; ii < TAM; ii++) {
        cout << "------------------------------------------" << endl;
        cout << "Codigo: " << c[ii].codigo << endl;
        cout << "Marca: " << c[ii].marca << endl;
        cout << "Precio de Lista: " << c[ii].precio_lista << endl;
        cout << "Precio al Publico: " << c[ii].precio_publico << endl;
        cout << "Stock: " << c[ii].stock << endl;
        cout << "------------------------------------------" << endl;
    }
}

void mostrar_listado_noStock(Celular *c) {

    cout << "Listado de Celulares sin Stock" << endl;
    for (int ii = 0; ii < TAM; ii++) {
        if (c[ii].stock == 0) {
            ofstream celulares;
            celulares.open("Listado_Celulares_noStock.txt", ios::app);
            cout << "------------------------------------------" << endl;
            celulares << "------------------------------------------" << endl;
            cout << "Codigo: " << c[ii].codigo << endl;
            celulares << "Codigo: " << c[ii].codigo << endl;
            cout << "Marca: " << c[ii].marca << endl;
            celulares << "Marca: " << c[ii].marca << endl;
            cout << "Precio de Lista: " << c[ii].precio_lista << endl;
            celulares << "Precio de Lista: " << c[ii].precio_lista << endl;
            cout << "Precio al Publico: " << c[ii].precio_publico << endl;
            celulares << "Precio al Publico: " << c[ii].precio_publico << endl;
            cout << "Stock: " << c[ii].stock << endl;
            celulares << "Stock: " << c[ii].stock << endl;
            cout << "------------------------------------------" << endl;
            celulares << "------------------------------------------" << endl;
        }
    }
}

void calcula_precio(Celular *c) {
    for (int i = 0; i < TAM; ++i) {
        c[i].precio_publico = ((c[i].precio_lista * 30) / 100) + c[i].precio_lista;
    }
}

void ordena_porPrecio(Celular *c) {
    Celular *tmp = nullptr;
    Celular **tmp2 = nullptr;
    float precio = 0;
    for (int i = 0; i < TAM; ++i) {
        if (i == 0) {
            precio = c[i].precio_publico;
            tmp = &c[i];
        }
        if (precio < c[i].precio_publico) {
            tmp2 = &c[i];
            c[i] = *tmp;
            tmp = &tmp2;//Tengo algun error que no logro entender, lo vemos la clase que viene jajaja

        }
    }
}
