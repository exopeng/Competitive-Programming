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
string x[4]={"Efficiency","Unbreaking","Silk","Touch"};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p,m;
    cin>>p>>m;
    //how many times said for this word
    int wct=0;
    //round number
    int rd=1;
    //current word to be said
    int cw=0;
    //current player
    int cp=1;
    //last word said
    string lw="";
    //last player
    int lp=0;
    //i represents how many words said
    for(int i=0;i<m;i++){
        wct++;
        lw=x[cw];
        //saying eff or unb
        if(cw<2){
            //said n words in the nth round
            if(wct==rd){
                cw++;
                wct=0;
            }
        }else{
            if(wct==2*rd){
                rd++;
                cw=0;
                wct=0;
            }else{
                //say touch
                if(wct%2){
                    cw=3;
                }else{
                    cw=2;
                }
            }
        }
        lp=cp;

        //cout<<lw<<" "<<lp<<"\n";
        cp++;
        if(cp==p+1){
            cp=1;
        }
    }
    cout<<lw<<"\n"<<lp<<"\n";
    return 0;
}

