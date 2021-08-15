#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*
4 4 7
1 2 3 4
2 3 4 5

5 4 4 3 3 2 2 1
//starting with blue
5 2
4 3
3 2 2


//starting with red
4 3
4 2 1
3 3 1
3 2 2


*/
long long dp[1001][2002][2];
const int MOD = 1000000007;
//dp[i][j][k] = num of ways you can fill the bookshelf to size i, using the first j books, and ending on color k
//handle repeats
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector< pair<int,int> > books;
    set<int> taken;
    set<int> need;
    int r,b,s;


    cin >> r >> b >> s;

    for (int i = 0; i < r; i++) {
        int a;
        cin >> a;
        books.push_back(make_pair(a,0));
        taken.insert(a);
    }
    for (int i = 0; i < b; i++) {
        int a;
        cin >> a;
        if (taken.find(a) != taken.end()) {
            need.insert(a);
        } else {
            books.push_back(make_pair(a,1));
        }
    }
    //dp[i][j][k] = dp[i][j-1][k];
    //dp[i][j][k] += dp[i-books[j]][j-1][opp(k)]

    sort(books.begin(), books.end());
    reverse(books.begin(), books.end());

    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    for (int i = 0; i <= s; i++) {
        for (int j = 1; j <= books.size(); j++) {
            dp[i][j][0] = dp[i][j-1][0];
            dp[i][j][1] = dp[i][j-1][1];
            if (i - books[j-1].first >= 0) {
                if (need.find(books[j-1].first) != need.end()) {
                    dp[i][j][0] += dp[i-books[j-1].first][j-1][1];
                    dp[i][j][1] += dp[i-books[j-1].first][j-1][0];
                    if (i - 2*books[j-1].first >= 0) {
                        dp[i][j][0] += dp[i-2*books[j-1].first][j-1][0];
                        dp[i][j][1] += dp[i-2*books[j-1].first][j-1][1];
                    }
                } else {
                    if (books[j-1].second == 0) {
                        dp[i][j][0] += dp[i-books[j-1].first][j-1][1];
                    } else {
                        dp[i][j][1] += dp[i-books[j-1].first][j-1][0];
                    }
                }
            }
            dp[i][j][0] %= MOD;
            dp[i][j][1] %= MOD;
            //cout << "i:" << i << " j:" << j << " " << dp[i][j][0] << " " << dp[i][j][1] << "\n";
        }
    }
    
    


    cout << (dp[s][books.size()][0] + dp[s][books.size()][1]) % MOD << "\n";
}
/* REMINDERS
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * PLANNING!!!!!!!! Concrete plan before code
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * NAIVE SOL FIRST TO CHECK AGAINST OPTIMIZED SOL
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

