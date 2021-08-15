#include <bits/stdc++.h>

using namespace std;
char ans;
string rep;
set<string> valid;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 0; i < 10; i++) {
    	cout << i << "\n";
    	cout << flush;
    	cin >> ans;
    	if (ans == 'Y') {
    		string temp = "";
    		temp += to_string(i);
    		valid.insert(temp);
    	} 
    	if (ans == 'C') {
    		return 0;
    	}
    }
    for (int i = 65; i < 91; i++) {
    	cout << (char)i << "\n";
    	cout << flush;
    	cin >> ans;
    	if (ans == 'Y') {
    		string temp = "";
    		temp += (char)i;
    		valid.insert(temp);
    	}
    	if (ans == 'C') {
    		return 0;
    	}
    }
    for (int i = 97; i < 123; i++) {
    	cout << (char)i << "\n";
    	cout << flush;
    	cin >> ans;
    	if (ans == 'Y') {
    		string temp = "";
    		temp += (char)i;
    		valid.insert(temp);
    	}
    	if (ans == 'C') {
    		return 0;
    	}
    }

    rep = *valid.begin();
    valid.erase(*valid.begin());
    while (!valid.empty()) {
    	string guess = (*valid.begin());
    	valid.erase(valid.begin());
    	int lo = 0;
    	int hi = rep.size() - 1;
    	int mid = 0;
    	while (lo <= hi) {
    		mid = (lo + hi) / 2;
    		string temp = rep[mid] + guess;
    		cout << temp << "\n";
    		cout << flush;
	    	cin >> ans;
	    	if (ans == 'Y') {
	    		lo = mid + 1;
	    	} else if (ans == 'N') {
	    		hi = mid - 1;
	    	} else {
	    		return 0;
	    	}
    	}
    	if (ans == 'Y') {
    		rep = rep.substr(0, mid + 1) + guess + rep.substr(mid + 1);
    	} else {
        	rep = rep.substr(0, mid) + guess + rep.substr(mid);
    	}
    }
    cout << rep << "\n";
    cout << flush;
}