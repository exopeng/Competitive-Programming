import java.util.Scanner;
import java.util.*;
import java.io.*;
public class slices {

	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(f.readLine());
		int testCases = Integer.parseInt(st.nextToken());
		for (int i = 0; i < testCases; i++) {
			st = new StringTokenizer(f.readLine());
			int rounds = Integer.parseInt(st.nextToken());
			int maxLevels = Integer.parseInt(st.nextToken());
			int kellyScore = 0;
			int jimScore = 0;
			int diff = 0;
			boolean kellyMad = false;
			boolean jimMad = false;
			for (int j = 0; j < rounds; j++) {
				st = new StringTokenizer(f.readLine());
				if ((st.nextToken()).equals("Kelly")) {
					kellyScore = Integer.parseInt(st.nextToken());
					diff = kellyScore - jimScore;
					if (Math.abs(diff) == maxLevels) {
						if (diff > 0) {
							jimMad = true;
						} else {
							kellyMad = true;
						}
					}
				} else {
					//String s = st.nextToken();
					jimScore = Integer.parseInt(st.nextToken());
					diff = kellyScore - jimScore;
					if (Math.abs(diff) >= maxLevels) {
						if (diff > 0) {
							jimMad = true;
						} else {
							kellyMad = true;
						}
					}
				}
			}
			if (kellyMad && jimMad) {
				System.out.println("Their friendship is doomed");
			} else if (kellyMad && !jimMad) {
				System.out.println("Kelly hates Jim");
			} else if (!kellyMad && jimMad) {
				System.out.println("Jim hates Kelly");
			} else {
				System.out.println("Everything is good");
			}
		}

	}

}
