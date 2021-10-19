#include <iostream>
using namespace std;

int menu ();
void reservaYcarga (int *,int);
int * agregaycarga (const int *, int *, int);
void muestra_datos (int *, int);

int main(){

    int opcion = 0;
    int cantidad = 0;
    int cantidad_agregada = 0;
    int * lista = nullptr;
    do{
        opcion = menu();
        switch(opcion){
            case 0:
                break;
            case 1:
                cout<<"Ingrese la cantidad de datos a cargar"<<endl;
                cin>> cantidad;
                lista = new int [cantidad];
                reservaYcarga(lista,cantidad);
                break;
            case 2:
                cout<<"Ingrese la cantidad de datos a agregar"<<endl;
                cin>>cantidad_agregada;
                lista = agregaycarga(lista, &cantidad, cantidad_agregada);
                reservaYcarga(lista,cantidad);
                break;
            case 3:
                muestra_datos(lista,cantidad);
                cout<<endl;
                break;

        }
    }while(opcion != 0);

    delete lista;

    return 0;
}

int menu (){
    int op = 0;

    cout<<"Ingrese la opcion a realizar"<<endl;
    cout<<"1. Reserva de memoria e introduccion de datos enteros."<<endl;
    cout<<"2. Agregar reserva de memoria e introduccion de nuevos datos enteros."<<endl;
    cout<<"3. Mostrar los datos en el orden y orden invertido al que fueron introducidos."<<endl;
    cout<<"0. Salir."<<endl;
    cin>>op;

    return op;
}

void reservaYcarga (int * l,int c){

    int numero = 0;

    for (int i = 0; i < c; ++i) {
        cout<<"Ingrese el valor "<<i+1<<endl;
        cin>>numero;
        l[i] = numero;
    }

}

int * agregaycarga (const int * l, int *c, int c_a){

    int numero = 0;
    int * tmp = nullptr;
    tmp = new int [*c];
    for (int i = 0; i < *c+c_a; ++i) {
        tmp[i] = l[i];
    }
    *c = *c+c_a;
    delete l;
    return tmp;
}

void muestra_datos (int * l, int c){

    cout<<"Los valores del vector son:"<<endl;
    for(int i = 0; i < c; i++){
        cout<<" "<<l[i];
    }
    cout<<"\nLos valores en orden inverso son:"<<endl;
    for (int i = 0; i < c; ++i) {
        cout<<" "<<l[(c-1)-i];
    }
}