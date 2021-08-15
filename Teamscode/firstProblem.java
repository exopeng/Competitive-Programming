/* Use the slash-star style comments or the system won't see your
   identification information */
/*
LANG: JAVA
ID: exopeng1
TASK: test
*/
import java.io.*;
import java.util.*;

class firstProblem {
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    Scanner scanner = new Scanner(System.in);
						  // Get line, break into tokens);
    System.out.print("X Distance: ");
    int num1 = Integer.parseInt(scanner.nextLine());
    System.out.print("Y Distance: ");
    int num2 = Integer.parseInt(scanner.nextLine());
    System.out.println(num1 + num2 - Math.pow(num1 * num1 + num2 * num2, 0.5));
  }
}