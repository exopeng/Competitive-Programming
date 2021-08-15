#include <bits/stdc++.h>
using namespace std; 

int ans = 0;
int n;
int w;
int val[100000];
int weight[100000];
int dp[100000][100000];


int rec(int item, int rweight) {
	//base case
	if (item == 0) {
		if (weight[item] > rweight) {
			return 0;
		}
		dp[item][rweight] = val[item];
		return dp[item][rweight];
	}
	if (rweight == 0) {
		return 0;
	}
	//some vals might equal to 0, so prefill it
	if (dp[item][rweight] != -1) {
		return dp[item][rweight];
	}
	//no item's weight is greater than weight left, can only save weight
	if (weight[item] > rweight) {
		dp[item][rweight] = rec(item-1, rweight);
	} else {
		dp[item][rweight] = max(rec(item-1, rweight), rec(item-1, rweight-weight[item]) + val[item]);
	}
	return dp[item][rweight];

}
int main() {
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> val[i];
		cin >> weight[i];
	}
	//assumes sorted by weight from least to greatest
	/*
	for (int i = 0; i <= w; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= n; j++) {
			if (i < weight[=j]) {
				continue;
			}
			dp[j][i] = max(dp[j-1][i], dp[j-1][i-weight[j]] + val[j]);
		}
	}
	*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= w; j++) {
			dp[i][j] = -1;
		}
	}
	cout << rec(n-1, w) << "\n";
	

}

