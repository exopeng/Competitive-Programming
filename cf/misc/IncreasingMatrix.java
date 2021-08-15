import java.util.StringTokenizer;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
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


public class IncreasingMatrix {
	public static void main(String[] args) throws IOException {
		//get input separately
		BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter p = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer s = new StringTokenizer(b.readLine());
		int rows = Integer.parseInt(s.nextToken());
		int cols = Integer.parseInt(s.nextToken());
		int[][] matrix = new int[rows][cols];
		int ans = -1;
		
		for (int i = 0; i < rows; i++) {
			s = new StringTokenizer(b.readLine());
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = Integer.parseInt(s.nextToken());
			}
		}
		//ArrayPrinter(matrix);
		//final long startTime = System.currentTimeMillis();
		//look through all the zeroes, from bottom to top, right to left
		for (int i = cols - 2; i > 0; i--) {
			for (int j = rows - 2; j > 0; j--) {
				if (matrix[j][i] == 0) {
					//get the range horiz
					//check if range is contradictory
					int maxX = matrix[j][i + 1] - 1;
					int minX = 0;
					for (int c = 0; c < i; c++) {
						if (matrix[j][c] == 0) {
							minX = matrix[j][c - 1] + 1;
							break;
						}
					}
					//System.out.println("Cell: Row: " + j + " Col: " + i + " MinX: " + minX + " maxX: " + maxX);
					
					if (maxX < minX) {
						p.println(-1);
						p.close();
						System.exit(0);
					}
					
					
					//get the range vert
					//check if range is contradictory
					int maxY = matrix[j + 1][i] - 1;
					int minY = 0;
					for (int c = 0; c < j; c++) {
						if (matrix[c][i] == 0) {
							minY = matrix[c - 1][i] + 1;
							break;
						}
					}
					//System.out.println("Cell: Row: " + j + " Col: " + i + " MinY: " + minY + " maxY: " + maxY);
					if (maxY < minY) {
						p.println(-1);
						System.exit(0);
					}
					
					//take intersection of 2 ranges
					int min = Math.max(minX, minY);
					int max = Math.min(maxX, maxY);
					int val = max;
					
					//fill the cell with max
					matrix[j][i] = val;
					//ArrayPrinter(matrix);
				}
				
			}
		}
		
		//then run through checking mechanism
		if (works(matrix)) {
			ans = sum(matrix);
		}
		
		p.println(ans);
		//final long endTime = System.currentTimeMillis();
		//p.println("Total execution time: " + (endTime - startTime));
		p.close();
		

	}
	public static int sum(int[][] matrix) {
		int sum = 0;
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[0].length; j++) {
				sum += matrix[i][j];
			}
		}
		return sum;
	}
	public static boolean works(int[][] matrix) {
		
		//check if increasing on horiz
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 1; j < matrix[0].length; j++) {
				if (!(matrix[i][j] > matrix[i][j - 1])) {
					return false;
				}
			}
		}
		
		//check if increasing on vert
		for (int i = 0; i < matrix[0].length; i++) {
			for (int j = 1; j < matrix.length; j++) {
				if (!(matrix[j][i] > matrix[j - 1][i])) {
					return false;
				}
			}
		}
		
		return true;
	}
	public static void ArrayPrinter(int[][] array) {
		for (int i = 0; i < array.length; i++) {
			for (int j = 0; j < array[0].length; j++) {
				System.out.print(array[i][j] + " ");
			}
			System.out.println();
		}
	}
	
	

}
