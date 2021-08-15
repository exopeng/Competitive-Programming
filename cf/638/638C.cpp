#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
    	int n, k;
    	cin >> n >> k;
    	vector <string> gs;
    	string s;
    	cin >> s;
    	sort(s.begin(), s.end());
    	if (k == 1) {
    		cout << s << "\n";
    		continue;
    	}
    	if (s[k-1] != s[0]) {
    		cout << s[k-1] << "\n";
    		continue;
    	}
    	//if remaining letters aren't equal, append them to the first one to maximize lex val
    	if (s[k] != s[n-1]) {
    		cout << s.substr(k-1) << "\n";
    		continue;
    	}
    	for (int i = 0; i < k; i++) {
    		gs.push_back("");
    	}
    	//check if all ks are equal or not
    	for (int i = 0; i < n; i++) {
    		gs[i % k] += s[i];
    	}
    	cout << gs[0] << "\n";
    }
}

