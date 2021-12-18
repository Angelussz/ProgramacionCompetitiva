#include <bits/stdc++.h>
using namespace std; 

struct Persona{
    int din;
    int tiempo;
    
    Persona(int m, int w){
        din = m;
        tiempo = w;
    }
};

bool compareMoney(const Persona &a, const Persona &b){
        return a.din >= b.din;
}

void queuePerson(vector<int> &v, Persona c){
    int i = c.tiempo;
    
    while(i >= 0){
        if(v[i] == 0){
            v[i] = c.din;
            return;
        }  
        i--; 
    }
}

int main(){ 

    int N, T, ci, ti;
    int sum = 0;
    int i = 0;
	
    scanf("%d %d", &N, &T);    
   
    vector<int> bQueue(T);
    vector<Persona> din;
    
    for(int i = 0; i < N; i++){
        scanf("%d %d", &ci, &ti);
        Persona c(ci, ti);
        
        din.push_back(c); 
    }    
	
    sort(din.begin(), din.end(), compareMoney);    
    
    while(i < din.size()){
        queuePerson(bQueue, din[i]);
        i++;
    }    
    
    for(int i = 0; i < bQueue.size(); i++){
        sum += bQueue[i];
    }
    
    printf("%d", sum); 
    return 0;
}