import java.util.Scanner;

public class WaterShed2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char[][] map2;
		int[][] map1;
		int i,j,m;
		int x,y;
		int xl,yl;
		int T;//number of the maps
		int h,w;//height and width of the current map
		int lable = 97;
		
		Scanner scanner = new Scanner(System.in);
		T=scanner.nextInt();
		for(m=0;m<T;m++)
		{
			lable = 97;
			//scanmaps
			h=scanner.nextInt();
			w=scanner.nextInt();
			map1 = new int[h][w];
			map2 = new char[h][w];
			x=0;
			y=0;
			for(i=0;i<h;i++)
				for(j=0;j<w;j++)
				{
					map1[i][j]=scanner.nextInt();
				}
			
			while(true)
			{
				int flag1 = 0;
				//first step: find the first
				for(i=0;i<h;i++)
				{
					for(j=0;j<w;j++)
						if(map2[i][j]==0)
						{
							flag1=1;
							x=i;
							y=j;
							break;
						}
					if(flag1==1)
						break;
				}
				
				map2[x][y]= (char)lable;
				//find the river from the peek
				while(true)
				{
					//find the lowest direction and mark
					{
						xl=x;
						yl=y;
						if(x-1>=0 && map1[x-1][y]<map1[x][y])
						{
							xl=x-1;
						}
						if(y-1>=0 && map1[x][y-1]<map1[xl][yl])
						{
							xl=x;
							yl=y-1;
						}						
						if(y+1<w && map1[x][y+1]<map1[xl][yl])
						{
							xl=x;
							yl=y+1;
						}
						if(x+1<h && map1[x+1][y]<map1[xl][yl])
						{
							xl=x+1;
							yl=y;
						}
					}
					{
						if(xl==x && yl==y)
						{
							lable++;
							break;
							//if no lower direction, break
						}
					}
						
					//merge if there is already a basin, and break
					{
						if(map2[xl][yl]!=0)
						{
							//unite
							int tempmap2;
							tempmap2=map2[x][y];
							for(i=0;i<h;i++)
								for(j=0;j<w;j++)
									if(map2[i][j]==tempmap2)
										map2[i][j]=map2[xl][yl];
							lable=tempmap2;
							//and break
							break;
						}
						else 
						{
							//if not match, carry on
							map2[xl][yl]=map2[x][y];
							x=xl;
							y=yl;
						}
					}
				}
				//if all are marked, then break
				int flag=0;
				for(i=0;i<h;i++)
					for(j=0;j<w;j++)
						if(map2[i][j]==0)
							flag=1;
				if(flag==0)
					break;
			}
			//print
			System.out.println("Case #"+(m+1)+":");
			for(i=0;i<h;i++)
			{
				for(j=0;j<w;j++)
					if(j==0)
						System.out.print(map2[i][j]);
					else
						System.out.print(" "+map2[i][j]);
				System.out.println();
			}
		}
	}
}

