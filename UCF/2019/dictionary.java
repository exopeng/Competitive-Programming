import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;   

public class dictionary {

	public static void main(String[] args) throws IOException {
		
		
		
		//get input separately
		Scanner scanner = new Scanner(System.in);
		int testCases = Integer.parseInt(scanner.nextLine());
		ArrayList<String[]> list = new ArrayList<String[]>();
		for (int i = 1; i <= testCases; i++) {
			int dictLength = Integer.parseInt(scanner.nextLine());
			String[] words = new String[dictLength];
			for (int j = 0; j < dictLength; j++) {
				words[j] = scanner.nextLine();
				
			}
			list.add(words);
			
		}
	
		for (int i = 1; i <= testCases; i++) {
			String[] words = list.get(i - 1);
			//bubble sort the things
			if (!(words.length == 1)) {
				for (int e = 0; e < words.length - 1; e++) {
		            for (int c = 0; c < words.length - 1; c++) {
		            	String word = words[c];
						String word1 = words[c + 1];
						boolean firstLower = compareTwo(word, word1);
		            	if (firstLower) { 
		                    // swap arr[j+1] and arr[i] 
		                    String temp = words[c]; 
		                    words[c] = words[c+1]; 
		                    words[c+1] = temp; 
		                } 
		            }
				}
			}
			dictPrinter(words, i);
			
			
		}
		
		
		
		

	}
	
	public static boolean compareTwo(String word, String word1) {
		//for each word, make charList
		//make char arrayList of characters, sorted alphabetically
		ArrayList<Character> chars = new ArrayList<Character>();
		for (int b = 0; b < word.length(); b++) {
			if (!(chars.contains(word.charAt(b)))) {
				chars.add(word.charAt(b));
			}
		}
		Collections.sort(chars);
		
		//make char arrayList of characters, sorted alphabetically
		ArrayList<Character> chars1 = new ArrayList<Character>();
		for (int b = 0; b < word1.length(); b++) {
			if (!(chars1.contains(word1.charAt(b)))) {
				chars1.add(word1.charAt(b));
			}
		}
		Collections.sort(chars1);
		
		
		//go through all the letters to see which one has more
		for (int i = 97; i < 123; i++) {
			char toCompare = (char)i;
			//System.out.println(toCompare);
			
			//if one contains it while the other doesn't, first one wins
			if (chars.contains(toCompare) && !(chars1.contains(toCompare))) {
				return false;
			}
			if (chars1.contains(toCompare) && !(chars.contains(toCompare))) {
				return true;
			}
			//if both contain it, get occurrences of each
			if (chars.contains(toCompare) && chars1.contains(toCompare)) {
				int charsOccurences = OccurencesOfCharacter(toCompare, word);
				int chars1Occurences = OccurencesOfCharacter(toCompare, word1);
				if (charsOccurences < chars1Occurences) {
					return true;
				} else if (charsOccurences > chars1Occurences) {
					return false;
				}
			}
			
			//if both have same occurrences of every letter, it is anagram, sort by first letter.. second letter
			if (i == 122) {
				return sortLex(word, word1);
			}
		}
		return false;
	}
	
	public static int OccurencesOfCharacter(char givenCharacter, String word) {
        int count = 0;
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == givenCharacter) {
                count++;
            }
        
        }

        return count;
    }
	
	public static boolean sortLex(String word, String word1) {
		//get longer word
		int max = 0;
		if (word.length() > word1.length()) {
			max = word1.length();
		} else {
			max = word.length();
		}
		for (int i = 0; i <= max; i++) {
			if (i == max) {
				if (max == word.length()) {
					return true;
				} else {
					return false;
				}
			}
			
			if ((int)(word.charAt(i)) > (int)(word1.charAt(i))) {
				return true;
			} else if ((int)(word.charAt(i)) < ((int)word1.charAt(i))) {
				return false;
			}
		}
		return false;
	}
	public static void dictPrinter(String[] array, int dictNumber) throws IOException {
		//PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("dictionary.out")));
		System.out.println("Dictionary #" + dictNumber + ":");
		for (int i = 0; i < array.length; i++) {
			System.out.println(array[i]);
		}
		System.out.println();
		System.out.close();
	}

}
