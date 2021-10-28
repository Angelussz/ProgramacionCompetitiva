#include <bits/stdc++.h>
using namespace std;

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string texto;

    deque<char> mensaje;
    char l;
    cin>>texto;
    for (int i = 0; i < texto.size(); i++)
    {
        l = texto[i];
        if (l != '#')
        {
            mensaje.push_back(l);
        }else{
            mensaje.pop_back();
        }
        
    }
    
    
    while (!mensaje.empty())
    {
        cout << mensaje.front();
        mensaje.pop_front();
    }
    cout<<"\n";
    return 0;
    
}