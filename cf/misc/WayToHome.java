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

public class WayToHome {

	public static void main(String[] args) {
		//get input separately
		Scanner scanner = new Scanner(System.in);
		int destination = scanner.nextInt();
		int jump = scanner.nextInt();
		scanner.nextLine();
		String map = scanner.nextLine();
		int curr = 0;
		int steps = 0;
		
		while (curr != destination - 1) {
			int des = 0;
			//System.out.println(curr);
			for (int i = curr + 1; i <= curr + jump ; i++) {
				//System.out.println(i);
				if (i == map.length() - 1) {
					if (map.charAt(i) == '1') {
						des = i;
					}
					break;
				}
				if (map.charAt(i) == '1') {
					des = i;
				}
			}
			if (des == 0) {
				System.out.println(-1);
				System.exit(0);
			}
			curr = des;
			steps++;
		}
		
		System.out.println(steps);

	}
	
	

}
