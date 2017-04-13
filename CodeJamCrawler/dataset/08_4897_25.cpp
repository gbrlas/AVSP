import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
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
               
                int numberFlavor = Integer.parseInt( s.nextLine() );
                int numberClients = Integer.parseInt( s.nextLine() );
                int client[][] = new int[numberClients][numberFlavor];                     
                for(int j = 0; j < numberClients; j++ )
                {
                    String linha = s.nextLine();
                    int numberFlavorsClient = Integer.parseInt( linha.split(" ")[0] );
                    for(int z = 0; z < numberFlavorsClient; z++ )
                    {
                        int flavor = Integer.parseInt( linha.split(" ")[ 1+z*2] );
                        int malted = Integer.parseInt( linha.split(" ")[(z+1)*2] );
                        client[j][flavor-1] = malted + 1;
                    }
                }
                
                String resposta = doIt( numberFlavor, numberClients, client );
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
    
    private static boolean verifica(int[][] client, int[] test, int numberClients, int numberFlavor, int flavor, int value)
    {
            test[flavor] = value;
            if(flavor == 0)
            {
                return check( client, test, numberClients, numberFlavor);
            }            
            if( verifica( client, test, numberClients, numberFlavor, flavor-1, 1) )
            {
                return true;
            }
            else
            {
                return verifica( client, test, numberClients, numberFlavor, flavor-1, 2);
            }
    }

    private static String doIt(int numberFlavor, int numberClients, int[][] client)
    {
        int []test = new int[numberFlavor];
        String resposta = "";
        if( verifica(client, test, numberClients, numberFlavor, numberFlavor-1, 1) )
        {
            for(int i = 0; i< numberFlavor; i++)
                resposta += test[i]-1 + " ";
        }
        else if( verifica(client, test, numberClients, numberFlavor, numberFlavor-1, 2) )
        {
            for(int i = 0; i< numberFlavor; i++)
                resposta += test[i]-1 + " ";
        }
        else 
        {
            resposta = "IMPOSSIBLE";
        }        
        
        return resposta;
    }

    private static boolean check(int[][] client, int[] test, int numberClients, int numberFlavor)
    {
        for(int i = 0; i < numberClients; i++)
        {
            boolean satisfaz = false;
            for(int j = 0; j < numberFlavor; j++)
            {
                if( client[i][j] == test[j] )
                    satisfaz = true;
            }
            if( !satisfaz )
                return false;
        }
        return true;
    }

    private static String doIt(int number)
    {        
        if(number == 0)
            return "001";
        double parcela = 3 + Math.sqrt( 5 );
        //double resultado = Math.pow(parcela, number);
        double resultado = parcela;
        for( int i = 1; i < number; i++)
        {
            resultado *= parcela;
            resultado %= 1000;
        }
        System.out.println( resultado );
        long resposta = Math.round( Math.floor (resultado%1000) );
        if( resposta < 10 )
            return "00" + resposta;
        if( resposta < 100 )
            return "0" + resposta;
        return "" + resposta;
    }

}
