#include <iostream>
#include <string>
#include <ctime>
#include "../Listas_Enlazadas/LinkedList.h"
#include <stack>
#include <queue>

using namespace std;

struct Participants {
    string country;
    int round1;
    int round2;
    int round3;
    int total;
};

int menu();

void loadPoints(LinkedList<Participants> *);

void roundWinner(LinkedList<Participants> *, queue<string> *);

void totalPoints(LinkedList<Participants> *);

void winner(LinkedList<Participants> *, stack<string> *);


int main() {

    int option;
    LinkedList<Participants> participants;
    queue<string> roundWinners;
    queue<string> q_aux;
    stack<string> winners;
    stack<string> s_aux;
    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                loadPoints(&participants);
                for (int i = 0; i < participants.size(); ++i) {
                    cout << participants.get(i).country << "\t" << participants.get(i).round1 << "\t"
                         << participants.get(i).round2 << "\t" << participants.get(i).round3 << "\n";
                }
                cout << endl;
                break;
            case 2:
                roundWinner(&participants, &roundWinners);
                while (!roundWinners.empty()) {
                    q_aux.push(roundWinners.front());
                    cout << roundWinners.front() << "\n";
                    roundWinners.pop();
                }
                roundWinners = q_aux;
                cout << endl;
                break;
            case 3:
                totalPoints(&participants);
                for (int i = 0; i < participants.size(); ++i) {
                    cout << participants.get(i).country << "\t" << participants.get(i).round1 << "\t"
                         << participants.get(i).round2 << "\t" << participants.get(i).round3 << "\t"
                         << participants.get(i).total << "\n";
                }
                cout << endl;
                break;
            case 4:
                winner(&participants,&winners);
                while (!winners.empty()) {
                    s_aux.push(winners.top());
                    cout << winners.top() << "\n";
                    winners.pop();
                }
                winners = s_aux;
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
    cout << "1. Cargar puntaje de las rondas" << endl;
    cout << "2. Evaluar ganador de cada ronda" << endl;
    cout << "3. Calcular el puntaje total" << endl;
    cout << "4. Obtener el ganador" << endl;
    cout << "0. Salir" << endl;
    cin >> op;

    return op;
}

void loadPoints(LinkedList<Participants> *p) {
    struct Participants aux;
    int r1;
    int r2;
    int r3;
    srand(time(NULL));
    r1 = rand() % 27 + 3;
    r2 = rand() % 27 + 3;
    r3 = rand() % 30 + 3;
    aux = {"Alemania", r1, r2, r3, 0};
    p->insert(0, aux);
    r1 = rand() % 27 + 3;
    r2 = rand() % 27 + 3;
    r3 = rand() % 27 + 3;
    aux = {"Argentina", r1, r2, r3, 0};
    p->insert(0, aux);
    r1 = rand() % 27 + 3;
    r2 = rand() % 27 + 3;
    r3 = rand() % 27 + 3;
    aux = {"Australia", r1, r2, r3, 0};
    p->insert(0, aux);
    r1 = rand() % 27 + 3;
    r2 = rand() % 27 + 3;
    r3 = rand() % 27 + 3;
    aux = {"Espana   ", r1, r2, r3, 0};
    p->insert(0, aux);
    r1 = rand() % 27 + 3;
    r2 = rand() % 27 + 3;
    r3 = rand() % 27 + 3;
    aux = {"Estados Unidos", r1, r2, r3, 0};
    p->insert(0, aux);
    r1 = rand() % 27 + 3;
    r2 = rand() % 27 + 3;
    r3 = rand() % 27 + 3;
    aux = {"China   ", r1, r2, r3, 0};
    p->insert(0, aux);
}

void roundWinner(LinkedList<Participants> *p, queue<string> *rw) {
    struct Participants aux1;
    struct Participants aux2;
    struct Participants aux3;
    struct Participants draw;
    aux1 = p->get(0);
    aux2 = p->get(0);
    aux3 = p->get(0);
    for (int i = 0; i < p->size(); ++i) {
        if (p->get(i).round1 > aux1.round1) {
            aux1 = p->get(i);
        }
        if (p->get(i).round2 > aux2.round2) {
            aux2 = p->get(i);
        }
        if (p->get(i).round3 > aux3.round3) {
            aux3 = p->get(i);
        }
    }
    for (int i = 0; i < p->size(); ++i) {

        if (aux1.country == p->get(i).country) {
            aux1.round1 = aux1.round1 + 2;
            p->replace(i, aux1);

        }
        if (aux2.country == p->get(i).country) {
            aux2.round2 = aux2.round2 + 2;
            p->replace(i, aux2);
        }
        if (aux3.country == p->get(i).country) {
            aux3.round3 = aux3.round3 + 2;
            p->replace(i, aux3);
        }
    }


    rw->push(aux1.country);
    rw->push(aux2.country);
    rw->push(aux3.country);
}

void totalPoints(LinkedList<Participants> *p) {
    struct Participants aux;
    for (int i = 0; i < p->size(); ++i) {
        aux = p->get(i);
        aux.total = aux.round1 + aux.round2 + aux.round3;
        p->replace(i, aux);
    }
}

void winner (LinkedList<Participants>* p,stack<string>* w) {
    struct Participants gold;
    struct Participants silver;
    struct Participants bronze;
    for (int i = 0; i < p->size(); ++i) {
        if(i == 0){
            gold = p->get(i);
            silver = p->get(i+1);
            bronze = p->get(i+2);
        }
        else if(p->get(i).total > gold.total){
            silver = gold;
            bronze = gold;
            gold = p->get(i);
        }
        else if(p->get(i).total < gold.total && p->get(i).total > silver.total){
            bronze = silver;
            silver = p->get(i);
        }
    }
    w->push(bronze.country);
    w->push(silver.country);
    w->push(gold.country);

}