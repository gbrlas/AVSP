import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;


public class SolverOne 
{
	
	public static void main(String[] args) {
		SolverOne solver = new SolverOne();
		try {
			//String file = args[0];
			String file = "Test.txt";
			solver.solve(new BufferedReader( new FileReader(new File(file))));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
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
				long n = Long.parseLong( line.split(" ")[0] );
				long k = Long.parseLong( line.split(" ")[1] );
				String solucao = "Case #" + i + ": " + (isOnTurbo(n, k)?"ON":"OFF") + "\n";
				writer.write( solucao.toCharArray() );
			}			
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public boolean isOn(long n, long k)
	{
	 long x = (2 << n) -1;
	 long y = (2 << n);
	 return (k % y == x);
	}
	
	public boolean isOnTurbo(long n, long k)
	{
		long x = (1 << n) -1;	 
		return (k & x) == x;
	}
	
}
