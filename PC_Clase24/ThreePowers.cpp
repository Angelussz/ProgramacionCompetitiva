#include <bits/stdc++.h>
using namespace std;

void Sol(int n){
    int shifts = 0;
    int elem = 0;
    cout << "{" ;
    while(n>0){
        if(n&1 == 1){
            if(elem == 0){
                cout << pow(3,shifts) << " ";
            }
            else{
                cout << ", " << pow(3,shifts) << " ";
            }
            elem++;
        }
        n >>=1;
        shifts++;
    }
    cout << "}";


}

int main(){
    while (true)
    {
        int n;
        cin >> n;
        if(n == 0)
            break;
        Sol(n-1);
    }
    return 0;
}