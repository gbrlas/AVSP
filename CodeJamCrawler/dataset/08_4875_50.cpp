import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Hashtable;
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
                int numServidores = Integer.parseInt(s.nextLine());
                String servidores[] = new String[ numServidores ];
                for(int j = 0; j < numServidores; j++)
                {
                    servidores[j] = s.nextLine();
                }
                int numQueries = Integer.parseInt(s.nextLine());
                String queries[] = new String[ numQueries ];
                for(int j = 0; j < numQueries; j++)
                {
                    queries[j] = s.nextLine();
                }
                
                String resposta = doIt( servidores, queries );
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

    private static String doIt(String[] servidores, String[] queries)
    {
        Hashtable<String, Integer> servidoresHash = new Hashtable<String, Integer>();
        int i = 0;
        for(String servidor : servidores)
        {
            servidoresHash.put(servidor, i++);
        }
        int usage[] = new int[servidores.length];
        int switchs = 0;
        int sobrando = servidores.length;
        for(String query : queries)
        {
            int servidorNum = servidoresHash.get( query );
            if( usage[servidorNum] != 0x666)
            {
                sobrando--;
                usage[servidorNum] = 0x666;    
            }
            if(sobrando == 0)
            {
                switchs++;
                sobrando = servidores.length-1;
                usage = new int[servidores.length];
                usage[servidorNum] = 0x666;
            }
        }
        
        // TODO Auto-generated method stub
        return "" + switchs;
    }

}
