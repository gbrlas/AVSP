import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;


public class CandySplitting {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader buffy = new BufferedReader(new FileReader(args[0]));
		int t = Integer.parseInt(buffy.readLine());
		
		
		for (int i = 0; i < t; i++){
			
			int n = Integer.parseInt(buffy.readLine());
			String cStr[] = buffy.readLine().split(" ");
			int c[] = new int[n];
			for (int j = 0; j < n; j++){
				c[j] = Integer.parseInt(cStr[j]);
			}
			String output = "Case #" + (i+1) + ": " + getMaxPile(n, c);
			System.out.println(output); 
		}
		
		

	}

	private static String getMaxPile(int n, int c[]) {
		int maxSeanPileActual = -1;
		int xor_total = 0;
		
		for (int cVal : c){
			xor_total ^= cVal;
		}
		
		if (xor_total != 0){
			return "NO";
		}
		
		BigInteger one = new BigInteger("1");
		BigInteger splits = new BigInteger("2");
		splits = splits.pow(n);
		splits = splits.subtract(one);
		/* Piles must be non-empty*/
		splits = splits.subtract(one);
		

		while (splits.getLowestSetBit() != -1) {
			int patPile = 0;
			int seanPile = 0;
			int seanPileActual = 0;
			for (int i = 0; i < n; i++){
				if (splits.testBit(i)){
					/* add to Sean pile */
					seanPile ^= c[i]; 
					seanPileActual += c[i];
				} else {
					/* add to Patrick pile */
					patPile ^= c[i];
					
				}
			}
			
			if (patPile == seanPile){
				if (maxSeanPileActual < seanPileActual) { 
					maxSeanPileActual = seanPileActual;
				}
			}
			
			splits = splits.subtract(one);
		}
		
		if (maxSeanPileActual != -1){
			return (String.valueOf(maxSeanPileActual));
		} else {
			/* Should never reach here */
			return ("NO");
		}
	}

}
