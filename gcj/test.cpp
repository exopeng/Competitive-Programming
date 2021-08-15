#include <bits/stdc++.h>

using namespace std;

int main() {
	unordered_set<int> st;
	st.insert(1);
	if (st.find(1) != st.end()) {
		cout << "Present";
	} else {
		cout << "not present";
	}

	unordered_map<int,int> map;
	map[0] = 5;
	cout << map[0] << "\n";
}