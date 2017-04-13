
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {

	final String FILENAME_IN = "A-small-attempt0.in.txt";
	final String FILENAME_OUT = "A-small-attempt0.out.txt";
	
	Scanner sc;
	
	int solve(int a[], int b[])
	{
		int cnt=0;
		int ans=0;
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				if(a[i] == b[j])
				{
					cnt++;
					ans = a[i];
				}
		
		switch(cnt)
		{
			case 0 : return 0;
			case 1 : return ans;
			default: return -1;
		}
	}
	
	void run()
	{
		PrintWriter pw;
		try
		{
			sc = new Scanner(new File(FILENAME_IN));
			pw = new PrintWriter(new BufferedWriter(new FileWriter(new File(FILENAME_OUT))));
		}
		catch(Exception e)
		{
			System.err.println(e);
			return;
		}
		
		int T = Integer.parseInt(sc.nextLine());
		
		int[][][] cards = new int[2][4][4];
		
		for(int caze = 1; caze <= T; caze++)
		{
			
			int[] l = new int[2];
			for(int n=0; n<2; n++)
			{
				l[n] = sc.nextInt();
				l[n] --;
				for(int i=0; i<4; i++)
					for(int j=0; j<4; j++)
						cards[n][i][j] = sc.nextInt();
			}
			
			pw.printf("Case #%d: ", caze);
			int ans = solve(cards[0][l[0]], cards[1][l[1]]);
			switch(ans)
			{
			case  0:
				pw.println("Volunteer cheated!");
				break;
			case -1:
				pw.println("Bad magician!");
				break;
			default:
				pw.println(ans);
			}
		}
		
		sc.close();
		pw.close();
	}
	
	
	public static void main(String[] arg)
	{
		new A().run();
	}
}
