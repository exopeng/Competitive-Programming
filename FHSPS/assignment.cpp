#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	string m;
    	cin >> m;
    	string temp;
    	cin >> temp;
    	int ans = 0;
    	for (int i = 0; i < m.length(); i++) {
    		if (m[i] == '1' || temp[i] == '1') {
    			ans++;
    		}
    	}
    	cout << (int)(((double)(ans) / m.length()) * 100) << "\n";
    }
}

