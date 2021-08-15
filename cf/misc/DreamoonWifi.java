import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;   

public class DreamoonWifi {
	public static ArrayList<Integer> possibilities = new ArrayList<Integer>();
	public static void main(String[] args) {
		//get input separately
		Scanner scanner = new Scanner(System.in);
		String signal = scanner.nextLine();
		String received = scanner.nextLine();
		int currVal = 0;
		
		//find the currVal without questionmarks
		//find the number of question marks, the number of possible signals is the 2^(that)
		int questionMarks = 0;
		for (int i = 0; i < received.length(); i++) {
			if (received.charAt(i) == '?') {
				questionMarks++;
			}
			if (received.charAt(i) == '+') {
				currVal++;
			} 
			if (received.charAt(i) == '-') {
				currVal--;
			}
		}
		//calculate the desired signal sent 
		int steps = 0;
		for (int i = 0; i < signal.length(); i++) {
			if (signal.charAt(i) == '+') {
				steps++;
			} else {
				steps--;
			}
		}
		int hits = 0;
		//just brute force through all the possibilites, calculate it's value, then see if it matches desired steps, if it does, add to hits
		calculate(questionMarks, currVal, 0);
		
		//check to see which ones in the possiblility list equals the desired val, add to counter
		for (int i = 0; i < possibilities.size(); i++) {
			if (possibilities.get(i) == steps) {
				hits++;
			}
		}
		//ArrayListPrinter(possibilities);
		double probability = (double)hits / possibilities.size();
		
		System.out.printf("%.12f %n", probability);


	}
	public static void calculate(int questionMarks, int currVal, int currNumber) {
		if ((currNumber >= questionMarks)) {
			possibilities.add(currVal);
		} else {
			calculate(questionMarks, currVal + 1, currNumber + 1);
			calculate(questionMarks, currVal - 1, currNumber + 1);
		}
		
	}
	public static void ArrayListPrinter(ArrayList<Integer> array) {
		for (int i = 0; i < array.size(); i++) {
			System.out.print(array.get(i) + " ");
		}
		System.out.println();
	}
	
	

}
