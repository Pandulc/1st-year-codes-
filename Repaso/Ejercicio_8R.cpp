#include <iostream>
#include "../Listas_Enlazadas/LinkedList.h"
#include <queue>
#include <string>

using namespace std;

struct Bill {
    int client_number;
    string city;
    int consumption;
    float amount;
};
struct Receipt {
    int client_number;
    string city;
    int consumption;
    int pay_date;
    float amount;

};

int menu();

void load(LinkedList<Bill> *);

void pay(LinkedList<Bill> *, LinkedList<Bill> *, queue<Receipt> *);

void show(LinkedList<Bill> *, LinkedList<Bill> *, queue<Receipt> *);

int main() {

    int option;
    LinkedList<Bill> month_bills;
    LinkedList<Bill> year_bills;
    queue<Receipt> month_receipt;
    load(&month_bills);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                pay(&month_bills, &year_bills, &month_receipt);
                break;
            case 2:
                show(&month_bills, &year_bills, &month_receipt);
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
    } while (option != 0);


    return 0;
}

int menu() {

    int option = 0;
    cout << "Ingrese la opcion a realizar" << endl;
    cout << "1. Pagar factura" << endl;
    cout << "2. Mostrar facturas y recibos del mes y del anio" << endl;
    cout << "0. Salir" << endl;
    cin >> option;
    return option;

}

void load(LinkedList<Bill> *l) {

    struct Bill aux;

    aux = {1, "Anisacate", 100, 0};
    aux.amount = aux.consumption * 70;
    l->insert(0, aux);
    aux = {2, "La Bolsa", 30, 0};
    aux.amount = aux.consumption * 70;
    l->insert(0, aux);
    aux = {3, "Villa Los Aromos", 35, 0};
    aux.amount = aux.consumption * 70;
    l->insert(0, aux);


}

void pay(LinkedList<Bill> *m_l, LinkedList<Bill> *y_l, queue<Receipt> *m_s) {
    int date;
    int city_toPay;
    struct Receipt aux_r;
    struct Bill aux_b;
    cout << "Ingrese el numero de cliente de la ciudad que va a pagar" << endl;
    cin >> city_toPay;
    cout << "Ingrese la fecha de pago" << endl;
    cin >> date;
    if (date >= 11) {
        for (int i = 0; i < m_l->size(); ++i) {
            if (city_toPay == m_l->get(i).client_number) {
                aux_b = m_l->get(i);
                aux_b.amount = aux_b.amount + (date - 11) * 10;
                m_l->replace(i, aux_b);
            }
        }
    }
    for (int i = 0; i < m_l->size(); ++i) {
        if (city_toPay == m_l->get(i).client_number) {
            cout << "----- FACTURA -----" << endl;
            cout << "--------------------------" << endl;
            cout << "Nro Cliente: " << m_l->get(i).client_number << endl;
            cout << "Ciudad: " << m_l->get(i).city << endl;
            cout << "Consumo: " << m_l->get(i).consumption << endl;
            cout << "Monto: " << m_l->get(i).amount << endl;
            cout << "--------------------------" << endl;
            aux_r = {m_l->get(i).client_number, m_l->get(i).city, m_l->get(i).consumption, date, m_l->get(i).amount};
            cout << "----- RECIBO -----" << endl;
            cout << "--------------------------" << endl;
            cout << "Nro Cliente: " << aux_r.client_number << endl;
            cout << "Ciudad: " << aux_r.city << endl;
            cout << "Consumo: " << aux_r.consumption << endl;
            cout << "Fecha: " << date << endl;
            cout << "Monto: " << aux_r.amount << endl;
            cout << "--------------------------" << endl;
            m_s->emplace(aux_r);
            y_l->insert(0, m_l->get(i));
        }
    }
}

void show(LinkedList<Bill> *m_l, LinkedList<Bill> *y_l, queue<Receipt> *m_s) {
    queue<Receipt> aux_r;

    cout << "-----FACTURAS DEL MES-----" << endl;
    for (int i = 0; i < m_l->size(); ++i) {
        cout << "--------------------------" << endl;
        cout << "Nro Cliente: " << m_l->get(i).client_number << endl;
        cout << "Ciudad: " << m_l->get(i).city << endl;
        cout << "Consumo: " << m_l->get(i).consumption << endl;
        cout << "Monto: " << m_l->get(i).amount << endl;
        cout << "--------------------------" << endl;
    }
    cout << "-----RECIBOS DEL MES-----" << endl;
    while (!m_s->empty()) {
        aux_r.push(m_s->front());
        m_s->pop();
        cout << "--------------------------" << endl;
        cout << "Nro Cliente: " << aux_r.front().client_number << endl;
        cout << "Ciudad: " << aux_r.front().city << endl;
        cout << "Consumo: " << aux_r.front().consumption << endl;
        cout << "Fecha: " << aux_r.front().pay_date << endl;
        cout << "Monto: " << aux_r.front().amount << endl;
        cout << "--------------------------" << endl;
    }
    m_s = &aux_r;
    cout << "-----FACTURAS DEL ANIO-----" << endl;
    for (int i = 0; i < y_l->size(); ++i) {
        cout << "--------------------------" << endl;
        cout << "Nro Cliente: " << y_l->get(i).client_number << endl;
        cout << "Ciudad: " << y_l->get(i).city << endl;
        cout << "Consumo: " << y_l->get(i).consumption << endl;
        cout << "Monto: " << y_l->get(i).amount << endl;
        cout << "--------------------------" << endl;
    }
}