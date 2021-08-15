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
int dp[MAXN][26];
int n[MAXN];
int s[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string st;
    cin>>st;
    for(int i=0;i<st.size();i++){
        s[i]=st[i]-'a';
    }
    for(int i=0;i<MAXN;i++){
        n[i]=-1;
        for(int j=0;j<26;j++){
            dp[i][j]=INF;
        }
    }
    //97
    map<char,int> lt;
    for(int i=st.size()-1;i>-1;i--){
        if(lt.find(s[i])==lt.end()){
            lt[s[i]]=i;
        }else{
            n[i]=lt[s[i]];
            lt[s[i]]=i;
        }
    }
    for(int i=0;i<st.size();i++){
        if(n[i]!=-1){
            if(i==0){
                dp[n[i]][s[i]]=min(dp[n[i]][s[i]],1);
            }else{
                dp[n[i]][s[i]]=min(dp[n[i]][s[i]],dp[i-1][s[i-1]]+1);
            }
        }
        if(i==0){
            dp[i][s[i]]=1;
        }
        if(i!=st.size()-1){
            dp[i+1][s[i+1]]=min(dp[i+1][s[i+1]],dp[i][s[i]]+1);
        }
        for(int j=0;j<26;j++){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
        }
    }
    cout<<dp[st.size()-1][s[st.size()-1]]<<"\n";
    return 0;
}

