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

public class VerseForSantaPrefixSums {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int cases = Integer.parseInt(s.nextToken());
		int[] ans = new int[cases];
		
		for (int i = 0; i < cases; i++) {
			s = new StringTokenizer(b.readLine());
			int parts = Integer.parseInt(s.nextToken());
			int[] verses = new int[parts];
			int secs = Integer.parseInt(s.nextToken());
			s = new StringTokenizer(b.readLine());
			for (int j = 0; j < parts; j++) {
				verses[j] = Integer.parseInt(s.nextToken());
			}
			long sum = 0;
			for (int j = 0; j < parts; j++) {
				sum += verses[j];
			}
			if (sum <= secs) {
				ans[i] = 0;
			} else {
				//start by making prefix sums of the elements
				int[] prefices = prefix(verses);
				//find when it first equals or exceeds the limit
				for (int j = 0; j < prefices.length; j++) {
					if (prefices[j] > secs) {
						//find the max seconds verse before or equal to it
						ans[i] = maxVerse(j, verses) + 1;
						break;
					}
					if (prefices[j] == secs && j != prefices.length - 1) {
						//find the max seconds verse before or equal to it or after it 1 place
						ans[i] = maxVerse(j + 1, verses) + 1;
						break;
					}
					
				}
			}
			
			
		}
		
		for (int i = 0; i < ans.length; i++) {
			System.out.println(ans[i]);
		}
		p.close();
		

	}
	public static int maxVerse(int index, int[] array) {
		int max = 0;
		int desired = 0;
		for (int j = index; j > - 1; j--) {
			if (array[j] > max) {
				max = array[j];
				desired = j;
			}
		}
		return desired;
	}
	public static int[] prefix(int[] array) {
		int[] prefix = new int[array.length];
		prefix[0] = array[0];
		for (int i = 1; i < array.length; i++) {
			prefix[i] = array[i] + prefix[i - 1];
		}
		return prefix;
	}
	public static int presentsCounter(int[] array, int removalIndex, int limit) {
		int presentCounter = 0;
		int timeUsed = 0;
		for (int i = 0; i < array.length; i++) {
			
			if (i != removalIndex) {
				timeUsed += array[i];
				presentCounter++;
				if (timeUsed > limit) {
					presentCounter--;
					break;
				}
			}
		}
		return presentCounter;
	}
	public static void ArrayPrinter(int[] array) {
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i] + " ");
		}
		System.out.println();
	}
	
	

}
