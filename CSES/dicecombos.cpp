#include <bits/stdc++.h>
using namespace std; 

long long ans = 0;
vector<int> nums;
int n, count;
int mod = 1000000007;
int dp[10000001];

int main() {
	cin >> n;
	for (int i = 0; i < 7; i++) {
		dp[i] = 1;
	}
	//dp[i] represents the ways to to roll dice to get to i
	//from the previous state, we can either roll 1,2,...6
	//we can only go from previous state to current state
	//otherwise you might overcount
	//in dp, think about the transition from previous to current
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (j >= i) {
				break;
			}
			dp[i] += dp[i-j];
			dp[i] %= mod;
		}
	}
	cout << dp[n] << "\n";


}


