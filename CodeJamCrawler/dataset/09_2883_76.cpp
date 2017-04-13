import java.text.DecimalFormat;
import java.util.Scanner;


public class Welcome {

	public static final String WELCOME = "welcome to code jam";
	public static int[][] results;
	public static boolean[][] resultsBool;
	public static int count;
	public static DecimalFormat format = new DecimalFormat("0000");
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int cases = scn.nextInt();
		scn.nextLine();
		
		for(int c = 1; c <= cases; c++) {
			String input = scn.nextLine();
			int res = process( input );
			StringBuilder builder = new StringBuilder("Case #");
			builder.append(c);
			builder.append(": ");
			builder.append(format.format(res));
			System.out.println(builder.toString());
		}
	}

	private static int process(String input) {
		results = new int[WELCOME.length()][input.length()];
		resultsBool = new boolean[WELCOME.length()][input.length()];
		int start = 0;
		int result = 0;
		char c = WELCOME.charAt(0);
		while(start < WELCOME.length()) {
			int pos = input.indexOf(c, start);
			if(pos == -1) {
				break;
			}
			result += doIt(input, pos+1, 1);
			result %= 10000;
			start = pos+1;
		}
		return result;
	}

	private static int doIt(String input, int inputPos, int welcomePos) {
		if( welcomePos >= WELCOME.length() )
			return 1;
		if(inputPos >= input.length())
			return 0;
		if(resultsBool[welcomePos][inputPos]) {
			return results[welcomePos][inputPos];
		}
		
		int start = inputPos;
		int result = 0;
		char c = WELCOME.charAt(welcomePos);
		while(start < input.length()) {
			int pos = input.indexOf(c, start);
			if(pos == -1) {
				break;
			}
			result += doIt(input, pos+1, welcomePos+1);
			result %= 10000;
			start = pos+1;
		}
		resultsBool[welcomePos][inputPos] = true;
		results[welcomePos][inputPos] = result;
		return result;
	}

}
