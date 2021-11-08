#include <iostream>

using namespace std;

void rotate_values(float *, float *);

int main() {
    float a = 0;
    float b = 0;

    cout << "Ingrese el valor de a" << endl;
    cin >> a;
    cout << "Ingrese el valor de b" << endl;
    cin >> b;
    cout << "Valor de a antes de rotar los valores: " << a << endl;
    cout << "Valor de b antes de rotar los valores: " << b << endl;
    rotate_values(&a, &b);
    cout << "Valor de a despues de rotar los valores: " << a << endl;
    cout << "Valor de b despues de rotar los valores: " << b << endl;

    return 0;
}

void rotate_values(float *A, float *B) {
    float temporal = 0;
    temporal = *A;
    *A = *B;
    *B = temporal;
}