class Solution {
public:
    int scoreOfParentheses(string s) {
        return calc_pilas(s, 0, s.length() - 1);
        
    }
    inline int calc_pilas(const std::string& datos, const int tam1, const int tam2) {
    //balance () return 1
    if (tam2 - tam1 == 1) return 1;

    int balanceo = 0;
    for (int i = tam1; i < tam2; ++i) {
        if (datos[i] == '(') ++balanceo;
        if (datos[i] == ')') --balanceo;
        if (balanceo == 0) {
            return calc_pilas(datos, tam1, i) + calc_pilas(datos, i + 1, tam2);
        }
    }

    return 2 * calc_pilas(datos, tam1 + 1, tam2 - 1);
}
};