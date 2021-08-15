#include <bits/stdc++.h>
using namespace std;
long long x,y;
string ans = "";
bool finished = false;
bool groupSum(long long currx, long long curry, long long moves, string seq, long long power) {
	if (currx == x && curry == y) {
		ans = seq;
		return true;
	}
  if (moves == 0) {
    if (currx == x && curry == y) {
    	ans = seq;
    	return true;
    }
    return false;
  }
  if (groupSum(currx + pow(2,power), curry, moves - 1, seq + "E", power + 1) || groupSum(currx - pow(2,power), curry, moves - 1, seq + "W", power+1) || groupSum(currx, curry + pow(2,power), moves - 1, seq + "N", power + 1) || groupSum(currx, curry - pow(2,power), moves - 1, seq + "S", power + 1)) {
      return true;
  }
  return false;
}
//void groupSum(long long currx, long long curry, long long moves, string seq, long long power) {
//	if (finished) {
//		return;
//	}
  // if (currx == x && curry == y) {
    //	ans = seq;
    //	finished = true;
    //	return;
    //}
    //if (moves == 0) {
    //	return;
    //}
  //groupSum(currx + pow(2,power), curry, moves - 1,seq + "E", power + 1);
  //groupSum(currx - pow(2,power), curry, moves - 1,seq + "W", power+1);
  //groupSum(currx, curry + pow(2,power), moves - 1,seq + "N", power + 1);
  //groupSum(currx, curry - pow(2,power), moves - 1,seq + "S", power + 1);
//}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	int counter = 1;
	while (t--) {
		finished = false;
		ans = "";
		cin >> x >> y;
		//error code
		double dist = ceil(pow(pow(x,2) + pow(y,2), 0.5));
		//cout << dist << "\n";
		//if perfect power of 2, then it's impossible
		//if (abs(x) == abs(y)) {
		//	cout << "Case #" << counter << ": " << "IMPOSSIBLE" << "\n";
		//	counter++;
		//	continue;
		//}
		//cout << ceil(log2(dist)) << floor(log2(dist)) << "\n";
		//cout << log2(dist + 1) << "\n"; 
		//eror code
		//long long moves = ceil(log2(ceil(dist) + 1));
		//cout << moves << "\n";
		//cout << moves;
		//backtrack to find sequence of moves
		string temp = "";
		//need upper bound on moves
		//long long moves = ceil(log2(1 + 2*abs(x)*2*abs(y)));
		long long moves = floor(log2(abs(x) + abs(y) + 1));
		groupSum(0,0,moves,temp,0);
		//groupSum(0,0,moves, temp,0);
		if (ans == "") {
			ans = "IMPOSSIBLE";
		}
		cout << "Case #" << counter << ": " << ans << "\n";
		counter++;
	}
}

