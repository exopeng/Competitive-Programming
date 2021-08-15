#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	string ans;
    	int m;
    	cin >> m;
    	string f;
    	cin >> f;
    	ans += f;
    	cin >> f;
    	ans += f.substr(0,2);
    	ans += "_";
    	for (int i = 0; i < m-2;i++) {
    		cin >> f;
    		ans += f[0];
    	}
    	cout << ans << "\n";
    }
}

