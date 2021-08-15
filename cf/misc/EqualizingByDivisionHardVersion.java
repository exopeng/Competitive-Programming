import java.util.StringTokenizer;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;   
/* REMINDERS
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 */

public class EqualizingByDivisionHardVersion {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
//		final long startTime = System.currentTimeMillis();
		int elements = Integer.parseInt(s.nextToken());
		int[] arr = new int[elements];
		int neededEqual = Integer.parseInt(s.nextToken());
		s = new StringTokenizer(b.readLine());
		for (int i = 0; i < elements; i++) {
			arr[i] = Integer.parseInt(s.nextToken());
		}
		Arrays.sort(arr);
		//find upper bound number to check
		//upper bound is the length of array - k elements
		int upper = arr[arr.length - 1 - (neededEqual - 1)];
		
		ArrayList<Integer>[] facs = new ArrayList[arr.length];
		for (int i = 0; i < arr.length; i++) {
			facs[i] = new ArrayList<Integer>();
		}
		//then loop through every element and take the unique ones and put in array
		ArrayList<Integer> master = new ArrayList<Integer>();
		//find all factors of every single element, put in ArrayList
		for (int i = 0; i < arr.length; i++) {
			int toTrans = arr[i];
			while (toTrans != 0) {
				facs[i].add(toTrans);
				if (!master.contains(toTrans)) {
					master.add(toTrans);
				}
				toTrans /= 2;
			}
			facs[i].add(0);
			
		}
		master.add(0);
		
		Collections.sort(master);
		//ArrayListPrinter(master);
		int ans = 0;
		
		//for every element, see how many numbers factors contain it, and record the ops and fulfilled
		for (int i = 0; i < master.size(); i++) {
			int toCheck = master.get(i);
			//if toCheck is greater than the max of amount of needed elements, don't bother checking anymore
			if (toCheck > upper) {
				break;
			}
			int fulf = 0;
			int[] opsTal = new int[arr.length];
			for (int j = 0; j < facs.length; j++) {
				if (facs[j].contains(toCheck)) {
					opsTal[j] = facs[j].indexOf(toCheck);
					fulf++;
				} else {
					opsTal[j] = -1;
				}
			}
			//get highest ops, and erase it, as you only need a certain amount
			if (fulf >= neededEqual) {
				int ops = 0;
				//if more than needed, take out the numFulfilled - needed largest ops
				if (fulf > neededEqual) {
					Arrays.sort(opsTal);
					for (int f = arr.length - 1; f > arr.length - 1 - (fulf - neededEqual); f--) {
						opsTal[f] = -1;
					}
				} 
				//tally up the total ops
				for (int f = 0; f < arr.length; f++) {
					if (opsTal[f] > 0) {
						ops += opsTal[f];
					}
				}
				if (i == 0) {
					ans = ops;
				} else {
					ans = Math.min(ans, ops);
				}
				
			}
			
		}
		System.out.println(ans);
//		final long endTime = System.currentTimeMillis();
//		System.out.println("Total execution time: " + (endTime - startTime));
		p.close();

	}
	public static void ArrayListPrinter(ArrayList<Integer> array) {
		for (int i = 0; i < array.size(); i++) {
			System.out.print(array.get(i) + " ");
		}
		System.out.println();
	}

}
