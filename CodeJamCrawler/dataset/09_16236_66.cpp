import java.util.regex.Pattern;
import java.util.Scanner;

public class PatternMatchesTest {
  public static void main(String args[]) {

	int i, matchCount, j;
	String regex;
	Scanner in = new Scanner(System.in);
	
	/* Read the L D N value */
	int L = in.nextInt();
	int D = in.nextInt();
	int N = in.nextInt();

	String dictionary[] = new String[D];

	/* Read the known values */
	for(i = 0; i < D; i++)
	{
		dictionary[i] = in.next();
	}

	for(i = 0; i < N; i++)
	{
		regex = in.next();
		regex = regex.replace('(', '[');
		regex = regex.replace(')', ']');
		matchCount = 0;

		for(j = 0; j < D; j++)
		{
			if(Pattern.matches(regex, dictionary[j]))
			{
				matchCount++;
			}
		}

		System.out.println("Case #" + (i+1) + ": " + matchCount);
	}
  }
}
