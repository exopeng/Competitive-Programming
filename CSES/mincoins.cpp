#include <bits/stdc++.h>
using namespace std; 

long long ans = 0;
vector<int> nums;
int n, x;
int dp[10000001];
int coins[100];

int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	for (int i = 0; i <= x; i++) {
		dp[i] = 10000000;
	}
	dp[0] = 0;
	//in dp, think about the transition from previous to current
	for (int i = 1; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (i - coins[j] < 0) {
				continue;
			}
			dp[i] = min(dp[i], dp[i-coins[j]] + 1);
		}
	}
	if (dp[x] == 10000000) {
		cout << -1 << "\n";
	} else {
		cout << dp[x] << "\n";
	}


}


