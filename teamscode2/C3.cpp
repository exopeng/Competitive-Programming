#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/
char arr[30][30];
int n, t;
int ans = 0;
void dfs(int starti, int startj, int dist) {
	queue< pair< pair<int,int>, int> > q;
	q.push(make_pair(make_pair(starti,startj),dist));
	while (!q.empty()) { 
        pair<pair<int,int> , int> f = q.front(); 
        q.pop(); 
        int i = f.first.first;
        int j = f.first.second;
        int dist = f.second;
  		if (i < 0 || i > n-1 || j < 0 || j > n-1) {
			continue;
		}
		if (arr[i][j] == '#' || arr[i][j] == 'v') {
			continue;
		}
		arr[i][j] = 'v';
		if (dist == 0) {
			continue;;
		}
		dist--;
		q.push(make_pair(make_pair(i+1,j), dist));
		q.push(make_pair(make_pair(i-1,j), dist));
		q.push(make_pair(make_pair(i,j+1), dist));
		q.push(make_pair(make_pair(i,j-1), dist));
    } 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t;
    int starti, startj;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		cin >> arr[i][j];
    		if (arr[i][j] == 'Z') {
    			starti = i;
    			startj = j;
    		}
    		if (arr[i][j] == '#') {
    			ans--;
    		}
    	}
    }
    dfs(starti, startj, t);
    /*
    cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	*/
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (arr[i][j] == 'v') {
    			if (i-1 >= 0 && arr[i-1][j] == '*') {
    				arr[i-1][j] = '#';
    			}
    			if (i+1 < n && arr[i+1][j] == '*') {
    				arr[i+1][j] = '#';
    			}
    			if (j-1 >= 0 && arr[i][j-1] == '*') {
    				arr[i][j-1] = '#';
    			}
    			if (j+1 < n && arr[i][j+1] == '*') {
    				arr[i][j+1] = '#';
    			}
    		}
    	}
    }

    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '#') {
				ans++;
			}
		}
	}
    cout << ans << "\n";
    
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

