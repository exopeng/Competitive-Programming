#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,l;
    queue<int> t;
    queue<int> wait;
    queue<int> room;
    cin >> n >> m >> l;
    m--;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        t.push(a);
    }
    int curr = t.front();
    t.pop();
    room.push(curr + m);

    int ans = 0;
    while (t.size() > 0 || wait.size() > 0 || room.size() > 0) {
        while (room.size() > 0 && room.front() < curr) {
            room.pop();
        }

        if (t.size() > 0 && t.front() == curr) {
            wait.push(t.front());
            t.pop();
        }

        while (room.size() < l && wait.size() > 0) {
            room.push(curr + m);
            wait.pop();
        }

        if (room.size() == 0) {
            ans++;
            //cout << curr << "\n";
        }
        curr++;
    }
    
    cout << ans - 1 << "\n";
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

