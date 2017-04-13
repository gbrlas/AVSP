/**
 * @(#)Jamcode.java
 *
 *
 * @author 
 * @version 1.00 2010/5/8
 */

import java.math.BigInteger;
import java.io.*;
import java.util.Scanner;

public class Jamcode {

    public Jamcode() {
    }
    
    public static BigInteger calc(BigInteger[] times)
    {
    	int n = times.length;
    	BigInteger[] differences = new BigInteger[((n*(n-1))/2)];
    	int counter = 0;
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = i+1; j < n; j++){
    			differences[counter] = (times[i].subtract(times[j])).abs();
    			counter += 1;
    		}
    	}
    	
    	BigInteger multiple = differences[0];
    	
    	for(int i = 1; i < differences.length; i++)
    	{
    		multiple = multiple.gcd(differences[i]);
    	}
    	
    	//System.out.println(multiple);
    	if (times[0].mod(multiple).equals(BigInteger.ZERO))
    		return BigInteger.ZERO;
    	return multiple.subtract(times[0].mod(multiple));
    }
    
    public static void main(String[] args)
    {
    	String filename = args[0];
    	try{
    	File file = new File(filename);
    	
    	Scanner sc = new Scanner(file);
    	
    	int numCases = sc.nextInt();
    	
    	for(int i = 0; i < numCases; i++)
    	{
    		int n = sc.nextInt();
    		BigInteger[] numArray = new BigInteger[n];
    		for(int j = 0; j < n; j++)
    		{
    			String nextStr = sc.next();
    			BigInteger b = new BigInteger(nextStr);
    			numArray[j] = b;
    		}
    		BigInteger answer = calc(numArray);
    		System.out.println("Case #" + (i+1) + ": " + answer);
    	}
    	
    	
    	}
    	catch(Exception e){
    		System.out.println(e);
    	}
    	
    }
}