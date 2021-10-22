// https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_mapa<string, function<int (int, int) > > mapa = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        std::stack<int> cola;
        for (string& s : tokens) {
            if (!mapa.count(s)) {
                cola.push(stoi(s));
            } else {
                int op1 = cola.top();
          pila.pop();
                int op2 = cola.top();
                cola.pop();
                cola.push(mapa[s](op2, op1));
            }
        }
        return cola.top();
    }
};