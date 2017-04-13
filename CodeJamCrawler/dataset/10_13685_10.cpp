import java.util.*;

class Main
{
	public static void main(String[] args)
	{
		Scanner lee = new Scanner(System.in);
		
		int n = lee.nextInt();
		int a, b, c, V[], p, count, x, y;
		
		for(int i=1; i<=n; i++)
		{
			a = lee.nextInt();
			b = lee.nextInt();
			c = lee.nextInt();
			
			V = new int [c];
			
			for(int j=0; j<c; j++)
				V[j] = lee.nextInt();
			
			p = 0; 
			count = 0;
			
			for(int j=1; j<=a; j++)
			{
				x = 0;
				y = 0;
				
				while(b >= x + V[p] && y < c)
				{
					count+=V[p];
					x+=V[p];
					p = (p + 1) % c;
					y++;
				}
			}
			
			System.out.println("Case #"+i+": "+count);
		}
	}
}