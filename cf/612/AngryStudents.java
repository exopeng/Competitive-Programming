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


public class AngryStudents {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int cases = Integer.parseInt(s.nextToken());
		//store the answers in an int array
		int[] ans = new int[cases];
		for (int i = 0; i < cases; i++) {
			s = new StringTokenizer(b.readLine());
			int students = Integer.parseInt(s.nextToken());
			char[] arr = new char[students];
			s = new StringTokenizer(b.readLine());
			String input = s.nextToken();
			for (int j = 0; j < students; j++) {
				arr[j] = input.charAt(j);
			}
			//ArrayPrinter(arr);
			//while loop
			int counter = -1;
			char[] test = arr.clone();
			do {
				arr = test.clone();
				//make every angry person up to length - 2 throw snowball
				for (int j = 0; j < arr.length - 1; j++) {
					if (arr[j] == 'A') {
						test[j + 1] = 'A';
					}
				}
				counter++;
			} while (!Arrays.equals(test, arr));
			p.println(counter);
			
		}
		
		
		p.close();
		

	}
	public static void ArrayPrinter(char[] array) {
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i] + " ");
		}
		System.out.println();
	}
	
	

}
