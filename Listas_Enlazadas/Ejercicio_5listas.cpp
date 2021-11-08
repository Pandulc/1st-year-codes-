#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"

using namespace std;

struct Stock {
    int code;
    string name;
    char size;
    float list_price;
    float public_price;
    int stock;
    int sold;

};
struct Sales {

    string name;
    char size;
    int units;
    float amount;
    float total;

};

int menu();

LinkedList<Stock> load(LinkedList<Stock>);

LinkedList<Sales> sale(LinkedList<Stock>);


int main() {

    int option = 0;
    LinkedList<Stock> stock;
    LinkedList<Sales> sales;
    stock = load(stock);

    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                sales = sale(stock);
                break;
            case 2:

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
    cout << "1. Registrar venta" << endl;
    cout << "2. Mostrar listado con las facturas registradas" << endl;
    cout << "3. Calcular la recaudacion del dia y la ganancia" << endl;
    cout << "4. Mostrar listado de productos por talle" << endl;
    cout << "5. Generar archivo con los productos sin Stock" << endl;
    cout << "0. Salir" << endl;
    cin >> option;
    return option;
}

LinkedList<Stock> load(LinkedList<Stock> s) {
    struct Stock aux_s;
    aux_s = {1, "Musculosa", 'S', 200, 0, 0, 0};
    s.insert(0, aux_s);
    aux_s = {2, "Musculosa", 'M', 230, 0, 8, 2};
    s.insert(0, aux_s);
    aux_s = {3, "Musculosa", 'L', 260, 0, 50, 10};
    s.insert(0, aux_s);
    aux_s = {4, "Short", 'S', 1100, 0, 5, 3};
    s.insert(0, aux_s);
    aux_s = {5, "Short", 'M', 1300, 0, 10, 0};
    s.insert(0, aux_s);
    aux_s = {6, "Short", 'L', 1400, 0, 0, 0};
    s.insert(0, aux_s);
    for (int i = 0; i < s.size(); ++i) {
        aux_s = s.get(i);
        aux_s.public_price = ((aux_s.list_price * 60) / 100) + aux_s.list_price;
        s.replace(i, aux_s);
    }
    return s;
}

LinkedList<Sales> sale(LinkedList<Stock> stock) {

    LinkedList<Sales> sales;

    struct Stock aux_stock[stock.size()];
    struct Sales aux_sales;

    int option = 0;
    int units = 0;
    int aux_code;
    char aux_size;


    for (int i = 0; i < stock.size(); ++i) {
        aux_stock[i] = stock.get(i);
        if (aux_stock[i].stock != 0) {
            cout << "------------------------------------" << endl;
            cout << "Codigo: " << aux_stock[i].code << endl;
            cout << "Nombre: " << aux_stock[i].name << endl;
            cout << "Talle: " << aux_stock[i].size << endl;
            cout << "Precio: " << aux_stock[i].public_price << endl;
            cout << "Stock: " << aux_stock[i].stock << endl;
            cout << "------------------------------------" << endl;
        }
    }
    do {
        cout << "Ingrese el codigo del producto a llevar" << endl;
        cin >> aux_code;
        cout << "Ingrese el talle" << endl;
        cin >> aux_size;
        for (int i = 0; i < stock.size(); ++i) {
            cout << "------------------------------------" << endl;
            cout << "Codigo: " << aux_stock[i].code << endl;
            cout << "Nombre: " << aux_stock[i].name << endl;
            cout << "Talle: " << aux_stock[i].size << endl;
            cout << "Precio: " << aux_stock[i].public_price << endl;
            cout << "Stock: " << aux_stock[i].stock << endl;
            cout << "------------------------------------" << endl;
            if (aux_stock[i].code == aux_code && aux_stock[i].size == aux_size) {
                aux_sales.name = aux_stock[i].name;
                aux_sales.size = aux_size;
                cout << "Ingrese las unidades a llevar" << endl;
                cin >> units;
                aux_sales.units = units;
                aux_sales.amount = units * aux_stock[i].public_price;
                aux_sales.total = aux_sales.total + aux_sales.amount;
                sales.insert(0, aux_sales);
            }
        }

    } while (option != 0);
}
