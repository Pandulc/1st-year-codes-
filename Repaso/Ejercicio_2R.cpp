#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Bill{
    int number;
    string date;
    float amount;
};

int menu ();
void load (Bill *, int);
int sum_amount (Bill *, int);
void save_sales (Bill *,int);

int main (){

    int option = 0;
    int quantity = 0;
    int amount = 0;
    Bill * sale;

    do{
        option = menu();
        switch(option){
            case 1:
                cout<<"Ingrese la cantidad de ventas a cargar"<<endl;
                cin>>quantity;
                sale = new Bill [quantity];
                load(sale,quantity);
                break;
            case 2:
                amount = sum_amount(sale,quantity-1);
                cout<<"El monto total del dia es de: "<<amount<<" pesos"<<endl;
                break;
            case 3:
                save_sales(sale,quantity);
                break;
        }
    }while(option != 0);





    return 0;
}

int menu (){

    int op = 0;
    cout<<"Ingrese la opcion a realizar"<<endl;
    cout<<"1. Cargar venta"<<endl;
    cout<<"2. Calcular la recaudacion del dia"<<endl;
    cout<<"3. Guardar los datos"<<endl;
    cout<<"0. Salir"<<endl;
    cin>>op;
    return op;

}

void load (Bill * s,int q){

    for(int ii = 0; ii < q; ii++){
        cout<<"Ingrese el numero de venta"<<endl;
        cin>>s[ii].number;
        cout<<"Ingrese la fecha de la venta"<<endl;
        getline(cin,s[ii].date,'.');
        cout<<"Ingrese el monto de la venta"<<endl;
        cin>>s[ii].amount;
    }
}

int sum_amount (Bill * s,int q){
    int a = 0;
    if(q == 0){
        return s[q].amount;
    }
    else{
        a = a + s[q].amount + sum_amount(s,q-1);
    }

    return a;
}

void save_sales(Bill *s, int q) {
    ofstream sales;
    sales.open("Facturas_Dia.txt", ios::app);
    for (int ii = 0; ii < q; ii++) {
        sales << "Numero de Venta: " << s[ii].number << endl;
        sales << "Fecha: " << s[ii].date << endl;
        sales << "Monto: " << s[ii].amount << endl;
    }
    sales.close();
}