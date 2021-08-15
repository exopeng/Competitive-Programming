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

public class Archer {

	public static void main(String[] args) throws IOException {
		//get input separately
		Scanner scanner = new Scanner(System.in);
		int num1 = scanner.nextInt();
		int den1 = scanner.nextInt();
		int num2 = scanner.nextInt();
		int den2 = scanner.nextInt();
		
		double sr = (double)num1 / den1;
		double za = (double)num2 / den2;
		
		double prob = sr;
		double currProb = 0;
		int counter = 1;
		do {
			currProb = Math.pow((1 - sr) *  (1 - za), counter) * sr;
			prob += currProb;
			counter++;
		} while (currProb > Math.pow(10, -10));
		System.out.printf("%.7f %n", prob);

	}
	
	

}
