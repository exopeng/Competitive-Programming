#include <bits/stdc++.h>
using namespace std;
bool avail[1000001];
long long ans = 0;
int n;
vector<int> arr;
vector<int> fin;
vector<int> todo;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int e;
		cin >> e;
		arr.push_back(e);
		avail[arr[i]] = true;
		fin.push_back(-1);
	}
	for (int i = 0; i < 1000001; i++) {
		if (!avail[i]) {
			todo.push_back(i);
		}
	}
	
	for (int i = 1; i < n; i++) {
		//if curr number is greater than previous, you can add prev to the list
		if (arr[i] > arr[i-1]) {
			fin[i] = arr[i-1];
		} 
	}
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (fin[i] == -1) {
			fin[i] = todo[counter];
			counter++;
		} 
	}
	unordered_set<int> cont;
	for (int i = 0; i < n; i++) {
		cont.insert(fin[i]);
		if (cont.find(arr[i]) != cont.end()) {
			cout << "-1" << "\n";
			break;
		}
	}
	//check if min of set -1 not equal to element, then imposssible
	for (int i = 0; i < n; i++) {
		cout << fin[i] << " ";
	}
	cout << "\n";
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

