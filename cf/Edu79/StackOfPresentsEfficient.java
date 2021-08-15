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
import java.util.HashMap;   

public class StackOfPresentsEfficient {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int cases = Integer.parseInt(s.nextToken());
		//final long startTime = System.currentTimeMillis();
		for (int i = 0; i < cases; i++) {
			s = new StringTokenizer(b.readLine());
			int numPresents = Integer.parseInt(s.nextToken());
			int presentsToSend = Integer.parseInt(s.nextToken());
			
			//keep parallel array, one with the indices of the presents, other with the actual values
			int[] orderIndex = new int[numPresents];
			int[] order = new int[numPresents];
			int[] desOrder = new int[presentsToSend];
			long time = 0;
			
			s = new StringTokenizer(b.readLine());
			for (int j = 0; j < numPresents; j++) {
				int temp = Integer.parseInt(s.nextToken());
				order[j] = temp;
				orderIndex[temp - 1] = j;
			}
			
			s = new StringTokenizer(b.readLine());
			for (int j = 0; j < presentsToSend; j++) {
				int temp = Integer.parseInt(s.nextToken());
				desOrder[j] = temp;
			}
			
			int currIndex = -1;
			
			for (int j = 0; j < presentsToSend; j++) {
				//if it's index is less than the last present's, than it only takes 1 sec as we can reorder optimally
				if (orderIndex[desOrder[j] - 1] < currIndex) {
					time++;
				} else {
					//we are minusing j because that many presents before it have already been removed, and since it's index is greater than the curr present, it's index is shifted down that many times
					time += 2 * (orderIndex[desOrder[j] - 1] - j) + 1;
					currIndex = orderIndex[desOrder[j] - 1];
				}
			}
			p.println(time);
			
			
			//
			
		}
		//final long endTime = System.currentTimeMillis();
		//System.out.println("Total execution time: " + (endTime - startTime));
		p.close();
		

	}
	
	public static void ArrayListPrinter(ArrayList<Integer> array) {
		for (int i = 0; i < array.size(); i++) {
			System.out.print(array.get(i) + " ");
		}
		System.out.println();
	}
	public static void ArrayPrinter(int[] array) {
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i] + " ");
		}
		System.out.println();
	}
	
	

}
