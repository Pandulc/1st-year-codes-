#include <iostream>
using namespace std;

//Menu
int menu (){
    int op = 0;

    cout<<"Ingrese la opcion a realizar"<<endl;
    cout<<"1. Cantidad de veces que se activo la caldera en un dia."<<endl;
    cout<<"2. Calcular el promedio de temperatura del agua en todo un dia"<<endl;
    cout<<"3. Ordenar las temperaturas."<<endl;
    cout<<"4. Guardar los datos en un archivo."<<endl;
    cout<<"0. Salir."<<endl;
    cin>>op;

    return op;
}

//Imprime vector
void show (int * v, int s){

    cout<<"Los valores del vector son:"<<endl;
    for(int ii = 0; ii < s; ii++){
        cout<<" "<<v[ii];
    }
}

//Sumador Recursivo
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

//Guarda datos en archivo
void save_sales(Bill * s,int q){
    ofstream sales;
    sales.open("Facturas_Dia.txt",ios::app);
    for(int ii = 0; ii < q; ii++){
        sales<<"Numero de Venta: "<<s[ii].number<<endl;
        sales<<"Fecha: "<<s[ii].date<<endl;
        sales<<"Monto: "<<s[ii].amount<<endl;
    }
    sales.close();
}

//Quicksort
void qs (int * t, int rl, int ll){
    int tmp = 0;
    int left = 0;
    int right = 0;
    int pivot = 0;
    left = ll;
    right = rl;
    pivot = t[(ll+rl)/2];
    do{
        while(t[left]<pivot && left < rl){
            left++;
        }
        while(t[right]>pivot && right>ll){
            right--;
        }
        if(left<=right){
            tmp = t[left];
            t[left] = t[right];
            t[right] = tmp;
            left++;
            right--;
        }
    }while(left<=right);
    if(ll<right){
        qs(t,right,ll);
    }
    if(rl>left){
        qs(t,rl,left);
    }
}

//Promedios
void average(int * t,int m){
    float av = 0;
    int sum = 0;

    for (int ii = 0; ii < m; ++ii) {
        sum = sum + t[ii];
    }
    av = (float)sum / m;
    cout<<"El promedio de temperaturas en el dia es de: "<<av<<endl;
}