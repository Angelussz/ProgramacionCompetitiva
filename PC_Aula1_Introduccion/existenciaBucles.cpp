//Dada una secuencia de elementos en un flujo de datos determinar si existe bucles

//El objetivo es encontrar la secuencia que corresponde al bucle

#include <iostream>
#include <vector>
using namespace std;

void repetido(vector<int> arr){
    vector<int> pos; //Vector donde se encuentran posiciones
    for (int i = 0; i < arr.size(); i++) //Llenar el vector con posiciones donde existan numeros repetidos
    {
        pos.push_back(i);
        for (int j = i+1; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                pos.push_back(j);
            }
            
        }
        if (pos.size() < 3)
        {
            pos.clear();
        }
        else{
            break;
        }
    }

    int val = pos[1]-pos[0];//restar 2 posiciones iniciales ya que si se repite el bucle va tener una distancia igual
    
    for (int i = 2; i < pos.size(); i++)//realizar lo anterior pero con todas las posiciones repetidas y eliminar si no cumple para saber si existe un arreglo con bucle si es diferente eliminar el bulce
    {
        if (val != pos[i]-pos[i-1])
        {
            pos.clear();
            break;
        }
        
    }
    //Imprimir elementos repetidos (EL BUCLE)
    if (!pos.empty())
    {
        for (int i = 0; i < val; i++)
        {
            cout<<arr[pos[0]+i]<<" ";
        }
        cout<<endl;
    }

    }
    

int main(){
    int num;
    vector<int> arrnum;
    cin>>num;
    //Creacion de arreglo hasta colocar 0
    while (num !=0)
    {
        arrnum.push_back(num);
        cin>>num;
    }
    
    // for (int i = 0; i < arrnum.size(); i++)
    // {
    //     cout<<arrnum[i]<<" ";
    // }
    // cout<<endl;
    // printf("===========================\n");
    repetido(arrnum);
    
    return 0;
}