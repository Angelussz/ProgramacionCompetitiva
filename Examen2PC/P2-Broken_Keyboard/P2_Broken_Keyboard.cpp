#include <bits/stdc++.h>
using namespace std;

#define tam_ascii 128
int m;



int bigger_substring(string texto,int tamtext = 0){

    int com_cad[tam_ascii];
    int start_subcad = 0;
    int end_cad = m-1;
    int tam_act = texto.length();
    
    int aux_m = 0;
    int counter_aux = 0;


    for (int i = 0; i < tam_ascii; ++i)
        com_cad[i] = 0;


    for (int i = 0; i < m; ++i){
        if(com_cad[texto[i]] == 0){

            // cout<<texto[i]<<endl;
            // cout<<com_cad[texto[i]]<<endl;
            aux_m++;
        }
        com_cad[texto[i]]++;
    }


    while(end_cad < tam_act-2){

        while(aux_m <= m && (end_cad < tam_act-2))
        {
            end_cad++;
            
            if(com_cad[texto[end_cad]] == 0){
                aux_m++;
            }

            com_cad[texto[end_cad]]++;
        }
        
        if(aux_m > m){
            start_subcad++;
        }

        if((end_cad - start_subcad + 1) > tamtext){
            tamtext = end_cad - start_subcad + 1;
        }

        if(com_cad[texto[start_subcad-1]] > 0){
            com_cad[texto[start_subcad-1]]--;
            counter_aux = com_cad[texto[start_subcad-1]];
            if(counter_aux == 0){
                aux_m--;
            }
        }
    }
    return tamtext;
}

int main()
{
    while(true){

        int tamtext = 0;

        cin>>m;
        
        char textual[1000010];
        
        if(m != 0){
          cin.ignore();
          // getline(cin,textual);
          if(fgets(textual,1000010, stdin) != NULL){
            tamtext = bigger_substring(textual,tamtext);
          }
            printf("%d\n", tamtext);
        }
        else{
            // Ultimo caso de teste
            break;
        }
    }
    return 0;
}