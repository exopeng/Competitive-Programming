#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cout << -5 % 2 << "\n";
    cin >> t;


    while (t--) {
    	int n;
    	cin >> n;
    	unordered_set<int> taken;
    	string ans;
    	int arr[200000];
    	for (int i = 0; i < n; i++) {
    		int e;
    		cin >> arr[i];
    	}
    	for (int i = 0; i < n; i++) {
    		int val = i + arr[i];
    		//make sure is positive, cuz mn + that might overlap with others
    		int m = ceil(-1*(val) / n);
    		val += m*n;
    		if (taken.find(val) != taken.end()) {
    			ans = "NO";
    			break;
    		}
    		taken.insert(val);
    	}
    	if (ans != "NO") {
    		ans = "YES";
    	} 
    	cout << ans << "\n";

    }
}

