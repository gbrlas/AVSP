/**
 * @(#)Prob2.java
 *
 *
 * @author 
 * @version 1.00 2010/6/5
 */
import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.lang.Math;


public class Prob2 {

		int[][] cell = new int[103][103];

    public Prob2() {
    }
    
    public void print()
    {
    	for(int i = 0; i < 10; i++)
    	{
    		for(int j = 0; j < 10; j++)
    		{
    			System.out.print(cell[i][j]);
    		}
    		System.out.println();
    	}
    }
    
    public void step()
    {
    	for(int i = 101; i >= 1; i--)
    	{
    		for(int j = 101; j >= 1; j--)
    		{
    			if(cell[i][j] == 1 && cell[i-1][j] == 0 && cell[i][j-1] == 0)
    				cell[i][j] = 0;
    			else if(cell[i][j] == 0 && cell[i-1][j] == 1 && cell[i][j-1] == 1)
    				cell[i][j] = 1;
    		}
    	}
    }
    
    public boolean isEmpty()
    {
    	for(int i = 0; i < 103; i++)
    	{
    		for(int j = 0; j < 103; j++)
    		{
    			if(cell[i][j] == 1)
    				return false;
    		}
    	}	
    	return true;	
    }
    
    public static void main(String[] args){
    	String filename = args[0];
    	
    	try{
    	File file = new File(filename);
    	
    	Scanner sc = new Scanner(file);
    	
    	int numCases = sc.nextInt();
    	
    	for(int i = 0; i < numCases; i++)
    	{
    		Prob2 solver = new Prob2();
    		int numBoxes = sc.nextInt();
    		for(int j = 0; j < numBoxes; j++)
    		{
    			int x1 = sc.nextInt();
    			int y1 = sc.nextInt();
    			int x2 = sc.nextInt();
    			int y2 = sc.nextInt();
    			for(int y = y1; y < y2+1; y++)
    			{
    				for(int x = x1; x < x2+1; x++)
    				{
    					solver.cell[y][x] = 1;
    				}
    			}
    		}
    		int counter = 0;
    		while(!solver.isEmpty())
    		{
    			solver.step();
    			counter += 1;
    		}
    		System.out.println("Case #" + (i+1) + ": " + counter);
    	}
    	
    	
    	}
    	catch(Exception e){
    		System.out.println(e);
    	}
    }
}