import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class A {

	/**
	 * @param args
	 */
	
		// TODO Auto-generated method stub
		static FileWriter fw;
		public static void main(String[] args) throws IOException {
			Scanner sc = new Scanner(new FileReader("A-small-attempt0(2).in"));
			fw =  new FileWriter("output.txt");
			int n = sc.nextInt();
			sc.nextLine();
			for(int q =0; q <n;q++)
			{
				//System.out.println(q);
				int teams = sc.nextInt();
				String[] str = new String[teams];
				for(int i=0; i < teams;i++)
				{
					str[i] = sc.next();
				}
				fw.write("Case #"+(q+1)+": \n");
				solve(teams,str);
				
			}
			fw.close();

	}
		public static void solve(int n,String[] teamData) throws IOException
		{
			char[][] grid = new char[n][n];
			boolean[][] np = new boolean[n][n];
			double[] WP = new double[n];
			double[] OP =new double[n];
			double WOOP[] = new double[n];
			
			for(int i =0; i < teamData.length;i++) //NOW IN GRID
			{
				String str = teamData[i];
				for(int j =0; j < str.length();j++)
				{
					grid[i][j] = str.charAt(j);
				}
			}
			
			for(int i =0; i < n;i++)
			{
				int notPlayed = 0;
				for(int j =0; j < n;j++)
				{
					if(grid[i][j] == '.')
					{
						notPlayed++;
						np[i][j] =true;
					}
					else
					{
						if(grid[i][j] == '1')
						{
							WP[i]++;
						}
					}
				}
				WP[i] /= (1.0*n-notPlayed);
				
			}
			
			for(int t = 0; t < n;t++)
			{double tot = 0;
			int noTeam = 0;
				for(int i =0; i < n;i++)
				{
					
					if(i==t)continue; if( np[i][t])
						{ //IGNORE THE TEAM THAT YOU ARE CHECKING
						noTeam ++;
						continue;
						}
					int wins =0;
					int notPlayed = 0;
					for(int j =0; j < n;j++)
					{
						if(j == t) 
							{
							continue; //THROW THE GAME
							
							}
						if(grid[i][j] == '.')
						{
							notPlayed++;
							np[i][j] = true;
						}
						if(grid[i][j] == '1')
						{
							wins++;
							
						}
							
							 
					}
					tot += 1.0*wins/(1.0*n-notPlayed-1);//System.out.println("i "+ t + "  "+tot + " "+tot/(n-1-noTeam));
				}tot /=(1.0*n-1-noTeam);//System.out.println(tot + " "+t);
				
				OP[t] = tot;
				
				
			}
			for(int i =0; i < n;i++)
			{
				int p = 0;
				for(int j =0; j < n;j++)
				{if(j==i )
					{
					continue;
					
					}
				if(np[i][j]){p++;continue;}
				WOOP[i] += OP[j];
				}WOOP[i] /= (1.0*(n-1-p));
			}//System.out.println(OP[3]);
			for(int i =0; i < n;i++)
			{
				fw.write(""+(0.25 * WP[i] + 0.50 * OP[i] + 0.25 * WOOP[i]) + "\n");

			}
			
			
			
			
		}

}
