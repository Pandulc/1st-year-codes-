/*3. Ingresar una palabra y determinar si es palindroma o no. 
(Un palindromo es una palabra, numero o frase que se lee igual hacia adelante que hacia atrás.
Si se trata de un numero, se llama capicua. Ejemplo: Neuquen)
*/

#include <iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

int palindrome (char [],int,int);

int main(int argc, char *argv[]){
	char word[10]={' '};
	int size = 0;
	int pal = 0;
	
	cout<<"ingrese una palabra para saber si es palindroma"<<endl;
	cin.getline(word,10);
	size=strlen(word);
	pal=palindrome(word,0,size-1);
	if(pal == 1){
		cout<<"La palabra efectivamente es palindroma"<<endl;
	}
	if(pal == 0){
		cout<<"La palabra no es palindroma"<<endl;
	}
	
	return 0;
}

int palindrome (char w[],int i, int f){
	if(i>=f){
		return 1;
	}
	if( w[i] == w[f] ){
		palindrome(w,i+1,f-1);
		return 1;
	}
	return 0;
}

