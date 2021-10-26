#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"

using namespace std;

struct invoice{

    int client_number;
    string commune;
    float GB;
    float amount;

};

int menu ();
LinkedList<invoice> load (LinkedList<invoice>);
LinkedList<invoice> pay (LinkedList<invoice>);
void show (LinkedList<invoice>);

int main (){

    int option = 0;
    LinkedList<invoice> bills;
    bills = load(bills);

    do{
        option = menu();
        switch(option){
            case 0:
                break;
            case 1:
                pay(bills);
                break;
            case 2:
                show(bills);
                break;

            default:
                cout<<"Ingrese una opcion valida"<<endl;
        }
    }while(option != 0);

    return 0;
}

LinkedList<invoice> load (LinkedList<invoice> b){
    struct invoice bill;
    bill = {1,"Anisacate",100,7000};
    b.insert(0,bill);
    bill = {2,"La Bolsa",30,3000};
    b.insert(0,bill);
    bill = {3,"Villa Los Aromos",35,3500};
    b.insert(0,bill);
    return b;
}

int menu (){
    int option = 0;
    cout<<"Ingrese la opcion a realizar"<<endl;
    cout<<"1. Pagar factura"<<endl;
    cout<<"2. Mostrar listado y generar archivo con las facturas pagadas"<<endl;
    cout<<"0. Salir"<<endl;
    cin>>option;
    return option;
}

LinkedList<invoice> pay (LinkedList<invoice> b){

    struct invoice aux_b;
    int aux_num;
    int date;
    float aux_a;

    cout<<"Ingrese el numero de cliente"<<endl;
    cin>>aux_num;
    for (int i = 0; i < b.size(); ++i) {
        aux_b = b.get(i);
        if(aux_num == aux_b.client_number){
           cout<<"Ingrese la fecha de pago"<<endl;
           cin>>date;
           if(date>=11){
               aux_b.amount =aux_b.amount + 10;
           }

           cout<<"Numero de Cliente: "<<aux_b.client_number<<"\n"<<"Comuna: "<<aux_b.commune<<"\n"<<"GB consumidos: "<<aux_b.GB<<"\n"<<"Monto a Pagar: "<<aux_b.amount<<endl;
           cout<<"Ingrese el monto a pagar"<<endl;
           cin>>aux_a;
           aux_b.amount = aux_b.amount - aux_a;
           cout<<"------------------------------------------------"<<endl;
           cout<<"RECIBO"<<endl;
           cout<<"Numero de Cliente: "<<aux_b.client_number<<"\n"<<"Comuna: "<<aux_b.commune<<"\n"<<"GB consumidos: "<<aux_b.GB<<"\n"<<"Monto Pagado: "<<aux_a<<"\n"<<"Saldo: "<<aux_b.amount<<endl;
           cout<<"------------------------------------------------"<<endl;

           b.replace(i,aux_b);
        }
    }

    return b;
}

void show (LinkedList<invoice> b){
    struct invoice aux_b;
    ofstream bills;
    bills.open("Clientes_Cooperativa.txt",ios::app);
    for (int i = 0; i < b.size(); ++i) {
        aux_b = b.get(i);
        cout<<"------------------------------------------------"<<endl;
        bills<<"------------------------------------------------"<<endl;
        cout<<"Nro Cliente: "<<aux_b.client_number<<endl;
        bills<<"Nro Cliente: "<<aux_b.client_number<<endl;
        cout<<"Comuna: "<<aux_b.commune<<endl;
        bills<<"Comuna: "<<aux_b.commune<<endl;
        cout<<"GB consumidos: "<<aux_b.GB<<endl;
        bills<<"GB consumidos: "<<aux_b.GB<<endl;
        cout<<"Monto a Pagar: "<<aux_b.amount<<endl;
        bills<<"Monto a Pagar: "<<aux_b.amount<<endl;
        cout<<"------------------------------------------------"<<endl;
        bills<<"------------------------------------------------"<<endl;
    }
    bills.close();
}
