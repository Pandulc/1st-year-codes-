#include <iostream>
#include <fstream>
#include "Ejercicio_3.h"

using namespace std;

int menu();

int main(){
    Product product[TAM];
    int option = 0;
    do{
        option = menu();
        switch(option){
            case 1:
                product->write(product);
                break;
            case 2:
                product->read();
                break;
            default:
                cout<<"Ingrese una opcion valida"<<endl;
                break;
        }
    }while(option != 0);

}

int menu(){
    int op = 0;
    cout<<"Ingrese la opcion a realizar"<<endl;
    cout<<"1. Cargar lista de productos en el archivo"<<endl;
    cout<<"2. Mostrar la lista de productos"<<endl;
    cout<<"0. Salir"<<endl;
    cin>>op;
    return op;
}