
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;   


/* REMINDERS
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 */
public class KolyaTandemRepeat {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		
		//start with each length, from 1 to size, then see if the rest match it and add characters
		//record length
		String str = s.nextToken();
		s = new StringTokenizer(b.readLine());
		int chars = Integer.parseInt(s.nextToken());
		//"-" denotes an extra character
		String extras = "";
		for (int i = 0; i < chars; i++) {
			extras += "-";
		}
		
		int len = 0;
		int i = str.length() + chars;
		//make the 2N even
		while (i % 2 == 1) {
			i--;
		}
		String newStr = (str + extras);
		//increment pointer(start and end) and length of string
		while (i > 1) {
			//start with tandem repeat N, greatest possible
			int n = i / 2;
			//then check for all positions
			int start = 0;
			int end = i;
			while (end <= newStr.length() && i > 1) {
				String curr = newStr.substring(start, end);
				//check if it fulfills a tandem repeat
				for (int j = 0; j < (curr.length() / 2); j++) {
					//if it doesn't break
					if (!(curr.charAt(j) == curr.charAt((j + (n))) || curr.charAt(j + (n)) == '-')) {
						break;
					}
					if (j == (curr.length() / 2) - 1) {
						len = curr.length();
						i = 1;
					}
				}
				start++;
				end++;
			}
			i -= 2;
		}
		System.out.println(len);
		
		p.close();
		

	}
	
	

}
