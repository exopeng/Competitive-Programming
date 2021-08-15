import java.io.*;
import java.util.*;


public class pascal {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int cases = Integer.parseInt(s.nextToken());
		//store the answers in an int array
		for (int i = 0; i < cases; i++) {
			s = new StringTokenizer(b.readLine());
			String ans = "";
			int n = Integer.parseInt(s.nextToken());
			//guaranteed n
			String steps = baseConverter(n, 2);
			
			p.print("Case #" + (i+1) + ":" + "\n" + ans);
		}
		p.close();
		

	}
	
	public static String baseConverter(long number, int base) {
		char[] charSet = new char[base];
		for (int i = 0; i < charSet.length; i++) {
			switch (i) {
				case 10:
					charSet[i] = 'A';
					break;
				case 11:
					charSet[i] = 'B';
					break;
				case 12:
					charSet[i] = 'C';
					break;
				case 13:
					charSet[i] = 'D';
					break;
				case 14:
					charSet[i] = 'E';
					break;
				case 15:
					charSet[i] = 'F';
					break;
				case 16:
					charSet[i] = 'G';
					break;
				case 17:
					charSet[i] = 'H';
					break;
				case 18:
					charSet[i] = 'I';
					break;
				case 19:
					charSet[i] = 'J';
					break;
				default:
					charSet[i] = (char)(i + '0');
					
			}
		}
		int power = 0;
		String baseRepresentation = "";
		boolean greater = true;
		while (greater) {
			power++;
			if (!(number >= Math.pow(base, power))) {
				power--;
				greater = false;
			}
		}
		while (power != -1) {
			int counter = 0;
			while (number >= Math.pow(base, power)) {
				number -= Math.pow(base, power);
				counter++;
			}
			baseRepresentation += String.valueOf(charSet[counter]);
			power--;
		
		}
		return baseRepresentation;
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
