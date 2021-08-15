#include <bits/stdc++.h>
using namespace std;
 

//store test cases here
/*


*/ 
const long long MOD = 1000000007;
long long l[1000000];
long long h[1000000];
long long p[1000000];

//  Insert the code that will be timed


// Store the time difference between start and end
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    freopen("a1.in","r",stdin);
    freopen("a1.out","w",stdout);
    int t;
    cin >> t;
    //auto start = chrono::steady_clock::now();
    //coord compress on possible coords
    for (int i = 0; i < t; i++) {
        long long lastse = 0;
        long long ans = 1;
        long long n, k, w, al, bl, cl, ah, bh, ch, dl, dh;
        cin >> n >> k >> w;
        
        for (int j = 0; j < n; j++) {
            l[j] = 0;
            h[j] = 0;
            p[j] = 0;
        }

        for (int j = 0; j < k; j++) {
            cin >> l[j];
        }

        cin >> al >> bl >> cl >> dl;
        for (int j = 0; j < k; j++) {
            cin >> h[j];
        }
        cin >> ah >> bh >> ch >> dh;

        for (int j = k; j < n; j++) {
            l[j] = ((al*l[j-2] + bl*l[j-1] + cl) % dl) + 1;
            h[j] = ((ah*h[j-2] + bh*h[j-1] + ch) % dh) + 1;
        }

        for (int j = 0; j < n; j++) {
            if (j == 0) {
                p[j] = 2 * (w + h[j]);
            } else {
                p[j] += 2 * (w + h[j]) + p[j-1];
                //check height overlap
                long long height = 0;
                for (int f = j-1; l[j] - l[f] <= w && f >= 0; f--) {
                    height = max(height, h[f]);
                }
                p[j] -= 2*(min(height, h[j]));
                //check width overlap
                if (l[j] < lastse) {
                    p[j] -= 2*(lastse - l[j]);
                } 
            }            
            lastse = l[j] + w;

            //cout << p[j] << " ";
            p[j] %= MOD;
            ans *= p[j];
            ans %= MOD;
        }
        cout << "Case #" << i+1 << ": " << ans << "\n";
    }
    //auto end = chrono::steady_clock::now();
    //auto diff = end - start;
    //cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;
}
/* REMINDERS
 * PLANNING!!!!!!!! Concrete plan before code
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * NAIVE SOL FIRST TO CHECK AGAINST OPTIMIZED SOL
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */
