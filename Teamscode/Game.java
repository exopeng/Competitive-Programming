import java.util.*;
public class Game {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("coords for test sheet? ");
    int x1 = Integer.parseInt(scanner.next()),  y1 = Integer.parseInt(scanner.next()), x2 = Integer.parseInt(scanner.next()), y2 = Integer.parseInt(scanner.next());
    System.out.print("coords for cover sheet? ");
    int x3 = Integer.parseInt(scanner.next()), y3 = Integer.parseInt(scanner.next()), x4 = Integer.parseInt(scanner.next()), y4 = Integer.parseInt(scanner.next());
    if(x3 >= x2 || x4 <= x1 || y3 >= y2 || y4 <= y1) {
      System.out.print("0");
      System.exit(0);
    }
    if (x3 < x1) {
      x3 = x1;
    }
    if (x4 > x2) {
      x4 = x2;
    }
    if (y3 < y1) {
      y3 = y1;
    }
    if (y4 > y2) {
      y4 = y2;
    }
    System.out.println((x4 - x3) * (y4 - y3));
  }
}