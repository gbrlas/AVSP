/**
 * @(#)RollerCoaster.java
 *
 *
 * @author 
 * @version 1.00 2010/5/8
 */

import java.util.LinkedList;
import java.io.*;
import java.util.Scanner;


public class RollerCoaster {

    public RollerCoaster() {
    }
    
    public static long calcProfit(int r, long k, LinkedList<Long> groups)
    {
    	long profit = 0;
    	boolean flag = true;
    	for(int i = 0; i < r; i++)
    	{
    		long total = 0;
    		LinkedList<Long> popped = new LinkedList<Long>();
    		long nextGroup = groups.removeFirst();
    		while(total+nextGroup <= k)
    		{
    			popped.add(nextGroup);
    			total = total + nextGroup;
    			if(groups.size() != 0)
    				nextGroup = groups.removeFirst();
    			else
    			{
    				flag = false;
    				break;
    			}
    		}
    		if(flag)
    			groups.addFirst(nextGroup);
    		profit += total;
    		groups.addAll(popped);
    		flag = true;
    	}
    	return profit;
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
    		int r = sc.nextInt();
    		long k = sc.nextLong();
    		int numGroups = sc.nextInt();
    		LinkedList<Long> groups = new LinkedList<Long>();
    		for(int j = 0; j < numGroups; j++)
    		{
    			long group = sc.nextLong();
    			groups.add(group);
    		}
    		long answer = calcProfit(r, k, groups);
    		System.out.println("Case #" + (i+1) + ": " + answer);
    	}
    	
    	
    	}
    	catch(FileNotFoundException e){
    		System.out.println(e);
    	}
    }
}