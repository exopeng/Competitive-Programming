#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
const int INF = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  	string line;
	getline(cin,line);
	while (!line.empty()) {
		int n;
	    cin >> n;
	    vector<int> a;
	    vector< pair<int,int> > d;
	    vector< int > p;
	    for (int i = 0; i < n; i++) {
	    	int b;
	    	cin >> b;
	    	a.push_back(b);
	    	d.push_back(make_pair(INF,-1));
	     	p.push_back(INF);
	    }

	    d.push_back(make_pair(INF,-1));
	    p.push_back(INF);

	    d[0] = make_pair(-1*INF, -1);

	    for (int i = 0; i < n; i++) {
	    	int ind = lower_bound(d.begin(),d.end(),make_pair(a[i]+1,-1)) - d.begin();
	    	/*
	    	for (int j = 0; j <=n; j++) {
	    		cout << p[j] << " ";
	    	}
	    	*/
	    	//acout << "\n";
	    	if (d[ind-1].first < a[i] && a[i] < d[ind].first) {
	    		//cout << a[i] << " ";
	            d[ind].first = a[i];
	        	d[ind].second = i;
	        	p[i] = d[ind-1].second;
	    	}
	    		
	    }

	    int ans = 0;
	    for (int i = 0; i <= n; i++) {
	    	if (d[i].first < INF) {
	    		ans = i;
	    	}
	    }

	    int last = d[ans].second;
	    cout << ans << "\n";
	    vector<int> inds;
	    while (last != -1) {
	    	inds.push_back(last);
	    	last = p[last];
	    }

	    reverse(inds.begin(),inds.end());
	    for (int i = 0; i < inds.size();i++) {
	    	cout << inds[i] << " ";
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

