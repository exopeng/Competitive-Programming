import java.io.*;
import java.util.*;



public class Maximums {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int len = Integer.parseInt(s.nextToken());
		int[] bs = new int[len];
		s = new StringTokenizer(b.readLine());
		for (int i = 0; i < len; i++) {
			bs[i] = Integer.parseInt(s.nextToken());
		}
		int[] x = new int[len];
		int[] a = new int[len];
		a[0] = bs[0];
		int max = a[0];
		for (int i = 1; i < len; i++) {
			if (max > a[i - 1]) {
				x[i] = max;
			} else {
				x[i] = a[i - 1];
				max = a[i - 1];
			}
			a[i] = bs[i] + x[i];
		}
		
		for (int i = 0; i < a.length; i++) {
			p.print(a[i]);
			if (i != a.length - 1) {
				p.print(" ");
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
