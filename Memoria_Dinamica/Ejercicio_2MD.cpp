#include <iostream>

using namespace std;

void load(char *, int);

void show(char *);

char *resize(const char *, int);


int main() {

    char *text;
    int characters = 0;
    int characters_toadd = 0;
    cout << "Ingrese la cantidad de caracteres a escribir" << endl;
    cin >> characters;
    text = new char[characters];
    load(text, characters);
    show(text);
    cout << endl;
    cout << "Cuantos caracteres desea agregar?" << endl;
    while (getchar() != '\n');
    cin.clear();
    cin >> characters_toadd;
    text = resize(text, characters_toadd);
    load(text, characters + characters_toadd);
    show(text);

    return 0;
}

void load(char *t, int c) {
    cout << "Ingrese el texto" << endl;
    cin.getline(t, c, '.');

}

void show(char *t) {
    cout << t;
}

char *resize(const char *t, int c_a) {
    char *tmp;
    tmp = new char[sizeof(t) + c_a];
    for (int ii = 0; ii < sizeof(t); ii++) {
        tmp[ii] = t[ii];
    }
    delete t;
    return tmp;
}