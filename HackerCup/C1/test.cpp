#include <bits/stdc++.h>
#include <chrono>

using namespace std;

int main() {

	chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	chrono::steady_clock::time_point end = std::chrono::steady_clock::now();	
	
	long long t = 1000000000000;
	for (long long i = 0; i < t; i++) {
		//cout << i << "\n";
	}
	cout << "Time difference = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[µs]" << endl;
	cout << "Time difference = " << chrono::duration_cast<chrono::nanoseconds> (end - begin).count() << "[ns]" << endl;
	return 0;
}