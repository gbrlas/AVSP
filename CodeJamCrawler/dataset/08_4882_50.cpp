import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
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
                int turnaroundTimeInMinutes = Integer.parseInt(s.nextLine());
                String line = s.nextLine();
                int numberA = Integer.parseInt( line.split(" ")[0] );
                int numberB = Integer.parseInt( line.split(" ")[1] );
                String aTrips[] = new String[ numberA ];
                String bTrips[] = new String[ numberB ];
                for(int j = 0; j < numberA; j++)
                {
                    aTrips[j] = s.nextLine();
                }
                for(int j = 0; j < numberB; j++)
                {
                    bTrips[j] = s.nextLine();
                }                
                
                String resposta = doIt( turnaroundTimeInMinutes, aTrips, bTrips );
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

    private static String doIt(int turnaroundTimeInMinutes, String[] aTrips, String[] bTrips)
    {
        int aArrive[] = new int[bTrips.length];
        int bArrive[] = new int[aTrips.length];
        int aDeparture[] = new int[aTrips.length];
        int bDeparture[] = new int[bTrips.length];
        
        int i = 0;
        for(String trip : aTrips)
        {   
            String departure = trip.split(" ")[0];
            String arrive = trip.split(" ")[1];
            bArrive[ i ] = new Integer( arrive.split(":")[0] ) * 60 + new Integer( arrive.split(":")[1] ) + turnaroundTimeInMinutes;
            aDeparture[ i++ ] = new Integer( departure.split(":")[0] ) * 60 + new Integer( departure.split(":")[1] );
        }
        i = 0;
        for(String trip : bTrips)
        {   
            String departure = trip.split(" ")[0];
            String arrive = trip.split(" ")[1];
            aArrive[ i ] = new Integer( arrive.split(":")[0] ) * 60 + new Integer( arrive.split(":")[1] ) + turnaroundTimeInMinutes;          
            bDeparture[ i++ ] = new Integer( departure.split(":")[0] ) * 60 + new Integer( departure.split(":")[1] );
        }
        
        Arrays.sort( aArrive );
        Arrays.sort( bArrive );
        Arrays.sort( aDeparture );
        Arrays.sort( bDeparture );
        
        int aTrains = 0;
        int bTrains = 0;
        aTrains = calculateTrains(aArrive, aDeparture, aTrains);
        bTrains = calculateTrains(bArrive, bDeparture, bTrains);
        
        return aTrains + " " + bTrains;
    }

    private static int calculateTrains(int[] aArrive, int[] aDeparture, int aTrains)
    {
        int gotTrains = 0;
        int arriveIndex = 0;
        int departureIndex = 0;
        System.out.println( aArrive.length  );
        System.out.println( aDeparture.length  );
        for(int j = 0; j <  aArrive.length + aDeparture.length; j++)
        {      
            if(aDeparture.length == 0 || departureIndex >= aDeparture.length)
            {
                gotTrains++;
                arriveIndex++;
                continue;
            }
            if(aArrive.length == 0 || arriveIndex >= aArrive.length)
            {
                if(gotTrains == 0)                   
                {
                    aTrains++;
                }
                else
                    gotTrains--;
                continue;
            }
            
            if(aArrive[arriveIndex] > aDeparture[departureIndex] )
            {
                if(gotTrains == 0)                   
                {
                    aTrains++;
                }
                else
                    gotTrains--;
                    
                departureIndex++;
            }
            else
            {
                gotTrains++;
                arriveIndex++;
            }
        }
        return aTrains;
    }

}
