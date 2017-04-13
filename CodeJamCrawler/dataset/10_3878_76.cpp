/**
 * @(#)Snapper.java
 *
 *
 * @author 
 * @version 1.00 2010/5/7
 */

import java.io.*;
import java.util.Scanner;

public class Snapper {

    public Snapper() {
    }
    
    public static boolean lightOn(long k, long n)
    {
    	while (k > (1 << n)-1)
    	{
    		k -= 1<<n;
    	}
    	if (k == (1<<n) - 1)
    	{
    		return true;
    	}
    	return false;
    }
    
    public static void main(String[] args){
    	String filename = args[0];
    	try{
    	File file = new File(filename);
    	
    	Scanner sc = new Scanner(file);
    	
    	int numCases = sc.nextInt();
    	for(int i = 0; i < numCases; i++)
    	{
    		long n = sc.nextLong();
    		long k = sc.nextLong();
    		System.out.print("Case #" + (i+1) + ": ");
    		if(lightOn(k,n))
    			System.out.println("ON");
    		else
    			System.out.println("OFF");
    	}
    	}
    	catch(Exception e){
    		System.out.println(e);
    	}
    	
    }
}