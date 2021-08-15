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
int gcd(int a,int b) {
   if(b==0)
   return a;
   return gcd(b,a%b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    map<char,int> oc;
    for(int i=0;i<s.size();i++){
        oc[s[i]]++;
    }
    int ov=0;
    for(auto it=oc.begin();it!=oc.end();it++){
        ov=gcd(ov,it->s);
    }
    if(ov==1){
        cout<<"IMPOSSIBLE"<<"\n";
    }else{
        s="";
        for(auto it=oc.begin();it!=oc.end();it++){
            for(int j=0;j<it->s/ov;j++){
                s+=it->f;
            }
        }
        string f;
        for(int j=0;j<ov;j++){
            f+=s;
        }
        cout<<f<<"\n";
    }
    return 0;
}

