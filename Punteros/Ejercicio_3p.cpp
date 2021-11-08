#include <iostream>
#include <string>

using namespace std;

struct Article {
    string name = " ";
    float price = 0;
};

void load(Article *);

void show_list(Article *);

int main() {
    Article a[3];
    load(a);
    show_list(a);

    return 0;
}

void load(Article *ar) {
    for (int ii = 0; ii < 3; ii++) {
        cout << "Ingrese el nombre del articulo " << ii + 1 << endl;
        getline(cin, ar[ii].name, '.');
        cout << "Ingrese el precio del articulo " << ii + 1 << endl;
        cin >> ar[ii].price;
    }
}

void show_list(Article *ar) {
    for (int ii = 0; ii < 3; ii++) {
        cout << "-------------------------------------" << endl;
        cout << "Nombre: " << ar[ii].name << endl;
        cout << "Precio: " << ar[ii].price << endl;
        cout << "-------------------------------------" << endl;
    }
}