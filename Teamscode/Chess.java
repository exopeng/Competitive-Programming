import java.util.*;
public class Chess {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Rows/Columns? "); 
    int rowcol = Integer.parseInt(scanner.nextLine());
    int y = 0;
    int minX = Integer.MAX_VALUE, maxX = Integer.MIN_VALUE;
    for(int i = 0; i < rowcol; i++) {
      System.out.print("Line #" + (i + 1) + " ");
      String line = scanner.nextLine();
      if(line.indexOf("*") != -1) {
        y++;
      }
      if (line.indexOf("*") < minX) {
        minX = line.indexOf("*");
      }
      if (line.lastIndexOf("*") > maxX) {
        maxX = line.lastIndexOf("*");
      }
    }
    int x = maxX - minX;
    System.out.println(2 * y + 2 * x);
  }
}