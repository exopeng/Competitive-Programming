import java.io.*;
import java.util.*;
/* REMINDERS
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 */


public class MezoPlayingZoma {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		long ans = 0;
		int numOfcomms = Integer.parseInt(s.nextToken());
		s = new StringTokenizer(b.readLine());
		String comms = s.nextToken();
		//count the number of R's
		int rCount = 0;
		//count the number of L's
				int lCount = 0;
		for (int i = 0; i < comms.length(); i++) {
			if (comms.charAt(i) == 'L') {
				lCount++;
			} else {
				rCount++;
			}
		}
		
		ans = 1 + rCount + lCount;
		
		
		p.println(ans);
		p.close();
		

	}
	
	

}
