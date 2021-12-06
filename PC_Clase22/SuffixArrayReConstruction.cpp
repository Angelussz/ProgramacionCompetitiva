
#include <bits/stdc++.h>
using namespace std;

struct Suffix {
    int pos;
    string suffix;
};

const char PLACEHOLDER = '#';
const char WILDCARD = '*';


inline bool insert_suffix(string& target, Suffix& s) {
    bool wildcard = false;
    for (int suffix_pos = 0, target_pos = s.pos;
         target_pos < target.size();
         suffix_pos++, target_pos++) {

        if (s.suffix[suffix_pos] == WILDCARD) {
            wildcard = true;
            break;
        }
        
        if (target[target_pos] != PLACEHOLDER &&
            target[target_pos] != s.suffix[suffix_pos])
            return false;
        else
            target[target_pos] = s.suffix[suffix_pos];
    }

    if (wildcard) {
        for (int suffix_pos = s.suffix.size() - 1, target_pos = target.size() - 1;
             s.suffix[suffix_pos] != WILDCARD;
             suffix_pos--, target_pos--) {
            
            if (target[target_pos] != PLACEHOLDER &&
                target[target_pos] != s.suffix[suffix_pos])
                return false;
            else
                target[target_pos] = s.suffix[suffix_pos];
        }
    }
    
    return true;
}


string solve(int tamanio, vector<Suffix>& suffixes) {
    string resp;
    resp.resize(tamanio, PLACEHOLDER);
    
    for (Suffix& s : suffixes) {
        if (!insert_suffix(resp, s)) return "";
    }

    for (char c : resp) {
        if (c == PLACEHOLDER) return "";
    }
    
    return resp;
}

int main() {
    int casos;
    cin >> casos;

    while (casos--) {
        int tamanio, suffix_count;
        cin >> tamanio >> suffix_count;

        vector<Suffix> suffixes;
        suffixes.reserve(suffix_count);
        
        while (suffix_count--) {
            Suffix s;
            cin >> s.pos >> s.suffix;
            s.pos--; // Make pos zero indexed.
            suffixes.push_back(s);
        }
        
        auto resp = solve(tamanio, suffixes);
        
        if (resp.empty()) printf("IMPOSSIBLE\n");
        else printf("%s\n", resp.c_str());
    }
}