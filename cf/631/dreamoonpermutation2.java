import java.io.*;
import java.util.*;



public class dreamoonpermutation2 {
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
			long ans = 0;
			int[] a = new int[n];
			s = new StringTokenizer(b.readLine());
			int max = 0;
			for (int j = 0; j < n; j++) {
				a[j] = Integer.parseInt(s.nextToken());
				max = Math.max(max, a[j]);
			}
			String mes = "";
			if (checker(0, max - 1, a, max) && checker(max, a.length - 1, a, a.length - max)) {
				ans++;
				mes += (max + " " + (a.length - max));
			} 
			if (!(ans == 1 && max == (double)(a.length / 2))) {
				if (checker(0, a.length - max - 1, a, a.length - max) && checker(a.length - max, a.length - 1, a, max)) {
					
					if (ans == 1) {
						mes += ("\n" + (a.length - max) + " " + max);	
					} else {
						mes += ((a.length - max) + " " + max);	

					}
					ans++;
				}
			}
			/*
			 * if () { reverse(a,a.length); if (checker(0, max - 1, a, max) && checker(max,
			 * a.length - 1, a, a.length - max)) { ans++; mes += ((a.length - max) + " " +
			 * max ); } else if (checker(0, a.length - max - 1, a, a.length - max) &&
			 * checker(a.length - max, a.length - 1, a, max)) { ans++; mes += ((a.length -
			 * max) + " " + max);
			 * 
			 * } }
			 */
			 
			p.println(ans);
			if (ans != 0) {
				p.println(mes);

			}
		}
		p.close();
		

	}
	static void reverse(int a[], int n) 
    { 
		for(int i=0; i<a.length/2; i++){ int temp = a[i]; a[i] = a[a.length -i -1]; a[a.length -i -1] = temp; }

    } 
	public static boolean checker(int index, int end, int[] arr, int toReach) {
		boolean[] check = new boolean[200000];
		int ans = 0;
		for (int j = index; j <= end; j++) {
			if (arr[j] > toReach) {
				return false;
			}
			if (check[arr[j]]) {
				return false;
			}
			check[arr[j]] = true;
			ans++;
		}
		if (ans == toReach) {
			return true;
		}
		return false;
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
