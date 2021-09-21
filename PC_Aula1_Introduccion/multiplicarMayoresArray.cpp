// Dada una secuencia de n numeros no negativos y mayores que 0
//El objetivo es encontrar el mayor número que se pueda obtener multiplicando dos números de esta secuencia

#include <iostream>
#include <vector>
using namespace std;
int multi(vector <int> arr){//Recibir un arreglo para multiplicar
    int pmax = 0;// primer numero mayor
    int smax = 0;//Segundo numero mayor
    for (int i=0;i<arr.size();i++){
        if(arr[i]>pmax){ // encontrar numero mayor
            smax = pmax; // pasar el valor que era el mas mayor al segundo mayor
            pmax = arr[i]; // actualizar el numero mas mayor
        }
    }
    return (pmax*smax);
}
int main(){
    int n; //tamaño del arreglo
    int num; //numero que se colocara a ese arreglo
    
    vector <int> arrnum;//creacion del arreglo
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>num;
        arrnum.push_back(num);

    }
    cout <<multi(arrnum)<<endl; //Resultado
    return 0;
}