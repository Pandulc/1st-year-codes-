#include <iostream>
#include <ctime>
#include <fstream>
#define TAM 5
using namespace std;

int menu ();
void load (int*);
void show (int*);
void showPairs (int*);
void sum (int*);
void save(int*);


int main(int argc, char *argv[]) {
	int values [TAM];
	int option;
    load(values);
	do{
        option = menu();
		switch(option){
		case 0:
			break;
		case 1:
            show(values);
			break;
		case 2:
            showPairs(values);
			break;
		case 3:
            sum(values);
			break;
		case 4:
            save(values);
			break;
		default:
			cout<<"Ingres una option valida"<<endl;
			break;
		}
	} while(option != 0);
	return 0;
}


int menu (){
	int option;
	cout<<"Ingrese la option a realizar"<<endl;
	cout<<"1. Mostrar los valores del vector"<<endl;
	cout<<"2. Mostrar los valores pares y su direccion de memoria"<<endl;
	cout<<"3. Calcular la sumatoria de los valores"<<endl;
	cout<<"4. Guardar los valores en un archivo"<<endl;
	cout<<"0. Salir"<<endl;
	cin >> option;
	return option;
}

void load (int val[]){
	int number;
	srand(time(NULL));
	for(int i = 0;i < TAM; i++){
        number = rand() % 10 + 1;
		val[i] = number;
	}
}

void show (int val []){
	cout<<"Listado completo"<<endl;
	for(int i = 0;i < TAM; i++){
		cout<<val[i]<<'\t';
	}
	cout<<endl;
}

void showPairs(int val[]){
	cout<<"Listado de valores pares"<<endl;
	for(int i = 0;i<TAM;i++){
		if(val[i] % 2 == 0){
			cout<<"Valor: "<<val[i]<<endl;
			cout<<"Direccion de Memoria: "<<&val[i]<<endl;
		}
	}
	cout<<endl;
}

void sum (int val[]){
	int sum = 0;
	for(int i = 0;i < TAM;i++){
        sum = sum + val[i];
	}
	cout << "La suma total de los valores es: " << sum << endl;
}

void save(int val[]){
	int sum = 0;
	ofstream Values;
	Values.open("Valores.txt", ios::app);
	Values << "Listado completo" << endl;
	for(int i = 0;i<TAM;i++){
		Values << val[i] << '\t';
	}
	Values << endl;
	Values << "Listado de Values pares" << endl;
	for(int i = 0;i<TAM;i++){
		if(val[i] % 2 == 0){
			Values << "Valor: " << val[i] << endl;
			Values << "Direccion de Memoria: " << &val[i] << endl;
	}
	}
	for(int i = 0;i < TAM;i++){
        sum = sum + val[i];
	}
	Values << "La sum total de los Values es: " << sum << endl;
}
