#include <bits/stdc++.h>
using namespace std;

struct intervalo{
    double a;
    double b;
    int index;

    bool operator < (intervalo x) const {
        return a < x.a;
    }
};

double A,B,maxi;    
int n, val, best;
vector<int> cover;
bool possible;

int main(){
	int n,l;
	double r,w,x;
	while (cin >> n >> l >> w){
		intervalo intervals[n];
		for (int i=0;i<n;i++){
			cin >> x >> r; 
			if (r >= w/2){
				double p = sqrt(r*r -w*w/4);
				intervals[i].a = x - p;
				intervals[i].b = x + p;
				intervals[i].index = i;
			}
			else {
				intervals[i].a = -1;
				intervals[i].b = -1;
				intervals[i].index = i;
			}
		}
		A = 0;
		B = l;

        sort(intervals,intervals+n); 
        val = 0;
        cover.clear();
        possible = true;
        
        while (intervals[val].b < A){
            val++;
            if (val == n){
                possible = false;
                break;
            }
        }
        if (A == B && possible){
            if (intervals[val].a <= A && intervals[val].b >= A)
                cover.push_back(intervals[val].index);
            else possible = false;
        }
        while (A < B && possible){
            if (val == n){
                possible = false;
                break;
            }
            maxi = -1;
            best = -1;
            while (intervals[val].a <= A){
                if (intervals[val].b - A > maxi){
                    maxi = intervals[val].b - A;
                    best = val;
                }
                val++;
                if (val == n) break;
            }
            if (best == -1){
                possible = false;
                break;
            }
            cover.push_back(intervals[best].index);
            A = intervals[best].b;
        }
        if (!possible)
            cout << "-1" << endl;
        else{
            cout << cover.size() << endl;

        }
	}

    return 0;
}