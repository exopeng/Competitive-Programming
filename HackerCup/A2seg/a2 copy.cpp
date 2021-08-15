#include <bits/stdc++.h>
using namespace std;
 

//store test cases here
/*


*/ 
const long long MOD = 1000000007;
long long l[1000000];
long long h[1000000];
long long w[1000000];
long long p[1000000];
//segtree for number of endpoints, might want to save mem by using vectors
vector<long,long> etree;
vector<bool> emarked;
//segtree for covered area, true means covered, false means not covered
vector<long,long> atree;
vector<bool> amarked;

vector<int> len;

void epush(int v) {
    if (emarked[v]) {
        etree[v*2] = etree[v*2+1] = etree[v];
        emarked[v*2] = emarked[v*2+1] = true;
        emarked[v] = false;
    }
}
//range update
void eupdate(int v, int tl, int tr, int l, int r, long long new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        etree[v] = new_val;
        emarked[v] = true;
    } else {
        epush(v);
        int tm = (tl + tr) / 2;
        eupdate(v*2, tl, tm, l, min(r, tm), new_val);
        eupdate(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

int eget(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return etree[v];
    }
    epush(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) 
        return eget(v*2, tl, tm, pos);
    else
        return eget(v*2+1, tm+1, tr, pos);
}

//
void apush(int v) {
    if (amarked[v]) {
        atree[v*2] = atree[v*2+1] = atree[v];
        amarked[v*2] = amarked[v*2+1] = true;
        amarked[v] = false;
    }
}

//range update
void aupdate(int v, int tl, int tr, int l, int r, long long new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        atree[v] = new_val;
        atreeval[v] = new_val;
        amarked[v] = true;
    } else {
        apush(v);
        int tm = (tl + tr) / 2;
        aupdate(v*2, tl, tm, l, min(r, tm), new_val);
        aupdate(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

int aget(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return len[tl];
    }
    apush(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) 
        return aget(v*2, tl, tm, pos);
    else
        return aget(v*2+1, tm+1, tr, pos);
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    freopen("a2.in","r",stdin);
    freopen("a2.out","w",stdout);
    int t;
    cin >> t;
    //mod everything out at the end

    //coordinate compress on possible coordinates
    for (int i = 0; i < t; i++) {
        unordered_map<long long, long long> mp;
        vector<int> points;
        long long ans = 1;
        long long n, k, w, aw, bw, cw, dw, al, bl, cl, ah, bh, ch, dl, dh;
        cin >> n >> k >> w;
        //remember to reset segtree
        for (int j = 0; j < n; j++) {
            l[j] = 0;
            h[j] = 0;
            p[j] = 0;
        }
        for (int j = 0; j < 8*n; j++) {
            etree.push_back(0);
            emarked.push_back(false);
            atree.push_back(0);
            atree.push_back(false);
        }
        for (int j = 0; j < k; j++) {
            cin >> l[j];
            points.push_back(l[j]);
            len.push_back(0);
        }        
        cin >> al >> bl >> cl >> dl;


        for (int j = 0; j < k; j++) {
            cin >> w[j];
            points.push_back(l[j] + w[j]);
            len.push_back(0);
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
            points.push_back(l[j]);
            points.push_back(l[j] + w[j]);
            len.push_back(0);
            len.push_back(0);
        }
        sort(points.begin(), points.end());
        //seg tree should be size 4 * ct
        //might not be all distinct
        long long last = 0;
        int ct = 0;
        for (int j = 0; j < n*2 ; j++) {
            if (mp.find(points[j]) == mp.end()) {
                mp[points[j]] = ct;
                ct++;
                if (j != 0) {
                    len[ct-1] = points[j] - last;
                }
                last = points[j];
            } 
        }

        for (int j = 0; j < n; j++) {
            if (j == 0) {
                p[j] = 2 * (w + h[j]);
            } else {
                p[j] += 2 * (w + h[j]) + p[j-1];
                //height overlap
                long long endpoints = eget(1, mp[l[j]], mp[l[j] + w[j]], 0, ct*2); 
                //check how many 
                //if the two current are within occupied space
                if (asum(1,mp[l[j]], mp[l[j]] + 1, 0, ct*2) == 1 || asum(1,mp[l[j]] - 1, mp[l[j]], 0, ct*2) == 1) {
                    endpoints++;
                } 
                if (asum(1,mp[l[j]+ w[j]] , mp[l[j]+ w[j]] + 1, 0, ct*2) == 1 || asum(1,mp[l[j]+ w[j]] - 1, mp[l[j]+ w[j]], 0, ct*2) == 1) {
                    endpoints++;
                }
                //if same rectangle, then don't do anything

                p[j] -= (h[j] * endpoints);
                //mark the new interval as having only 2 endpoints, lazy prop

                //width overlap
                p[j] -= w[j] - asum(1, mp[l[j]], mp[l[j] + w[j]], 0, ct*2);
            }
            //reset number of endpoints in that interval to 0 and length to 1, which means occupied
            eupdate(0, mp[l[j]], mp[l[j] + w[j]], 0, ct*2, 0);
            //don't update last one
            aupdate(0, mp[l[j]], mp[l[j] + w[j]] - 1, 0, ct*2, 1);

            eupdate(0, mp[l[j]], mp[l[j]])
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
