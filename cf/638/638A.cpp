#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;


    while (t--) {
    	int coins;
    	cin >> coins;
    	int a = 0;
    	int b = 0;
        if (coins == 2) {
            cout << 2 << "\n";
            continue;
        }
        a+=pow(2,coins);
        b+=pow(2,coins - 1);
    	for (int i = 1; i < coins / 2; i++) {
    		a += pow(2,i);
            b += pow(2,coins - i - 1);
    	}
    	cout << a - b << "\n";
    }
}

