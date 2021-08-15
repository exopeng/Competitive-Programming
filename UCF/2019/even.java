import java.util.Scanner;
public class even {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int queries = Integer.parseInt(scanner.nextLine());
		int[] queryList = new int[queries];
		for (int i = 0; i < queries; i++) {
			queryList[i] = Integer.parseInt(scanner.nextLine());
		}
		
		for (int i = 0; i < queryList.length; i++) {
			//find next biggest power of 2
			int level = 2;
			while (queryList[i] >= level) {
				level = level * 2;
			}
			
			System.out.println("Pokemon " + (i + 1) + ": " + (level - queryList[i]));
		}
	}
}
