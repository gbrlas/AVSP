import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
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

                int k = Integer.parseInt( s.nextLine() );
                String string =  s.nextLine() ;
                
                String resposta = doIt( k, string );
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
    
    private static int tamanho(String string, int permutacao[], int pos, int k)
    {
        int x = 0;
        permutacao[pos] = x++;                
        
        if( k == pos)
        {
        }
        else
        {
            return tamanho( string, permutacao, pos++, k );
        }
        return 0;
    }

    private static String doIt(int k, String string)
    {               
        
        int permutacao[] = new int[k];
        int counter = 1000;
        int best = string.length();
        while( counter-- > 0 )
        {

            for(int i = 0; i < k; i++)
            {
                int valor = (int)Math.round((Math.random()*10000)%(k-1));
                boolean invalido = false;
                for(int j = 0; j <i;j++)
                {
                    if( permutacao[j] == valor )
                    {
                        invalido = true;
                    }
                }
                if(invalido)
                {
                    i--;
                    continue;
                }
                permutacao[i] = valor;                
            }
    
            
            char entrada[] = string.toCharArray();           
            char saida[] = new char[ entrada.length ];            
            for(int j = 0; j < (entrada.length /k); j++)
            {
                for(int i = 0; i<k; i++)
                {
                    saida[j*k+i] = entrada[ j*k+permutacao[i] ];
                }
            }            
            char verificar = saida[0];
            int contagem = 1;
            for(int i = 0; i < saida.length; i++)
            {
                if( saida[i] != verificar)
                {
                    verificar = saida[i];
                    contagem++;
                }               
            }
            best = Math.min(contagem, best);
        }
        System.out.println(best);
        return "" + best;
    }

}
