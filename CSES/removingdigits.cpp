#include <bits/stdc++.h>
using namespace std; 

int dp[1000001];
int n;

int main() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		dp[i] = 10000000;
	}
	dp[n] = 0;
	for (int i = n; i > -1; i--) {
		int num = i;
		while (num != 0) {
			int dig = num % 10;
			dp[i - dig] = min(dp[i] + 1, dp[i-dig]);
			num /= 10;
		}
	}
	cout << dp[0] << "\n";


}


