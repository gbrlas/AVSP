import java.util.regex.Pattern;
import java.util.Scanner;

public class Watersheds {
  public static void main(String args[]) {

	int i, j, k, p, cur, nextJ, nextK, min, oldJ, oldK;
	char nextBasin = 'a', curBasin;
	int acuJ[] = new int[1000];
	int acuK[] = new int[1000];

	Scanner in = new Scanner(System.in);
	
	/* Read the T value */
	int T = in.nextInt();

	for(i = 0; i < T; i++)
	{
		nextBasin = 'a';
		/* Read H W values */
		int H = in.nextInt();
		int W = in.nextInt();
		int map[][] = new int[H][W];
		char basins[][] = new char[H][W];

		/* Read the map */
		for(j = 0; j < H; j++)
		{
			for(k = 0; k < W; k++)
			{
				map[j][k] = in.nextInt();		
			}
		}

		for(j = 0; j < H; j++)
		{
			for(k = 0; k < W; k++)
			{
				if(Character.isLowerCase(basins[j][k]))
				{
					continue;
				}
				else
				{
					cur = 0;
					oldJ = j;
					oldK = k;
					while(true)
					{
						min = map[j][k];
						nextJ = -1;
						nextK = -1;

						/* Check North */
						if(j > 0 && map[j-1][k] < min)
						{
							min = map[j-1][k];
							nextJ = j-1;
							nextK = k;
						}
						
						/* Check West */
						if(k > 0 && map[j][k-1] < min)
						{
							min = map[j][k-1];
							nextJ = j;
							nextK = k-1;
						}

						/* Check East */
						if(k < W-1 && map[j][k+1] < min)
						{
							min = map[j][k+1];
							nextJ = j;
							nextK = k+1;
						}	

						/* Check South */
						if(j < H-1 && map[j+1][k] < min)
						{
							min = map[j+1][k];
							nextJ = j+1;
							nextK = k;
						}	
	
						if(nextJ >= 0 && !Character.isLowerCase(basins[nextJ][nextK]))
						{
							acuJ[cur] = j;
							acuK[cur] = k;
							cur++;
							j = nextJ;
							k = nextK;
						}
						else
						{
							/* Clear Accumulated Part */
							if(nextJ >= 0 && Character.isLowerCase(basins[nextJ][nextK]))
							{
								curBasin = basins[nextJ][nextK];
							}
							else
							{
								curBasin = nextBasin;
								nextBasin++;
							}
							basins[j][k] = curBasin;
							p = 0;
							while(p < cur)
							{
								basins[acuJ[p]][acuK[p]] = curBasin;
								p++;
							}
							j = oldJ;
							k = oldK;
							break;
						}	
					}
				}
			}
		}
		System.out.println("Case #" + (i+1) + ":");
		for(j = 0; j < H; j++)
		{
			for(k = 0; k < W; k++)
			{
				System.out.print(basins[j][k] + " ");
			}
			System.out.println();
		}
	}

  }

}
