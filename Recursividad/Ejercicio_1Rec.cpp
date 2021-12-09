//1. Realizar un programa que solicite el ingresar de un número y show su equivalente en binario usando una función recursiva. Por ejemplo:
//
//SISTEMA DECIMAL    SISTEMA BINARIO

//2                10

//3                11

//4                100

//5                101

#include<iostream>

using namespace std;

void binary_converter(int);

int main() {
    int numero = 0;

    do {

        cout << endl << "ingrese un numero para saber su equivalente en binario, ingrese un numero negativo para salir"
             << endl;
        cout << "cargue el numero: " << endl;
        cin >> numero;
        binary_converter(numero);

    } while (numero > 0);

    return 0;
}

void binary_converter(int num) {

    if (num == 0) {
        cout << "0";
    } else {
        binary_converter(num / 2);
    }
    cout << num % 2;

}