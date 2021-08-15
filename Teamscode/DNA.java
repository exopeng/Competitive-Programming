import java.util.*;
public class DNA {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Strand: ");
    String strand = scanner.nextLine();
    System.out.print("Comp strand");
    String compStrand = scanner.nextLine();
    int counter = 0;
    for (int i = 0; i < strand.length(); i++) {
      if (strand.charAt(i) == 'A' && compStrand.charAt(i) != 'T') {
        counter++;
      }
      if (strand.charAt(i) == 'T' && compStrand.charAt(i) != 'A') {
        counter++;
      }
      if (strand.charAt(i) == 'G' && compStrand.charAt(i) != 'C') {
        counter++;
      }
      if (strand.charAt(i) == 'C' && compStrand.charAt(i) != 'G') {
        counter++;
      }
    }
    System.out.println(counter);
  }
}