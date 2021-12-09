#include <iostream>
#include <cstdlib>
#include <ctime>

#define TAM 5
using namespace std;

int menu();

void carga_datos(int *);

void muestra_valorydireccion(int *);

void muestra_mayorymenor(int *);

void suma_pares(int *);

int main() {

    int opcion = 0;
    int vector[TAM];
    carga_datos(vector);
    do {
        opcion = menu();
        switch (opcion) {
            case 0:
                break;
            case 1:
                muestra_valorydireccion(vector);
                break;
            case 2:
                muestra_mayorymenor(vector);
                break;
            case 3:
                suma_pares(vector);
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
    } while (opcion != 0);


    return 0;
}

int menu() {
    int op = 0;

    cout << "Ingrese la opcion a realizar" << endl;
    cout << "1. Mostrar los valores y direcciones de memoria." << endl;
    cout << "2. Buscar y show el numero menor y el numero mayor." << endl;
    cout << "3. Calcular la suma de los valores pares." << endl;
    cout << "0. Salir." << endl;
    cin >> op;

    return op;
}

void carga_datos(int *v) {
    int numero = 0;
    srand(time(NULL));
    for (int i = 0; i < TAM; ++i) {
        numero = rand() % 10 + 1;
        v[i] = numero;
    }
}

void muestra_valorydireccion(int *v) {

    cout << "Los valores del vector son:" << endl;
    for (int ii = 0; ii < TAM; ii++) {
        cout << " " << v[ii];
    }
    cout << "\nLas direcciones de memoria de los elementos del vector son:" << endl;
    for (int ii = 0; ii < TAM; ii++) {
        cout << " " << &v[ii];
    }
    cout << endl;
}

void muestra_mayorymenor(int *v) {

    int mayor = 0;
    int menor = 0;

    for (int i = 0; i < TAM; ++i) {
        if (i == 0) {
            mayor = v[i];
            menor = v[i];
        }
        if (mayor < v[i]) {
            mayor = v[i];
        }
        if (menor > v[i]) {
            menor = v[i];
        }
    }
    cout << "El valor mayor de la lista es: " << mayor << endl;
    cout << "El valor menor de la lista es: " << menor << endl;
}

void suma_pares(int *v) {
    int sumador = 0;
    for (int i = 0; i < TAM; ++i) {
        if (v[i] % 2 == 0) {
            sumador = sumador + v[i];
        }
    }
    cout << "La suma de los valores pares es: " << sumador << endl;
}