#include <iostream>
using namespace std;

int addition (int);

int main(int argc, char *argv[]) {
	
	int quantity = 0;
	int result=0;
	
	cout<<"Ingrese la cantidad de valores naturales a imprimir"<<endl;
	cin>>quantity;
	result=addition(quantity);
	cout<<"suma: "<<result;
	
	
	return 0;
}

int addition (int q){
	
	if (q == 0){
		return 0;
	}
	else{
		return q+addition(q-1);
	}
}
	
