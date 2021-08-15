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
const int MAXN = 2e5;
//store test cases here
/*


*/
int a[MAXN];

ll binpow(ll a,ll b,ll m){
    a%=m;
    ll res = 1;
    while(b>0){
        if(b&1)
            res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    vector<int> p;
    vector<bool> ip(MAXN+1,true);
	ip[0]=ip[1]=false;
	for(int i=2;i*i<=MAXN;i++){
	    if(ip[i]){
	    	p.pb(i);
	        for(int j=i*i;j<=MAXN;j+=i)
	            ip[j]=false;
	    }
	}
    for(int i=0;i<t;i++){
    	map<int,map<int,int>> ps;
    	int n;
    	cin>>n;
    	for(int j=0;j<n;j++){
    		cin>>a[j];
    		for(ll d:p){
			    int ct=0;
			    if(d*d>a[j])
			        break;
			    while(a[j]%d==0){
			        ct++;
			        a[j]/=d;
			    }
			    if(ct){
			        ps[d][ct]++;
			    }
			}
			if(a[j]>1){
				ps[a[j]][1]++;
			}
    	}
    	ll as=1;
    	for(auto it=ps.begin();it!=ps.end();it++){
    		int tt=0;
    		for(auto it1=it->s.begin();it1!=it->s.end();it1++){
    			tt+=it1->s;
    		}
    		int lt=0;
    		for(auto it1=it->s.begin();it1!=it->s.end();it1++){
    			lt+=it1->s;
    			ll pw1=(((binpow(2,it1->s,MOD-1)-1)*(binpow(2,tt-lt,MOD-1)))+MOD-1)%(MOD-1);
    			ll ms=(it1->f*pw1)%(MOD-1);
    			as=(as*binpow(it->f,ms,MOD))%MOD;
    		}
    	}
    	cout<<as<<"\n";
    }
    return 0;
}

