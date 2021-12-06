
#include <bits/stdc++.h>
using namespace std;

struct Suffix {
    int position;
    string suffix;
};

const char PLACEHOLDER = '#';
const char WILDCARD = '*';


inline bool insert_suffix(string& target, Suffix& s) {
    bool wildcard = false;
    for (int suffix_pos = 0, target_pos = s.position;
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


string solve(int length, vector<Suffix>& suffixes) {
    string result;
    result.resize(length, PLACEHOLDER);
    
    for (Suffix& s : suffixes) {
        if (!insert_suffix(result, s)) return "";
    }

    for (char c : result) {
        if (c == PLACEHOLDER) return "";
    }
    
    return result;
}

int main() {
    int test_count;
    cin >> test_count;

    while (test_count--) {
        int length, suffix_count;
        cin >> length >> suffix_count;

        vector<Suffix> suffixes;
        suffixes.reserve(suffix_count);
        
        while (suffix_count--) {
            Suffix s;
            cin >> s.position >> s.suffix;
            s.position--; // Make position zero indexed.
            suffixes.push_back(s);
        }
        
        auto result = solve(length, suffixes);
        
        if (result.empty()) printf("IMPOSSIBLE\n");
        else printf("%s\n", result.c_str());
    }
}