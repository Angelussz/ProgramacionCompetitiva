#include <bits/stdc++.h>

using namespace std;

deque<int> mita_i;
deque<int> mita_d;

void balanceo(){
    
    int difer = mita_i.size() - mita_d.size();
	if (difer < 0) {//if  right is larger than mita_i
		double mitad = (double)difer / -2;
		for (size_t i = 0; i < ceil(mitad); i++) {
			mita_i.push_back(mita_d.front());
			mita_d.pop_front();
		}
	}
	else if (difer > 1) {//if  left is larger than right
		double mitad = (double)difer / 2;
		for (size_t i = 0; i < floor(mitad); i++) {
			mita_d.push_front(mita_i.back());
			mita_i.pop_back();
		}
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queries,val;
    cin>>queries;
    string texto;  

    for (size_t i = 0; i < queries; i++)
    {
        cin>>texto;
        cin>>val;
        if(texto == "push_back"){
            mita_d.push_back(val);
			      balanceo();
        }else if(texto == "push_front"){
            mita_i.push_front(val);
			      balanceo();
        }else if(texto == "push_middle"){
            mita_i.push_back(val);
			      balanceo();
        }else if(texto == "get"){
            if (mita_i.size() > val){
                cout << mita_i[val] << "\n";
            }
            else{
                cout << mita_d[val - mita_i.size()] << "\n";
            }
        }

    }
    return 0;
}