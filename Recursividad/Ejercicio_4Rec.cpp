/*4. Realizar un programa que muestre la serie Fibonacci, ingresando la cantidad de n�meros de la serie a
* visualizar. Por ejemplo: 10 valores. Deber�a mostrar: 0   1   1   2   3   5   8   13   21   34
*/
#include <iostream>

using namespace std;

int fibonacci(int);

int main() {
    int quantity = 0;
    int ii = 0;

    cout << "Ingrese la cantidad de valores de la sucesion a mostrar" << endl;
    cin >> quantity;

    for (ii = 0; ii < quantity; ii++) {
        cout << fibonacci(ii) << '\t';
    }

    return 0;
}

int fibonacci(int i) {
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    return fibonacci(i - 2) + fibonacci(i - 1);
}
