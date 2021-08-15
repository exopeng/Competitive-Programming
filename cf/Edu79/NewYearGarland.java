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

public class NewYearGarland {
	private static String path;
	private static int counter;
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int cases = Integer.parseInt(s.nextToken());
		//store the answers in a boolean array
		boolean[] ans = new boolean[cases];
		for (int i = 0; i < cases; i++) {
			s = new StringTokenizer(b.readLine());
			int red = Integer.parseInt(s.nextToken());
			int green = Integer.parseInt(s.nextToken());
			int blue = Integer.parseInt(s.nextToken());
			//sort the array
			int[] array = new int[] {red, green, blue};
			Arrays.sort(array);
			if (array[2] <= (array[1] + array[0]) + 1) {
				ans[i] = true;
			}
			
		}
		
		for (int i = 0; i < ans.length; i++) {
			if (ans[i]) {
				System.out.println("Yes");
			} else {
				System.out.println("No");
			}
		}
		p.close();
		

	}
	public static void ArrayPrinter(int[] array) {
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i] + " ");
		}
		System.out.println();
	}
	
	

}
