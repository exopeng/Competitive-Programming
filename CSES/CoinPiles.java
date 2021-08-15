import java.io.*;
import java.util.*;



public class CoinPiles {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int cases = Integer.parseInt(s.nextToken());
		//store the answers in an int array
		for (int i = 0; i < cases; i++) {
			String ans = "";
			s = new StringTokenizer(b.readLine());
			long a = Long.parseLong(s.nextToken());
			long b1 = Long.parseLong(s.nextToken());
			if (a < 2 && b1 < 2) {
				if (a == 0 && b1==0) {
					ans = "YES";
				} else {
					ans = "NO";
				}
			}  else {
				if (a == b1) {
					if (a % 2 == 0) {
						ans = "NO";
					} else {
						ans = "YES";
					}
				} else {
					double exact = Math.log(Math.max(a, b1)) / Math.log(2);
					long diff = Math.abs(a - b1);
					if (exact == diff) {
						ans = "YES";
					} else {
						ans = "NO";
					}
				}
			}
			p.println(ans);
			
		}
		p.close();
		

	}
	
	// you should actually read the stuff at the bottom

}
/* REMINDERS
 * PLANNING!!!!!!!! Concrete plan before code
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * NAIVE SOL FIRST
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 */
