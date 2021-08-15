#include <bits/stdc++.h>

using namespace std;
long long ans = 0;
long long ans1 = 1;
long long mod = 1000000007;
int n,k;
vector<int> arr;
unordered_set<int> yes;
vector< pair<int,int> > pairs;
unordered_set<int> taken;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
    	int e;
    	cin >> e;
    	arr.push_back(e);
    	yes.insert(e);
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n-1; i++) {
    	if (yes.find(arr[i] + k) != yes.end()) {
    		pairs.push_back(make_pair(arr[i], arr[i] + k));
    		//cout << arr[i] << " " << arr[i] + k << "\n";
    	}
    	yes.erase(arr[i]);
    }

    int power2 = n - 2;;
    int power3 = 0;
    for (int i = 0; i < pairs.size(); i++) {
    	int curr2 = power2;
    	int curr3 = power3;
    	//.wrong code, long overflow possibly
    	int add = (long long)pow(2,curr2) % mod;
    	int add1 = (long long)pow(3,curr3) % mod;
    	cout << (add * add1) << "\n";
    	ans += (add * add1) % mod;
    	ans %= mod;
    	if (i == 0) {
    		power2 -= 2;
    	} else {
    	   	power2--;
    	}
    	if ((taken.find(pairs[i].first) != taken.end() || taken.find(pairs[i].second) != taken.end())) {
    	}  else {
    		power3++;
    	}
    	taken.insert(pairs[i].first);
    	taken.insert(pairs[i].second);
    }
    for (int i = 0; i < n; i++) {
    	ans1 *= 2;
    	ans1 %= mod;
    }
    ans1--;
    cout << ((ans1 + mod - ans) + mod) % mod  << "\n";
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

