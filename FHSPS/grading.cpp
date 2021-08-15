#include <bits/stdc++.h>
int arr[10000];
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	int m;
    	cin >> m;
    	int lswap = 0;
    	int sswap = 0;
    	int max = -1;
    	int min = 111;
    	int maxpos = 0;
    	int minpos = 0;
    	for (int i = 0; i < m; i++) {
    		cin >> arr[i];
    		if (arr[i] >= max) {
    			max = arr[i];
    			maxpos = i;
    		}
    		if (arr[i] < min) {
    			min = arr[i];
    			minpos = i;
    		}
    	}
    	//cout << minpos << " " << maxpos << "\n";
    	//handle special cases
    	if (maxpos < minpos) {
    		sswap = minpos - 1;
    	} else {
    		sswap = minpos;
    	}

    	lswap = m - maxpos - 1;
    	cout << lswap + sswap << "\n";
    }
}

