import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * User: spuvvada
 * Date: 4/13/13
 */
public class TicTac
{

    public static void main(String [] s) throws Exception
    {
        String xwon = "X won";
        String ywon = "O won";
        String notCompleted = "Game has not completed";
        String draw = "Draw";

        int[][] xMatrix = new int[4][4];
        int[][] yMatrix = new int[4][4];

        boolean empty = false;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(br.readLine());

        String line = null;
        //cases
        for(int _case=0; _case<cases;_case++)
        {
            //xMatrix = new int[4][4];
            //yMatrix = new int[4][4];

            for(int i=0;i<4;i++)
            {
                int[] xrow = xMatrix[i];
                int[] yrow = yMatrix[i];
                Arrays.fill(xrow, 0);
                Arrays.fill(yrow, 0);
            }

            check(xwon, ywon, notCompleted, draw, xMatrix, yMatrix,  br, _case);
            br.readLine();
        }
    }

    private static void check(String xwon, String ywon, String notCompleted, String draw, int[][] xMatrix, int[][] yMatrix, BufferedReader br, int _case) throws IOException
    {
        boolean empty = false;
        String line;//for each row
        for(int j=0;j<4;j++)
        {
            line = br.readLine();

            //for each column
            for(int m=0; m<4; m++)
            {
                //for each char in a row
                char c = line.charAt(m);
                if(c == 'X')
                {
                    //xRows[j].set(m);
                    xMatrix[j][m] = 1;
                }
                else if(c == 'O')
                {
                    //yRows[j].set(m);
                    yMatrix[j][m] = 1;
                }
                else if(c == 'T')
                {
                    //xRows[j].set(m);
                    //yRows[j].set(m);
                    xMatrix[j][m] = 1;
                    yMatrix[j][m] = 1;
                }
                else if(c == '.')
                {
                    //xRows[j].set(m, 0);
                    //yRows[j].set(m,0);

                    xMatrix[j][m] = 0;
                    yMatrix[j][m] = 0;

                    empty = true;
                }
            }
        }

        //a row has been read
        //check if anybody won ?
        for(int __r = 0; __r<4; __r++)
        {
        boolean _xwon= true;
        boolean _ywon = true;
        for(int col = 0; col<4; col++)
        {
            _xwon = _xwon && (xMatrix[__r][col] == 1);
            _ywon = _ywon && (yMatrix[__r][col] == 1);
        }

        if(_xwon)
        {
            System.out.println("Case #"+(_case+1)+": "+xwon);
            return ;
        }
        else if(_ywon)
        {
            System.out.println("Case #"+(_case+1)+": "+ywon);
            return ;
        }
        }

        //all rows read
        //check for columns
        for(int c =0; c<4; c++)
        {
            boolean xwin = true;
            boolean ywin = true;
            for(int r =0; r<4; r++)
            {
                xwin = xwin && (xMatrix[r][c] == 1);
                ywin = ywin && (yMatrix[r][c]==1);
            }

            if(xwin)
            {
                System.out.println("Case #"+(_case+1)+": "+xwon);
                return ;
            }
            else if(ywin)
            {
                System.out.println("Case #"+(_case+1)+": "+ywon);
                return ;
            }
        }

        //check for diagnonals

        //fwd diagonal
        int r =0;
        int c =0;
        boolean xwin = true;
        boolean ywin = true;
        while(r<4 && c<4)
        {

            xwin = xwin && (xMatrix[r][c] == 1);
            ywin = ywin && (yMatrix[r][c]==1);

            r++;
            c++;
        }

        if(xwin)
        {
            System.out.println("Case #"+(_case+1)+": "+xwon);
            return ;
        }
        else if(ywin)
        {
            System.out.println("Case #"+(_case+1)+": "+ywon);
            return ;
        }

        //back diagonal
        r =0;
        c =3;
        xwin = true;
        ywin = true;
        while(r<3 && c>=0)
        {

            xwin = xwin && (xMatrix[r][c] == 1);
            ywin = ywin && (yMatrix[r][c]==1);

            r++;
            c--;
        }

        if(xwin)
        {
            System.out.println("Case #"+(_case+1)+": "+xwon);
            return ;
        }
        else if(ywin)
        {
            System.out.println("Case #"+(_case+1)+": "+ywon);
            return ;
        }


        if(empty)
        {
            System.out.println("Case #"+(_case+1)+": "+notCompleted);
        }
        else
        {
            System.out.println("Case #"+(_case+1)+": "+draw);
        }
    }


}
