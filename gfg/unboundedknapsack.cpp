#include <bits/stdc++.h>
using namespace std;

bool n[2001];
int ans = 0;
int t,k,f;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> f >> k;
		vector<int> arr;
		for (int i = 0; i < f; i++) {
			int e;
			cin >> e;
			arr.push_back(e);
		}

		for (int i = 0; i < 2001; i++) {
        	n[i] = false;
	    }

	    n[0] = true;

	    for (int i = 0; i < k; i++) {
	        if (n[i]) {
	            for (int j = 0; j < arr.size(); j++) {
	                if (i + arr[j] <= k) {
	                    n[i+arr[j]] = true;
	                }
	            }
	        }
	    }

	    int ans = 0;
	    for (int i = k; i > -1; i--) {
	        if (n[i]) {
	            ans = i;
	            break;
	        }
	    }
	    cout << ans << "\n";
	}
	

}