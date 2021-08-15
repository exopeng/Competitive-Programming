#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 800000;
//store test cases here
/*


*/ 
//fing thing, make sure to check array bounds next time
//when in doubt, make as big as possible as that
//almost never hurts
int dpbr[MAXN * 2];
int dplb[MAXN * 2];
int p[MAXN];
int h[MAXN];
int ans;

//if endpoint, then can only go in it's direction
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    freopen("timber.in","r",stdin);
    freopen("timber.out","w",stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector< pair<int,int> >points;
        //sort and pretend each is a starting point, then find the longest you can get,
        //can only start with base-right or left-base
        //if base-right, find left-base or base-right that shares the same point as right
        //if left-base, find a left-base that shares the same base 
        for (int j = 0; j < MAXN * 2; j++) {
            dpbr[j] = 0;
            dplb[j] = 0;
        }
        ans = 0;
        map<int,int> mp;

        for (int j = 0; j < n; j++) {
            cin >> p[j] >> h[j];
            points.push_back(make_pair(p[j], j));
            //points.push_back(make_pair(p[j] + h[j], j));
            points.push_back(make_pair(p[j] - h[j], j));
        }

        sort(points.begin(), points.end());
        int ct = 0;
        for (int j = 0; j < points.size(); j++) {
            if (mp.find(points[j].first) == mp.end()) {
                mp.insert(make_pair(points[j].first,ct));
                ct++;
            } 
            //cout << points[j].first << " " << points[j].second << "\n";
            //if duplicate it is also j
        }
        /*
        for (auto it = mp.begin(); it != mp.end(); it++) {
            cout << it->first << ":" << it->second << " ";
        }
        */
        dpbr[mp[points[points.size()-1].first]] = h[points[points.size()-1].second];
        ans = max(ans, dpbr[mp[points[points.size()-1].first]]);
        for (int j = points.size()-2; j > -1; j--) {
            //base
            //pos depends if left or right
            //cout << points[j].first << " " << points[j].second << "\n";
            int pos = 0;
            if (points[j].first == p[points[j].second]) {
                pos = p[points[j].second] + h[points[j].second];
                dpbr[mp[points[j].first]] = max(dpbr[mp[points[j].first]],h[points[j].second] + max(dpbr[mp[pos]], dplb[mp[pos]]));
                ans = max(ans, dpbr[mp[points[j].first]]);
            } else {
                //left
                pos = p[points[j].second];
                dplb[mp[points[j].first]] = max(dplb[mp[points[j].first]],h[points[j].second] + dplb[mp[pos]]);
                ans = max(ans, dplb[mp[points[j].first]]);
            }
        }
        /*
        for (int j = 0; j < points.size(); j++) {
            cout << dpbr[j] << " ";
        }
        cout << "\n";
        for (int j = 0; j < points.size(); j++) {
            cout << dplb[j] << " ";
        }
        */
        cout << "Case #" << i+1 << ": " << ans << "\n";
    }
}
/* REMINDERS
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
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */
