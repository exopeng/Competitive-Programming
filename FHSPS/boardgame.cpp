#include <bits/stdc++.h>

int pos[10];
bool squares[100];
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int g;
    cin >> g;
    while (g--) {
    	int n, p, t;
    	cin >> n >> p >> t;
    	for (int i = 0; i < 10; i++) {
    		pos[i] = 0;
    	}
    	for (int i = 0; i < 100; i++) {
    		squares[i] = false;
    	}
    	int player = 0;
    	squares[0] = true;
    	for (int i = 0; i < t; i++) {
    		if (player == p) {
    			player = 0;
    		}
    		int moves;
    		cin >> moves;
    		int initmoves = moves;
    		while (moves > 0) {
    			//mark last position as vacant
    			if (moves != initmoves || i >= p - 1) {
    				squares[pos[player]] = false;
    			}
    			pos[player]++;
    			if (pos[player] >= n) {
    				pos[player] = 0;
    			}
    			while (squares[pos[player]]) {
    				pos[player]++;
    				if (pos[player] == n) {
    					pos[player] = 0;
    				}
    			}
    			squares[pos[player]] = true;
    			moves--;
    		}
			player++;
    	}
    	for (int i = 0; i < p; i++) {
			cout << pos[i] << "\n";
		}
    	
    }
}

