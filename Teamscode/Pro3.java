import java.util.*;
public class Pro3 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Distance from Earth? ");
    int dis = Integer.parseInt(scanner.nextLine());
    int counter = 0;
    while(dis != 0) {
    	if (dis % 4 == 0) {
    		dis /= 4;
    	} 
    	else if (dis % 3 == 0) {
    		dis /= 3;
    	}
    	else {
    		dis -= 1;
    	} 
    	counter++;
    }
 	System.out.println(counter);
  }
}