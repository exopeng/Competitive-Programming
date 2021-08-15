#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	double ans = 0;
    	int r, s;
    	cin >> r >> s;
    	vector <double> vals;
    	for (int i = 0; i < r; i++) {
    		int d, tickets;
    		cin >> d >> tickets;
    		vals.push_back(((double)1 / (tickets+1)) * (double)d);
    	}
    	sort(vals.begin(), vals.end());
    	reverse(vals.begin(), vals.end());
    	for (int i = 0; i < s; i++) {
    		ans += vals[i];
    	}
    	cout << setprecision(2) << fixed << ans << "\n";
    }
}

