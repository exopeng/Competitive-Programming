#include <bits/stdc++.h>
using namespace std; 

int ans = 0;
int n;
int price[100];
int dp[100];

int max1(int n) {
	int mprice = price[n-1];
	if (dp[n-1]) {
		return dp[n-1];
	}
	for (int i = 1; i <= n/2; i++) {
		mprice = max(mprice, max1(n-i) + max1(i));
	}
	dp[n-1] = mprice;
	return mprice;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	cout << max1(n) << "\n";

}

