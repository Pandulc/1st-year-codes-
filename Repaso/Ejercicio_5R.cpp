#include <iostream>
#include <string>
#include <stack>
#include "../Listas_Enlazadas/LinkedList.h"
#include <fstream>

using namespace std;

struct App {
    string name;
    int priority;
};

struct Game {
    string name;
    stack<App> apps;
};

void load(LinkedList<Game> *);

int main() {

    string gName;
    LinkedList<Game> games;
    stack<App> sAux;

    load(&games);
    cout << "Ingrese el juego a descargar" << endl;
    getline(cin, gName, '.');
    for (int i = 0; i < games.size(); ++i) {
        if (gName == games.get(i).name) {
            ofstream requirements;
            requirements.open("Requisitos.txt");
            sAux = games.get(i).apps;
            cout << "Juego: " << gName << endl;
            requirements << "Juego: " << gName << endl;
            while (!sAux.empty()) {
                cout << "Aplicacion: " << sAux.top().name << "\n" << "Prioridad: " << sAux.top().priority << endl;
                requirements << "Aplicacion: " << sAux.top().name << "\n" << "Prioridad: " << sAux.top().priority
                             << endl;
                sAux.pop();
            }
        }
    }
    return 0;
}

void load(LinkedList<Game> *g) {
    stack<App> requirements;
    struct App rApps;
    struct Game game;
    rApps = {"Steam", 1};
    requirements.push(rApps);
    rApps = {"DirectX_11", 1};
    requirements.push(rApps);
    rApps = {"MSI Afterburner", 3};
    requirements.push(rApps);
    game = {"War Thunder", requirements};
    g->insert(0, game);
    while (!requirements.empty()) {
        requirements.pop();
    }
    rApps = {"Steam", 1};
    requirements.push(rApps);
    rApps = {"BeamMP Launcher", 1};
    requirements.push(rApps);
    rApps = {"Discord", 1};
    requirements.push(rApps);
    game = {"BeamNG Drive", requirements};
    g->insert(0, game);
    while (!requirements.empty()) {
        requirements.pop();
    }
    rApps = {"Epic Games", 1};
    requirements.push(rApps);
    rApps = {"Discord", 2};
    requirements.push(rApps);
    game = {"Rocket League", requirements};
    g->insert(0, game);
}