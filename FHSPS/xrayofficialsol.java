import java.util.*;
import java.io.*;

/*
Each point (x,y) sits on two diagonals. The main diagonal x-y and the antidiagonal x+y.
The answer will be centered on one of the main diagonals and one of the antidiagonals that contain points.
We iterate over each combination of diagonals. The answer will be the sum of points on both diagonals.
If there is a point at the intersection of the diagonals, we overcounted, so subtract 1.
*/

public class xrayofficialsol {

	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner(new File("xray.in"));
		PrintWriter out = new PrintWriter(System.out);
		int t = scan.nextInt();
		long time = System.currentTimeMillis();
		for(int q = 1; q <= t; q++){

			int n = scan.nextInt();
			HashSet<Long> set = new HashSet<Long>();
			HashMap<Integer, Integer> d1 = new HashMap<Integer, Integer>();
			HashMap<Integer, Integer> d2 = new HashMap<Integer, Integer>();
			for(int i = 0; i < n; i++){
				int x = scan.nextInt();
				int y = scan.nextInt();

				int D1 = x+y;
				int D2 = x-y;

				int g1 = d1.getOrDefault(D1, 0);
				int g2 = d2.getOrDefault(D2, 0);

				d1.put(D1, g1+1);
				d2.put(D2, g2+1);

				set.add(((long)(D1) << 32L) + D2);
			}

			int ans = 0;
			for(int D1 : d1.keySet()){
				for(int D2 : d2.keySet()){
					int m = d1.get(D1)+d2.get(D2);
					if(set.contains(((long)(D1) << 32L) + D2)) m--;
					ans = Math.max(ans, m);
				}
			}
			out.println(ans);
		}
		out.flush();
		System.out.println(System.currentTimeMillis()-time);
	}
}