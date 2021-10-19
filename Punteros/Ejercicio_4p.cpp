#include <iostream>
#define TAM 5
using namespace std;

void find_max(float *);
void find_min(float *);
void get_prom(float *);

int main (){
    float vector[TAM] = {4.5,8,2.3,1.1,3};
    find_max(vector);
    find_min(vector);
    get_prom(vector);

    return 0;
}

void find_max(float * v){
    float max = 0;

    for(int ii = 0; ii < TAM; ii++){
        if(ii == 0){
            max = v[ii];
        }
        if(v[ii] > max){
            max = v[ii];
        }
    }

    cout<<"El valor maximo es: "<<max<<endl;
}

void find_min (float * v){
    float min = 0;

    for(int ii = 0; ii < TAM; ii++){
        if(ii == 0){
            min = v[ii];
        }
        if(v[ii] < min){
            min = v[ii];
        }
    }

    cout<<"El valor minimo es: "<<min<<endl;
}

void get_prom (float * v){
    float prom = 0;
    float sum = 0;
    for(int ii = 0; ii < TAM; ii++){
        sum = sum + v[ii];
    }
    prom = sum / TAM;
    cout<<"El promedio es: "<<prom<<endl;
}
