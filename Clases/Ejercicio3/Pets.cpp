#include <iostream>
#include "Pets.h"
using namespace std;

int menu (void);
void show_list(Pets []);
void show_list_byType(Pets []);

int main(int argc, char *argv[]) {
	Pets pets[3];
	int ii = 0;
	int option = 0;
	int a = 0;
	string t = " ";
	string r = " ";
	string n = " ";
	string re = " ";
	
	do{
		option = menu();
		switch(option){
		case 1:
			for(ii = 0;ii < 3;ii++){
				cout<<"Ingrese el tipo de mascota"<<endl;
				getline(cin,t,'.');
				pets[ii].setType(t);
				cout<<"Ingrese la raza de su mascota"<<endl;
				getline(cin,r,'.');
				pets[ii].setRace(r);
				cout<<"Ingrese el nombre de su mascota"<<endl;
				getline(cin,n,'.');
				pets[ii].setName(n);
				cout<<"Ingrese el responsable a cargo de la mascota"<<endl;
				getline(cin,re,'.');
				pets[ii].setResponsable(re);
				cout<<"Ingrese la edad de su mascota"<<endl;
				cin>>a;
				pets[ii].setAge(a);
			}
			break;
		case 2:
			show_list(pets);
			break;
		case 3:
			show_list_byType(pets);
			break;
		default:
			break;
		}
	} while(option != 0);
	return 0;
}

int menu (){
	int op = 0;
	
	cout<<"Ingrese la opcion a realizar"<<endl;
	cout<<"1. Carga de datos\n2. Mostrar listado de animales\n3. Mostrar listado de animales por tipo\n0. Salir\n"<<endl;
	cin>>op;
	return op;
}	

void show_list(Pets p[3]){
	for(int ii = 0;ii < 3;ii++){
		cout<<p[ii].toString();
	}
}
	
void show_list_byType(Pets p[3]){
	string t_wanted = " ";
	
	cout<<"Ingrese el tipo de mascota a mostrar"<<endl;
	getline(cin,t_wanted,'.');
	
	for(int ii = 0;ii < 3;ii++){
		if(t_wanted == p[ii].getType()){
		cout<<p[ii].toString();
		}
	}
}
