#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Product {
    int code;
    string name;
    int quantity;
    float price;
};

int menu();

stack<Product> load(stack<Product>);

void show_list(stack<Product>);

stack<Product> stock_discount(stack<Product>);

stack<Product> stock_add(stack<Product>);

int main() {

    int option = 0;
    stack<Product> stock;
    stock = load(stock);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                show_list(stock);
                break;
            case 2:
                stock = stock_discount(stock);
                break;
            case 3:
                stock = stock_add(stock);
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
        }
    } while (option != 0);


    return 0;
}

int menu() {

    int option = 0;
    cout << "Ingrese la opcion a realizar" << endl;
    cout << "1. Mostrar listado de elementos" << endl;
    cout << "2. Descontar stock" << endl;
    cout << "3. Agregar stock" << endl;
    cout << "0. Salir" << endl;
    cin >> option;
    return option;

}

stack<Product> load(stack<Product> s) {
    struct Product aux;
    aux = {0, "Pan", 10, 25};
    s.push(aux);
    aux = {1, "Facturas", 50, 30};
    s.push(aux);
    aux = {2, "Alfajores", 5, 55};
    s.push(aux);
    return s;
}

void show_list(stack<Product> s) {
    stack<Product> aux;
    while (!s.empty()) {
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Codigo: " << s.top().code << "\n" << "Nombre: " << s.top().name << endl;
        cout << "Stock: " << s.top().quantity << "\n" << "Precio: " << s.top().price << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        aux.push(s.top());
        s.pop();

    }
    s = aux;
    cout << endl;
}

stack<Product> stock_discount(stack<Product> s) {

    stack<Product> aux_s;
    int quantity;
    int code;

    cout << "Ingrese el code de producto a descontar stock" << endl;
    cin >> code;
    cout << "Ingrese la cantidad de stock a descontar" << endl;
    cin >> quantity;

    while (!s.empty()) {
        aux_s.push(s.top());
        if (aux_s.top().code == code) {
            aux_s.top().quantity = aux_s.top().quantity - quantity;
        }
        s.pop();
    }

    s = aux_s;

    return s;

}

stack<Product> stock_add(stack<Product> s) {

    stack<Product> aux_s;
    int quantity;
    int code;

    cout << "Ingrese el code de producto a agregar stock" << endl;
    cin >> code;
    cout << "Ingrese la cantidad de stock a agregar" << endl;
    cin >> quantity;

    while (!s.empty()) {
        aux_s.push(s.top());
        if (aux_s.top().code == code) {
            aux_s.top().quantity = aux_s.top().quantity + quantity;
        }
        s.pop();
    }

    s = aux_s;

    return s;

}
