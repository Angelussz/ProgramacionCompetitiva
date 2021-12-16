#include<cstdio>

using namespace std;

int main(){    
    int n,m;
    int a[10];
    bool prof[1000001];
    
    while(scanf("%d %d",&n,&m)==2){
        for(int i=0;i<m;i++) scanf("%d",&a[i]);
        
        prof[0]=false;
        for(int i=1;i<=n;i++){
            prof[i]=false;
            
            for(int j=0;j<m;j++)
                if(i>=a[j] && !prof[i-a[j]]){
                    prof[i]=true;
                    break;
                }
        }
        
        if(prof[n]) printf("Stan wins\n");
        else printf("Ollie wins\n");
    }
    
    return 0;
}