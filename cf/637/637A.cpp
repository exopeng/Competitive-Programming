#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	int n,a,b,c,d;
    	cin >> n >> a >> b >> c >> d;
    	int x = ceil(c - d / -1);
    	int y = ceil(c+d);
    	string ans = "No";
    	if (n*a >= c - d && n * a <= c + d) {
    		ans = "Yes";
    	} else if (n*a > c+d) {
    		if ((double)((((c+d) - n*a )/ -1) / (double)n) <= b) {
    			ans = "Yes";
    		}
    	} else if (n*a < c-d){
    		if (((double)((double)(c-d - n*a) / n)) <= b) {
    			ans = "Yes";
    		}
    	}
    	cout << ans << "\n";
    }
}

