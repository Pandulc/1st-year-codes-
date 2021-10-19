/*1. Crear un programa que pida los siguientes datos de una canción: Artista, Titulo,
* Duración (en segundos),Tamaño del archivo (en KB). Crear una estructura que almacene datos de la canción y
* luego los muestre por pantalla.*/
#include <iostream>
#include <string.h>

using namespace std;

struct song{
	char artist [50] = " ";
	char title [50] = " ";
	int duration = 0;
	int size = 0;
};

int main (){
	struct song song1;
	/* pensar "struct song" como si fuera "int": es el tipo de dato que posee string string int int. song1 es la variable que contendra los datos */
	cout<<"Ingrese el artista de la cancion"<<endl;
	cin.getline(song1.artist,50);
	cout<<"Ingrese el titulo de la cancion"<<endl;
	cin.getline(song1.title,50);
	cout<<"Ingrese la duracion en segundos de la cancion"<<endl;
	cin>>song1.duration;
	cout<<"Ingrese el tamanio de la cancion"<<endl;
	cin>>song1.size;
	
	cout<<endl;
	
	cout<<"Artista: "<<song1.artist<<endl;
	cout<<"Titulo: "<<song1.title<<endl;
	cout<<"Duracion: "<<song1.duration<<" segundos"<<endl;
	cout<<"Tamanio:  "<<song1.size<<" kb"<<endl;
	
	return 0;
}
