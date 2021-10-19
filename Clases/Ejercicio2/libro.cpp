//2. Crear una clase Libro, y luego un vector de objetos (diagrama y c�digo fuente).

#include <iostream>
#include "libro.h"
using namespace std;

int menu (void);
void show_list (Book []);
void add_prices (Book []);

int main(int argc, char *argv[]) {
	Book b[3];
	int ii = 0;
	int option = 0;
	int pages = 0;
	float price = 0;
	string author = " ";
	string subject = " ";
	
	do{
		option = menu();
		switch(option){
		case 1:
			for(ii = 0; ii < 3;ii++){
				cout<<"Ingrese la materia del libro"<<endl;
				cin>>subject;
				b[ii].setSubject(subject);
				cout<<"Ingrese el autor del libro"<<endl;
				cin>>author;
				b[ii].setAuthor(author);
				cout<<"Ingrese la cantidad de paginas del libro"<<endl;
				cin>>pages;
				b[ii].setPages(pages);
				cout<<"Ingrese el precio del libro"<<endl;
				cin>>price;
				b[ii].setPrice(price);
			}
			cout<<endl;
			break;
		case 2:
			show_list(b);
			break;
		case 3:
			add_prices(b);
			break;
		default:
			cout<<"La opcion ingresada no es valida"<<endl;
		}
		
	} while(option != 0);
	
	
	return 0;
}

int menu (){
	int op = 0;
	cout<<"Ingrese la opcion a realizar"<<endl;
	cout<<"1. Carga de libros\n2. Imprime libros\n3. Suma de precios\n0. Salir\n"<<endl;
	cin>>op;
	return op;
}

void show_list(Book book[3]){
	int ii = 0;
	
	for(ii = 0;ii < 3;ii++){
	cout<<"--------------------------------------"<<endl;
	cout<<"Materia: "<<book[ii].getSubject()<<endl;
	cout<<"Paginas: "<<book[ii].getPages()<<endl;
	cout<<"Precio: "<<book[ii].getPrice()<<endl;
	cout<<"Autor: "<<book[ii].getAuthor()<<endl;
	cout<<"--------------------------------------"<<endl;
	}
	
}
	
void add_prices (Book book[]){
	int adder = 0;
	int ii = 0;
	cout<<endl;
	for(ii = 0;ii < 3;ii++){
		adder = adder + book[ii].getPrice();
	}
	cout<<"La suma total es de: "<<adder<<" pesos"<<endl;
	cout<<endl;
}
