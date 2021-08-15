#include <bits/stdc++.h>

using namespace std;
int n;
list< pair<int,int> > r;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
    	int a,b;
    	cin >> a >> b;
    	r.push_back(make_pair(a, b));
    }
    list< pair<int,int> >::iterator it = r.begin();
    //get reference to last item of list
    for (int i = 0; i < n-1; i++) {
        it++;
    }
    bool finished = false;
    //locate first right facing rhino sweeping from right to left
    while (true) {
        if (it == r.begin() && *it.second == 0) {
            break;
        } else if (it == r.begin()) {
            finished = true;
        }

        while (!finished && (*it).second != 1) {
            it--;
            if (it == r.begin()) {
                finished = true;
                break;
            }
        }
        if (finished) {
            break;
        }
        //collide with all the left facing rhinos it can
        while (true) {
            list< pair<int,int> >::iterator toface = next(it, 1);
            //no more left facing rhinos on the right side of the rhino
            if (toface == r.end()) {
                break;
            }
            //same stamina, erase both
            if ((*toface).first == (*it).first) {
                r.erase(toface);
                list< pair<int,int> >::iterator temp = it;
                it = next(it, -1);
                r.erase(temp);
                break;
                //right facing rhino wins, erase the left one
            } else if ((*toface).first < (*it).first) {
                (*it).first -= (*toface).first;
                r.erase(toface);
                //right facing rhino loses, erase it
            } else {
                (*toface).first -= (*it).first;
                list< pair<int,int> >::iterator temp = it;
                it = next(it, -1);
                r.erase(temp);
                break;
            }
        }
    }
    for (list< pair<int,int> >::iterator i = r.begin(); i != r.end(); i++) {
        cout << (*i).first << " " << (*i).second << "\n";
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

