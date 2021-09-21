/******************************************************************************

Problema 7:
    El codigo ((n & (n-1)) == 0)
    
    El codigo sirve saber si un AND a nivel de bits de un numero n con el mismo reducido en -1 es
    equivalente a 0

*******************************************************************************/
#include <iostream>
using namespace std;

bool comprobar(int n){
    bool f = ((n & (n-1)) == 0);
    return f;
}
int main()
{
    int n1=4,n2=6;
    
    printf("El numero %d al aplicar la funcion sale: %d \n",n1,comprobar(n1));
    printf("El numero %d al aplicar la funcion sale: %d \n",n2,comprobar(n2));

    return 0;
}