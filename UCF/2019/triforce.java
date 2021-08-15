import java.util.Scanner;

public class triforce {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int testCases = scanner.nextInt();
		for (int i = 0; i < testCases; i++) {
			int sideLength = scanner.nextInt();
			int iterations = scanner.nextInt();
			int pricePerSqFt = scanner.nextInt();
			int triforces =  (int)Math.pow(3, iterations);
			double sideLengthPerTriforce = sideLength / Math.pow(2, iterations);
			double areaPerTriforce = ((Math.sqrt(Math.pow(sideLengthPerTriforce, 2) - Math.pow(sideLengthPerTriforce / 2, 2))) * sideLengthPerTriforce / 2);
			double totalCost = areaPerTriforce * triforces * pricePerSqFt;
			System.out.println(totalCost);
		}

	}

}
