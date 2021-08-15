#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
const long long MOD = 1000000007;
const int MAXN = 100001;
long long t[4*MAXN];
long long t1[4*MAXN];
vector<long long> arr;
vector<long long> arr1;

//separate the 2
void build(int curr, int l, int r) {
    if (l == r ) {
        t[curr] = arr[l];
    } else {
        int mid = (r + l) / 2;
        //an edge's two children are the indices 2i && 2i+1
        //in this sum segtree, an edge's value is the values from it's left to right indices
        build(curr * 2, l, mid);
        build(curr*2 + 1, mid + 1, r);
        t[curr] = (t[curr*2] * t[curr*2+1]);
    }
    t[curr] %= MOD;
    //cout << "l: " << l << " r: " << r << " val: " << t[curr] << "\n";
}
void build1(int curr, int l, int r) {
    if (l == r ) {
        t1[curr] = arr1[l];
    } else {
        int mid = (r + l) / 2;
        //an edge's two children are the indices 2i && 2i+1
        //in this sum segtree, an edge's value is the values from it's left to right indices
        build1(curr * 2, l, mid);
        build1(curr*2 + 1, mid + 1, r);
        t1[curr] = (t1[curr*2] * t1[curr*2+1]);
    }
    t1[curr] %= MOD;
    //cout << "l: " << l << " r: " << r << " val: " << t[curr] << "\n";
}

//tl-tr is the current segment, and l-r is the desired segment
long long sum(int curr, int tl, int tr, int l, int r) {
    if (l > r) {
        return 1;
    }
    if (l == tl && r == tr) {
        return t[curr];
    }
    int mid = (tl + tr) / 2;
    //taking min of r and mid, because mid might be greater than r, same for max
    return (sum(curr*2, tl, mid, l, min(r,mid)) * sum(curr*2+1, mid +1, tr, max(l,mid+1), r)) % MOD;
}

long long sum1(int curr, int tl, int tr, int l, int r) {
    if (l > r) {
        return 1;
    }
    if (l == tl && r == tr) {
        return t1[curr];
    }
    int mid = (tl + tr) / 2;
    //taking min of r and mid, because mid might be greater than r, same for max
    return (sum1(curr*2, tl, mid, l, min(r,mid)) * sum1(curr*2+1, mid +1, tr, max(l,mid+1), r)) % MOD;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (i % 2 == 0) {
            arr.push_back(a);
        } else {
            arr1.push_back(a);
        }
    }
    for (int i = 0; i < 4*MAXN; i++) {
        t[i] = 1;
        t1[i] = 1;
    }

    build(1,0, arr.size()-1);
    build1(1,0,arr1.size()-1);


    cin >> m;
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        if ((b - a) % 2 == 1) {
            b--;
        }
        a--;
        b--;
        if (a % 2 == 0) {
            cout << sum(1,0,arr.size()-1, a / 2 , b / 2) << "\n";
        } else {
            cout << sum1(1, 0, arr1.size()-1, (a-1)/2 , (b-1)/2) << "\n";
        }
    }
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

