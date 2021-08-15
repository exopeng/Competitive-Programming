import java.io.*;
import java.util.*;


//confusing problem
//just know that there is always a way to make a route such that you can use the max fav # to get to destination, it can make a polygon with all sides len of that max
//don't need to consider other numbers unless that are the distance to destination themselves, as it will be a hop of 1
//if max is greater than dist, than it is just 2, as you can make a polygon with sides len max
public class cowFriends {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int cases = Integer.parseInt(s.nextToken());
		//store the answers in an int array
		for (int i = 0; i < cases; i++) {
			s = new StringTokenizer(b.readLine());
			long ans = 0;
			int max = 0;
			int nums = Integer.parseInt(s.nextToken());
			int dist = Integer.parseInt(s.nextToken());
			s = new StringTokenizer(b.readLine());
			for (int j = 0; j < nums; j++) {
				int fav = Integer.parseInt(s.nextToken());
				if (fav == dist) {
					max = fav;
					break;
				}
				max = Math.max(max, fav);
			}
			if (max != dist) {
				if (max > dist) {
					p.println(2);
				} else {
					p.println((int)Math.ceil((double)dist / max));
				}
				
			} else {
				p.println(1);
			}
			
			
			
			
		}
		p.close();
		

	}
	
	// you should actually read the stuff at the bottom

}
/* REMINDERS
 * PLANNING!!!!!!!! Concrete plan before code
 * DON'T MAKE ASSUMPTIONS
 * DON'T OVERCOMPLICATE
 * NAIVE SOL FIRST
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 * TO TEST TLE/MLE, PLUG IN MAX VALS ALLOWED AND SEE WHAT HAPPENS
 * ALSO CALCULATE BIG-O, OVERALL TIME COMPLEXITY
 */
