#include <bits/stdc++.h>
using namespace std; 

#define size_alpha 26
int maping(char c) { 
    return c - 'A'; 
}

class Node {
public:
    Node *chrv[size_alpha];
	int c = 0;
	int d = 0;
	Node() {
		for (int i = 0; i < size_alpha; ++i) chrv[i] = NULL;
	}
	
	void insert_chr(string &s, int i = 0) {
		while (i < s.length() && s[i] == ' ') i++;
		if (i == s.length()) { c++; return; }
		else {
			c++;
			int v = maping(s[i]);
			if (chrv[v] == NULL) {
				chrv[v] = new Node();
				chrv[v]->d = d + 1;
			}
			chrv[v]->insert_chr(s, i + 1);
		}
	}
	void limpiar() {
		for (int i = 0; i < size_alpha; ++i) {
			if (chrv[i] != NULL) chrv[i]->limpiar();
			delete chrv[i];
		}
	}
	void contar(vector<int> &contar) {
		contar[d] = max(c, contar[d]);
		for (int i = 0; i < size_alpha; ++i)
			if (chrv[i] != NULL)
				chrv[i]->contar(contar);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string text;
	while (getline(cin, text)) {
		if (text.length() == 0) break;
		Node root;
		for (int i = 0; i < text.length(); ++i)
			if (text[i] != ' ')
				root.insert_chr(text, i);
		
		vector<int> dpth_text(text.length() + 3, 0);
		root.contar(dpth_text);
		for (int i = 1; i <= text.length() + 1; ++i) {
			if (dpth_text[i] > 1) cout << dpth_text[i] << endl;
			else {
				cout << endl;
				break;
			}
		}
	}
	
	return 0;
}