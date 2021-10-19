#include <iostream>

using namespace std;


int main (){

    int number = 10;
    int * pointer;
    pointer = &number;

    cout<<"Valor de Numero: "<<number<<endl;
    cout<<"Valor de Puntero: "<<pointer<<endl;
    cout<<"Valor al que apunta Puntero: "<<*pointer<<endl;
    cout<<"Direccion de memoria de Numero: "<<&number<<endl;
    cout<<"Direccion de memoria de Puntero: "<<&pointer<<endl;

    return 0;
}
