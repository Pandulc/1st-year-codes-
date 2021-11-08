#include <iostream>
#include <stack>
#include <queue>
#include <ctime>
#include <random>
#include "../Listas_Enlazadas/LinkedList.h"

using namespace std;

int menu();

void load(queue<int> *);

int search_number(queue<int>, int);

void add_numbers(queue<int> *);

void pass_numbers(queue<int>, LinkedList<int> *, stack<int> *);

void sum(queue<int>, LinkedList<int>, stack<int>);

void show(queue<int>, LinkedList<int>, stack<int>);

int main() {

    int option;
    queue<int> qNumbers;
    LinkedList<int> greater_5;
    stack<int> less_5;

    load(&qNumbers);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                add_numbers(&qNumbers);
                break;
            case 2:
                pass_numbers(qNumbers, &greater_5, &less_5);
                break;
            case 3:
                sum(qNumbers, greater_5, less_5);
                break;
            case 4:
                show(qNumbers, greater_5, less_5);
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
    cout << "1. Agregar un valor a la cola de numeros y mostrar la cantidad de valores que hay en la cola." << endl;
    cout << "2. Pasar los valores menores a 5 a una pila y los mayores a 5 una lista." << endl;
    cout << "3. Calcular la sumatoria de los valores de la pila, cola y lista." << endl;
    cout << "4. Mostrar todos los valores de la pila, cola y lista." << endl;
    cout << "0. Salir" << endl;
    cin >> option;
    return option;

}

void load(queue<int> *q) {
    int quantity = 0;
    int number = 0;
    int continuation;
    srand(time(NULL));
    cout << "Ingrese la cantidad de numeros a insertar en la cola" << endl;
    cin >> quantity;
    for (int i = 0; i < quantity; ++i) {
        if (i == 0) {
            number = rand() % 10;
            q->emplace(number);
        } else {
            number = rand() % 10;
            continuation = search_number(*q, number);
            if (continuation != 0) {
                q->emplace(number);
            } else {
                i--;
            }
        }
    }
}

int search_number(queue<int> q, int n) {

    while (!q.empty()) {
        if (q.front() == n) {
            return 0;
        } else {
            q.pop();
        }
    }
    return 1;
}

void add_numbers(queue<int> *q) {

    int number = 0;

    cout << "Ingrese el valor a agregar" << endl;
    cin >> number;
    q->emplace(number);
    cout << "Cantidad de valores en la cola: " << q->size() << endl;

}

void pass_numbers(queue<int> q, LinkedList<int> *l, stack<int> *s) {

    queue<int> aux;

    if (q.empty()) {
        cout << "La cola esta vacia" << endl;
    }

    while (!q.empty()) {
        if (q.front() < 5) {
            s->push(q.front());
            aux.push(q.front());
            q.pop();
        } else {
            l->insert(0, q.front());
            aux.push(q.front());
            q.pop();
        }
    }
}

void sum(queue<int> q, LinkedList<int> l, stack<int> s) {
    int adder = 0;

    queue<int> qAux;
    stack<int> sAux;

    for (int i = 0; i < l.size(); ++i) {
        adder = adder + l.get(i);
    }
    while (!s.empty()) {
        sAux.push(s.top());
        adder = adder + s.top();
        s.pop();
    }
    while (!q.empty()) {
        qAux.push(q.front());
        adder = adder + q.front();
        q.pop();
    }

    cout << "La suma de los valores de la lista, pila y cola es: " << adder << endl;
}

void show(queue<int> q, LinkedList<int> l, stack<int> s) {

    queue<int> qAux;
    stack<int> sAux;

    cout << "Lista de valores mayores o iguales a 5" << endl;
    l.print();

    cout << "Pila de valores menores que 5" << endl;
    while (!s.empty()) {
        sAux.push(s.top());
        cout << s.top() << " - ";
        s.pop();
    }
    cout << endl;

    cout << "Cola con todos los valores" << endl;
    while (!q.empty()) {
        qAux.push(q.front());
        cout << q.front() << " - ";
        q.pop();
    }
    cout << endl;
}