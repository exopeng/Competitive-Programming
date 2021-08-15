#include <bits/stdc++.h>
using namespace std;


// Complete the longestIncreasingSubsequence function below.
int longestIncreasingSubsequence(vector<int> arr) {
    int dp[1000000];
    int ans = 1;
    //dp[i] = longest subsequence starting here
    //cout << dp[arr.size()-1] << " ";
    dp[arr.size()-1] = 1;
    for (int i = arr.size()-2; i > -1; i--) {
        //find the first element greater than it
        int index = -1;
        int maxv = 0;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] > arr[i] && dp[j] > maxv) {
                index = j;
                maxv = dp[j];
            }
        }
        if (index != -1) {
            dp[i] = dp[index] + 1;
        } else {
            dp[i] = 1;
        }
        ans = max(ans,dp[i]);
        //cout << dp[i] << " ";
    }
    //cout << "\n";
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout << longestIncreasingSubsequence(arr) << "\n";
}
