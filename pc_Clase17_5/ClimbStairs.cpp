class Solution {
public:
    int climbStairs(int n) {
        int re[n+1];
        re[0]=1;
        re[1]=1;

        for(int i=2;i<=n;i++){
            re[i] = re[i-1] + re[i-2];
        }
        return re[n];
    }
};