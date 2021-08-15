import java.util.StringTokenizer;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;   


/* REMINDERS
 * CHECK INT VS LONG, IF YOU NEED TO STORE LARGE NUMBERS
 * CHECK CONSTRAINTS, C <= N <= F...
 * CHECK SPECIAL CASES, N = 1...
 * CHECK ARRAY BOUNDS, HOW BIG ARRAY HAS TO BE
 */


public class Party {
	public static int[] adj;
	public static int max = 0;
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int peeps = Integer.parseInt(s.nextToken());
		
		//find max length from root to child
		//make adjacency array, directed
		adj = new int[peeps];
		
		for (int i = 0; i < peeps; i++) {
			s = new StringTokenizer(b.readLine());
			adj[i] = Integer.parseInt(s.nextToken()) - 1;
		}
		
		
		//might need to optmize
		
		//find max distance from root to child
		for (int i = 0; i < peeps; i++) {
			dfs(i, 1);
		}
		
		
		System.out.println(max);
		
		p.close();
		

	}
	
	public static void dfs(int curr, int len) {
		//base case, stop when you reach employee with manager -1
		if (adj[curr] == -2) {
			max = Math.max(max, len);
			return;
		} else {
			//locate it's manager
			dfs(adj[curr], len + 1);
		}
		
		
	}
	
	

}
