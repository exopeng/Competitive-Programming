import java.io.*;
import java.util.*;



public class Solution {
	public static int[] lTally;
	public static int[] rTally;
	public static int[] nums;
	public static void main(String[] args) throws IOException {
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int cases = Integer.parseInt(s.nextToken());
		//store the answers in an int array
		for (int i = 0; i < cases; i++) {
			s = new StringTokenizer(b.readLine());
			String fin = s.nextToken();
			rTally = new int[fin.length()];
			lTally = new int[fin.length()];
			nums = new int[fin.length()];
			for (int j = 0; j < fin.length(); j++) {
				nums[j] = Integer.parseInt(fin.substring(j, j+1));
			}
			int currElement = 0;
			int elementIndex = 0;
			for (int j = 0; j < fin.length(); j++) {
				if (fin.charAt(j) =='(' || fin.charAt(j) ==')') {
					continue;
				}
				fin = extendLeft(fin, Integer.parseInt(fin.substring(j,j+1)), j, elementIndex);
				while (fin.charAt(j) == ')' || fin.charAt(j) == '(') {
					j++;
				}
				fin = extendRight(fin, Integer.parseInt(fin.substring(j,j+1)), j, elementIndex);
				elementIndex++;
				lTally = Arrays.copyOf(rTally, rTally.length);
			}
			
			p.println("Case #" + (i + 1) + ": " +  fin);
		}
		p.close();
	}
	public static String extendRight(String str, int currElement, int strIndex, int elementIndex) {
		if (rTally[elementIndex] == currElement) {
			return str;
		}
		int parens = currElement - rTally[elementIndex];
		for (int i = strIndex; i < str.length(); i++) {
			//if were on the last element
			if (str.charAt(i) == '(' || str.charAt(i) == ')') {
				continue;
			}
			rTally[elementIndex] += parens;
			if (elementIndex == rTally.length - 1) {
				return endParenAdder(str, parens, i);
			}
			//check if the next element has enough, if it doesn't require all of it, add to the current one now
			elementIndex++;
			int needed = nums[elementIndex] - rTally[elementIndex];
			//if the next element doesn't need any more parentheses, stop, if it needs a few more, add the rest to the current one and then parens = needed
			if (needed < parens) {
				//should i comment this?
				//rTally[elementIndex] += needed;
				//even if it can only take a few, the few can keep going on
				str = endParenAdder(str, parens - needed , i);
				parens = needed;
			}
		}
		return str;
		
	}
	public static String extendLeft(String str, int currElement, int strIndex, int elementIndex) {
		if (lTally[elementIndex] == currElement) {
			return str;
		}
		int parens = currElement - lTally[elementIndex];
		for (int i = strIndex; i > -1; i--) {
			//if were on the last element
			if (str.charAt(i) == '(' || str.charAt(i) == ')') {
				continue;
			}
			lTally[elementIndex] += parens;
			if (elementIndex == 0) {
				return startParenAdder(str, parens, i - 1);
			}
			
			elementIndex--;
			int needed = nums[elementIndex] - lTally[elementIndex];
			if (needed < parens) {
				str = startParenAdder(str, parens - needed , i - 1);
				parens = needed;
			}
		}
		return str;
	}
	public static String startParenAdder(String str, int num, int start) {
		String startPar = "";
		for (int i = 0; i < num; i++) {
			startPar += "(";
		}
		str = str.substring(0, start + 1) + startPar + str.substring(start + 1);
		return str;
	}
	public static String endParenAdder(String str, int num, int start) {
		String endPar = "";
		for (int i = 0; i < num; i++) {
			endPar += ")";
		}
		str = str.substring(0, start + 1) + endPar + str.substring(start + 1);
		return str;
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
