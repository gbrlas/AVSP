import java.util.Arrays;
import java.util.Scanner;


public class p1b {

	public static void debug(Object... obs)
	{
		System.out.println(Arrays.deepToString(obs));
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int c = 1; c <= t; c++)
		{
			int n = sc.nextInt();
			String[]sch=new String[n];
			for(int i=0;i<n;i++)
			{
				sch[i]=sc.next();
			}
			
			double[] res=solve(n,sch);
			
			System.out.println("Case #" + c + ":");
			for(double r : res)
			{
				System.out.println(r);
			}
		}
	}

	private static double[] solve(int n, String[] sch)
	{
		
		double[]res=new double[n];

		double[] wp=new double[n];
		int[] win=new int[n];
		int[] tot=new int[n];
		double[] owp=new double[n];
		double[] oowp=new double[n];
		
		for(int i=0;i<n;i++)
		{
			int wi=0;
			int lo=0;
			for(int j=0;j<sch.length;j++)
			{
				if(sch[i].charAt(j)=='1') wi++;
				if(sch[i].charAt(j)=='0') lo++;
			}
			win[i] = wi;
			tot[i] = wi+lo;
			wp[i] = wi/(double)(lo+wi);
		}
		
		for(int i=0;i<n;i++)
		{
			int opo = 0;
			for(int j=0;j<n;j++)
			{
				if(j==i) continue;
				if(sch[j].charAt(i) != '.')
				{
					int wa=win[j];
					int ta=tot[j]-1;
					if(sch[j].charAt(i) == '1') wa=wa-1;
					owp[i]+=( (double)wa/ta );
					opo++;
				}
			}
			if(opo > 0)
				owp[i] = owp[i]/(double)opo;
		}
		
		
		for(int i=0;i<n;i++)
		{
			int opo = 0;
			for(int j=0;j<n;j++)
			{
				if(j==i) continue;
				if(sch[j].charAt(i) != '.')
				{
					oowp[i]+=owp[j];
					opo++;
				}
			}
			if(opo > 0)
				oowp[i] = oowp[i]/(double)opo;
		}
		
		//debug(wp);
		//debug(owp);
		//debug(oowp);
		
		for(int i=0;i<sch.length;i++)
		{
			res[i] = 0.25*wp[i] + 0.5*owp[i] + 0.25*oowp[i];
		}
		
		return res;
	}
	
}
