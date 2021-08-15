#include <bits/stdc++.h>
using namespace std;

//store test cases here
/*


*/

int s,ra,pa,rb,pb,c;
bool taken[37][37];
int dfs(int i,int j) {
    if (i > s || j > i*2-1 || i < 1 || j < 1 ) {
        return 0;
    }
    if (taken[i][j]) {
        return 0;
    }
    int x=0;
    int y=0;
    int z=0;
    int d=0;
    taken[i][j]=true;
    if (j % 2 == 0) {
        x = dfs(i-1,j-1);
    } else {
        //down
        y = dfs(i+1,j+1);
    } 
    //right
    z = dfs(i,j-1);
    //left
    d = dfs(i,j+1);
    x = max(x,y);
    x = max(x,z);
    x = max(x,d);
    taken[i][j] = false;
    return 1 + x;
}
int rec(int i,int j,int k,int f, int turn) {
    //cout << "i: " << i << " j: " << j << " k: " << k << " f: " << f << " turn: " << turn << "\n";
    //check if you already visited that state
    if (i > s || j > i*2-1 || k > s || f > k*2-1 || i < 1 || j < 1 || k < 1 || f < 1) {
        if (turn == 0) {
            return -100;
        } 
        return 100;
    }
    if (turn == 0 && taken[i][j] == true ) {
        return -100;
    }
    if (turn == 1 && taken[k][f] == true) {
        return 100;
    }

    if (turn == 0) {
        taken[i][j] = true;
    } else {
        taken[k][f] = true;
    }
    //mark lost cause as visited
    if (turn ==0) {
        int x = 100;
        int y = 100;
        int z = 100;
        int d = 100;
        if (f % 2 == 0) {
            x = rec(i,j,k-1,f-1,1);
        } else {
            //down
            y = rec(i,j,k+1,f+1,1);
        } 
        //right
        z = rec(i,j,k,f+1,1);
        //left
        d = rec(i,j,k,f-1,1);
        taken[i][j] = false;
        if (x == 100 && y == 100 && z == 100 && d == 100) {
            //dfs
            x = dfs(i,j);
            return x;
        }
        //when it comes to b's turn, it will give the least answer
        if (x <= y && x <= z && x <= d) {
            return x+1;
        } 
        if (y <= x && y <= z && y <= d) {
            return y+1;
        }
        if (z <= x && z <= d && z <= y) {
            return z+1;
        }
        return d+1;
    } else {
        int x = -100;
        int y = -100;
        int z = -100;
        int d = -100;
        if (j % 2 == 0) {
            x = rec(i-1,j-1,k,f,0);
        } else {
            //down
            y = rec(i+1,j+1,k,f,0);
        } 
        //right
        z = rec(i,j+1,k,f,0);
        //left
        d = rec(i,j-1,k,f,0);
        taken[k][f] = false;
        if (x == -100 && y == -100 && z == -100 && d == -100) {
            //dfs
            x = dfs(k,f);
            return -1*x;
        }
        if (x >= y && x >= z && x >= d) {
            return x-1;
        } 
        if (y >= x && y >= z && y >= d) {
            return y-1;
        }
        if (z >= x && z >= d && z >= y) {
            return z-1;
        }
        return d-1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ti;
    cin >> ti;
    int l = ti;

    while (ti--) {
        //reset stuff
        for (int i = 0; i < 37; i++) {
            for (int j= 0;j < 37; j++) {
                taken[i][j]=false;
            }
        }
        cin >> s >> ra >> pa >> rb >> pb >> c;

        for (int i = 0; i < c; i++) {
            int a,b;
            cin >> a >> b;
            taken[a][b] = true;
        }

        taken[ra][pa]=true;
    	cout << "Case #" << (l-ti) << ": " << 1 + rec(ra,pa,rb,pb,1)  << "\n";
    }
}
/* REMINDERS
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * PLANNING!!!!!!!! Concrete plan before code
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * IF CAN'T FIGURE ANYTHING OUT, MAKE TEN TEST CASES TO EVALUATE ALL TYPES OF SCENARIOS, THEN CONSTRUCT SOLUTION TO FIT IT
 * NAIVE SOL FIRST TO CHECK AGAINST OPTIMIZED SOL
 * MOD OUT EVERY STEP
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */

