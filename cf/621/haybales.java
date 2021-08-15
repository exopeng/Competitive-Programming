import java.io.*;
import java.util.*;



public class haybales {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int cases = Integer.parseInt(s.nextToken());
		//store the answers in an int array
		for (int i = 0; i < cases; i++) {
			long ans = 0;
			s = new StringTokenizer(b.readLine());
			int[] bales = new int[Integer.parseInt(s.nextToken())];
			int days = Integer.parseInt(s.nextToken());
			s = new StringTokenizer(b.readLine());
			for (int j = 0; j < bales.length; j++) {
				bales[j] = Integer.parseInt(s.nextToken());
			}
			
			//loop through every haybale until days = 0
			for (int j = 0; j < bales.length; j++) {
				int max = bales[j];
				if (j != 0) {
					max = days / j;
				}
				if (bales[j] <= max) {
					ans += bales[j];
					days -= j * bales[j];
				} else {
					ans += max;
					days -= j * max;
				}
				
				if (days < j + 1) {
					break;
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
