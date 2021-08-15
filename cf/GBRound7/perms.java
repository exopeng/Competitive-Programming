import java.io.*;
import java.util.*;



public class perms {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int len = Integer.parseInt(s.nextToken());
		int[] perm = new int[len];
		int k = Integer.parseInt(s.nextToken());
		s = new StringTokenizer(b.readLine());
		long sum =  0;	
		//put them back in the original positions
		for (int i = 0; i < len; i++) {
			perm[i] = Integer.parseInt(s.nextToken());
		}
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		ArrayList<Integer> li = new ArrayList<Integer>();
		long counter = 1;
		for (int j = 0; j < perm.length; j++) {
			if (perm[j] >= (len - (k-1)) && perm[j] <= len) {
				li.add(perm[j]);
				map.put(perm[j], j);
				sum += perm[j];
			}
		}
		
		for (int i = 1; i < li.size(); i++) {
			counter *= (map.get(li.get(i)) - map.get(li.get(i - 1)));
			counter %= 998244353;
		}
		p.println(sum + " " + counter % 998244353);
		
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
