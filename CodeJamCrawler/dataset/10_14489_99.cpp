import java.io.BufferedReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class Solution {

	/**
	 * @param args
	 */
	
	
	public static void main(String[] args) {
	
		Arquivo arq = new Arquivo("b.in","b.out");
		int t = arq.readInt();
		BigInteger numbers[], mdc;
		
		for(int i = 0; i < t; i++){
			int n = arq.readInt();
			numbers = new BigInteger[n];
			for(int j = 0; j < n; j++){
				
				String s = arq.readString();
				numbers[j] = new BigInteger(s);
			}
			mdc = new BigInteger("0");
			for(int j = 0; j < n; j++){
				for(int k = j+1; k < n; k++){
					BigInteger b = numbers[j].subtract(numbers[k]).abs();
					mdc = mdc.gcd(b);
				}
			}
			
			BigInteger y;
			
			y = numbers[0].mod(mdc);
			
			if(y.compareTo(BigInteger.ZERO) != 0){
				y = mdc.subtract(y);
			}
			
			arq.print("Case #" + (i+1) + ": ");
			arq.print(y.toString());
			arq.print("\n");
			
		}
		arq.close();
	}

	

}
