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
int n,a,b;
bool g[1000];
int fs[1000][21];
int us[21];
int cur[21];
void rec(int cu){
	if(cu<=0){
		return;
	}
	if(cur[cu]>0){
		cur[cu]--;
	}else{
		rec(cu-a);
		rec(cu-b);
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	cin>>n>>a>>b;
    	for(int j=0;j<21;j++){
    		cur[j]=0;
    	}
    	/*
    	for(int j=0;j<1000;j++){
    		for(int f=0;f<=20;f++){
    			fs[j][f]=0;
    		}
    	}
    	*/
    	for(int j=1;j<=n;j++){
    		cin>>us[j];
    	}
    	bool mt=true;
    	int ts=0;
    	for(int j=1;j<40;j++){
    		for(int f=1;f<=n;f++){
    			cur[f]=us[f];
    		}
    		rec(j);
    		bool gt=true;
    		for(int f=1;f<=n;f++){
    			if(cur[f]>0){
    				gt=false;
    			}
    		}
    		if(gt){
    			ts=j;
    			mt=false;
    			break;
    		}
    	}
    	cout<<"Case #"<<(i+1)<<": ";
    	if(!mt){
    		cout<<ts<<"\n";
    	}else{
    		cout<<"IMPOSSIBLE"<<"\n";
    	}
    }
    return 0;
}

