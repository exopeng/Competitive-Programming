#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
    	long long cards;
    	cin >> cards;
    	int pyramids = 0;
    	long long ans = 1;
    	while (true) {
    		ans = floor((-1+floor(pow(1-4*3*(-2)*cards, 0.5))) / 6);
    		if (ans == 0) {
    			break;
    		} else {
    			cards -= 3*(ans)*(ans + 1) / 2 - ans;
    			pyramids++;
    		}
    	}
    	cout << pyramids << "\n";
    }
}

