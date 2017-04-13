import java.util.*;

public class x
{
static int[][] d = new int[][]{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
public static void main(String[] args) throws Throwable{
    Scanner in = new Scanner(System.in);
    int t = Integer.parseInt(in.nextLine());
    for(int i = 1; i <= t; i++)
    {
        System.out.print("Case #"+i+": ");
        String[] ttt = in.nextLine().split(" ");
        int n = Integer.parseInt(ttt[0]);
        int K = Integer.parseInt(ttt[1]);
        char[][] b = new char[n][n];
        for(int j = 0; j < n; j++)
            b[j] = in.nextLine().toCharArray();
        boolean chg = true;
        for(int iter = 0; chg; iter++){chg = false;
        for(int j = 0; j < n; j++)
            for(int k = n-2; k >= 0; k--)
                if(b[j][k] != '.' && b[j][k+1] == '.')
                {
                    b[j][k+1] = b[j][k];
                    b[j][k] = '.';
                    chg = true;
                }
        }
        boolean rw = false, bw = false;
        for(int j = 0; j < n; j++)
        for(int k = 0; k < n; k++)for(int kk = 0; kk < 8; kk++){boolean rwh = true, bwh = true;
        for(int p = 0; p < K; p++)
        {
            try{
            if(b[j+p*d[kk][0]][k+p*d[kk][1]] != 'R')rwh = false;
            if(b[j+p*d[kk][0]][k+p*d[kk][1]] != 'B')bwh = false;
            
            }catch(Exception e){rwh = bwh = false;}
        }
        rw|=rwh; bw|=bwh;
        }
        System.out.println(rw&&bw?"Both":rw?"Red":bw?"Blue":"Neither");}
            }}