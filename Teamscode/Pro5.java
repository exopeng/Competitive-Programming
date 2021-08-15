import java.util.*;
public class Pro5 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
  	System.out.print("Input? ");
  	String inp = scanner.nextLine();
  	char[] inpArray = new char[inp.length()];
  	String decrypt = "";
  	for(int i = 0; i < inp.length(); i++) {
  		inpArray[i] = inp.charAt(i);
  	}
  	for(int i = 0; i < inpArray.length; i++) {
  		if (i != inpArray.length - 1) {
  			inpArray[i] -= (int)inpArray[i + 1];;
  		}
  		decrypt += inpArray[i];
  	}
  	System.out.println(decrypt);
  }
}