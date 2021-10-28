#include <bits/stdc++.h>
//con @ se altera la entrada
using namespace std;

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string texto;
    string result = "";
    queue<char> arrtexto;
    bool pushmayu = false;
    cin>>texto;
    for (int i = 0; i < texto.size(); i++)
    {
        if (texto[i] == '$')
        {
            while (!arrtexto.empty())
            {
                result += arrtexto.front();
                arrtexto.pop();
            }
            
        }else if (texto[i] == '@'){

            for (int j = 0; j < arrtexto.size(); j++)
            {
                arrtexto.push(toupper(arrtexto.front()));
                
                arrtexto.pop();
            }
            
            pushmayu = pushmayu == true ? false : true;
        }else{
            if (pushmayu) arrtexto.push(toupper(texto[i]));
            else arrtexto.push(texto[i]);
        }
        
    }
    
    cout<<result<<"\n";
    return 0;
    
}