import java.io.*;
import java.util.*;



public class badUglyNums3 {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int cases = Integer.parseInt(s.nextToken());
		//store the answers in an int array
		int[] arr = new int[100000];
		
		for (int i = 0; i < cases; i++) {
			long ans = 0;
			s = new StringTokenizer(b.readLine());
			int digits = Integer.parseInt(s.nextToken());
			
			if (digits == 1) {
				p.println(-1);
			} else {
				String temp = "23";
				for (int j = 3; j <= digits; j++) {
					temp += "" + 3;
				}
				p.println(temp);
			}
			
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
