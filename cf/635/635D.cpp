#include <bits/stdc++.h>

using namespace std;
int r,g,b;
const int MAXN = 100000001;
const int MINN = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;

	while (t--) {
		long long ans = 1000000000000000000;
		cin >> r >> g >> b;
		int maxr = MINN;
		int minr = MAXN;
		int maxg = MINN;
		int ming = MAXN;
		int maxb = MINN;
		int minb = MAXN;

		int temp = 0;
		for (int i = 0; i < r; i++) {
			cin >> temp;
			maxr = max(temp, maxr);
			minr = min(temp, minr);
		}
		for (int i = 0; i < g; i++) {
			cin >> temp;
			maxg = max(temp, maxg);
			ming = min(temp, ming);
		}
		for (int i = 0; i < b; i++) {
			cin >> temp;
			maxb = max(temp, maxb);
			minb = min(temp, minb);
		}
		int rct = 1;
		int gct = 1;
		int bct = 1;
		if (r > 1) {
			rct = 2;
		}
		if (g > 1) {
			gct = 2;
		}		
		if (b > 1) {
			bct = 2;
		}

		//permute on the 6C3 possibilites
		for (int i = 0; i < rct; i++) {
			int cr = maxr;
			if (i == 1) {
				cr = minr;
			}
			for (int j = 0; j < gct; j++) {
				int cg = maxg;
				if (j == 1) {
					cg = ming;
				}
				for (int e = 0; e < bct; e++) {
					int cb = maxb;
					if (e == 1) {
						cb = minb;
					}
					cout << "\n" << cr << " " << cg << " " << cb;

					ans = min(ans, static_cast<long long>(pow(cr-cg,2)) + static_cast<long long>(pow(cg - cb,2)) + static_cast<long long>(pow(cr-cb,2)) );
					cout << " " << ans;
				}
			}
		}
		cout << "\n" << ans << "\n";

	}
}

