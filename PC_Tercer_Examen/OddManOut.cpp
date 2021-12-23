#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int C,Nf,Ni,Gf,Gi;
    cin >> Nf;
    Ni = 0;
    while (Ni < Nf) {
        unordered_map<int, int> impar;
        Gi = 0;
        cin >> Gf;
        while (Gi < Gf) {
            cin >> C;
            impar[C]++;
            Gi++;
        }
        cout << "Case #" << Ni + 1 << ": ";
        for(auto C : impar){
            if (C.second == 1) {
                cout << C.first << endl;
            }
        }
        Ni++;
    }
    return 0;
}