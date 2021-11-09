#include <iostream>
#include "../Listas_Enlazadas/LinkedList.h"
#include <queue>
#include <string>

using namespace std;

struct Bill {
    int code;
    string name;
    int consumption;
    float amount;
};

struct Receipt {
    int date;
    int code;
    string name;
    int consumption;
    float amount;
    float final_amount;
};

int menu();

void load(LinkedList<Bill> *);

void pay(LinkedList<Bill> *, queue<Receipt> *);

void show(LinkedList<Bill>, queue<Receipt>);

int main() {
    int option;
    LinkedList<Bill> bills;
    queue<Receipt> receipts;
    load(&bills);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                pay(&bills, &receipts);
                break;
            case 2:
                show(bills, receipts);
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
        }
    } while (option != 0);

    return 0;
}

int menu() {
    int option;
    cout << "Ingrese la opcion a realizar" << endl;
    cout << "1. Pagar factura" << endl;
    cout << "2. Mostrar listado de facturas y recibos" << endl;
    cout << "0. Salir" << endl;
    cin >> option;
    return option;
}

void load(LinkedList<Bill> *b) {

    struct Bill aux;

    aux = {1, "Anisacate", 100, 0};
    aux.amount = aux.consumption * 70;
    b->push_front(aux);
    aux = {2, "La Bolsa", 30, 0};
    aux.amount = aux.consumption * 70;
    b->push_back(aux);
    aux = {3, "Villa Los Aromos", 35, 0};
    aux.amount = aux.consumption * 70;
    b->push_back(aux);

}

void pay(LinkedList<Bill> *b_l, queue<Receipt> *r_q) {

    int s_code;
    int date;
    struct Bill b_aux;
    struct Receipt r_aux;

    cout << ".--------Listado de Facturas del Mes--------." << endl;
    for (int i = 0; i < b_l->size(); ++i) {
        cout << "---------------------------------------" << endl;
        cout << "Codigo: " << b_l->get(i).code << "\n" << "Comuna: " << b_l->get(i).name << "\n" << "Consumo: "
             << b_l->get(i).consumption << "\n" << "Monto a pagar: " << b_l->get(i).amount << endl;
        cout << "---------------------------------------" << endl;
    }
    cout << "Ingrese el codigo de comuna que va a pagar" << endl;
    cin >> s_code;
    for (int i = 0; i < b_l->size(); ++i) {
        b_aux = b_l->get(i);
        if (s_code == b_aux.code) {
            cout << ".--------FACTURA--------." << endl;
            cout << "---------------------------------------" << endl;
            cout << "Codigo: " << b_aux.code << "\n" << "Comuna: " << b_aux.name << "\n" << "Consumo: "
                 << b_aux.consumption << "\n" << "Monto a pagar: " << b_aux.amount << endl;
            cout << "---------------------------------------" << endl;
            cout << "Ingrese el dia de pago" << endl;
            cin >> date;
            if (date >= 11) {
                r_aux.date = date;
                r_aux.code = b_aux.code;
                r_aux.name = b_aux.name;
                r_aux.consumption = b_aux.consumption;
                r_aux.amount = b_aux.amount;
                r_aux.final_amount = r_aux.amount + 10;
                cout << ".---------RECIBO---------." << endl;
                cout << "---------------------------------------" << endl;
                cout << "Fecha: " << r_aux.date << "\n" << "Codigo: " << r_aux.code << "\n" << "Comuna: " << r_aux.name
                     << "\n" << "Consumo: "
                     << r_aux.consumption << "\n" << "Subtotal: " << r_aux.amount << "\n" << "Total: "
                     << r_aux.final_amount << endl;
                cout << "---------------------------------------" << endl;
                r_q->push(r_aux);
                b_l->erase(i);
            } else {
                r_aux.date = date;
                r_aux.code = b_aux.code;
                r_aux.name = b_aux.name;
                r_aux.consumption = b_aux.consumption;
                r_aux.amount = b_aux.amount;
                r_aux.final_amount = r_aux.amount;
                cout << ".---------RECIBO---------." << endl;
                cout << "---------------------------------------" << endl;
                cout << "Fecha: " << r_aux.date << "\n" << "Codigo: " << r_aux.code << "\n" << "Comuna: " << r_aux.name
                     << "\n" << "Consumo: "
                     << r_aux.consumption << "\n" << "Subtotal: " << r_aux.amount << "\n" << "Total: "
                     << r_aux.final_amount << endl;
                cout << "---------------------------------------" << endl;
                r_q->push(r_aux);
                b_l->erase(i);
            }
        }
    }
}

void show(LinkedList<Bill> b_l, queue<Receipt> r_q) {
    struct Receipt r_aux;

    cout << ".--- LISTADO DE FACTURAS PENDIENTES DE PAGO ---." << endl;
    if(b_l.size() == 0){
        cout << endl;
        cout << "No hay facturas pendientes de pago" << endl;
        cout << endl;
    }
    for (int i = 0; i < b_l.size(); ++i) {
        cout << "---------------------------------------" << endl;
        cout << "Codigo: " << b_l.get(i).code << "\n" << "Comuna: " << b_l.get(i).name << "\n" << "Consumo: "
             << b_l.get(i).consumption << "\n" << "Monto a pagar: " << b_l.get(i).amount << endl;
        cout << "---------------------------------------" << endl;
    }
    cout << ".--- LISTADO DE RECIBOS ---." << endl;
    if(r_q.size() == 0){
        cout << endl;
        cout << "No hay recibos de pago" << endl;
        cout << endl;
    }
    while (!r_q.empty()) {
        r_aux = r_q.front();
        cout << "---------------------------------------" << endl;
        cout << "Fecha: " << r_aux.date << "\n" << "Codigo: " << r_aux.code << "\n" << "Comuna: " << r_aux.name
             << "\n" << "Consumo: "
             << r_aux.consumption << "\n" << "Subtotal: " << r_aux.amount << "\n" << "Total: "
             << r_aux.final_amount << endl;
        cout << "---------------------------------------" << endl;
        r_q.pop();

    }
}