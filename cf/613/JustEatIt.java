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


public class JustEatIt {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int cases = Integer.parseInt(s.nextToken());
		//store the answers in an int array
		for (int i = 0; i < cases; i++) {
			s = new StringTokenizer(b.readLine());
			int nums = Integer.parseInt(s.nextToken());
			s = new StringTokenizer(b.readLine());
			long[] arrZero = new long[nums - 1];
			long[] arrOne = new long[nums - 1];
			long y = 0;
			for (int j = 0; j < nums; j++) {
				//calc Yasser's val
				int input = Integer.parseInt(s.nextToken());
				if (j != nums - 1) {
					arrZero[j] = input;
				}
				if (j != 0) {
					arrOne[j - 1] = input;
				}
				y += input;
				
			}
			//ArrayPrinter(arrZero);
			//ArrayPrinter(arrOne);
			//feed it in Kadane's algo, and see if the max value is greater than Yasser's
			//special vase, subarray cannot be whole thing, so feed in 2 different subarrays
			//of indices [0, n - 2] and [1, n - 1]
			
			long zeroSum = maxSubArraySum(arrZero);
			long oneSum = maxSubArraySum(arrOne);
			
			if (zeroSum >= y || oneSum >= y) {
				p.println("NO");
			} else {
				p.println("YES");
			}
		}
		

		p.close();
		

	}
	public static long maxSubArraySum(long a[]) 
    { 
        int size = a.length; 
        long max_so_far = Integer.MIN_VALUE;
		long max_ending_here = 0; 
        //modify such that you can't take sum of whole array
        for (int i = 0; i < size; i++) 
        { 
            max_ending_here = max_ending_here + a[i]; 
            if (max_so_far < max_ending_here) 
                max_so_far = max_ending_here; 
            if (max_ending_here < 0) 
                max_ending_here = 0; 
        } 
        return max_so_far; 
    } 
	public static void ArrayPrinter(int[] array) {
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i] + " ");
		}
		System.out.println();
	}
	
	

}
