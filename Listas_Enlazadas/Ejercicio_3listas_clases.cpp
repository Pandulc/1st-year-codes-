#include <iostream>
#include "Stock.h"
#include "LinkedList.h"

int menu ();
LinkedList<Stock> load (LinkedList<Stock>);
void show_stock (LinkedList<Stock>);
void rest_stock (LinkedList<Stock>);
void add_stock (LinkedList<Stock>);

int main(){

    LinkedList<Stock> stock;
    int option = 0;

    do{
        option = menu();
        switch(option){
            case 0:
                break;
            case 1:
                stock = load(stock);
                break;
            case 2:
                show_stock(stock);
                break;
            case 3:
                rest_stock(stock);
                break;
            case 4:
                add_stock(stock);
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
    cout<<"3. Descontar stock de producto especifico"<<endl;
    cout<<"4. Sumar stock de producto especifico"<<endl;
    cout<<"0. Salir"<<endl;
    cin>>option;
    return option;
}

LinkedList<Stock> load (LinkedList<Stock> stock){
    Stock aux;
    string aux_name;
    int aux_quantity;
    float aux_price;

    for (int i = 0; i < 3; ++i) {
        aux.setCode(i + 1);
        cout<<"Ingrese el nombre del producto numero "<<i+1<<endl;
        getline(cin,aux_name,'.');
        aux.setName(aux_name);
        cout<<"Ingrese la cantidad de elementos en stock"<<endl;
        cin>>aux_quantity;
        aux.setQuantity(aux_quantity);
        cout<<"Ingrese el precio de lista"<<endl;
        cin>>aux_price;
        aux.setPrice(aux_price);
        stock.insert(i,aux);
    }

    return stock;
}

void show_stock (LinkedList<Stock> stock){
    cout<<"Codigo\tNombre\tCantidad   Precio"<<endl;
    for (int i = 0; i < 3; ++i) {
        cout<<"  "<<stock.get(i).getCode();
        cout<<"  "<<stock.get(i).getName();
        cout<<"  "<<stock.get(i).getQuantity();
        cout<<"  "<<stock.get(i).getPrice();
        cout<<endl;
    }
}

void rest_stock (LinkedList<Stock> stock){
    int code = 0;
    int stock_toremove = 0;
    Stock aux;

    cout<<"Ingrese el codigo de producto a descontar stock"<<endl;
    cin>>code;
    cout<<"Ingrese el stock a reducir"<<endl;
    cin>>stock_toremove;

    for (int i = 0; i < 3; ++i) {
        if(stock.get(i).getCode() == code){
            aux.setCode(stock.get(i).getCode());
            aux.setQuantity(stock.get(i).getQuantity() - stock_toremove);
            aux.setName(stock.get(i).getName());
            aux.setPrice(stock.get(i).getPrice());
            stock.replace(i,aux);
        }
    }
}

void add_stock (LinkedList<Stock> stock){
    int code = 0;
    int stock_toadd = 0;
    Stock aux;

    cout<<"Ingrese el codigo de producto a agregar stock"<<endl;
    cin>>code;
    cout<<"Ingrese el stock a agregar"<<endl;
    cin >> stock_toadd;

    for (int i = 0; i < 3; ++i) {
        if(stock.get(i).getCode() == code){
            aux.setCode(stock.get(i).getCode());
            aux.setQuantity(stock.get(i).getQuantity() + stock_toadd);
            aux.setName(stock.get(i).getName());
            aux.setPrice(stock.get(i).getPrice());
            stock.replace(i,aux);
        }
    }
}