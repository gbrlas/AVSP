import java.util.*;
import java.io.*;

public class blah
{
	public static void main(String[] args) throws Throwable
	{
		Scanner in1 = new Scanner(new File("lookup.txt"));
		Scanner in2 = new Scanner(new File("A.in"));
		HashMap<String, Integer> xx = new HashMap<String, Integer>();
		in2.nextLine();
		for(int i = 0; i < 511; i++)
			xx.put(in2.nextLine().trim(), Integer.parseInt(in1.nextLine().split(" ")[2]));
		Scanner in = new Scanner(System.in);
		int T = Integer.parseInt(in.nextLine());
		for(int i = 1; i <= T; i++)
			System.out.println("Case #"+i+": "+xx.get(in.nextLine().trim()));
	}
}