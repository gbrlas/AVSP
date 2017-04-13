
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {

	final String FILENAME = "B-small-attempt0";
	final String FILENAME_IN = FILENAME+".in.txt";
	final String FILENAME_OUT = FILENAME+".out.txt";
//	final String FILENAME_IN  = "B-sample.in.txt";
//	final String FILENAME_OUT = "B-sample.out.txt";
	
	Scanner sc;
	
	double solve(double C, double F, double X)
	{
		double f = 2.0;
		double t = 0.0;
		
		if(X <= C)
		{
			return (X / f);
		}
		
		double a, b;
		for(;;)
		{
			//a = ((X-0) / (F+f)) + t;
			//b = ((X-C) / f    ) + t;
			
			a = (X / f) + t;// Hê‚ðì‚ç‚È‚¢.
			b = (C / f) + (X / (f + F)) + t;// Hê‚ðì‚é.
			
			if(a <= b)
			{
				return a;
			}
			else
			{
				t = t + (C / f);
				f = f + F;
			}
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
		
		int T = sc.nextInt();
		double C, F, X;
		double ans;
		for(int caze = 1; caze <= T; caze++)
		{
			C = sc.nextDouble();
			F = sc.nextDouble();
			X = sc.nextDouble();
			
			ans = solve(C, F, X);
			
			pw.printf("Case #%d: %1.7f\n", caze, ans);
		}
		
		sc.close();
		pw.close();
	}
	
	
	public static void main(String[] arg)
	{
		new B().run();
	}
}
