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
const int MAXN = 3e5;
//store test cases here
/*


*/
int t[4*MAXN][2];
int arr[MAXN];
void build(int curr,int l,int r,bool ts){
	if(l==r){
		t[curr][ts]=arr[l];
	}else{
		int mid=(r+l)/2;
		build(curr*2,l,mid,ts);
		build(curr*2+1,mid+1,r,ts);
		if(ts){
			t[curr][ts]=min(t[curr*2][ts],t[curr*2+1][ts]);
		}else{
			t[curr][ts]=max(t[curr*2][ts],t[curr*2+1][ts]);
		}
	}
}
int sum(int curr,int tl,int tr,int l,int r,bool ts){
	if(l>r){
        if(ts){
            return INF;
        }else{
            return -1*INF;
        }
	}
	if(l==tl&&r==tr){
		return t[curr][ts];
	}
	int mid=(tl+tr)/2;
	if(ts){
		return min(sum(curr*2,tl,mid,l,min(r,mid),ts),sum(curr*2+1,mid+1,tr,max(l,mid+1),r,ts));
	}else{
		return max(sum(curr*2,tl,mid,l,min(r,mid),ts),sum(curr*2+1,mid+1,tr,max(l,mid+1),r,ts));
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n,m;
        string s;
    	cin>>n>>m>>s;
    	for(int j=1;j<=n;j++){
            char a=s[j-1];
    		if(a=='-'){
    			arr[j]=arr[j-1]-1;
    		}else{
    			arr[j]=arr[j-1]+1;
    		}
    	}
    	build(1,0,n,true);
    	build(1,0,n,false);
    	for(int j=0;j<m;j++){
    		int a,b;
    		cin>>a>>b;
    		int l1=0,l2=0,r1=0,r2=0;
    		l1=sum(1,0,n,0,a-1,true);
            r1=sum(1,0,n,0,a-1,false);
    		l2=sum(1,0,n,b+1,n,true);
            r2=sum(1,0,n,b+1,n,false);
    		if(b==n){
                cout<<abs(r1-l1)+1;
            }else{
                vector<int> at;
                l2-=arr[b]-arr[a-1],r2-=arr[b]-arr[a-1];
                at.pb(l2),at.pb(l1),at.pb(r2),at.pb(r1);
                sort(at.begin(),at.end());
                cout<<abs(at[3]-at[0])+1;
            }
            cout<<"\n";
    	}
    }

    return 0;
}

