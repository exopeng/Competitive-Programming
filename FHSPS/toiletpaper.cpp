#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	long long ans = 0;
    	int n;
    	cin >> n;
    	if (n > 100) {
    		ans = 100 * 5;
    	} else {
    		ans = n * 5;
    	}
    	ans -= n;
    	cout << ans << "\n";
    }
}

