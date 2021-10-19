#include <iostream>
using namespace std;

void load (int *, int);
void show (int *, int);
void show_inverted (int *,int);

int main(){

    int characters = 0;
    int * array;
    cout<<"Introduzca la cantidad de caracteres a cargar"<<endl;
    cin>>characters;
    array=new int [characters];
    load(array,characters);
    show(array,characters);
    show_inverted(array,characters);


    return 0;
}

void load (int * a, int c){

    for(int ii = 0; ii < c; ii++){
        cout<<"Ingrese el caracter "<<ii+1<<endl;
        cin>>a[ii];
    }

}

void show (int * a,int c){

    cout<<"Los elementos ingresados son"<<endl;
    for(int ii = 0; ii < c; ii++){
        cout<<a[ii];
    }
    cout<<endl;
}

void show_inverted (int * a, int c){
    cout<<"Los elementos ingresados, en orden inverso, son"<<endl;
    for(int ii = 0; ii < c;ii++){
        cout<<a[(c-1)-ii];

    }
}