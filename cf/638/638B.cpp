#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
    	int n, k;
    	cin >> n >> k;
    	unordered_set<int> taken;
    	for (int i = 0; i < n; i++) {
    		int element;
    		cin >> element;
    		if (taken.find(element) == taken.end()) {
    			taken.insert(element);
    		}
    	}
    	if (taken.size() > k) {
    		cout << "-1" << "\n";
    		continue;
    	}
    	unordered_set<int>::iterator it = taken.begin();
 		vector<string> elems;
		// Iterate till the end of set
		while (it != taken.end())
		{
			elems.push_back(to_string(*it));
			//Increment the iterator
			it++;
		}
		while (elems.size() < k) {
			elems.push_back("1");
		}
		int counter = 0;
		while (elems.size() < 10000) {
			elems.push_back(elems[counter]);
			counter++;
		}
		cout << elems.size() << "\n";
		for (int i = 0; i < elems.size(); i++) {
			if (i == elems.size() - 1) {
				cout << elems[i];
			} else {
				cout << elems[i] << " ";
			}
		}
		cout << "\n";
    }
}

