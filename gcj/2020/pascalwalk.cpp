#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int temp = t;
    while (t--) {
    	int n;
    	cin >> n;
    	string toprint = "";
    	string ans = "";
    	int orig = n;
    	if (n <= 30) {
    		for (int i = 0; i < n; i++) {
    			toprint = toprint + to_string(i + 1) + " " + to_string(i + 1) + "\n";
    		}
    	} else {
    		n -= 30;
    		//read from smallest to largest powers, 2^0, 2^1...

    		while(n) ans = ans + to_string(n%2), n/=2;

    		//see how much we overcount by, add it back in
    		//int len = ans.length();
    		//for (int i = 0; i < len; i++) {
    		//	if (ans[i] == '0') {
    		//		ans = ans + to_string(0);
    		//	}
			//}

			//count how much we have now
			int sum = 0;
			for (int i = 0; i < ans.length(); i++) {
				if (ans[i] == '1') {
					sum += pow(2,i);
				} else {
					sum++;
				}
			}

			//get back what we missed in the end
			for (int i = 0; i < orig - sum; i++) {
				ans = ans + to_string(0);
			}

			int col = 0;
			for (int i = 0; i < ans.length(); i++) {
				if (ans[i] == '0') {
					toprint = toprint + to_string(i + 1) + " " + to_string(col + 1) + "\n";
					if (col != 0) {
						col++;
					}
				} else {
					if (col == 0) {
						for (int j = 0; j < (i+1); j++) {
							toprint = toprint + to_string(i + 1) + " " + to_string(col + 1) + "\n";
							col++;
						}
					} else {
						for (int j = 0; j < (i+1); j++) {
							toprint = toprint + to_string(i + 1) + " " + to_string(col + 1) + "\n";
							col--;
						}
						col++;
					}
				}

				
			}
    	}

		
		cout << "Case #" + to_string(temp - t) + ":" + "\n" + toprint;


    }
}

