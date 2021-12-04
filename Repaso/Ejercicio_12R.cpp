//Escribir un programa donde se solicite el tamaño del vector y reservar memoria. Luego al finalizar la ejecución del
//programa liberarla.  (malloc, sizeof). El tamaño debe ser entre 1 y 10, caso contrario debe mostrar el mensaje de
//error y solicitar nuevamente el ingreso de otro número. Luego crear las siguientes funciones:

//rellenarVector() que rellene aleatoriamente el vector con números del 1 al 20 utilizando punteros.
//
//mostrarVector() que muestre el vector anterior por medio de punteros los valores del vector y sus correspondientes direcciones.
//
//sumar() que sume los primeros “n” valores del vector de manera recursiva.
//
//Utilizar funciones y punteros en este ejercicio.

#include <iostream>
#include <ctime>

using namespace std;

int menu();

int *load(int *, int);

void show(int *, int);

int sum(int *, int);


int main() {

    int option;
    int *vector;
    int size;
    int total;
    int n;

    cout << "Ingrese la cantidad de valores a cargar (entre 1 y 10)" << endl;
    cin >> size;
    if (size > 10) {
        cout << "Porfavor, igrese un valor entre 1 y 10" << endl;
        cin >> size;
    }
    vector = new int[size];

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                vector = load(vector, size);
                cout << endl;
                break;
            case 2:
                show(vector, size);
                cout << endl;
                break;
            case 3:
                cout << "Ingrese la cantidad de elementos a sumar" << endl;
                cin >> n;
                total = sum(vector, n-1);
                cout << "La suma de los n elementos es: " << total << endl;
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
    } while (option != 0);

    delete vector;
    return 0;
}

int menu() {
    int op = 0;
    cout << "Ingrese la opcion a realizar" << endl;
    cout << "1. Rellenar el vector" << endl;
    cout << "2. Mostrar los valores y su direccion de memoria" << endl;
    cout << "3. Calcular la suma de n numeros del vector" << endl;
    cout << "0. Salir" << endl;
    cin >> op;

    return op;
}

int *load(int *v, int s) {
    v = new int[s];
    int number;
    srand(time(NULL));
    for (int i = 0; i < s; ++i) {
        number = rand() % 20 + 1;
        v[i] = number;
    }
    return v;
}

void show(int *v, int s) {
    cout << "Valores del vector y su direccion de memoria:" << endl;
    for (int i = 0; i < s; ++i) {
        cout << "Valor: " << v[i] << "\n" << "Direccion de Memoria: " << &v[i] << endl;
    }
}

int sum(int *v, int n) {
    int total = 0;
    if (n == -1) {
        return total;
    }
    else{
        total = total + v[n] + sum(v, n - 1);
    }
    return total;

}