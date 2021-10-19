#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int menu ();
void load (int *,int);
void show (int *,int);
int sum (int *,int);

int main(){
    int option = 0;
    int size = 0;
    int total = 0;
    int * vector = nullptr;
    cout<<"Ingrese la cantidad de numeros a almacenar"<<endl;
    cin>>size;
    vector = new int [size];
    do{
        option = menu();
        switch(option){
            case 1:
                load(vector, size);
                break;
            case 2:
                show(vector, size);
                cout<<endl;
                break;
            case 3:
                total = sum(vector, size-1);
                cout<<"La suma de los elementos del vector es igual a: "<<total<<endl;
                break;
            default:
                cout<<"Ingrese una opcion valida"<<endl;
                break;
        }
    }while(option != 0);

    delete vector;

    return 0;
}

int menu (){

    int op = 0;
    cout<<"Ingrese la opcion a realizar"<<endl;
    cout<<"1. Rellenar aleatoriamente el vector con numeros entre el 1 y 10 utilizando punteros."<<endl;
    cout<<"2. Mostrar el vector anterior por medio de punteros los valores del vector y las direcciones en las cuales los valores sean mayores a 5 inclusive."<<endl;
    cout<<"3. Sumar todos los numeros del vector de manera recursiva."<<endl;
    cout<<"0. Salir"<<endl;
    cin>>op;
    return op;

}

void load (int * v, int s){

    int number = 0;
    srand(time(NULL));
    for(int ii = 0; ii < s; ii++){
        number = rand()%10+1;
         v[ii] = number;
    }

}

void show (int * v, int s){

    cout<<"Los valores del vector son:"<<endl;
    for(int ii = 0; ii < s; ii++){
        cout<<" "<<v[ii];
    }
    cout<<endl;
    cout<<"Las direcciones de memoria de los valores mayores a 5 son:"<<endl;
    for(int ii = 0; ii < s; ii++){
        if(v[ii] >= 5){
            cout<<" "<<&v[ii];
        }
    }
}

int sum (int * v,int s){

    int adder = 0;
    if(s == 0){
        return v[s];
    }
    else{
        adder = adder + v[s] + sum(v,s-1);
    }
    return adder;
}
