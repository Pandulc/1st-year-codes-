#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Product{
    string name;
    string mark;
    int price;
    string date;
    int size;
};

int main (){
    Product p;
    cout<<"Ingrese el nombre del producto"<<endl;
    getline(cin,p.name,'.');
    cout<<"Ingrese la marca del producto"<<endl;
    getline(cin,p.mark,'.');
    cout<<"Ingrese el precio del producto"<<endl;
    cin>>p.price;
    cout<<"Ingrese la fecha de caducidad del producto"<<endl;
    getline(cin,p.date,'.');
    cout<<"Ingrese el tamanio del producto"<<endl;
    cin>>p.size;
    ofstream product;
    product.open("Datos_Producto.txt");
    product<<"Datos del producto: "<<endl;
    product<<"Nombre: "<<p.name<<endl;
    product<<"Marca: "<<p.mark<<endl;
    product<<"Precio Unitario: "<<p.price<<endl;
    product<<"Fecha de Caducidad: "<<p.date<<endl;
    product<<"Tamanio: "<<p.size<<endl;
    product.close();
}
