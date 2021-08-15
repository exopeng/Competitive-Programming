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
string a[101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n;
    	cin>>n;
    	for(int j=0;j<n;j++){
    		cin>>a[j];
    	}
    	int as=0;
    	for(int j=1;j<n;j++){
    		//check lex order
    		 //   		cout<<a[j-1]<<" ";

    		if(a[j].size()>a[j-1].size()){
    			continue;
    		}
			if(a[j]==a[j-1]){
    			a[j]+="0";
    			as++;
    			continue;
    		}    		
    		if(a[j].size()==a[j-1].size()){
    			bool g=true;
    			for(int f=0;f<a[j].size();f++){
    				if(a[j][f]>a[j-1][f]){
    					g=false;
    					break;
    				}else if(a[j][f]<a[j-1][f]){
    					break;
    				}
    			}
    			if(!g){
    				continue;
    			}
    		}
    		int diff=a[j-1].size()-(a[j].size());
    		int ix=0;
    		while(a[j][ix]==a[j-1][ix]&&ix<a[j].size()){
    			ix++;
    		}
    		//substring
    		if(ix==a[j].size()){
    			//if not all nines
    			int ms=a[j-1].size()-1;
				while(a[j-1][ms]=='9'){
					ms--;
					if(ms<ix){
						break;
					}
				}
				if(ms<ix){
					as+=diff+1;
	    			for(int m=0;m<=diff;m++){
						a[j]+="0";
					}
				}else{
					as+=diff;
					int ns=(a[j-1][ms]-'0')+1;
					a[j]+=a[j-1].substr(ix,ms-ix)+to_string(ns);
					for(int m=0;m<a[j-1].size()-a[j].size();m++){
						a[j]+="0";
					}
				}
				continue;
    		}
    		if(a[j][ix]>a[j-1][ix]){
    			if(diff==0){
    				as++;
    				a[j]+="0";
    			}else{
    				as+=diff;
    				for(int m=0;m<diff;m++){
    					a[j]+="0";
    				}
    			}
    		}else{
    			as+=diff+1;
    			for(int m=0;m<=diff;m++){
					a[j]+="0";
				}
    		}
    	}
    	//cout<<a[n-1]<<"\n";
    	cout<<"Case #"<<(i+1)<<": "<<as<<"\n";
    }
    return 0;
}

