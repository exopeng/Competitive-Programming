#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	int n;
    	string ans = "Yes";
    	cin >> n;
    	int arr[100000];
    	int map[100000];
    	for (int i = 0; i < n; i++) {
    		cin >> arr[i];
    		map[arr[i] - 1] = i;
    	}
    	int maxpos = 0;
    	int edge = n - 1;
    	int minedge = n - 1;

    	int place = map[0];
    	minedge = min(minedge, place);

		if (place == edge) {
			maxpos = -1;
			edge--;
			minedge--;
		} else {
			maxpos = place + 1;

		}
		//cout << maxpos << "\n";
    	for (int i = 1; i < n; i++) {
    		place = map[i];
    		minedge = min(minedge, place);

    		if (maxpos == -1) {
    			if (place == edge) {
    				maxpos = -1;
    				edge = minedge - 1;
    			} else {
    				//find next available one
    				maxpos = place + 1;
    			}
    		} else {
    			if (place != maxpos) {
    				ans = "No";
    				break;
    			} else {
    				if (place == edge) {
	    				maxpos = -1;
	    				edge = minedge - 1;
	    			} else {
	    				//find next available one
	    				maxpos = place + 1;
	    			}
    			}
    		}
    		//cout << i << " " << maxpos << " " << edge << "\n";

    		//cout << maxpos << "\n";
    	}
    	cout << ans << "\n";
    }
}

