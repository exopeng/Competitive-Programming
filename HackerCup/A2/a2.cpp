#include <bits/stdc++.h>
using namespace std;
 
#define mp make_pair
#define pb push_back

//store test cases here
/*


*/ 
const long long MOD = 1000000007;
long long l[1000000];
long long h[1000000];
long long w[1000000];
long long p[1000000];


int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    freopen("a2.in","r",stdin);
    freopen("a2.out","w",stdout);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long n, k, al, bl, cl, ah, bh, ch, aw, bw, cw, dw, dl, dh;
        cin >> n >> k;
 
        for (int j = 0; j < n; j++) {
            l[j] = 0;
            h[j] = 0;
            w[j] = 0;
            p[j] = 0;
        }

        for (int j = 0; j < k; j++) {
            cin >> l[j];
        }
        cin >> al >> bl >> cl >> dl;
       
        for (int j = 0; j < k;j++) {
            cin >> w[j];
        }
        cin >> aw >> bw >> cw >> dw;

        for (int j = 0; j < k; j++) {
            cin >> h[j];
        }
        cin >> ah >> bh >> ch >> dh;

        for (int j = k; j < n; j++) {
            l[j] = ((al*l[j-2] + bl*l[j-1] + cl) % dl) + 1;
            h[j] = ((ah*h[j-2] + bh*h[j-1] + ch) % dh) + 1;
            w[j] = ((aw*w[j-2] + bw*w[j-1] + cw) % dw) + 1;
        }

        set< pair<long long,long long> > points;
        //insert dummy vals
        points.insert(mp(MOD, 0));
        points.insert(mp(-1, 1));

        points.insert(mp(l[0], 0));
        points.insert(mp(l[0] + w[0], 1));

        p[0] = 2 * h[0] + 2 * w[0];
        //cout << p[0] << "\n";
        for (int j = 1; j < n; j++) {
            long long left = l[j];
            long long right = l[j] + w[j];
            long long height = h[j];
            p[j] = p[j-1] + 2*height + 2*w[j];
            //first one less or equal to it
            auto rit = points.upper_bound(mp(right,1));
            //first one greater than or equal to it, if returns greater, than it is empty
            auto lit = points.lower_bound(mp(left,0));
            long long currr = 0;
            long long currl = 0;
            for (auto it = lit; it != rit; it++) {
                if (it == lit && it->second == 1) {
                    p[j] -= 2*(it->first-left);
                } else if (it == prev(rit) && it->second == 0) {
                    p[j] -= 2*(right - it->first);
                } else {
                    if (it->second == 1) {
                        currr = it->first;
                        p[j] -= 2*(currr - currl);
                    } else {
                        currl = it->first;
                    }
                }
                p[j] -= height;
            }
            //handle entirely inside
            

           

            if (lit == rit && rit->second == 1 && prev(lit)->second == 0) {
                p[j] -= (right - left) * 2;
                p[j] -= height*2;
            } else {
                long long l = prev(lit)->second;
                long long r = rit->second;
                if (lit->first != MOD && lit->first != -1) {
                    points.erase(lit,rit);
                }
                if (l == 0 && r == 1) {
                    p[j] -= 2*height;
                } else if ( l == 0 && r == 0) {
                    points.insert(mp(right, 1));
                    p[j] -= height;
                } else if (l == 1 && r == 0 ) {
                    points.insert(mp(left, 0));
                    points.insert(mp(right,1));
                } else if ( l == 1  && r == 1 ){
                    points.insert(mp(left, 0));
                    p[j] -= height;
                }
            }   
            
            //cout << p[j] << "\n";
            //last one that goes equal or after, del everything in between
            p[j] %= MOD;
        }

        for (int j = 1; j < n; j++) {
            p[j] *= p[j-1];
            p[j] %= MOD;
        }

        cout << "Case #" << i+1 << ": " << p[n-1] << "\n";
    }
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
