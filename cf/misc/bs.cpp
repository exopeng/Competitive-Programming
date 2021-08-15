#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;

#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define f first
#define ll long long
#define s second
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<ll,ll>
#define is insert
const long long INF = 1e9;
const long long MOD = 1e9+7;
const int MAXN = 3e6;
//store test cases here
/*


*/
int t[MAXN];
int lazy[MAXN];
void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
pair<int,pii> ls[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>ls[i].s.f>>ls[i].s.s>>ls[i].f;
    }
    sort(ls,ls+n);
    int r=0;
    int as=INF;
    update(1,1,m-1,ls[0].s.f,ls[0].s.s-1,1);
    for(int i=0;i<n;i++){
        if(i){
            update(1,1,m-1,ls[i-1].s.f,ls[i-1].s.s-1,-1);
        }
        while(query(1,1,m-1,1,m-1)==0){
            r++;
            if(r==n){
                cout<<as<<'\n';
                return 0;
            }
            update(1,1,m-1,ls[r].s.f,ls[r].s.s-1,1);
        }
        as=min(as,ls[r].f-ls[i].f);
    }
    cout<<as<<'\n';
    return 0;
}

