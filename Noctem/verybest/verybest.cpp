#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-8;

const int mxN = 2e5;

ll n, m, s[mxN];

bool solve(ll k) {
    ll ans = 0;
    for (int i = 0; i < n;) {
        ll sum = 0;
        while (sum+s[i] <= k) {
            sum += s[i];
            ++i;
        }
        ++ans;
        if (sum == 0) {
            return false;
        }
    }

    return ans <= m;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    if (fopen("verybest.in", "r")) {
        freopen("verybest.in", "r", stdin);
        freopen("verybest.out", "w", stdout);
    }

    cin >> n >> m;
    ll l = LINF;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        l = min(l, s[i]);
    }

    ll r = 2e14;

    while (l < r) {
        ll mid = (l+r)/2;
        if (solve(mid)) r = mid;
        else l = mid+1;
    }

    cout << l << endl;

    return 0;
}