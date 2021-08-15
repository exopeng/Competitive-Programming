import java.io.*;
import java.util.*;



public class dreamoonpermutation {
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
			for (int j = 0; j < n; j++) {
				a[j] = Integer.parseInt(s.nextToken());
			}
			//check if possible to be any way
			int breakIndex = 0;
			boolean[] check = new boolean[200000];
			for (int j = 0; j < n; j++) {
				if (check[a[j]]) {
					if (checker(j, a.length - 1, a, n - j) && checker(0,j - 1, a, j)) {
						breakIndex = j;
						ans = 1;
					} else {
						ans = 0;
					}
					break;
				}
				check[a[j]] = true;
			}
			if (ans != 0) {
				//see if palindrome
				if (breakIndex != (double)(a.length / 2)) {
					if (pal(breakIndex,a)) {
						ans++;
					}
				}
				
			}
			if (ans == 0) {
				//try from the back
				reverse(a, a.length);
				check = new boolean[200000];
				for (int j = 0; j < n; j++) {
					if (check[a[j]]) {
						if (checker(j, a.length - 1, a, n - j) && checker(0,j - 1, a, j)) {
							breakIndex = j;
							ans = 1;
						} else {
							ans = 0;
						}
						break;
					}
					check[a[j]] = true;
				}
				if (ans == 1) {
					if (breakIndex != (double)(a.length / 2)) {
						if (pal(breakIndex,a)) {
							ans++;
						}
					}
					if (ans == 2) {
						p.println(ans);
						p.println(breakIndex + " " + Math.abs(breakIndex - a.length));
						p.println(Math.abs(breakIndex - a.length) + " " + breakIndex);
						
					} else {
						p.println(ans);
						p.println(Math.abs(breakIndex - a.length) + " " + breakIndex );
					}
				} else {
					p.println(ans);
				}
			} else {
				if (ans == 2) {
					p.println(ans);
					p.println(Math.abs(breakIndex - a.length) + " " + breakIndex);
					p.println(breakIndex + " " + Math.abs(breakIndex - a.length));
				} else {
					p.println(ans);
					p.println(breakIndex + " " + Math.abs(breakIndex - a.length));
				}
			}
			
		}
		p.close();
		

	}
	static void reverse(int a[], int n) 
    { 
		for(int i=0; i<a.length/2; i++){ int temp = a[i]; a[i] = a[a.length -i -1]; a[a.length -i -1] = temp; }

    } 
	public static boolean pal(int index, int[] arr) {
		boolean[] n = new boolean[200000];
		for (int j = arr.length - 1; j >= index; j--) {
			n[arr[j]] = true;
		}
		for (int j = 0; j < arr.length - index; j++) {
			if (!n[arr[j]]) {
				return false;
			}
		}
		return true;
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
