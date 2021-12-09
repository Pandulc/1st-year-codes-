#include <iostream>
#include "../Listas_Enlazadas/LinkedList.h"
#include <stack>
#include <queue>

using namespace std;
struct Order {
    int code;
    string garment;
    int weight;
    int service;
    float amount;
    int state;
};

int menu();

void load(LinkedList<Order> *, int *);

void calculateAmount(struct Order *);

void show(LinkedList<Order> *, queue<Order>*, stack<Order>*);

void changeState(LinkedList<Order> *);

void passQueue(LinkedList<Order> *, queue<Order> *);

void passStack(LinkedList<Order> *, stack<Order> *);

int main() {
    LinkedList<Order> orders;
    queue<Order> inProcess;
    stack<Order> payed;
    int code = 1;
    int option;
    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                show(&orders, &inProcess, &payed);
                break;
            case 2:
                load(&orders, &code);
                break;
            case 3:
                changeState(&orders);
                break;
            case 4:
                passQueue(&orders, &inProcess);
                break;
            case 5:
                passStack(&orders, &payed);
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
    } while (option != 0);


    return 0;
}

int menu() {
    int option;
    cout << "Ingrese la opcion a realizar" << endl;
    cout << "1. Mostrar listado de pedidos" << endl;
    cout << "2. Registrar un pedido" << endl;
    cout << "3. Cambiar state de un pedido" << endl;
    cout << "4. Pasasr pedidos EN PROCESO" << endl;
    cout << "5. Pasar pedidos PAGADOS" << endl;
    cout << "0. Salir" << endl;
    cin >> option;
    return option;
}

void load(LinkedList<Order> *p, int *c) {
    struct Order aux;
    aux.code = *c;
    *c = *c + 1;
    aux.garment = "ropa";
    cout << "Ingrese la cantidad de kilos de ropa" << endl;
    cin >> aux.weight;
    cout << "Ingrese el tipo de service" << '\n' << "1. Lavanderia" << '\n' << "2. Lavanderia completa" << '\n'
         << "3. Tintoreria" << endl;
    cin >> aux.service;
    calculateAmount(&aux);
    aux.state = 0;
    p->push_front(aux);
}

void calculateAmount(struct Order *aux) {
    if (aux->service == 1) {
        aux->amount = aux->weight * 200;
    }
    if (aux->service == 2) {
        aux->amount = aux->weight * 300;
    }
    if (aux->service == 3) {
        aux->amount = aux->weight * 500;
    }
}

void show(LinkedList<Order> *p, queue<Order>* ip, stack<Order>* pd) {
    cout<<"Listado de pedidos ingresados"<<endl;
    for (int i = 0; i < p->size(); ++i) {
        cout << "--------------------" << endl;
        cout << "Codigo: " << p->get(i).code << '\n' << "Prendas: " << p->get(i).garment << '\n' << "Peso: "
             << p->get(i).weight << '\n' << "Servicio: " << p->get(i).service << '\n' << "Monto: " << p->get(i).amount
             << '\n' << "Estado: " << p->get(i).state << endl;
        cout << "--------------------" << endl;
    }
}

void changeState(LinkedList<Order> *p) {
    int auxCode;
    int auxState;
    struct Order aux;
    cout << "Ingrese el code del pedido" << endl;
    cin >> auxCode;
    for (int i = 0; i < p->size(); ++i) {
        if (p->get(i).code == auxCode) {
            if (p->get(i).state != 3) {
                aux = p->get(i);
                cout << "Ingrese el state del pedido" << '\n' << "1. EN PROCESO" << '\n' << "2. LISTO" << '\n'
                     << "3. PAGADO" << endl;
                cin >> auxState;
                aux.state = auxState;
                p->replace(i,aux);
            }
            else{
                cout<<"El code no correspone a un pedido activo o no pago" << endl;
            }
        }
    }
}

void passQueue(LinkedList<Order>* p, queue<Order>* ip){
    struct Order aux;
    queue<Order> qAux;
    for (int i = 0; i < p->size(); ++i) {
        aux = p->get(i);
        if(aux.state == 1){
            ip->push(aux);
        }
    }
    cout<<"Listado de pedidos en proceso"<<endl;
    while(!ip->empty()){
        qAux.push(ip->front());
        cout << "--------------------" << endl;
        cout << "Codigo: " << ip->front().code << '\n' << "Prendas: " << ip->front().garment << '\n' << "Peso: "
             << ip->front().weight << '\n' << "Servicio: " << ip->front().service << '\n' << "Monto: " << ip->front().amount
             << '\n' << "Estado: " << ip->front().state << endl;
        cout << "--------------------" << endl;
        ip->pop();
    }
    ip = &qAux;
}

void passStack (LinkedList<Order>* p, stack<Order>* pd){
    struct Order aux;
    stack<Order> sAux;
    float sum = 0;
    for (int i = 0; i < p->size(); ++i) {
        aux = p->get(i);
        if(aux.state == 3){
            pd->push(aux);
            sum = sum + aux.amount;
        }
    }
    cout<<"Listado de pedidos pagados"<<endl;
    while(!pd->empty()){
        sAux.push(pd->top());
        cout << "--------------------" << endl;
        cout << "Codigo: " << pd->top().code << '\n' << "Prendas: " << pd->top().garment << '\n' << "Peso: "
             << pd->top().weight << '\n' << "Servicio: " << pd->top().service << '\n' << "Monto: " << pd->top().amount
             << '\n' << "Estado: " << pd->top().state << endl;
        cout << "--------------------" << endl;
        pd->pop();
    }
    pd = &sAux;
    cout<<"Lo recaudado por los pedidos pagados es: " << sum << endl;
}