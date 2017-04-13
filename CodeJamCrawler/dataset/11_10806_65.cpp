import java.util.Arrays;
import java.util.Scanner;


public class p1c {

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
			int r = sc.nextInt();
			int co = sc.nextInt();
			String[]in=new String[r];
			for(int i=0;i<r;i++)
			{
				in[i]=sc.next();
			}
			System.out.println("Case #" + c + ":");
			String[]res=solve(r,co,in);
			for(String re : res)
			{
				System.out.println(re);
			}
		}
	}

	private static String[] solve(int r, int co, String[] in)
	{
		String[] imp=new String[1];
		imp[0]="Impossible";
		String[] res=new String[r];
		
		char[][] pic=new char[r][co];
		for(int i=0;i<r;i++)
			for(int j=0;j<co;j++)
				pic[i][j]=in[i].charAt(j);
		
		//debug(r,co);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<co;j++)
			{
				if(pic[i][j]=='#')
				{
					//debug(i,j);
					if((i<(r-1))&&(j<(co-1))&&(pic[i][j+1]=='#') && (pic[i+1][j]=='#') && (pic[i+1][j+1]=='#'))
					{
						pic[i][j]='/';
						pic[i][j+1]='\\';
						pic[i+1][j]='\\';
						pic[i+1][j+1]='/';
					}
					else
					{
						//debug("here");
						return imp;
					}
				}
			}
		}
		
		for(int i=0;i<r;i++)
		{
			StringBuilder sb=new StringBuilder();
			for(int j=0;j<co;j++)
			{
				sb.append(pic[i][j]);
			}
			res[i]=sb.toString();
		}
		return res;
	}
	
}
