import java.util.HashMap;
import java.util.Scanner;
import java.io.File;

public class Googlerese {

	public static void main(String[] args) throws Exception {

		HashMap<Character,Character> mapping = new HashMap<Character,Character>();
		mapping.put('e', 'o');
		mapping.put('j', 'u');
		mapping.put('a', 'y');
		mapping.put('b', 'h');
		mapping.put('c', 'e');
		mapping.put('d', 's');
		mapping.put('e', 'o');
		mapping.put('f', 'c');
		mapping.put('g', 'v');
		mapping.put('h', 'x');
		mapping.put('i', 'd');
		mapping.put('j', 'u');
		mapping.put('k', 'i');
		mapping.put('l', 'g');
		mapping.put('m', 'l');
		mapping.put('n', 'b');
		mapping.put('o', 'k');
		mapping.put('p', 'r');
		mapping.put('q', 'z');
		mapping.put('r', 't');
		mapping.put('s', 'n');
		mapping.put('t', 'w');
		mapping.put('u', 'j');
		mapping.put('v', 'p');
		mapping.put('w', 'f');
		mapping.put('x', 'm');
		mapping.put('y', 'a');
		mapping.put('z', 'q');
		mapping.put(' ', ' ');

		Scanner fileReader = new Scanner(new File("A-small-attempt0.in"));
		int t = fileReader.nextInt();
		fileReader.nextLine();

		String inputString;
		for (int i = 0; i < t; i++) {
			inputString = fileReader.nextLine();
			char[] characters = inputString.toCharArray();
			char[] outputString = new char[characters.length];
			for (int j = 0; j < characters.length; j++) {
				outputString[j] = mapping.get(characters[j]);
			}
			System.out.print("Case #" + (i+1) + ": ");
			System.out.println(outputString);
		}

	}

}