//El gerente de una empresa de software quiere dar reconocimiento y otorgar incentivos a sus mejores programadores de
// acuerdo a su desempeño. Para ello fijó los siguientes criterios para calcular el incentivo: (crear una función por
// cada criterio)
//
//Según su antigüedad, es decir la cantidad de meses que está programando. Por cada mes de antigüedad se calcula un
// incentivo parcial de $30.
//
//Según la cantidad de líneas de código que ha programado en el mes. Una línea de código equivale a $15
//
//Según la cantidad de errores que ha introducido en el código en el mes. Dependiendo del tipo de error es la
//penalización (descuento) que tendrá el incentivo.
//
//  Por cada error de sintaxis se le descontará $3
//
//  Por cada error de enlace se le descontará $5
//
//  Por cada error de ejecución se le descontará $7
//
//  Por cada error de semántica se le descontará $10
//
//En el caso de que se el programador tenga más o igual cantidad de errores que líneas de código escritas, el programador no tendrá incentivo este mes.
//
//
//Crear un menú de opciones con las siguientes operaciones:
//
//Cargar datos.
//
//Mostrar un listado (TDA Lista) de los incentivos percibidos por los programadores.
//
//Mostrar el mejor programador del mes. Es quien tiene más líneas de código con menos errores.
//
//Mostrar un TDA Pila de todos los incentivos totales por cada programador, es decir generar y show una
//pila con todos los incentivos.
//
//Mostrar un TDA Cola de todas las penalizaciones totales por cada programador, es decir generar y show
//una cola con todas las penalizaciones por errores en el código.
//
//Generar un archivo txt con el listado de incentivos a los programadores.


#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include "../Listas_Enlazadas/LinkedList.h"

using namespace std;

struct Employee {
    int file;
    string name;
    int antiquity;
    int lines;
    int syntaxErrors;
    int linkErrors;
    int executionErrors;
    int semanticErrors;
};

struct Incentives {
    string name;
    int i_antiquity;
    int i_lines;
    int p_errors;
    int total;
};

int menu();

void load(LinkedList<Employee> *, LinkedList<Incentives> *);

void show(LinkedList<Incentives> *);

void bestEmployee(LinkedList<Employee> *);

void passIncentives(LinkedList<Incentives> *, stack<Incentives> *);

void passErrors (LinkedList<Incentives> *, queue<Incentives> *);

void save (LinkedList<Incentives> *);

int main() {

    int option;
    LinkedList<Employee> employees;
    LinkedList<Incentives> incentivesErrors;
    stack<Incentives> incentives;
    queue<Incentives> errors;

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                load(&employees, &incentivesErrors);
                cout << endl;
                break;
            case 2:
                show(&incentivesErrors);
                cout << endl;
                break;
            case 3:
                bestEmployee(&employees);
                cout << endl;
                break;
            case 4:
                passIncentives(&incentivesErrors, &incentives);
                cout << endl;
                break;
            case 5:
                passErrors(&incentivesErrors, &errors);
                cout << endl;
                break;
            case 6:
                save(&incentivesErrors);
                cout<<endl;
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
    cout << "1. Cargar datos del programador" << endl;
    cout << "2. Mostrar listado de incentivos" << endl;
    cout << "3. Mostrar el mejor programador del mes" << endl;
    cout << "4. Mostrar listado de incentivos por programador" << endl;
    cout << "5. Mostrar listado de penalizaciones por programador" << endl;
    cout << "6. Generar archivo con el listado de incentivos" << endl;
    cout << "0. Salir" << endl;
    cin >> op;

    return op;
}

