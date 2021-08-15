#include <bits/stdc++.h>

using namespace std;
int n;
ll gcd(ll a,ll b) {
   if(b==0)
   return a;
   return gcd(b,a%b);
}
//prime factorization in log(n) with sqrtn space compleixty
vector<int> p;
vector<int> ip(n+1,true);
ip[0]=ip[1]=false;
for(int i=2;i<=n;i++){
    if(ip[i]&&(ll)i*i<=n){
        for(int j=i*i;j<=n;j+=i)
            ip[j]=false;
    }
    if(ip[i]){
        p.pb(i);
    }
}
for(ll d:p){
    int ct=0;
    if(d*d>a[j])
        break;
    while(a[j]%d==0){
        ct++;
        a[j]/=d;
    }
    if(ct){
        ps.pb(mp(d,ct));
    }
}
if(a[j]!=1){
    ps.pb(mp(a[j],1));
}
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


