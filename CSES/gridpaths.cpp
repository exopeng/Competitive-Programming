#include <bits/stdc++.h>
using namespace std; 


int mod = 1000000007;
int dp[1000][1000];
int arr[1000][1000];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			if (temp[j] == '*') {
				arr[i][j] = 1;
			}
		}
	}
	if (arr[0][0] == 0) {
		dp[0][0] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (arr[0][i] == 0) {
			dp[0][i] += dp[0][i-1];
		}
		if (arr[i][0] == 0) {
			dp[i][0] += dp[i-1][0];
		}

	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[i][j] == 0) {
				dp[i][j] += dp[i-1][j];
				dp[i][j] %= mod;
				dp[i][j] += dp[i][j-1];
				dp[i][j] %= mod;
			}
		}
	}
	
	cout << dp[n-1][n-1] << "\n";


}