#include <iostream>
#include "../Listas_Enlazadas/LinkedList.h"
#include <queue>
#include <ctime>

using namespace std;

struct Multiplication {
    int f_operand;
    int s_operand;
    int product;
    int correct_product;
    int qualification;
};

int menu();

void resolve(LinkedList<Multiplication> *, queue<Multiplication> *);

void show(queue<Multiplication> *);

int main() {

    int option;
    LinkedList<Multiplication> operations;
    queue<Multiplication> correct_operations;

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                resolve(&operations, &correct_operations);
                break;
            case 2:
                show(&correct_operations);
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
    } while (option != 0);

    return 0;
}

int menu() {

    int op;
    cout << "Ingrese la opcion a realizar" << endl;
    cout << "1. Realizar una multiplicacion" << endl;
    cout << "2. Mostrar errores" << endl;
    cout << "0. Salir del juego" << endl;
    cin >> op;
    return op;

}

void resolve(LinkedList<Multiplication> *op, queue<Multiplication> *c_op) {

    int option;
    int number1;
    int number2;
    int result;
    struct Multiplication aux;
    do {
        srand(time(NULL));
        number1 = rand() % 10 + 2;
        number2 = rand() % 10 + 2;
        aux.f_operand = number1;
        aux.s_operand = number2;
        aux.correct_product = aux.f_operand * aux.s_operand;
        cout << "La multiplicacion a resolver es: " << number1 << " x " << number2 << endl;
        cin >> result;
        aux.product = result;
        if (result != aux.correct_product) {
            aux.qualification = 0;
            c_op->push(aux);
        } else {
            aux.qualification = 10;
        }
        op->push_front(aux);
        cout << "Quieres seguir practicando? 1) SI 0) NO" << endl;
        cin >> option;
    } while (option != 0);

}

void show(queue<Multiplication> *c_op) {
    struct Multiplication aux;
    cout << "Multiplicando" << "  " << "Multiplicador" << "  " << "Resultado Propuesto" << "  " << "Resultado Correcto"
         << "  " << "Puntaje" << endl;
    while (!c_op->empty()) {
        aux = c_op->front();
        cout << "      " << aux.f_operand << "\t\t     " << aux.s_operand << "\t\t       " << aux.product << "\t\t   "
             << aux.correct_product << "\t\t  "
             << aux.qualification << endl;
        c_op->pop();
    }
}