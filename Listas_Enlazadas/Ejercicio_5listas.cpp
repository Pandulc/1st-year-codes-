#include <iostream>
#include "LinkedList.h"
#include <string>
#include <fstream>
using namespace std;

struct Product {
    int code;
    string name;
    char size;
    float list_price;
    float public_price;
    int stock;
    int sold;
};

struct Bills {
    int code;
    string name;
    char size;
    int unities;
    float price;
    float subtotal;
};

int menu();

void load(LinkedList<Product> *);

float sale(LinkedList<Product> *, LinkedList<Bills> *);

void show(LinkedList<Bills> *);

void r_g(float, LinkedList<Product> *, LinkedList<Bills> *);

void size_list(LinkedList<Product> *);

void stock(LinkedList<Product> *);

int main() {
    int option;
    float total;
    LinkedList<Product> products;
    LinkedList<Bills> bills;

    load(&products);
    do {
        option = menu();

        switch (option) {
            case 0:
                break;
            case 1:
                cout<<endl;
                total = total + sale(&products, &bills);
                break;
            case 2:
                cout<<endl;
                show(&bills);
                break;
            case 3:
                cout<<endl;
                r_g(total, &products, &bills);
                break;
            case 4:
                cout<<endl;
                size_list(&products);
                break;
            case 5:
                cout<<endl;
                stock(&products);
                break;
            default:
                cout<<endl;
                cout << "Ingrese una opcion valida" << endl;
        }
    } while (option != 0);

    return 0;
}

int menu() {
    int option = 0;
    cout << "Ingrese la opcion a realizar" << endl;
    cout << "1. Realizar una venta" << endl;
    cout << "2. Mostrar un listado de las facturas del dia" << endl;
    cout << "3. Calcular la recaudacion del dia y la ganancia del dia" << endl;
    cout << "4. Mostrar el listado de productos por talle" << endl;
    cout << "5. Generar archivo con productos sin stock" << endl;
    cout << "0. Salir" << endl;
    cin >> option;
    return option;
}

void load(LinkedList<Product> *l) {
    struct Product aux;
    aux = {1, "Musculosa", 'S', 200, 0, 0, 0};
    aux.public_price = (aux.list_price * 60) / 100 + aux.list_price;
    l->push_front(aux);
    aux = {2, "Musculosa", 'M', 230, 0, 8, 2};
    aux.public_price = (aux.list_price * 60) / 100 + aux.list_price;
    l->push_front(aux);
    aux = {3, "Musculosa", 'L', 260, 0, 50, 10};
    aux.public_price = (aux.list_price * 60) / 100 + aux.list_price;
    l->push_front(aux);
    aux = {4, "Short", 'S', 1100, 0, 5, 3};
    aux.public_price = (aux.list_price * 60) / 100 + aux.list_price;
    l->push_front(aux);
    aux = {5, "Short", 'M', 1300, 0, 10, 0};
    aux.public_price = (aux.list_price * 60) / 100 + aux.list_price;
    l->push_front(aux);
    aux = {6, "Short", 'L', 1400, 0, 0, 0};
    aux.public_price = (aux.list_price * 60) / 100 + aux.list_price;
    l->push_front(aux);
}

