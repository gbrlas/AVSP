import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class QuestionA {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));

		int t = sc.nextInt(); // number of test cases
		sc.nextLine();
		
		for (int i = 0; i < t; i++) {
			pw.print("Case #" + (i + 1) + ": ");
			System.out.print("Case #" + (i + 1) + ": ");
			
			String line = sc.nextLine();
			String english = "";
			
			for (int j = 0; j < line.length(); j++) {
				if (line.charAt(j) == 'a') 
					english += 'y';
				if (line.charAt(j) == 'b') 
					english += 'h';
				if (line.charAt(j) == 'c') 
					english += 'e';
				if (line.charAt(j) == 'd') 
					english += 's';
				if (line.charAt(j) == 'e') 
					english += 'o';
				if (line.charAt(j) == 'f') 
					english += 'c';
				if (line.charAt(j) == 'g') 
					english += 'v';
				if (line.charAt(j) == 'h') 
					english += 'x';
				if (line.charAt(j) == 'i') 
					english += 'd';
				if (line.charAt(j) == 'j') 
					english += 'u';
				if (line.charAt(j) == 'k') 
					english += 'i';
				if (line.charAt(j) == 'l') 
					english += 'g';
				if (line.charAt(j) == 'm') 
					english += 'l';
				if (line.charAt(j) == 'n') 
					english += 'b';
				if (line.charAt(j) == 'o') 
					english += 'k';
				if (line.charAt(j) == 'p') 
					english += 'r';
				if (line.charAt(j) == 'q') 
					english += 'z';
				if (line.charAt(j) == 'r') 
					english += 't';
				if (line.charAt(j) == 's') 
					english += 'n';
				if (line.charAt(j) == 't') 
					english += 'w';
				if (line.charAt(j) == 'u') 
					english += 'j';
				if (line.charAt(j) == 'v') 
					english += 'p';
				if (line.charAt(j) == 'w') 
					english += 'f';
				if (line.charAt(j) == 'x') 
					english += 'm';
				if (line.charAt(j) == 'y') 
					english += 'a';
				if (line.charAt(j) == 'z') 
					english += 'q';
				if (line.charAt(j) == ' ') 
					english += ' ';
			}
			pw.print(english + "\n");
			System.out.println(english);
		}	
		pw.flush();
		pw.close();
		sc.close();
	}

}
