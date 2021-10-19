#include <iostream>
#include <fstream>
#include <string>
#define TAM 3

using namespace std;

struct Product{
    string name;
    string mark;
    int price;
    string date;
    int size;
};

int menu (void);
void write (Product []);
void read (void);

int main(){
    Product p[TAM];
    int option = 0;

    do{
        option = menu();
        switch(option){
            case 1:
                write(p);
                break;
            case 2:
                read();
                break;
            default:
                cout<<"Ingrese una opcion valida"<<endl;
        }
    }while(option != 0);
}

int menu (){
    int op = 0;
    cout<<"Ingrese la opcion a realizar"<<endl;
    cout<<"1. Cargar lista de productos en el archivo"<<endl;
    cout<<"2. Mostrar la lista de productos"<<endl;
    cout<<"0. Salir"<<endl;
    cin>>op;
    return op;
}

void write (Product pr [TAM]){
    int ii = 0;

    for(ii = 0; ii < TAM ; ii++){
        cout<<"Ingrese el nombre del producto"<<endl;
        getline(cin,pr[ii].name,'.');
        cout<<"Ingrese la marca del producto"<<endl;
        getline(cin,pr[ii].mark,'.');
        cout<<"Ingrese el precio del producto"<<endl;
        cin>>pr[ii].price;
        cout<<"Ingrese la fecha de caducidad del producto"<<endl;
        getline(cin,pr[ii].date,'.');
        cout<<"Ingrese el tamanio del producto"<<endl;
        cin>>pr[ii].size;
    }
    ofstream product;
    product.open("Datos_Producto_Estructura.txt");
    for(ii = 0; ii < TAM; ii++){
        product<<"Datos del Producto "<<ii+1<<endl;
        product<<"Nombre: "<<pr[ii].name<<endl;
        product<<"Marca: "<<pr[ii].mark<<endl;
        product<<"Precio: "<<pr[ii].price<<endl;
        product<<"Fecha de Caducidad: "<<pr[ii].date<<endl;
        product<<"Tamanio: "<<pr[ii].size<<endl;
    }
    product.close();
}

void read (){
    string message = " ";
    ifstream product;
    product.open("Datos_Producto_Estructura.txt");
    while(!product.eof()){
        getline(product, message);
        cout<<message<<endl;
    }
    product.close();
}