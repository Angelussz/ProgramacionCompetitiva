#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums{1,2,4,5,12};
    vector<int> pos;
    int punt1,punt2=nums.size()-1;
    int target = 19;
    int nuevo;
    for(int i = 0;i<nums.size()-2;i++){
        nuevo = target - nums[i];
        punt1 = i+1;
        pos.push_back(i);
        // cout<<i<<endl;
        // cout<<nuevo<<endl;
        while(punt1 != punt2){
            int sum = nums[punt1]+nums[punt2];
            // cout<<"suma "<<sum<<endl;
            if(sum == nuevo){
                pos.push_back(punt1);
                // cout<<nums[punt1]<<endl;
                pos.push_back(punt2);
                // cout<<nums[punt2]<<endl;
                break;
            }
            else if(sum > nuevo){
                punt2--;
            }
            else if(sum < nuevo){
                punt1++;
            }
        }
        if(pos.size()==1){
            pos.clear();
        }
        else if(pos.size() == 3){
            // cout<<"hola"<<endl;
            cout<<pos[0]<<" "<<pos[1]<<" "<<pos[2]<<"\n";
            break;
        }
    }
    cout<<"hola";
    return 0;
}