import java.util.Scanner;

public class lights {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int testCases = Integer.parseInt(scanner.nextLine());
		//get pattern 
		for (int i = 0; i < testCases; i++) {
			String pattern = scanner.nextLine();
			for (int j = 1; j < pattern.length(); j++) {
				//boolean hasRemainder = false;
				int remainder = pattern.length() % j;
				int toAdd = 0;
				if (remainder > 0) {
					//hasRemainder = true;
					toAdd = 1;
				}
				//String[] array = new String[(pattern.length()) / j + toAdd ];
				int counter = 0;
				String toCheck = pattern.substring(counter, counter + j);
				counter += j;
				for (int e = 1; e < (pattern.length()) / j + toAdd ; e++) {
					String bad = "";
					if (e != (pattern.length()) / j + toAdd - 1) {
						bad = pattern.substring(counter, counter + j);
						counter += j;
					} else {
						bad = pattern.substring(counter, pattern.length());
						if (bad.equals(toCheck.substring(0, bad.length()))) {
							System.out.println("OK");
							j = pattern.length() - 1;
							break;
						}
					}
					
					if (e != 0) {
						if (!(toCheck.equals(bad))) {
							break;
						}
						
					}
				}
				if (j == pattern.length() - 1) {
					System.out.println("MESSY");
				}
				
				
			}
		}
		
		
	}
}