void load(LinkedList<Employee> *e, LinkedList<Incentives> *i) {
    struct Employee e_aux;
    struct Incentives i_aux;
    int continuity;
    do {
        cout << "Ingrese el numero de legajo del empleado" << endl;
        cin >> e_aux.file;
        cout << "Ingrese el nombre del empleado" << endl;
        getline(cin, e_aux.name, '.');
        cout << "Ingrese los meses de antiguedad" << endl;
        cin >> e_aux.antiquity;
        cout << "Ingrese la cantidad de lineas codeadas por el empleado" << endl;
        cin >> e_aux.lines;
        cout << "Ingrese la cantidad de errores de sintaxis del empleado en este mes" << endl;
        cin >> e_aux.syntaxErrors;
        cout << "Ingrese la cantidad de errores de enlace del empleado en este mes" << endl;
        cin >> e_aux.linkErrors;
        cout << "Ingrese la cantidad de errores de ejecucion del empleado en este mes" << endl;
        cin >> e_aux.executionErrors;
        cout << "Ingrese la cantidad de errores de semantica del empleado en este mes" << endl;
        cin >> e_aux.semanticErrors;
        e->push_front(e_aux);
        if (e_aux.lines > (e_aux.linkErrors + e_aux.executionErrors + e_aux.syntaxErrors + e_aux.semanticErrors)) {
            i_aux.name = e_aux.name;
            i_aux.i_antiquity = e_aux.antiquity * 30;
            i_aux.i_lines = e_aux.lines * 15;
            i_aux.p_errors = (e_aux.semanticErrors * 10) + (e_aux.syntaxErrors * 3) + (e_aux.executionErrors * 7) +
                             (e_aux.linkErrors * 5);
            i_aux.total = i_aux.i_antiquity + i_aux.i_lines - i_aux.p_errors;
            i->push_front(i_aux);
        } else {
            cout << "Debido a que el empleado este mes tuvo igual cantidad de lineas que errores, no recibira incentivo"
                 << endl;
        }
        cout << "Desea load otro empleado? 1. Si 0. No" << endl;
        cin >> continuity;
    } while (continuity != 0);


}

void show(LinkedList<Incentives> *i) {
    for (int j = 0; j < i->size(); ++j) {
        cout << "-----------------------------" << endl;
        cout << "Nombre: " << i->get(j).name << "\n" << "Incentivo por antiguedad: "
             << i->get(j).i_antiquity << "\n" << "Incentivo por lineas codeadas: " << i->get(j).i_lines << "\n"
             << "Descuentos: " << i->get(j).p_errors << "\n" << "Incentivo total: "
             << i->get(j).total << endl;
        cout << "-----------------------------" << endl;
    }
}

void bestEmployee(LinkedList<Employee> *e) {
    int reason;
    struct Employee aux;
    struct Employee best;
    for (int i = 0; i < e->size(); ++i) {
        aux = e->get(i);
        if (i == 0) {
            reason = (aux.semanticErrors + aux.syntaxErrors + aux.executionErrors + aux.linkErrors) / aux.lines;
            best = aux;
        } else {
            if (((aux.semanticErrors + aux.syntaxErrors + aux.executionErrors + aux.linkErrors) / aux.lines) < reason) {
                best = aux;
            }
        }
    }
    cout << "El empleado del mes: " << endl;
    cout << "Legajo: " << best.file << "\n" << "Nombre: " << best.name << "\n" << "Antiguedad: " << best.antiquity
         << "\n" << "Lineas: " << best.lines << "\n" << "Errores: " << "\n" << "        Sintaxis: " << best.syntaxErrors
         << "\n" << "        Enlace: " << best.linkErrors << "\n" << "        Ejecucion: " << best.executionErrors
         << "\n" << "        Semantica: " << best.semanticErrors << endl;
}

void passIncentives(LinkedList<Incentives> *ie, stack<Incentives> *i) {
    struct Incentives aux;
    stack<Incentives> s_aux;
    for (int j = 0; j < ie->size(); ++j) {
        aux = ie->get(j);
        i->push(aux);
    }
    while(!i->empty()){
        s_aux.push(i->top());
        cout << "-----------------------------" << endl;
        cout << "Nombre: " << i->top().name << "\n" << "Incentivo total: " << i->top().total << endl;
        cout << "-----------------------------" << endl;
        i->pop();
    }
    i = &s_aux;
}

void passErrors(LinkedList<Incentives> *ie, queue<Incentives> *e) {
    struct Incentives aux;
    queue<Incentives> q_aux;
    for (int j = 0; j < ie->size(); ++j) {
        aux = ie->get(j);
        e->push(aux);
    }
    while(!e->empty()){
        q_aux.push(e->front());
        cout << "-----------------------------" << endl;
        cout << "Nombre: " << e->front().name << "\n" << "Descuento total: " << e->front().p_errors << endl;
        cout << "-----------------------------" << endl;
        e->pop();
    }
    e = &q_aux;
}

void save (LinkedList<Incentives> *i){
    ofstream Incentives;
    Incentives.open("Incentivos.txt",ios::app);
    for (int j = 0; j < i->size(); ++j) {
        Incentives << "-----------------------------" << endl;
        Incentives << "Nombre: " << i->get(j).name << "\n" << "Incentivo por antiguedad: "
             << i->get(j).i_antiquity << "\n" << "Incentivo por lineas codeadas: " << i->get(j).i_lines << "\n"
             << "Descuentos: " << i->get(j).p_errors << "\n" << "Incentivo total: "
             << i->get(j).total << endl;
        Incentives << "-----------------------------" << endl;
    }

}