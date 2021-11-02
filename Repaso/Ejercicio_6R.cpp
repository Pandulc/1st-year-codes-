#include <iostream>
#include "../Listas_Enlazadas/LinkedList.h"
#include <fstream>

using namespace std;

struct Ticket{
    int number;
    char info;
    int persons;
    float amount;
};

int menu ();
void generate_ticket (LinkedList<Ticket> *,int);
void generate_summary (LinkedList<Ticket>);

int main (){

    int option;
    int ticket_number;
    LinkedList<Ticket> station;

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                ticket_number++;
                generate_ticket(&station,ticket_number);
                break;
            case 2:
                generate_summary(station);
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
    } while (option != 0);

    return 0;
}

int menu (){

    int option = 0;
    cout<<"Ingrese la opcion a realizar"<<endl;
    cout<<"1. Generar ticket."<<endl;
    cout<<"2. Generar resumen del dia."<<endl;
    cout<<"0. Salir"<<endl;
    cin>>option;
    return option;

}

void generate_ticket (LinkedList<Ticket> * l,int n){

    struct Ticket t_ticket;

    t_ticket.number = n;
    cout<<"Entra o Sale de la ciudad?"<<endl;
    cin>>t_ticket.info;
    cout<<"Ingrese la cantidad de personas en el vehiculo"<<endl;
    cin>>t_ticket.persons;
    if(t_ticket.persons == 1){
        t_ticket.amount = 40;
    }
    if(t_ticket.persons == 2){
        t_ticket.amount = 30;
    }
    if(t_ticket.persons == 3){
        t_ticket.amount = 20;
    }
    if(t_ticket.persons >= 4){
        t_ticket.amount = 10;
    }

    cout<<"-------------------------------------"<<endl;
    cout<<"Nro Ticket: "<<t_ticket.number<<"\n"<<"Entra/Sale: "<<t_ticket.info<<"\n";
    cout<<"Cant. Personas: "<<t_ticket.persons<<"\n"<<"Monto: "<<t_ticket.amount<<endl;
    cout<<"-------------------------------------"<<endl;
    l->insert(0,t_ticket);

}

void generate_summary (LinkedList<Ticket> l){

    struct Ticket t_ticket;
    int car_E = 0;
    int persons_E = 0;
    int car_S = 0;
    int persons_S = 0;
    int total_amount = 0;

    ofstream stationA;
    stationA.open("Estacion_A.txt",ios::app);

    for (int i = 0; i < l.size(); ++i){
        if(l.get(i).info == 'E'){
            car_E++;
            persons_E = persons_E + l.get(i).persons;
        }
        if(l.get(i).info == 'S'){
            car_S++;
            persons_S = persons_S + l.get(i).persons;
        }
        total_amount = total_amount + l.get(i).amount;

        t_ticket = l.get(i);

        stationA<<"-------------------------------------"<<endl;
        cout<<"-------------------------------------"<<endl;
        stationA<<"Nro Ticket: "<<t_ticket.number<<"\n"<<"Entra/Sale: "<<t_ticket.info<<"\n";
        cout<<"Nro Ticket: "<<t_ticket.number<<"\n"<<"Entra/Sale: "<<t_ticket.info<<"\n";
        stationA<<"Cant. Personas: "<<t_ticket.persons<<"\n"<<"Monto: "<<t_ticket.amount<<endl;
        cout<<"Cant. Personas: "<<t_ticket.persons<<"\n"<<"Monto: "<<t_ticket.amount<<endl;
        stationA<<"-------------------------------------"<<endl;
        cout<<"-------------------------------------"<<endl;

    }

    cout<<"Cantidad total de autos que entran a la ciudad: "<<car_E<<endl;
    stationA<<"Cantidad total de autos que entran a la ciudad: "<<car_E<<endl;
    cout<<"Cantidad total de personas que entran a la ciudad: "<<persons_E<<endl;
    stationA<<"Cantidad total de personas que entran a la ciudad: "<<persons_E<<endl;
    cout<<"Cantidad total de autos que salen de la ciudad: "<<car_S<<endl;
    stationA<<"Cantidad total de autos que salen de la ciudad: "<<car_S<<endl;
    cout<<"Cantidad total de personas que salen de la ciudad: "<<persons_S<<endl;
    stationA<<"Cantidad total de personas que salen de la ciudad: "<<persons_S<<endl;
    cout<<"Monto total recaudado: "<<total_amount<<endl;
    stationA<<"Monto total recaudado: "<<total_amount<<endl;

}
