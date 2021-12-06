#include <bits/stdc++.h>
using namespace std;

int main() {
	int pr; 
    cin >> pr;
	while(pr--){
		string circular; 
        cin >> circular;
		int length = circular.length();
		vector<string> guardar;
		guardar.push_back(circular);
		for(int i=1;i<length;i++){
			string prim = circular.substr(i);
			string seg = circular.substr(0,i);
			guardar.push_back(prim+seg);
		}
		sort(guardar.begin(),guardar.end());
		cout << guardar[0] << endl;
	}
	return 0;
}