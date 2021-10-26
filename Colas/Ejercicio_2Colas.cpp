#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Product{
    int code;
    string name;
    int quantity;
    float price;
};

int menu ();
queue<Product> load (queue<Product>);
void show_list (queue<Product>);
queue<Product> stock_discount (queue<Product>);
queue<Product> stock_add (queue<Product>);

int main (){

    int option = 0;
    queue<Product> stock;
    stock = load(stock);

    do{
        option = menu();
        switch(option){
            case 0:
                break;
            case 1:
                show_list(stock);
                break;
            case 2:
                stock = stock_discount(stock);
                break;
            case 3:
                stock = stock_add(stock);
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
    cout<<"1. Mostrar listado de elementos"<<endl;
    cout<<"2. Descontar stock"<<endl;
    cout<<"3. Agregar stock"<<endl;
    cout<<"0. Salir"<<endl;
    cin>>option;
    return option;

}

queue<Product> load (queue<Product> s){
    struct Product aux;
    aux = {0,"Pan",10,25};
    s.push(aux);
    aux = {1,"Facturas",50,30};
    s.push(aux);
    aux = {2,"Alfajores",5,55};
    s.push(aux);
    return s;
}

void show_list (queue<Product> s){
    queue<Product> aux;
    while(!s.empty()){
        cout<<"--------------------------------------------------------------------------"<< endl;
        cout <<"Codigo: "<< s.front().code << "\n" << "Nombre: "<< s.front().name << endl;
        cout <<"Stock: " << s.front().quantity << "\n" << "Precio: " << s.front().price << endl;
        cout<<"--------------------------------------------------------------------------"<< endl;
        aux.push(s.front());
        s.pop();

    }
    s = aux;
    cout<<endl;
}

queue<Product> stock_discount (queue<Product> s) {

    struct Product aux_s;
    int quantity;

    cout<<"Ingrese la cantidad de stock a descontar"<<endl;
    cin>>quantity;
    s.front().quantity = s.front().quantity - quantity;

    return s;

}

queue<Product> stock_add (queue<Product> s) {

    struct Product aux_s;
    int quantity;

    cout<<"Ingrese la cantidad de stock a agregar"<<endl;
    cin>>quantity;
    s.front().quantity = s.front().quantity + quantity;

    return s;

}