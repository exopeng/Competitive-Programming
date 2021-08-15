#include <bits/stdc++.h>
using namespace std; 
 
long long ans = 0;
vector<int> nums;
int n, x;
int mod = 1000000007;
int dp[1000001];
int coins[100];
 
int main() {
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
    //dp[coins[i]] = 1;
  }
  dp[0] = 1;
  for (int i = 1; i <= x; i++) {
    for (int j = 0; j < n; j++) {
      if (i < coins[j]) {
        continue;
      }
      dp[i] += dp[i-coins[j]];
      dp[i] %= mod;
    }
  }
  cout << dp[x] << "\n";
 
 
}