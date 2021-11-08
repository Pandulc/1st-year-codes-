#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>


using namespace std;

int menu();

void load(int *, int);

void boiler(int *, int);

void average(int *, int);

void qs(int *, int, int);

void save(int *, int);

int main() {
    int *temperatures;
    int measurements = 24;
    int option = 0;

    temperatures = new int[measurements];
    load(temperatures, measurements);
    do {
        option = menu();
        switch (option) {
            case 0:
                break;
            case 1:
                boiler(temperatures, measurements);
                break;
            case 2:
                average(temperatures, measurements);
                break;
            case 3:
                qs(temperatures, measurements - 1, 0);
                for (int i = 0; i < measurements; ++i) {
                    cout << " " << temperatures[i];
                }
                break;
            case 4:
                save(temperatures, measurements);
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }

    } while (option != 0);

}

int menu() {
    int op = 0;

    cout << "Ingrese la opcion a realizar" << endl;
    cout << "1. Cantidad de veces que se activo la caldera en un dia." << endl;
    cout << "2. Calcular el promedio de temperatura del agua en todo un dia" << endl;
    cout << "3. Ordenar las temperaturas." << endl;
    cout << "4. Guardar los datos en un archivo." << endl;
    cout << "0. Salir." << endl;
    cin >> op;

    return op;
}

void load(int *t, int m) {
    int temp = 0;
    srand(time(NULL));

    for (int ii = 0; ii < m; ii++) {
        temp = rand() % 50 + 0;
        t[ii] = temp;
    }
    for (int jj = 0; jj < m; jj++) {
        cout << " " << t[jj];
    }
    cout << endl;
}

void boiler(int *t, int m) {
    int accountant = 0;
    for (int ii = 0; ii < m; ii++) {
        if (t[ii] < 34) {
            accountant++;
        }
    }
    cout << "La cantidad de veces que la caldera se encendio fueron: " << accountant << endl;
}

void average(int *t, int m) {
    float av = 0;
    int sum = 0;

    for (int ii = 0; ii < m; ++ii) {
        sum = sum + t[ii];
    }
    av = (float) sum / m;
    cout << "El promedio de temperaturas en el dia es de: " << av << endl;
}

void qs(int *t, int rl, int ll) {
    int tmp = 0;
    int left = 0;
    int right = 0;
    int pivot = 0;
    left = ll;
    right = rl;
    pivot = t[(ll + rl) / 2];
    do {
        while (t[left] < pivot && left < rl) {
            left++;
        }
        while (t[right] > pivot && right > ll) {
            right--;
        }
        if (left <= right) {
            tmp = t[left];
            t[left] = t[right];
            t[right] = tmp;
            left++;
            right--;
        }
    } while (left <= right);
    if (ll < right) {
        qs(t, right, ll);
    }
    if (rl > left) {
        qs(t, rl, left);
    }
}

void save(int *t, int m) {

    ofstream temperatures;
    temperatures.open("Mediciones_Dia.txt", ios::app);
    for (int ii = 0; ii < m; ++ii) {
        temperatures << "Medicion " << ii << ": " << t[ii] << endl;
    }

}