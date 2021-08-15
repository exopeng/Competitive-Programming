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
const int MAXN = 2e5+100;
//store test cases here
/*


*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        map<char,int> ct;
        for(int j=0;j<s.size();j++){
            ct[s[j]]++;
        }
        ll init=ct.begin()->s;
        //cout<<init;
        ll f=1;
        ll tot=s.size()-init;
        while(tot*(f-1)<init-f){
            f++;
        }
        for(int j=0;j<f;j++){
            cout<<ct.begin()->f;
        }
        ll lt=init-f;
        for(int j=0;j<s.size()-f;j++){
            if(lt){
                if(j%(f)){
                    cout<<ct.begin()->f;
                    lt--;
                }else{
                    cout<<s[init];
                    init++;
                }
            }else{
                cout<<s[init];
                init++;
            }
        }
        cout<<'\n';
    }
    return 0;
}

