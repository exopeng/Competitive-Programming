import java.io.*;
import java.util.*;



public class dreamoonranking {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int cases = Integer.parseInt(s.nextToken());
		//store the answers in an int array
		for (int i = 0; i < cases; i++) {
			s = new StringTokenizer(b.readLine());
			int n = Integer.parseInt(s.nextToken());
			int x = Integer.parseInt(s.nextToken());
			int[] a = new int[n];
			s = new StringTokenizer(b.readLine());
			for (int j = 0; j < n; j++) {
				a[j] = Integer.parseInt(s.nextToken());
				
			}
			Arrays.sort(a);
			int counter = 1;
			int counter1 = 0;
			long ans = 0;
			boolean finished = false;
			while (!finished) {
				while (counter1 < a.length && a[counter1] < counter) {
					counter1++;
				}
				if (counter1 >= a.length || a[counter1] != counter) {
					if (x == 0) {
						break;
					}
					x--;
				} 
				ans++;
				counter++;
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
