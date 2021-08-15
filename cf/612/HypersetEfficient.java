import java.util.StringTokenizer;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;  
import java.util.HashMap;

/* REMINDERS
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 */


public class HypersetEfficient {
	public static int ans = 0;
	public static int feats;
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int cards = Integer.parseInt(s.nextToken());
		feats = Integer.parseInt(s.nextToken());
		String[] possCards = new String[cards];
		HashMap<String, Integer> map = new HashMap<>(); 
		for (int i = 0; i < cards; i++) {
			s = new StringTokenizer(b.readLine());
			String te = s.nextToken();
			possCards[i] = te;
			map.put(te, 0);
			
		}
		
		
		//for every pair of cards, see if there exists a third card that fulfills a set
		for (int i = 0; i < cards; i++) {
			for (int j = i + 1; j < cards; j++) {
				String feat = "";
				//construct what the third cards features should look like
				for (int c = 0; c < feats; c++) {
					//1st case, the features are all the same, so the third card must have the same feature
					if (possCards[i].charAt(c) == possCards[j].charAt(c)) {
						feat += possCards[i].charAt(c);
					}
					//2nd case, the features are all different, so the third card's features must be different from the other 2
					if (possCards[i].charAt(c) == 'T' && possCards[j].charAt(c) == 'S' || possCards[i].charAt(c) == 'S' && possCards[j].charAt(c) == 'T') {
						feat += 'E';
					}
					if (possCards[i].charAt(c) == 'E' && possCards[j].charAt(c) == 'T' || possCards[i].charAt(c) == 'T' && possCards[j].charAt(c) == 'E') {
						feat += 'S';
					}
					if (possCards[i].charAt(c) == 'S' && possCards[j].charAt(c) == 'E' || possCards[i].charAt(c) == 'E' && possCards[j].charAt(c) == 'S') {
						feat += 'T';
					}
				}
				
				if (map.containsKey(feat)) {
					ans++;
				}
			}
		}
		
		// for the set {A, B, C}, we will overcount three times, with the subsets {A, B, ?}, {A, C, ?}, and {B,C, ?}, all of which lead to the same thing
		p.println(ans/ 3);
		p.close();
		

	}
	
    
	
	
	

}
