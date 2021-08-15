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
const long long INF = 2e9;
const long long MOD = 1e9+7;
const int MAXN = 2e5;
//store test cases here
/*


*/
string nt(ll st){
    string s;
    while(st!=0){
        s+=to_string(st%2);
        st/=2;
    }
    reverse(s.begin(),s.end());
    if(s.size()==0){
        return "1";
    }
    string ret;
    for(int j=0;j<s.size();j++){
        if(s[j]=='1'){
            ret+="0";
        }else{
            ret+="1";
        }
    }
    for(int j=0;j<ret.size();j++){
        if(ret[j]=='1'){
            return ret.substr(j,ret.size()-j);
        }
    }
    return "0";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s,e;
        cin>>s>>e;
        int rs=0;
        int re=0;
        reverse(s.begin(),s.end()),reverse(e.begin(),e.end());
        for(int j=0;j<s.size();j++){
            if(s[j]=='1'){
                rs+=pow(2,j);
            }
        }
        for(int j=0;j<e.size();j++){
            if(e[j]=='1'){
                re+=pow(2,j);
            }
        }
        map<ll,int> dp;
        dp[rs]=0;
        queue<ll> q;
        q.push(rs);
        while(!q.empty()){
            ll cu=q.front();
            q.pop();
            string mt=nt(cu);
            ll ct=0;
            for(int j=0;j<mt.size();j++){
                if(mt[j]=='1'){
                    ct+=pow(2,mt.size()-1-j);
                }
            }
            ll cl=cu*2;
            if(ct<INF){
                if(dp.find(ct)==dp.end()){
                    dp[ct]=dp[cu]+1;
                    q.push(ct);
                }
                if(ct==re){
                    break;
                }
            }
            if(cl<INF){
                if(dp.find(cl)==dp.end()){
                    dp[cl]=dp[cu]+1;
                    q.push(cl);
                }
                if(cl==re){
                    break;
                }
            }
        }
        cout<<"Case #"<<(i+1)<<": ";
        if(dp.find(re)!=dp.end()){
            cout<<dp[re]<<"\n";
        }else{
            cout<<"IMPOSSIBLE"<<"\n";
        }
    }
    return 0;
}

