//Una comuna organiza las ferias culturales todos los fin de semanas en donde se venden artesanías elaboradas por los
//lugareños, y se ofrecen shows y comidas al paso. La comuna se encarga de gestionar el evento separando por sectores,
//y en cada uno de ellos hay un puesto, además la comuna ofrece los servicios de luz, agua y baños químicos es por ello
//que tiene un costo base de $1000. En caso de que se requiera mesa y silla se sumarán $500.
//
//Se pide generar un listado (TDA Lista) con las solicitudes de las personas que desean participar en la feria.
//Generar un menú con las siguientes opciones:
//
//        Registrar una solicitud. El N° de solicitud deberá ser generado automáticamente y se solicitará que el
//        usuario ingrese los siguientes datos: apellido y nombre del responsable del sector, rubro al que pertenece
//        (Artesanía, Gastronomía o Espectáculo), si requiere mesa o silla. Luego deberá llamar a una función para
//        calcular el monto a pagar y otra función para asignar el sector, los sectores deben ser consecutivos y no
//        repetirse. En caso de que el rubro sea espectáculo se le asigna sector 0 que es el escenario.
//
//        Mostrar Listado de solicitudes
//
//        Pasar los espectáculos a una pila y mostrar pila.


#include <iostream>
#include <string>
#include "../Listas_Enlazadas//LinkedList.h"
#include <stack>

using namespace std;

struct Request {
    int number;
    string lastName;
    string firstName;
    int heading;
    char table;
    float amount;
    int sector;
};

int menu();

void load(LinkedList<Request> *, int *, int *);

void amount(LinkedList<Request> *);

void show(LinkedList<Request> *, stack<Request> *);

void pass(LinkedList<Request> *, stack<Request> *);

int main() {

    int option;
    int number = 1;
    int sector = 1;
    LinkedList<Request> requests;
    stack<Request> shows;

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                load(&requests, &number, &sector);
                cout << endl;
                break;
            case 2:
                show(&requests, &shows);
                cout << endl;
                break;
            case 3:
                pass(&requests, &shows);
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
    } while (option != 0);

    return 0;
}

int menu() {
    int op = 0;
    cout << "Ingrese la opcion a realizar" << endl;
    cout << "1. Registrar una solicitud" << endl;
    cout << "2. Mostrar Listado de solicitudes" << endl;
    cout << "3. Pasar los espectaculos a una pila y mostrar pila" << endl;
    cout << "0. Salir" << endl;
    cin >> op;

    return op;
}

void load(LinkedList<Request> *r, int *n, int *s) {
    struct Request aux;
    int continuity;
    do {
        aux.number = *n;
        cout << "Ingrese el apellido del solicitante" << endl;
        getline(cin, aux.lastName, '.');
        cout << "Ingrese el nombre del solicitante" << endl;
        getline(cin, aux.firstName, '.');
        cout << "Inserte el rubro al que pertenece:" << "\n" << "1. Artesania" << "\n" << "2. Gastronomia" << "\n"
             << "3. Espectaculo" << endl;
        cin >> aux.heading;
        cout << "Necesita una mesa? S/N" << endl;
        cin >> aux.table;
        if (aux.heading == 3) {
            aux.sector = 0;
            *s = *s - 1;
        } else {
            aux.sector = *s;
        }
        r->push_back(aux);
        amount(r);
        *n = *n + 1;
        *s = *s + 1;
        cout << "Desea cargar otra solicitud? 1. Si 0. No" << endl;
        cin >> continuity;
    } while (continuity != 0);
}

void amount(LinkedList<Request> *r) {
    float basic = 1000;
    struct Request aux;
    for (int i = 0; i < r->size(); ++i) {
        if (r->get(i).table == 'S') {
            aux = r->get(i);
            aux.amount = basic + 500;
        } else {
            aux = r->get(i);
            aux.amount = basic;
        }
        r->replace(i, aux);
    }
}

void show(LinkedList<Request> *r, stack<Request> *s) {
    stack<Request> aux;
    cout << "---- Artesanias y Gastronomia ----" << endl;
    for (int i = 0; i < r->size(); ++i) {
        cout << "---------------------------------" << endl;
        cout << "Nro: " << r->get(i).number << "\n" << "Apellido: " << r->get(i).lastName << "\n" << "Nombre: "
             << r->get(i).firstName << "\n" << "Rubro: " << r->get(i).heading << "\n"
             << "Mesa: " << r->get(i).table << "\n" << "Monto: " << r->get(i).amount << "\n" << "Sector: "
             << r->get(i).sector
             << endl;
        cout << "---------------------------------" << endl;
    }
    cout << "----- Espectaculos -----" << endl;
    while (!s->empty()){
        aux.push(s->top());
        cout << "---------------------------------" << endl;
        cout << "Nro: " << s->top().number << "\n" << "Apellido: " << s->top().lastName << "\n" << "Nombre: "
             << s->top().firstName << "\n" << "Rubro: " << s->top().heading << "\n"
             << "Mesa: " << s->top().table << "\n" << "Monto: " << s->top().amount << "\n" << "Sector: "
             << s->top().sector
             << endl;
        cout << "---------------------------------" << endl;
        s->pop();
    }
    s = &aux;

}

void pass(LinkedList<Request> *r, stack<Request> *s) {
    for (int i = 0; i < r->size(); ++i) {
        if (r->get(i).heading == 3) {
            s->push(r->get(i));
            r->erase(i);
        }
    }
}