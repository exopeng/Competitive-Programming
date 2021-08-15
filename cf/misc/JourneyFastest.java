import java.util.Scanner;
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
import java.util.Collections;   

public class JourneyFastest {
	public static ArrayList<Integer> vals = new ArrayList<Integer>();
	public static ArrayList<Double> valsProb = new ArrayList<Double>();
	public static ArrayList<Integer>[] adj;
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int cities = Integer.parseInt(s.nextToken());
		adj = new ArrayList[cities];
		
		for (int i = 0; i < cities; i++) { 
            adj[i] = new ArrayList<Integer>(); 
        } 
		for (int i = 0; i < cities - 1; i++) {
			s = new StringTokenizer(b.readLine());
			int loc1 = Integer.parseInt(s.nextToken());
			int loc2 = Integer.parseInt(s.nextToken());
			adj[loc1 - 1].add(loc2 - 1);
			adj[loc2 - 1].add(loc1 - 1);
			
		}
		
		//call dfs on location 1
		//ArrayList<Integer> visited = new ArrayList<Integer>();
		
		boolean[] visited = new boolean[cities];
		visited[0] = true;
		dfs(visited, 1, 0, 0);
		
		//sum up all the values in vals and take the average of it
		double prob = 0;
		for (int i = 0; i < vals.size(); i++) {
			prob += vals.get(i) * valsProb.get(i);
		}

		
		System.out.printf("%.10f %n", prob);

	}
	public static void dfs(boolean[] visited, double prob, int curr, int counter) {
		boolean hasConnection = false;
		int possible = 0;
		
		//find how many possible nodes the current place has
		int conns = adj[curr].size();
		if (curr == 0) {
			possible = conns;
		} else {
			possible = conns - 1;
		}
		
		for (int i = 0; i < adj[curr].size(); i++) {
			int node = adj[curr].get(i);
			if (!visited[node]) {
				//clone the array
				visited[node] = true;
				hasConnection = true;
				//dfs(visited, adj, prob / possible, node);
				dfs(visited, prob / possible, node, counter + 1);
			}
		}
		//if it already has visited all the possible connections, it can't move anymore and add to the vals array
		if (!hasConnection) {
			//get the length of the path, and add to vals
			//len of path is just number of true in visited array - 1
			vals.add(counter);
			valsProb.add(prob);
			return;
		}
	}
	
	

}
