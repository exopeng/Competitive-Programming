#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	int maxp = 0;
    	int index = 0;
    	int n, k;
    	cin >> n >> k;
    	int arr[200000];
    	int peak[200000];
    	for (int i = 0; i < n; i++) {
    		cin >> arr[i];
    	}
    	for (int i = 1; i < n - 1; i++) {
    		if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
    			peak[i] = 1;
    		} else {
    			peak[i] = 0;
    		}
    		//cout << peak[i] << " ";

    	}
    	int start = 0;
    	int end = k - 1;
    	for (int i = start + 1; i < end; i++) {
    		if (peak[i]) {
    			maxp++;
    		}
    	}
    	start++;
    	end++;
    	int curr = maxp;
    	while (end <= n - 1) {
    		if (peak[start]) {
    			curr--;
    		}
    		if (peak[end - 1]) {
    			curr++;
    		}
    		start++;
    		end++;
    		if (curr > maxp) {
    			index = start-1;
    			maxp = curr;
    		}
    	}
    	cout << maxp + 1 << " " << index+1 << "\n"; 
    }
}

