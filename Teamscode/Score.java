import java.util.*;
public class Score {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Ari's score");
    int ariScore = Integer.parseInt(scanner.nextLine());
    System.out.print("Number of students");
    int numberStudents = Integer.parseInt(scanner.nextLine());
    System.out.print("Scores, separated by spaces? ");
    int[] scores = new int[numberStudents];
    for(int i = 0; i < numberStudents; i++) {
      scores[i] = Integer.parseInt(scanner.next());
    }
    
    Arrays.sort(scores);
    
    int place = 1;
    for (int i = scores.length - 1; i > -1; i--) {
      if (scores[i] == ariScore) {
        System.out.println(place);
        break;
      }
      place++;
    }
  }
}