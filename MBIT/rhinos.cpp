
#include <bits/stdc++.h>

using namespace std;
int n;
long long ans = 0;
vector< pair<int,int> > r;
set<int> lhs;
set<int, greater<int> > rhs;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ans = n;
    for (int i = 0; i < n; i++) {
    	int a,b;
    	cin >> a >> b;
    	r.push_back(make_pair(a, b));
    }
    //maintain 2 pointer, look for first right facing from left to right, keep track of closest left facing
    //if right dies, look for the next closest right facing, keeping track of closest left facing. if end, break
    //if left dies, look for next left facing, if end, look for next right facing
    int target = -1;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (r[i].second == 0) {
            lhs.insert(i);
        } else {
            rhs.insert(i);
        }
    }
    while (true) {
        if (rhs.empty() || lhs.empty() || *rhs.rbegin() > *lhs.rbegin()) {
            break;
        }
        if (index == -1) {
            index = *rhs.begin();    
        }
        target = *lhs.lower_bound(index);
        //if none to the right
        if (lhs.lower_bound(index) == lhs.end()) {
            rhs.erase(rhs.begin());
            index = -1;
            continue;
        }
        if (r[target].first == r[index].first) {
            ans -= 2;
            r[target].second = -1;
            r[index].second = -1;
            lhs.erase(lhs.lower_bound(index));
            rhs.erase(rhs.begin());
            index = -1;
        } else if (r[target].first < r[index].first) {
            ans--;
            r[index].first -= r[target].first;
            r[target].second = -1;
            lhs.erase(lhs.lower_bound(index));
        } else {
            ans--;
            r[target].first -= r[index].first;
            r[index].second = -1;
            rhs.erase(rhs.begin());
            index = -1;
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        if (r[i].second != -1) {
            cout << r[i].first << " " << r[i].second << "\n";
        }
    }
    
}
/* REMINDERS
 * PLANNING!!!!!!!! Concrete plan before code
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * NAIVE SOL FIRST TO CHECK AGAINST OPTIMIZED SOL
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 */

