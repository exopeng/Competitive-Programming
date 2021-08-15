#include <bits/stdc++.h>

using namespace std;
long long ans = 0;
int n;
int arr[1000][1000];
bool visited[1000][1000];
int vals[1000][1000];
int maxv = -1;
void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vals[i][j] = 0;
        }
    }
    maxv = -1;
}
bool dfs(int i, int j, int lasti, int lastj, int target) {
    if (i >= n || i < 0 || j >= n || j < 0) {
        return false;
    }
    if (arr[i][j] < arr[lasti][lastj]) {
        return false;
    }
    //
    if (visited[i][j] && arr[i][j] == target) {
        return true;
    }
    visited[i][j] = true;
    //even if it is greater, it might be able to hold water
    if (arr[i][j] > arr[lasti][lastj]) {
        //small = min(small, arr[i][j]);
        if (dfs(i+1,j,i,j, target) && dfs(i-1,j,i,j,target) && dfs(i,j+1,i,j,target) && dfs(i,j-1,i,j,target)) {
            vals[i][j] = -1;
        }
        return true;
    }
    if (!dfs(i+1,j,i,j, target) || !dfs(i-1,j,i,j,target) || !dfs(i,j+1,i,j,target) || !dfs(i,j-1,i,j,target)) {
        return false;
    }
    vals[i][j] = -1;
    return true;
}
void label1(int i,int j) {
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            if (vals[i][j] == -1) {
                if (vals[i+1][j] == 0) {
                    maxv = max(maxv, arr[i][j]);
                }
                if (vals[i-1][j] == 0) {
                    maxv = max(maxv, arr[i][j]);
                }
                if (vals[i][j+1] == 0) {
                    maxv = max(maxv, arr[i][j]);
                }
                if (vals[i][j-1] == 0) {
                    maxv = max(maxv, arr[i][j]);
                }
            }
        }   
    }
}
void label(int i, int j, int num) {
    if (i >= n || i < 0 || j >= n || j < 0) {
        return;
    }
    if (vals[i][j] != -1) {
        return;
    }
    vals[i][j] = maxv - arr[i][j];
    label(i+1,j,num);
    label(i-1,j,num);
    label(i,j+1,num);
    label(i,j-1,num);
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            if (!visited[i][j]) {
                reset();
                if (dfs(i,j,i,j,arr[i][j])) {
                    label1(i,j);
                    label(i,j,arr[i][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += vals[i][j];
        }
    }

    cout << ans << "\n";
}
/* REMINDERS
 * PLANNING!!!!!!!! Concrete plan before code
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * NAIVE SOL FIRST TO CHECK AGAINST OPTIMIZED SOL
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 */

