#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
const long long MOD = 1000000007;
const int MAXN = 100001;
pair<long long, long long> t[4*MAXN];
vector< pair<char,long long> > arr;

void build(int curr, int l, int r) {
    if (l == r ) {
        if (arr[l].first == '*') {
            t[curr].first *= arr[l].second;
            t[curr].second *= arr[l].second;
        } else if (arr[l].first == '+') {
            t[curr].second += arr[l].second;
        } else {
            t[curr].second -= arr[l].second;
        }
    } else {
        int mid = (r + l) / 2;
        //an edge's two children are the indices 2i && 2i+1
        //in this sum segtree, an edge's value is the values from it's left to right indices
        build(curr * 2, l, mid);
        build(curr*2 + 1, mid + 1, r);
        t[curr] = t[curr*2];
        t[curr].first *= t[curr*2+1].first;
        t[curr].second = (t[curr].second * t[curr*2+1].first + MOD) % MOD;
        t[curr].second = (t[curr].second + t[curr*2+1].second + MOD) % MOD;
    }
    t[curr].first %= MOD;
    t[curr].second = (t[curr].second + MOD) % MOD;
    //cout << "l: " << l << " r: " << r << " val: " << t[curr] << "\n";
}

//tl-tr is the current segment, and l-r is the desired segment
pair<long long,long long> sum(int curr, int tl, int tr, int l, int r) {
    if (l > r) {
        return make_pair(1,0);
    }
    if (l == tl && r == tr) {
        return t[curr];
    }
    int mid = (tl + tr) / 2;
    //taking min of r and mid, because mid might be greater than r, same for max
    pair<long long,long long> temp = sum(curr*2, tl, mid, l, min(r,mid));
    pair<long long, long long> temp1 = sum(curr*2+1, mid +1, tr, max(l,mid+1), r);
    temp.first *= temp1.first;
    temp.second = (temp.second * temp1.first + MOD) % MOD;
    temp.second = (temp.second + temp1.second + MOD) % MOD;
    temp.first %= MOD;
    temp.second = (temp.second + MOD) % MOD;
    return temp;
}

void update(int curr, int tl, int tr, int pos, pair<char,long long> newval) {
    if (tl == tr) {
        t[curr] = make_pair(1,0);
        if (newval.first == '*') {
            t[curr].first *= newval.second;
            t[curr].second *= newval.second;
        } else if (newval.first == '+') {
            t[curr].second += newval.second;
        } else {
            t[curr].second -= newval.second;
        }
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(curr*2, tl, tm, pos, newval);
        else
            update(curr*2+1, tm+1, tr, pos, newval);
        t[curr] = t[curr*2];
        t[curr].first *= t[curr*2+1].first;
        //maybe mult 100?
        t[curr].second = (t[curr].second * t[curr*2+1].first + MOD) % MOD;
        t[curr].second = (t[curr*2+1].second + t[curr].second + MOD) % MOD;
    }

    t[curr].first %= MOD;
    t[curr].second = (t[curr].second + MOD) % MOD;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        char b;
        int a;
        cin >> b >> a;
        arr.push_back(make_pair(b,a));
    }

    for (int i = 0; i < 4*MAXN; i++) {
        t[i] = make_pair(1,0);
    }

    build(1,0, n - 1);

    for (int i = 0; i < m; i++) {
        char a;
        cin >> a;
        if (a == 'q') {
            int b,c;
            cin >> b >> c;
            c--;
            pair<long long, long long> p = sum(1, 0, n-1, 0 , c);
            cout << ((b*p.first + p.second) + MOD) % MOD << "\n";
        } else {
            int b,d;
            char c;
            cin >> b >> d >> c;
            b--;
            update(1, 0, n-1, b, make_pair(c,d));
        }
    }
    //neg number mod positive is positive
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

