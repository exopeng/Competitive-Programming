import java.util.StringTokenizer;
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


/* REMINDERS
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 */
public class AzamonWebServicesCorrect {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer st = new StringTokenizer(b.readLine());
		int cases = Integer.parseInt(st.nextToken());
		for (int i = 0; i < cases; i++) {
			String ans = "";
			st = new StringTokenizer(b.readLine());
			String s = st.nextToken();
			String c = st.nextToken();
			
			//important note, even if s and c are equal, it doesn't mean that it is impossible
			//See AzamonWebServices for more info
			
			boolean found = false;
			if (s.compareTo(c) < 0) {
				ans = s;
				found = true;
			}
			if (!found) {
				//sort s
				char[] sortS = s.toCharArray();
				Arrays.sort(sortS);
				//check to make sure if s is already sorted, if it is, then compare
				for (int j = 0; j < s.length(); j++) {
					if (s.charAt(j) != sortS[j]) {
						break;
					}
					//if its already sorted
					if (j == s.length() - 1) {
						found = true;
						if (s.compareTo(c) < 0) {
							ans = s;
						}
						if (s.compareTo(c) >= 0) {
							ans = "---";
						}
	 				}
				}
				//then find first occurence where s and sortS doesn't match
				if (!found) {
					for (int j = 0; j < s.length(); j++) {
						if (sortS[j] != s.charAt(j)) {
							//find where the letter should be at s
							for (int f = s.length() - 1; f > j; f--) {
								if (s.charAt(f) == sortS[j]) {
									String newStr = replace(s, j, f);
									//then compare to see if it works, if it doesn't then it is impossible
									if (newStr.compareTo(c) < 0) {
										ans = newStr;
									} else {
										ans = "---";
									}
									break;
								}
							}
							break;
						}
					}
				}
			}
			
			
			
			System.out.println(ans);
			
		}
		p.close();
	}
	public static void ArrayPrinter(char[] array) {
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i] + " ");
		}
		System.out.println();
	}
	public static String replace(String str, int index1, int index2) {
		String newStr = "";
		String swap1 = str.substring(index1, index1 + 1);
		String swap2 = str.substring(index2, index2 + 1);
		
		for (int i = 0; i < str.length(); i++) {
			if (i == index1) {
				newStr += swap2;
			}
			if (i == index2) {
				newStr += swap1;
			}
			if (i != index2 && i != index1) {
				newStr += str.substring(i, i + 1);
			}
		}
		
		
		return newStr;
	}
	
	

}
