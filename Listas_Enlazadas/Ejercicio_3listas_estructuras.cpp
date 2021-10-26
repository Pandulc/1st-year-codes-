#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

struct Stock{
    int code = 0;
    string name = " ";
    int quantity = 0;
    float price = 0;
};

int menu ();
LinkedList<Stock> load (LinkedList<Stock>);
void show_stock (LinkedList<Stock>);
void rest_stock (LinkedList<Stock>);
void add_stock (LinkedList<Stock>);


int main (){

    LinkedList<Stock> s;
    int option;

    do{
        option = menu();
        switch(option){
            case 0:
                break;
            case 1:
                s = load(s);
                break;
            case 2:
                show_stock(s);
                break;
            case 3:
                rest_stock(s);
                break;
            case 4:
                add_stock(s);
                break;
            default:
                cout<<"Ingrese una opcion valida"<<endl;
        }
    }while(option != 0);

    return 0;
}

int menu (){
    int option = 0;
    cout<<"Ingrese la opcion a realizar"<<endl;
    cout<<"1. Cargar datos"<<endl;
    cout<<"2. Mostrar listado completo"<<endl;
    cout<<"3. Descontar Stock de producto especifico"<<endl;
    cout<<"4. Sumar Stock de producto especifico"<<endl;
    cout<<"0. Salir"<<endl;
    cin>>option;
    return option;
}

LinkedList<stock> load (LinkedList<stock> stock){
    struct Stock aux;

    for (int i = 0; i < 3; ++i) {
        aux.code = i + 1;
        cout<<"Ingrese el nombre del producto numero "<<i+1<<endl;
        getline(cin,aux.name,'.');
        cout<<"Ingrese la cantidad de elementos en Stock"<<endl;
        cin>>aux.quantity;
        cout<<"Ingrese el precio de lista"<<endl;
        cin>>aux.price;
        stock.insert(i,aux);
    }

    return stock;
}

void show_stock (LinkedList<stock> stock){
    cout<<"Codigo\tNombre\tCantidad   Precio"<<endl;
    for (int i = 0; i < 3; ++i) {
        cout<<"  "<<stock.get(i).code;
        cout<<"  "<<stock.get(i).name;
        cout<<"  "<<stock.get(i).quantity;
        cout<<"  "<<stock.get(i).price;
        cout<<endl;
    }

}

void rest_stock (LinkedList<stock> stock){
    int code = 0;
    int stock_toremove = 0;
    struct Stock aux;

    cout<<"Ingrese el codigo de producto a descontar Stock"<<endl;
    cin>>code;
    cout<<"Ingrese el Stock a reducir"<<endl;
    cin>>stock_toremove;

    for (int i = 0; i < 3; ++i) {
        if(stock.get(i).code == code){
            aux.code = stock.get(i).code;
            aux.quantity = stock.get(i).quantity - stock_toremove;
            aux.name = stock.get(i).name;
            aux.price = stock.get(i).price;
            stock.replace(i,aux);
        }
    }
}

void add_stock (LinkedList<stock> stock){
    int code = 0;
    int stock_toadd = 0;
    struct Stock aux;

    cout<<"Ingrese el codigo de producto a agregar Stock"<<endl;
    cin>>code;
    cout<<"Ingrese el Stock a agregar"<<endl;
    cin>>stock_toadd;

    for (int i = 0; i < 3; ++i) {
        if(stock.get(i).code == code){
            aux.code = stock.get(i).code;
            aux.quantity = stock.get(i).quantity + stock_toadd;
            aux.name = stock.get(i).name;
            aux.price = stock.get(i).price;
            stock.replace(i,aux);
        }
    }

}