float sale(LinkedList<Product> *l_p, LinkedList<Bills> *l_v) {
    int s_code;
    int s_quantity;
    int option1;
    int option2;
    int pay_method;
    float amount;
    float total = 0;
    struct Product aux_p;
    struct Bills aux_b;
    LinkedList<Bills> b_auxl;

    for (int i = 0; i < l_p->size(); ++i) {
        if (l_p->get(i).stock != 0) {
            cout << "Codigo: " << l_p->get(i).code << "\t" << "Producto: " << l_p->get(i).name << "\t" << "Talle: "
                 << l_p->get(i).size << "\t" << "Precio: " << l_p->get(i).public_price << "\t" << "Stock: "
                 << l_p->get(i).stock << endl;
        }
    }
    cout << endl;
    do {
        cout << "Ingrese el codigo del producto buscado" << endl;
        cin >> s_code;
        cout << "Ingrese la cantidad de unidades a llevar" << endl;
        cin >> s_quantity;
        for (int i = 0; i < l_p->size(); ++i) {
            aux_p = l_p->get(i);
            if (s_code == aux_p.code) {
                if (aux_p.stock == 0) {
                    cout << "NO HAY STOCK" << endl;
                }
                if (s_quantity > aux_p.stock) {
                    cout << "Stock insuficiente! Desea realizar la operacion con el stock existente (" << aux_p.stock
                         << ")? 1) SI 0) NO" << endl;
                    cin >> option2;
                    if (option2 == 1) {
                        aux_b.code = aux_p.code;
                        aux_b.name = aux_p.name;
                        aux_b.size = aux_p.size;
                        aux_b.price = aux_p.public_price;
                        aux_b.unities = aux_p.stock;
                        aux_b.subtotal = aux_b.price * aux_b.unities;
                        b_auxl.push_front(aux_b);
                        aux_p.sold = aux_p.sold + aux_p.stock;
                        aux_p.stock = 0;
                        l_p->replace(i, aux_p);
                    }
                }
                if (s_quantity <= aux_p.stock) {
                    aux_b.code = aux_p.code;
                    aux_b.name = aux_p.name;
                    aux_b.size = aux_p.size;
                    aux_b.price = aux_p.public_price;
                    aux_b.unities = s_quantity;
                    aux_b.subtotal = aux_b.price * aux_b.unities;
                    b_auxl.push_front(aux_b);
                    aux_p.stock = aux_p.stock - s_quantity;
                    aux_p.sold = aux_p.sold + s_quantity;
                    l_p->replace(i, aux_p);
                }

            }
        }
        cout << "Quiere agregar mas productos? 1) SI 0) NO" << endl;
        cin >> option1;
    } while (option1 != 0);
    for (int i = 0; i < b_auxl.size(); ++i) {
        aux_b = b_auxl.get(i);
        cout << "Codigo: " << aux_b.code << "\t" << "Producto: " << aux_b.name << "\t" << "Talle: "
             << aux_b.size << "\t" << "Precio Unitario: " << aux_b.price << "\t" << "Unidades: "
             << aux_b.unities << "\t" << "Subtotal: " << aux_b.subtotal << endl;
        total = aux_b.subtotal + total;
    }
    cout << "Ingrese el metodo de pago: " << "\n" << "1) Efectivo" << "\n" << "2) Debito" << "\n" << "3) Credito"
         << endl;
    cin >> pay_method;
    if (pay_method == 1) {
        cout << "El total a pagar es: " << total << endl;
        cout << "Ingrese el monto abonado" << endl;
        cin >> amount;
        cout << "El vuelto a entregar es de: " << amount - total << endl;
    }
    if (pay_method == 2) {
        cout << "El total a pagar es: " << total << endl;
    }
    if (pay_method == 3) {
        total = total + (total / 100);
        cout << "El total a pagar es: " << total << endl;
    }
    for (int i = 0; i < b_auxl.size(); ++i) {
        l_v->push_front(b_auxl.get(i));
    }

    return total;
}

void show(LinkedList<Bills> *l_b) {
    for (int i = 0; i < l_b->size(); ++i) {
        cout << "---------- FACTURA " << i << " ----------" << endl;
        cout << "Cod: " << l_b->get(i).code << "\n" << "Prod: " << l_b->get(i).name << "\n" << "Talle: "
             << l_b->get(i).size << "\n" << "Unid: " << l_b->get(i).unities << "\n" << "P/U: " << l_b->get(i).price
             << "\n" << "Subtot: " << l_b->get(i).subtotal << endl;
        cout << "-------------------------------" << endl;
    }
}

