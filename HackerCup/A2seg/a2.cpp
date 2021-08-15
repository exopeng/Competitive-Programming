#include <bits/stdc++.h>
using namespace std;
 

const long long MOD = 1000000007;
long long l[1000000];
long long h[1000000];
long long w[1000000];
long long p[1000000];
//segtree for number of endpoints, might want to save mem by using vectors
vector<long long> etree;
vector<long long> lazye;
//segtree for covered area, true means covered, false means not covered
vector<long long> atree;
vector<long long> lazya;

vector<long long> psum;
vector<int> len;

void updateRangeUtil(int si, int ss, int se, int us, 
                    int ue, int diff) 
{ 
    if (lazye[si] != 0) 
    { 
        // Make pending updates using value stored in lazy 
        // nodes 
        etree[si] = (se-ss+1)*lazye[si]; 
 
        if (ss != se) 
        { 
            lazye[si*2 + 1] = lazye[si]; 
            lazye[si*2 + 2] = lazye[si]; 
        } 

        // Set the lazy value for current node as 0 as it 
        // has been updated 
        lazye[si] = 0; 
    } 

    // out of range 
    if (ss>se || ss>ue || se<us) 
        return ; 

    // Current segment is fully in range 
    if (ss>=us && se<=ue) 
    { 
        etree[si] = (se-ss+1)*diff; 

        if (ss != se) 
        { 
            lazye[si*2 + 1] = diff; 
            lazye[si*2 + 2] = diff; 
        } 
        return; 
    } 

    int mid = (ss+se)/2; 
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff); 

    etree[si] = etree[si*2+1] + etree[si*2+2]; 
} 
void updateRange(int n, int us, int ue, int diff) 
{ 
    updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 
long long getSumUtil(int ss, int se, int qs, int qe, int si) 
{ 
    if (lazye[si] != 0) 
    { 
        etree[si] += (se-ss+1)*lazye[si];  
        if (ss != se) 
        { 
            lazye[si*2+1] += lazye[si]; 
            lazye[si*2+2] += lazye[si]; 
        } 

        lazye[si] = 0; 
    } 

    // Out of range 
    if (ss>se || ss>qe || se<qs) 
        return 0; 

    if (ss>=qs && se<=qe) 
        return etree[si]; 
    int mid = (ss + se)/2; 
    return getSumUtil(ss, mid, qs, qe, 2*si+1) + 
        getSumUtil(mid+1, se, qs, qe, 2*si+2); 
} 

long long getSum(int n, int qs, int qe) 
{ 
    /*
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        printf("Invalid Input"); 
        return -1; 
    } 
    */
    return getSumUtil(0, n-1, qs, qe, 0); 
} 

//
void updateRangeUtil1(int si, int ss, int se, int us, 
                    int ue, int diff) 
{ 
    if (lazya[si] != 0) 
    { 
        // Make pending updates using value stored in lazy 
        // nodes 
        if (ss != 0) {
            atree[si] = psum[se] - psum[ss-1];
        } else {
            atree[si] = psum[se];
        }
 
        if (ss != se) 
        { 
            lazya[si*2 + 1] = lazya[si]; 
            lazya[si*2 + 2] = lazya[si]; 
        } 

        // Set the lazy value for current node as 0 as it 
        // has been updated 
        lazya[si] = 0; 
    } 

    // out of range 
    if (ss>se || ss>ue || se<us) 
        return ; 

    // Current segment is fully in range 
    if (ss>=us && se<=ue) 
    { 
        if (ss != 0) {
            atree[si] = psum[se] - psum[ss-1];
        } else {
            atree[si] = psum[se];
        }

        if (ss != se) 
        { 
            lazya[si*2 + 1] = diff; 
            lazya[si*2 + 2] = diff; 
        } 
        return; 
    } 

    int mid = (ss+se)/2; 
    updateRangeUtil1(si*2+1, ss, mid, us, ue, diff); 
    updateRangeUtil1(si*2+2, mid+1, se, us, ue, diff); 
    atree[si] = atree[si*2+1] + atree[si*2+2]; 
} 
void updateRange1(int n, int us, int ue, int diff) 
{ 
    updateRangeUtil1(0, 0, n-1, us, ue, diff); 
} 
long long getSumUtil1(int ss, int se, int qs, int qe, int si) 
{ 
    if (lazya[si] != 0) 
    { 
        if (ss != 0) {
            atree[si] = psum[se] - psum[ss-1];
        } else {
            atree[si] = psum[se];
        }

        if (ss != se) 
        { 
            lazya[si*2+1] += lazya[si]; 
            lazya[si*2+2] += lazya[si]; 
        } 

        lazya[si] = 0; 
    } 

    // Out of range 
    if (ss>se || ss>qe || se<qs) 
        return 0; 

    if (ss>=qs && se<=qe) 
        return atree[si]; 
    int mid = (ss + se)/2; 
    return getSumUtil1(ss, mid, qs, qe, 2*si+1) + 
        getSumUtil1(mid+1, se, qs, qe, 2*si+2); 
} 

long long getSum1(int n, int qs, int qe) 
{ 
    /*
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        printf("Invalid Input"); 
        return -1; 
    } 
    */
    return getSumUtil1(0, n-1, qs, qe, 0); 
} 

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
    freopen("a2.in","r",stdin);
    freopen("a2.out","w",stdout);
    int t;
    cin >> t;

    //coordinate compress on possible coordinates
    for (int i = 0; i < t; i++) {
        unordered_map<long long, long long> mp;
        vector<long long> points;
        etree.clear();
        lazye.clear();
        atree.clear();
        lazya.clear();
        len.clear();
        psum.clear();
        long long ans = 1;
        long long n, k, aw, bw, cw, dw, al, bl, cl, ah, bh, ch, dl, dh;
        cin >> n >> k;
        //remember to reset segtree
        for (int j = 0; j < n; j++) {
            l[j] = 0;
            h[j] = 0;
            p[j] = 0;
            w[j] = 0;
        }
        for (int j = 0; j < 8*n; j++) {
            etree.push_back(0);
            atree.push_back(0);
            lazye.push_back(0);
            lazya.push_back(0);
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
        long long last = 0;
        int ct = 0;
        for (int j = 0; j < n*2 ; j++) {
            if (mp.find(points[j]) == mp.end()) {
                mp[points[j]] = ct;
                ct++;
                if (j != 0) {
                    len[ct-1] = points[j] - last;
                    psum.push_back(0);
                }
                last = points[j];
            } 
        }
        ct--;
        psum[0] = len[0];
        for (int j = 1; j < len.size(); j++) {
            psum[j] = psum[j-1] + len[j];
        }
        //start from count
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                p[j] = 2 * (w[j] + h[j]);
            } else {
                p[j] += 2 * (w[j] + h[j]) + p[j-1];
                //height overlap
                long long endpoints = getSum(ct, mp[l[j]], mp[l[j] + w[j]]); 
                //check how many 
                //if the two current are within occupied space, area
                if (getSum1(ct, mp[l[j]], mp[l[j]]+1) > 0 || getSum1(ct, mp[l[j]] - 1, mp[l[j]]) > 0) {
                    endpoints++;
                } 
                //maybe segfault
                if (getSum1(ct, mp[l[j] + w[j]], mp[l[j] + w[j]] + 1) > 0 || getSum1(ct, mp[l[j] + w[j]] - 1, mp[l[j] + w[j]]) > 0) {
                    endpoints++;
                } 
                //if same rectangle, then don't do anything
                cout << endpoints << "\n";

                p[j] -= (h[j] * endpoints);

                //seg tree stores area starting from here
                //width overlap
                p[j] -= 2 * getSum1(ct, mp[l[j]], mp[l[j] + w[j]] - 1);
            }

            //reset number of endpoints in that interval to 0 and length to 1, which means occupied
            updateRange(ct, mp[l[j]], mp[l[j] + w[j]], 0);
            updateRange(ct, mp[l[j]], mp[l[j]], 1);
            updateRange(ct, mp[l[j] + w[j]], mp[l[j] + w[j]], 1);
            
            //don't update last one
            updateRange1(ct, mp[l[j] + w[j]], mp[l[j]],  0);
            //everything in that range becomes connected
            updateRange1(ct, mp[l[j] + w[j]], mp[l[j]],  w[j]);

            for (int f = 0; f <= ct*2; f++) {
                cout << atree[f] << " ";
            }
            //cout << p[j] << " ";
            p[j] %= MOD;
            ans *= p[j];
            ans %= MOD;
        }
        cout << "Case #" << i+1 << ": " << ans << "\n";
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
