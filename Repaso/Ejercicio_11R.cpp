//Escribir un programa que cree un vector de 5 valores aleatorios entre el 1 al 10. Luego crear las siguientes funciones:
//
//Mostrar todos los valores del vector anterior por medio de punteros.
//
//Mostrar los valores mayores a 5 por medio de punteros y su correspondiente dirección.
//
//Calcular la sumatoria de los valores.
//
//Guardar en un archivo los resultados anteriores (los puntos a, b y c)
//
//Utilizar funciones y punteros en este ejercicio.

#include <iostream>
#include <ctime>
#include <fstream>

#define TAM 5

using namespace std;

int menu();

void create(int []);

void show(int []);

void biggersThan5(int []);

void sum(const int []);

void save(int []);

int main() {

    int option;
    int numbers[TAM] = {0};
    create(numbers);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                show(numbers);
                cout << "\n\n";
                break;
            case 2:
                biggersThan5(numbers);
                cout << endl;
                break;
            case 3:
                sum(numbers);
                cout << endl;
                break;
            case 4:
                save(numbers);
                cout << endl;
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
    cout << "1. Mostrar los valores" << endl;
    cout << "2. Mostrar valores mayores a 5 y su direccion de memoria" << endl;
    cout << "3. Calcular la suma total" << endl;
    cout << "4. Guardar los datos en un archivo" << endl;
    cout << "0. Salir" << endl;
    cin >> op;
    cout << endl;
    return op;
}

void create(int n[]) {
    int number;
    srand(time(NULL));
    for (int i = 0; i < TAM; ++i) {
        number = rand() % 10 + 1;
        n[i] = number;
    }
}

void show(int n[]) {
    for (int i = 0; i < TAM; ++i) {
        cout << n[i] << "\t";
    }
}

void biggersThan5(int n[]) {
    cout << "Los valores mayores a 5 son:" << endl;
    for (int i = 0; i < TAM; ++i) {
        if (n[i] >= 5) {
            cout << "Valor: " << n[i] << "\n" << "Direccion de Memoria: " << &n[i] << endl;
        }
    }
}

void sum(const int n[]) {
    int sum = 0;
    for (int i = 0; i < TAM; ++i) {
        sum = sum + n[i];
    }
    cout << "La suma de los valores es: " << sum << endl;
}

void save(int n[]) {
    int sum = 0;
    ofstream Vector;
    Vector.open("Vector.txt", ios::app);
    Vector << "-------------------------------------" << endl;
    Vector << "Valores del vector:" << endl;
    for (int i = 0; i < TAM; ++i) {
        Vector << n[i] << "\t";
        sum = sum + n[i];
    }
    Vector << endl;
    Vector << "Valores mayores a 5:" << endl;
    for (int i = 0; i < TAM; ++i) {
        if (n[i] >= 5) {
            Vector << "Valor: " << n[i] << "\n" << "Direccion de Memoria: " << &n[i] << endl;
        }
    }
    Vector << "Suma de los valores: " << sum << endl;
    Vector << "-------------------------------------" << endl;
    Vector.close();
}