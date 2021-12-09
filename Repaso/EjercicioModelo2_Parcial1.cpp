#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Phone{
    string mark;
    string model;
    float price;
};

void load (Phone *, int);
void show_list (Phone *,int);
void show_list_byprice (Phone *,int);
void save (Phone *,int);

int main (){
    int quantity = 0;

    Phone * phone;
    cout<<"Ingrese el numero de telefonos a load"<<endl;
    cin>>quantity;
    phone = new Phone [quantity];
    load(phone,quantity);
    show_list(phone,quantity);
    cin.clear();

    show_list_byprice(phone,quantity);
    save(phone,quantity);
    return 0;
}

void load (Phone * p,int q){

    for (int i = 0; i < q; ++i) {
        cout<<"Ingrese la marca del celular "<<i+1<<endl;
        getline(cin,p[i].mark,'.');
        cout<<"Ingrese el modelo del celular"<<i+1<<endl;
        getline(cin,p[i].model,'.');
        cout<<"Ingrese el precio del celular"<<i+1<<endl;
        cin>>p[i].price;
    }
}

void show_list (Phone * p,int q){
    for (int i = 0; i < q; ++i) {
        cout<<"Marca del celular: "<<p[i].mark<<endl;
        cout<<"Modelo del celular: "<<p[i].model<<endl;
        cout<<"Precio del celular: "<<p[i].price<<endl;

    }
}

void show_list_byprice (Phone * p, int q){
    int price = 0;
    cout<<"Ingrese el precio para filtrar"<<endl;
    cin>>price;
    for (int i = 0; i < q; ++i) {
        if(p[i].price<price){
            cout<<"Marca del celular: "<<p[i].mark<<endl;
            cout<<"Modelo del celular: "<<p[i].model<<endl;
            cout<<"Precio del celular: "<<p[i].price<<endl;
        }
    }
}

void save (Phone * p, int q){
    ofstream phones;
    phones.open("Catalogo_Telefonos.txt",ios::app);
    for (int i = 0; i < q; ++i) {
        phones<<"Marca del celular: "<<p[i].mark<<endl;
        phones<<"Modelo del celular: "<<p[i].model<<endl;
        phones<<"Precio del celular: "<<p[i].price<<endl;
    }

}