import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;


public class Magicka {

	private static final Character NOCOMB='.';
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int c = 1; c <= t; c++)
		{
			
			int C=0,D=0,N=0;
			C = sc.nextInt();
			String[] comb = new String[C];
			for(int i=0;i<C;i++)
				comb[i]=sc.next();
			
			D = sc.nextInt();
			String[] opo = new String[D];
			for(int i=0;i<D;i++)
				opo[i]=sc.next();
			
			N=sc.nextInt();
			String inv=sc.next();
			
			System.out.println("Case #" + c + ": " + solve(comb,opo,inv,N));
		}
	}
	
	
	private static String solve(String[] comb, String[] opo, String inv, int n)
	{
		boolean opoMat[][] = new boolean[8][8];
		char combMat[][] = new char[8][8];
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				combMat[i][j]=NOCOMB;
		
		for(int i=0;i<opo.length;i++)
		{
			int x=base(opo[i].charAt(0));
			int y=base(opo[i].charAt(1));
			opoMat[x][y] = true;
			opoMat[y][x] = true;
		}
		for(int i=0;i<comb.length;i++)
		{
			int x=base(comb[i].charAt(0));
			int y=base(comb[i].charAt(1));
			combMat[x][y] = comb[i].charAt(2);
			combMat[y][x] = comb[i].charAt(2);
		}
		
		Stack<Character> spell = new Stack<Character>();
		
		int seen[] = new int[8];
		Arrays.fill(seen, 0);
		
		for(int i=0;i<n;i++)
		{
			boolean dontAdd=false;
			char ch = inv.charAt(i);
			if(!spell.empty())
			{
				int c1=base(ch);
				int c2=base(spell.peek());
				
				if(c2!=-1 && combMat[c1][c2]!=NOCOMB )
				{
					ch = combMat[c1][c2];
					seen[c2]--;
					spell.pop();
				}
				else if(c2!=-1 && combMat[c2][c1]!=NOCOMB )
				{
					ch = combMat[c2][c1];
					seen[c2]--;
					spell.pop();
				}
				
				//comb didnt happen
				if(ch == inv.charAt(i))
				{
					for(int k=0;k<seen.length;k++)
					{
						if(seen[k]>0)
						{
							if(opoMat[c1][k] || opoMat[k][c1])
							{
								spell.clear();
								Arrays.fill(seen, 0);
								dontAdd=true;
								break;
							}
						}
					}
				}
			}
			
			if(!dontAdd)
			{
				if(ch == inv.charAt(i))
					seen[base(ch)]++;
				spell.push(ch);
			}
			
//			debug(seen);
//			for(int l=0;l<spell.size();l++)
//				System.out.print(spell.elementAt(l)+" ");
//			System.out.println();
		}
		
		
		char[] res=new char[spell.size()];
		for(int i=res.length-1;i>=0;i--)
		{
			res[i] = spell.pop();
		}
		return Arrays.toString(res);
	}

//	1
//	4 QR FA DW SE
//	4 QFB ARO SDZ EWP
//	2 BO
	static int base(char c)
	{
		switch(c)
		{
		case 'Q': return 0;
		case 'W': return 1;
		case 'E': return 2;
		case 'R': return 3;
		
		case 'A': return 4;
		case 'S': return 5;
		case 'D': return 6;
		case 'F': return 7;
		
		default : return -1;
		}
	}
	
	static void debug(Object...objects)
	{
		System.out.println(Arrays.deepToString(objects));
	}
}