void r_g(float t, LinkedList<Product> *l_p, LinkedList<Bills> *l_b) {
    float cost = 0;
    float gain = 0;
    for (int i = 0; i < l_p->size(); ++i) {
        for (int j = 0; j < l_b->size(); ++j) {
            if (l_b->get(j).code == l_p->get(i).code) {
                cost = cost + (l_b->get(j).unities * l_p->get(i).list_price);
            }
        }

    }
    gain = t - cost;
    cout << "La recaudacion total del dia fue de: " << t << endl;
    cout << "La ganancia total del dia es de: " << gain << endl;
}

void size_list(LinkedList<Product> *l_p) {
    LinkedList<Product> M;
    LinkedList<Product> L;
    LinkedList<Product> S;
    struct Product aux;
    for (int i = 0; i < l_p->size(); ++i) {
        aux = l_p->get(i);
        if (aux.size == 'M') {
            M.push_front(aux);
        }
        if (aux.size == 'S') {
            S.push_front(aux);
        }
        if (aux.size == 'L') {
            L.push_front(aux);
        }
    }
    cout << "/////Lista de productos talle M/////" << endl;
    for (int i = 0; i < M.size(); ++i) {
        cout << ".-----------------------------------------." << endl;
        cout << "Codigo: " << M.get(i).code << "\n" << "Producto: " << M.get(i).name << "\n" << "Talle: "
             << M.get(i).size << "\n" << "Precio Lista: " << M.get(i).list_price << "\n" << "Precio Publico: "
             << M.get(i).public_price << "\n" << "Stock: "
             << M.get(i).stock << "\n" << "Vendido: " << M.get(i).sold << endl;
        cout << ".-----------------------------------------." << endl;
    }
    cout << "/////Lista de productos talle S/////" << endl;
    for (int i = 0; i < S.size(); ++i) {
        cout << ".-----------------------------------------." << endl;
        cout << "Codigo: " << S.get(i).code << "\n" << "Producto: " << S.get(i).name << "\n" << "Talle: "
             << S.get(i).size << "\n" << "Precio Lista: " << S.get(i).list_price << "\n" << "Precio Publico: "
             << S.get(i).public_price << "\n" << "Stock: "
             << S.get(i).stock << "\n" << "Vendido: " << S.get(i).sold << endl;
        cout << ".-----------------------------------------." << endl;
    }
    cout << "/////Lista de productos talle L/////" << endl;
    for (int i = 0; i < L.size(); ++i) {
        cout << ".-----------------------------------------." << endl;
        cout << "Codigo: " << L.get(i).code << "\n" << "Producto: " << L.get(i).name << "\n" << "Talle: "
             << L.get(i).size << "\n" << "Precio Lista: " << L.get(i).list_price << "\n" << "Precio Publico: "
             << L.get(i).public_price << "\n" << "Stock: "
             << L.get(i).stock << "\n" << "Vendido: " << L.get(i).sold << endl;
        cout << ".-----------------------------------------." << endl;
    }
}

void stock(LinkedList<Product> *l_p) {
    ofstream stock;
    stock.open("Productos_NoStock.txt", ios::app);
    stock << "Listado de Productos sin Stock" << endl;
    for (int i = 0; i < l_p->size(); ++i) {
        if (l_p->get(i).stock == 0) {
            stock << ".-----------------------------------------." << endl;
            stock << "Codigo: " << l_p->get(i).code << "\n" << "Producto: " << l_p->get(i).name << "\n" << "Talle: "
                  << l_p->get(i).size << "\n" << "Precio Lista: " << l_p->get(i).list_price << "\n"
                  << "Precio Publico: "
                  << l_p->get(i).public_price << "\n" << "Stock: "
                  << l_p->get(i).stock << "\n" << "Vendido: " << l_p->get(i).sold << endl;
            stock << ".-----------------------------------------." << endl;
        }
    }
}