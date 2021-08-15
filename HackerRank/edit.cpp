#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    string b;
    cin >> a >> b;
    string c = a;
    string t = b;
    if (a.length() < b.length()) {
        c = b;
        t = a;
    } 
    //dp[i][j] = min number of moves to make character j and onwards equal to string i and onwards
    for (int j = 0; j <= c.length(); j++) {
        for (int e = 0; e <= c.length(); e++) {
            dp[j][e] = 0;
        }
    }

    for (int j = t.length() - 1; j > -1; j--) {
        dp[j][c.length()] = 1 + dp[j+1][c.length()];
    }
    for (int j = c.length() - 1; j > -1; j--) {
        dp[t.length()][j] = 1 + dp[t.length()][j+1];
    }

    for (int e = t.length() - 1; e > -1; e--) {
        for (int f = c.length() - 1; f > -1; f--) {
            if (c[f] == t[e]) {
                dp[e][f] = min(dp[e+1][f+1], dp[e][f+1] + 1);
                dp[e][f] = min(dp[e][f], dp[e+1][f] + 1);
            } else {
                dp[e][f] = min(dp[e][f+1] + 1, dp[e+1][f+1] + 1);
                dp[e][f] = min(dp[e][f], dp[e+1][f] + 1);
            }  
            //cout <<  "e: " << e << " f: " << f << " val: " << dp[e][f] <<"\n";
        }
    }

    cout << dp[0][0] << "\n";
}
