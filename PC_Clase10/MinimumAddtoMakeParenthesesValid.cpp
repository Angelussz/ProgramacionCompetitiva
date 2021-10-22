class Solution {
public:
    int minAddToMakeValid(string s) {
        
        if(s.size() == 0) return 0;
        stack<char> cola;
        int ans = 0;
        for(auto it : s){
            if(it == '(')
                cola.push(it);
        
            else{
                if(!st.empty() && it == ')')
                    cola.pop();
                else
                    ans++;
                }
        }
    // cout << st.size() << endl;
    return ans+cola.size();
    }
};