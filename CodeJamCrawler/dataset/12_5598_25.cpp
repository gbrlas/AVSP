import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;
public class Tongue {
	public static void main(String[] args) throws FileNotFoundException{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter("Tongue_out.txt");
		int t = in.nextInt();
		in.nextLine();
		for (int i = 0; i < t; i++){
			String string = in.nextLine();
			char[] ch = new char[string.length()];
			translate(string, ch);
			out.printf("Case #%d: ", i+1);
			for(int j = 0; j < ch.length; j++){
				out.printf("%c", ch[j]);
			}
			out.printf("%n");
		}
		out.close();
	}
	
	private static void translate(String a, char[] b){
		for (int i = 0; i < a.length(); i++){
			switch (a.charAt(i)) {
			case 'a':
				b[i] = 'y';
				break;
			case 'b':
				b[i] = 'h';
				break;
			case 'c':
				b[i] = 'e';
				break;
			case 'd':
				b[i] = 's';
				break;
			case 'e':
				b[i] = 'o';
				break;
			case 'f':
				b[i] = 'c';
				break;
			case 'g':
				b[i] = 'v';
				break;
			case 'h':
				b[i] = 'x';
				break;
			case 'i':
				b[i] = 'd';
				break;
			case 'j':
				b[i] = 'u';
				break;
			case 'k':
				b[i] = 'i';
				break;
			case 'l':
				b[i] = 'g';
				break;
			case 'm':
				b[i] = 'l';
				break;
			case 'n':
				b[i] = 'b';
				break;
			case 'o':
				b[i] = 'k';
				break;
			case 'p':
				b[i] = 'r';
				break;
			case 'q':
				b[i] = 'z';
				break;
			case 'r':
				b[i] = 't';
				break;
			case 's':
				b[i] = 'n';
				break;
			case 't':
				b[i] = 'w';
				break;
			case 'u':
				b[i] = 'j';
				break;
			case 'v':
				b[i] = 'p';
				break;
			case 'w':
				b[i] = 'f';
				break;
			case 'x':
				b[i] = 'm';
				break;
			case 'y':
				b[i] = 'a';
				break;
			case 'z':
				b[i] = 'q';
				break;
			case ' ':
				b[i] = ' ';
			default:
				break;
			}
		}
	}
}
