#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int menu ();
void write ();
void read ();

int main (){
    int option = 0;
    do{
        option = menu();
        switch(option){
            case 1:
                write();
                break;
            case 2:
                read();
                break;
            default:
                cout<<"Ingrese una opcion valida"<<endl;
        }
    }while(option != 0);
}

int menu (){
    int op = 0;
    cout<<"Ingrese la opcion a realizar"<<endl;
    cout<<"1. Escribir poema"<<endl;
    cout<<"2. Mostrar poema escrito"<<endl;
    cout<<"0. Salir"<<endl;
    cin>>op;
    return op;
}

void write(){
    string poem = " ";
    cout<<"Escriba su poema"<<endl;
    getline(cin,poem,'.');
    ofstream p;
    p.open("Poema.txt",ios::app);
    p<<poem<<endl;
    p.close();
}

void read(){
    string poem = " ";
    ifstream p;
    p.open("Poema.txt");
    while(!p.eof()){
        getline(p,poem);
        cout<<poem<<endl;
    }
    p.close();
}