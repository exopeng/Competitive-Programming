import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;
public class escape {

	public static void main(String[] args) throws IOException {
		//get input separately
		Scanner scanner = new Scanner(System.in);
		int testCases = (scanner.nextInt());
		for (int i = 0; i < testCases; i++) {
			System.out.println((int)Math.pow(scanner.nextInt(), 3) + (int)Math.pow(scanner.nextInt(), 3) + (int)Math.pow(scanner.nextInt(), 3));
		}
		
		

	}

}
