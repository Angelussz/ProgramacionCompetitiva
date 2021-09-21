/******************************************************************************

Problema 9: Escriba una función que genere el numero n de la secuencia Fibonacci


*******************************************************************************/
#include <iostream>
using namespace std;

//función Fibonacci para numero que sobrepasen a los valores int 
long fibo(int n){
    if(n<=1) return n;
    return fibo(n-1) + fibo(n-2);
}


int main()
{
    long n;
    cin>>n;//Entrada de numero
    printf("Numero %ld genera en la secuencia fibonacci el numero %ld",n,fibo(n));

    return 0;
}

