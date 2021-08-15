#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	int x,n,m;
    	string ans = "NO";
    	cin >> x >> n >> m;
    	for (int i = 0; i < n; i++) {
    		if ((x / 2) + 10 > x) {
    			break;
    		}
    		x = (x/2) + 10;
    	}
    	for (int i = 0; i < m; i++) {
    		x -= 10;
    	}
    	if (x <= 0) {
    		ans = "YES";
    	}
    	cout << ans << "\n";

    }
}

