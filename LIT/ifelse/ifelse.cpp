#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
 

//store test cases here
/*


*/ 
long long ans = 0;
string arr[100];
bool yes[100];
ifstream in("ifelse.in");

unordered_set<string> taken;

vector<string> gl() {
    vector<string> ln;
    string line;
    if (getline(in, line)) {
      // Parse the line using a string stream
      istringstream row(line);
      string field;
      while (row>> field)
        ln.push_back(field);
    }
    return ln;
}

void paren();

void check() {    
    vector<string> temp = gl();
    if (temp[0] == "output") {
        for (int i = 1; i < temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << "\n";
        return;
    }
    string c = temp[3];
    if (taken.find(c) != taken.end()) {
        check();
    } else {
        paren();
        //get to next line that has parentheses, line after that
    } 
}
void paren() {
    int ct = 0;
    while (true) {
        vector<string> temp = gl();
        if (temp[0] == "IF") {
            ct+=2;
            //end statement
        } else if (temp[0] == ")" && ct == 0) {
            check();
            break;
        } else if (temp[0] == ")") {
            ct--;
        } 
    }
}
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);

    int n;
    vector<string> temp = gl();
    n = stoi(temp[0]);
    temp = gl();
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
        //cout << arr[i] << "\n";
    }

    temp = gl();
    for (int i = 0; i < n; i++) {
        int a = (int)(temp[0][i]);
        if (a) {
            taken.insert(arr[i]);
        }
    }
    check();
    return 0;
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
 * IF ALL ELSE FAILS, DO CASEWORK
 * compile with "g++ -std=c++11 filename.cpp" if using auto keyword
 */
