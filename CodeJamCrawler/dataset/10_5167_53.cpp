import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class SolverThree 
{

	public static void main(String[] args) {
		SolverThree solver = new SolverThree();
		try {
			String file = "Test.txt";
			solver.solve(new BufferedReader( new FileReader(new File(file))));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	public void solve(BufferedReader reader)
	{
		try {
			FileWriter writer = new FileWriter("Saida.txt");
			long cases = Long.parseLong( reader.readLine() );
			for(int i = 1; i <= cases; i++)
			{
				String line = reader.readLine();
				long R = Long.parseLong( line.split(" ")[0] );
				long k = Long.parseLong( line.split(" ")[1] );
				int n = Integer.parseInt( line.split(" ")[2] );
				line = reader.readLine();
				long clients[] = new long[n];
				int clientCounter = 0;
				for(String client : line.split(" "))
				{
					clients[clientCounter++] = Long.parseLong(client);
				}
				//System.out.println("Case #" + i + ": " + ride(R,k,clients,n) );
				String solution =  ("Case #" + i + ": " + ride(R,k,clients,n) ) + "\n";
				writer.write( solution.toCharArray() );
			}			
			writer.flush();
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private long ride(long r, long k, long[] clients, int n) {
		long totalMoney = 0;
		int nextClient = 0;

		while( r >0 )
		{
		 long spaceLeft = k;
		 int firstClient = nextClient;
		 do
		 {
		  spaceLeft -= clients[nextClient];
		  if( spaceLeft >= 0)
		  {
		   totalMoney += clients[nextClient];
		   nextClient = (nextClient +1)%n;
		  }
		 }while( spaceLeft  > 0 && firstClient != nextClient);
		 r--;
		}
		return totalMoney;
	}
	
	
	
}
