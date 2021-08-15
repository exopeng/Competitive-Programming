#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>


using namespace std;
using std::cout;
using std::cin;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
ll MOD = 1000000007;



int main() {
    ll n, m;
    cin >> n >> m;
    int arr[n+2];
    for(int i = 1; i <= n; i++)cin >> arr[i];
    arr[0] = m+1;
    arr[n+1] = m+1;
    int idx = 0;
    int ans = 1;
    while (idx <= n+1){
        int start = idx;
        idx++;
        while (idx <= n+1 && arr[idx] == 0)idx++;
        if (idx == start + 1){
            if (arr[idx] == arr[start])ans = 0;
            continue;
        }
        int gap = idx - (start+1);
        ll dp[gap+1][2];
        for(int i = 0; i <= gap; i++){
            dp[i][0] = 0;
            dp[i][1] = 0;
        }

        if (arr[idx] == arr[start])dp[0][1] = 1;
        else dp[0][0] = 1;

        if (arr[start] == m+1 && arr[idx] == m+1){
            dp[1][0] = m;
            dp[1][1] = 0;
        }else if (arr[start] == m+1 && arr[idx] != m+1){
            dp[1][0] = m-1;
            dp[1][1] = 1;
        } else if (arr[start] != m+1 && arr[idx] == m+1){
            dp[1][0] = m-1;
            dp[1][1] = 0;
        }else{
            dp[1][0] = ((dp[0][1] * (m-1)) % MOD + (dp[0][0] * (m-2)) % MOD) % MOD;
            dp[1][1] = dp[0][0]% MOD;
        }
        for(int i = 2; i <= gap; i++){
            if (arr[idx] != m+1)dp[i][0] = (dp[i-1][1] * (m-1)) % MOD + (dp[i-1][0] * (m-2) % MOD) % MOD;
            else dp[i][0] = (dp[i-1][0] * (m-1)) % MOD;
            dp[i][1] = dp[i-1][0] % MOD;
        }
        ans = (ans*(dp[gap][0] % MOD)%MOD);
    }
    cout << ans << "\n";
    return 0;
}
