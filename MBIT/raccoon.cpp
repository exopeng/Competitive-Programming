#include <bits/stdc++.h>

using namespace std;
long long ans = 0;
int n,q;
long long start[100000];
long long stop[100000];
vector<pair<int,int> > startvals[100000];
vector<pair<int,int> > stopvals[100000];

long long arr[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    for (int i = 0; i < q; i++) {
    	int l,r,x;
    	cin >> l >> r >> x;
    	l--,r--;
    	start[l]++;
    	stop[r]++;
    	startvals[l].push_back(make_pair(i,x));
    	stopvals[r].push_back(make_pair(i,x));
    }

    int starts = 0;
    int sum = 0;
    multiset< pair<int,int> , greater<pair<int,int> > > vals;
    //maintain a set of startvals, whenever there is a new one, sum becomes that
    //when one ends, remove it from the possible startvals
    for (int i = 0; i < n; i++) {
		starts += start[i];
		for (int j = 0; j < startvals[i].size(); j++) {
			vals.insert(startvals[i][j]);
		}
		//sum equals the last one put on
		if (!vals.empty()) {
			sum = (*vals.begin()).second;
			if (starts % 2 == 0) {
				if (arr[i] != 0) {
					arr[i] = sum;
				} else {
					arr[i] = 0;
				}
			} else {
				if (arr[i] == 0) {
					arr[i] = sum;
				} else {
					arr[i] = 0;
				}
			}
		} 
		starts -= stop[i];
		for (int j = 0; j < stopvals[i].size(); j++) {
			vals.erase(stopvals[i][j]);
		}
    }
    for (int i = 0; i < n; i++) {
    	cout << arr[i] << " ";
    }
    cout << "\n";

    
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

