import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;


public class SolverTwo {

	public static void main(String[] args) {
		SolverTwo solver = new SolverTwo();
		try {
			String file = "Test.txt";
			solver.solve(new BufferedReader( new FileReader(new File(file))));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	public static BigInteger zero = new BigInteger( "0" );
	public void solve(BufferedReader reader)
	{
		try {
			FileWriter writer = new FileWriter("Saida.txt");
			long cases = Long.parseLong( reader.readLine() );
			for(int i = 1; i <= cases; i++)
			{
				String line = reader.readLine();
				int n = Integer.parseInt( line.split(" ")[0] );
				BigInteger bigNumbers[] = new BigInteger[n];
				String numbers[] = line.split(" ");
				for(int j= 1; j <= n; j++)
				{
					String number = numbers[j];
					bigNumbers[j-1] = new BigInteger(number);
				}
				
				BigInteger[] bigDifferences = diferrences(bigNumbers);
				BigInteger mdc = mdcFinder( bigDifferences );
				String resp;
				if( bigNumbers[1].remainder(mdc).equals( BigInteger.ZERO ) )
					resp = "0";
				else
					resp = mdc.subtract( bigNumbers[1].remainder(mdc) ).toString();
				
				String solution =  ("Case #" + i + ": " + resp) +"\n";
				System.out.print( solution);
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

	private BigInteger mdcFinder(BigInteger[] bigNumbers) {
		BigInteger candidate = bigNumbers[0].gcd(bigNumbers[1]);
		for( int i = 0; i< bigNumbers.length; i++)
		{
			candidate = bigNumbers[0].gcd( candidate );
		}
		return candidate;
	}

	private BigInteger[] diferrences(BigInteger[] bigNumbers) 
	{
		ArrayList<BigInteger> array = new ArrayList<BigInteger>();
		for( int i = 0; i < bigNumbers.length; i++ )
		{
			for(int j = 0; j < bigNumbers.length; j++ )
			{
				BigInteger bigInteger = bigNumbers[i].subtract(bigNumbers[j]);
				if( !bigInteger.equals(zero))
					array.add( bigInteger );
			}
		}
		return array.toArray(new BigInteger[array.size()]);
	}


}
