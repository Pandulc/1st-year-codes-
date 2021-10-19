#include <iostream>
#include <math.h>

using namespace std;

int menu();

void sum(float *, float *);

void subtraction(float *, float *);

void division(float *, float *);

void multiplication(float *, float *);

void potency(float *, float *);

void square_root(float *);

int main() {
    float a = 0;
    float b = 0;
    int option = 0;
    do {
        option = menu();
        switch (option) {
            case 1:
                cout << "Ingrese el primer operando" << endl;
                cin >> a;
                cout << "Ingrese el segundo operando" << endl;
                cin >> b;
                sum(&a, &b);
                break;
            case 2:
                cout << "Ingrese el primer operando" << endl;
                cin >> a;
                cout << "Ingrese el segundo operando" << endl;
                cin >> b;
                subtraction(&a, &b);
                break;
            case 3:
                cout << "Ingrese el primer operando" << endl;
                cin >> a;
                cout << "Ingrese el segundo operando" << endl;
                cin >> b;
                multiplication(&a, &b);
                break;
            case 4:
                cout << "Ingrese el primer operando" << endl;
                cin >> a;
                cout << "Ingrese el segundo operando" << endl;
                cin >> b;
                division(&a, &b);
                break;
            case 5:
                cout << "Ingrese el primer operando" << endl;
                cin >> a;
                cout << "Ingrese el exponente a potenciar" << endl;
                cin >> b;
                potency(&a, &b);
                break;
            case 6:
                cout << "Ingrese el operando" << endl;
                cin >> a;
                square_root(&a);
                break;
            default:
                cout<<"Ingrese una opcion valida"<<endl;
        }
    } while (option != 0);

    return 0;
}

int menu() {
    int option = 0;

    cout << "Ingrese la opcion a realizar" << endl;
    cout << "1) Sumar 2 valores" << endl << "2) Restar 2 valores" << endl << "3) Multiplicar 2 valores" << endl
         << "4) Dividir 2 valores" << endl << "5) Elevar un numero a una potencia" << endl
         << "6) Calcular la raiz de un numero" << endl << "0) Salir" << endl;
    cin >> option;
    return option;
}

void sum(float *A, float *B) {
    float r = 0;
    r = *A + *B;
    cout << "El resultado es: " << r << endl;
}

void subtraction(float *A, float *B) {
    float r = 0;
    r = *A - *B;
    cout << "El resultado es: " << r << endl;
}

void multiplication(float *A, float *B) {
    float r = 0;
    r = *A * *B;
    cout << "El resultado es: " << r << endl;
}

void division(float *A, float *B) {
    float r = 0;
    r = *A / *B;
    cout << "El resultado es: " << r << endl;
}

void potency(float *A, float *B) {
    float r = 0;
    r = pow(*A,*B);
    cout << "El resultado es: " << r << endl;
}

void square_root(float *A) {
    float r = 0;
    r = sqrt(*A);
    cout << "El resultado es: " << r << endl;
}