#include<bits/stdc++.h>
using namespace std;
#define int long long

//set<int> xs, ys;
int n;
vector<array<int, 2>> points;

const double eps = 1e-6;

double getslope(double sx, double sy, double fx, double fy){
    if (fx - sx == 0){
        return (1e9+5);
    }
    return (fy - sy) / (fx - sx + 0.0);
}

signed main(){
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; i++){
        cin >> points[i][0] >> points[i][1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){ // line from points i to points j
            int startx = points[i][0];
            int starty = points[i][1];
            int finishx = points[j][0];
            int finishy = points[j][1];
            int cnt = 0;
            for (int k = 0; k < n; k++){
                int curx = points[k][0], cury = points[k][1];
                if (k==i || k==j) cnt++; // endpoints of the line
                else if(getslope(startx, starty, finishx, finishy) - getslope(curx, cury, finishx, finishy)==0) cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    if(ans<1){
        cout<<1<<'\n';
    }else{
        cout<<ans<<'\n';
    }
}