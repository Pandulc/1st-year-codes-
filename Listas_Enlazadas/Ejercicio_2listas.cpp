#include <iostream>
#include <ctime>
#include "LinkedList.h"

using namespace std;

LinkedList<char> load(LinkedList<char>);

void show(LinkedList<char>);

void consonants(LinkedList<char>);

void vowels(LinkedList<char>);

int main() {

    LinkedList<char> l;
    l = load(l);
    consonants(l);
    vowels(l);
    show(l);

    return 0;
}

LinkedList<char> load(LinkedList<char> list) {

    srand(time(NULL));
    for (int i = 0; i < 20; ++i) {
        list.insert(i, rand() % 25 + 65);
    }

    return list;
}

void consonants(LinkedList<char> list) {
    int adder = 0;
    for (int i = 0; i < 20; ++i) {
        if (list.get(i) != 'A' && list.get(i) != 'E' && list.get(i) != 'I' && list.get(i) != 'O' &&
            list.get(i) != 'U') {
            adder++;
        }
    }
    cout << "La cantidad de consonantes son: " << adder << endl;
}

void vowels(LinkedList<char> list) {
    int adder = 0;
    for (int i = 0; i < 20; ++i) {
        if (list.get(i) == 'A' || list.get(i) == 'E' || list.get(i) == 'I' || list.get(i) == 'O' ||
            list.get(i) == 'U') {
            adder++;
        }
    }
    cout << "La cantidad de vocales son: " << adder << endl;
}

void show(LinkedList<char> list) {
    list.print();
}