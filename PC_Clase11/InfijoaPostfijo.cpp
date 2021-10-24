#include<bits/stdc++.h>
using namespace std;
map<char,int> reg;

void reglas()
{
    reg['+']=1;
    reg['-']=1;
    reg['/']=2;
    reg['*']=2;
    reg['^']=3;
}
void InfiaPos(string calc)
{
    stack<char> pilasimb;
    
    for(int i=0;i<calc.length();i++)
    {
        if(isalnum(calc[i]))
        {
          cout<<calc[i];
        }
        
        
        else if(calc[i]=='+'||calc[i]=='-'||calc[i]=='*'||calc[i]=='/'||
        calc[i]=='^')
        {
            if(!pilasimb.empty()){
            while(reg[calc[i]]<=reg[pilasimb.top()])
            {
                cout<<pilasimb.top();
                pilasimb.pop();
                if(pilasimb.empty()) break;
            }
            }
            pilasimb.push(calc[i]);
        }
        else if(calc[i]=='('){
            pilasimb.push('(');
            
        }
        
        else if(calc[i]==')')
        {
            while(pilasimb.top()!='(')
            {
                cout<<pilasimb.top();
                pilasimb.pop();
            }
            pilasimb.pop();
        }
    }
    while(!pilasimb.empty())
    {
        cout<<pilasimb.top();
        pilasimb.pop();
    }
    cout<<endl;
}
int main()
{
    reglas();
    int t;
    cin>>t;
    
    string calc;
    for(int i=0;i<t;i++)
    {
        cin>>calc;
        InfiaPos(calc);
    }
    return 0;
}