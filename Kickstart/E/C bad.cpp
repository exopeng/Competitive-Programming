#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int l = t;

    while (t--) {
    	long long ans = 0;
    	int n;
    	cin >> n;
        //cast everything long long
    	vector< pair<long long, int> > toys;

        //multiset< pair<long long, int> > mins;

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int e,r;
            cin >> e >> r;
            toys.push_back(make_pair(e,r));
            sum += toys[i].first;
        }
        long long csum = 0;
        bool ind = false;


        //have to consider ones that are affected by removals, ones before
        for (int i = 0; i < n; i++) {
            if (sum - toys[i].first - toys[i].second < 0) {
                ans = max(ans, csum + sum);
                sum -= toys[i].first;
            } else {
                csum += toys[i].first;
                ans = max(ans, sum + csum);
            }
        }


        bool fi = true;
        multiset< pair<long long,int> > del;
        multiset< pair<int,long long> > rem;

        //is this the min number of removals?
        long long csum = 0;

        for (int i = 0; i < n; i++) {
            if (sum - toys[i].first - toys[i].second < 0) {
                //maybe this part wrong, if removing current one allows you to get more
                //by getting the one before the next one that fails
                fi = false;
                del.insert(toys[i]);
                rem.insert(make_pair(i, toys[i].first));
            } else {
                mins.insert(make_pair(sum - toys[i].first - toys[i].second, i));
            }
            //ans = max(ans, sum - toys[i].first - toys[i].second);
            if (fi) {
                csum += toys[i].first;
            }
        }  

        long long add = 0;
        while (true) {
            //check edge case
            if (del.empty()) {
                ind = true;
                break;
            }
            if (mins.size() == 0) {
                break;
            }
            long long miny = (*mins.begin()).first;
            //sum up all of the e's in delete
            for (auto it = del.begin(); it != del.end(); it++) {
                add += it->first;
            }
            //erase stuff in del
            //if min - sum < 0, add to del, repeat
            if (miny - add < 0) {
                del.clear();
                del.insert(toys[mins.begin()->second]);
                rem.insert(make_pair(mins.begin()->second, toys[mins.begin()->second].first));
                mins.erase(mins.begin());
            } else {
                ind = true;
                break;
            }
        }

        int numr = 0;
        int ct = 0;
        if (ind) {
            cout << "Case #" << (l-t) << ": " << (n - mins.size()) << " INDEFINITELY" << "\n";
        } else {
            //find max sum
            //the new sum might improve, get the one before 
            for (auto it = rem.begin(); it != rem.end(); it++) {
                if (sum + csum > ans) {
                    ans = sum + csum;
                    numr = (ct);
                }
                sum -= it->second;
                //add csum up
                //error code
                //csum += it->second;
                //might remove second if statement
                if (ct != rem.size() - 1) {
                    for (int i = it->first + 1; i < next(it)->first; i++) {
                        csum += toys[i].first;
                    }
                }
                ct++;
            }
            cout << "Case #" << (l-t) << ": " << numr << " " << ans << "\n";
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
 * MOD OUT EVERY STEP
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

