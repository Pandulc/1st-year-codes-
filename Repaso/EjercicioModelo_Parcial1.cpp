#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main (){

    char *  alphabet;
    int limit = 0;
    cout<<"Ingrese los espacios del arreglo"<<endl;
    cin>>limit;
    alphabet = new char [limit];
    srand(time(NULL));
    for (int i = 0; i < limit; ++i) {
        alphabet[i]= rand()%90+65;
    }
    for (int j = 0; j < limit; ++j) {
        cout<<" "<<alphabet[j];
    }

    return 0;
}

