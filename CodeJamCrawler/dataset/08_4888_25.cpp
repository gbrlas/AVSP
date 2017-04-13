import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public abstract class MainClass
{   
    /**
     * @param args
     */
    public static void main(String[] args)
    {
        Scanner s;    
        try {
            s = new Scanner(new File( "teste.pipa" ));
            FileWriter f = new FileWriter( "resultado.pipa" );
            int n = Integer.parseInt(s.nextLine());
            for(int i = 0; i < n; i++) {
                f.write("Case #");
                f.write((new Integer(i+1)).toString());
                f.write(": ");
                int vectorSize = Integer.parseInt(s.nextLine());
                int vectorA[ ] = new int[vectorSize];
                int vectorB[ ] = new int[vectorSize];
                
                String vA[] = s.nextLine().split(" ");
                for(int j = 0; j < vectorSize; j++)
                {
                    vectorA[ j ] = Integer.parseInt(  vA[j] );
                }
                String vB[] = s.nextLine().split(" ");
                for(int j = 0; j < vectorSize; j++)
                {
                    vectorB[ j ] = Integer.parseInt(  vB[j] );
                }                
                
                String resposta = doIt( vectorSize, vectorA, vectorB );
                f.write( resposta );
                f.write("\n");
            }
            f.flush();
            f.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }        
    }

    private static String doIt(int vectorSize, int[] vectorA, int[] vectorB)
    {
        Arrays.sort( vectorA );
        Arrays.sort( vectorB );
       
        int produto = 0;
        for(int i = 0; i < vectorSize; i++)
        {
            produto += vectorA[i]*vectorB[vectorSize-1-i];
        }
        
        return "" + produto;
    }

}
