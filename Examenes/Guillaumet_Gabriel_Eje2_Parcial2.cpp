#include <iostream>
#include "../Listas_Enlazadas/LinkedList.h"
#include <stack>
#include <ctime>

#define quantity 10

using namespace std;

int menu();

void load(stack<int> *);

int search_number(stack<int>, int);

void show(stack<int>);

void show_lists(stack<int>);

void sum(stack<int>);

void max_value(stack<int>);

void min_value(stack<int>);

int main() {
    int option;
    stack<int> numbers;
    load(&numbers);
    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                cout << endl;
                show(numbers);
                cout << endl;
                break;
            case 2:
                cout << endl;
                show_lists(numbers);
                break;
            case 3:
                cout << endl;
                sum(numbers);
                break;
            case 4:
                cout << endl;
                max_value(numbers);
                break;
            case 5:
                cout << endl;
                min_value(numbers);
                break;
            default:
                cout << endl;
                cout << "Ingrese una opcion valida" << endl;
        }
    } while (option != 0);


    return 0;
}

int menu() {
    int option;
    cout << "Ingrese la opcion a realizar" << endl;
    cout << "1. Mostrar todos los valores" << endl;
    cout << "2. Mostrar listado de valores pares e impares" << endl;
    cout << "3. Sumar todos los valores" << endl;
    cout << "4. Mostrar el valor maximo" << endl;
    cout << "5. Mostrar el valor minimo" << endl;
    cout << "0. Salir" << endl;
    cin >> option;
    return option;
}

void load(stack<int> *n) {
    int number;
    int option;
    srand(time(NULL));
    for (int i = 0; i < quantity; ++i) {
        if (i == 0) {
            number = rand() % 100 + 1;
            n->emplace(number);
        } else {
            number = rand() % 100 + 1;
            option = search_number(*n, number);
            if (option == 1) {
                n->emplace(number);
            }
            if (option == 0) {
                i--;
            }
        }
    }
}

int search_number(stack<int> s, int n) {
    while (!s.empty()) {
        if (s.top() == n) {
            return 0;
        } else {
            s.pop();
        }
    }
    return 1;
}

void show(stack<int> n) {
    cout << "Valores de la pila" << endl;
    while (!n.empty()) {
        cout << n.top() << "\t";
        n.pop();
    }
    cout << endl;
}

void show_lists(stack<int> n) {
    LinkedList<int> pairs;
    LinkedList<int> noPairs;
    while (!n.empty()) {
        if (n.top() % 2 == 0) {
            pairs.push_front(n.top());
        } else {
            noPairs.push_front(n.top());
        }
        n.pop();
    }
    cout << "Lista de valores PARES" << endl;
    pairs.print();
    cout << endl;
    cout << "Lista de valores IMPARES" << endl;
    noPairs.print();
    cout << endl;
}

void sum(stack<int> n) {
    int adder = 0;
    while (!n.empty()) {
        adder = adder + n.top();
        n.pop();
    }
    cout << "La suma de los valores es: " << adder << endl;
    cout << endl;
}

void max_value(stack<int> n) {
    int max;
    int counter = 0;
    while (!n.empty()) {
        if (counter == 0) {
            max = n.top();
        } else {
            if (n.top() > max) {
                max = n.top();
            }
        }
        counter++;
        n.pop();
    }
    cout << "El valor maximo es: " << max << endl;
    cout << endl;
}


void min_value(stack<int> n) {
    int min;
    int counter = 0;
    while (!n.empty()) {
        if (counter == 0) {
            min = n.top();
        } else {
            if (n.top() < min) {
                min = n.top();
            }
        }
        counter++;
        n.pop();
    }
    cout << "El valor maximo es: " << min << endl;
    cout << endl;
}