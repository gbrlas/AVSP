/**
 * @(#)Prob3.java
 *
 *
 * @author 
 * @version 1.00 2010/6/5
 */
import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.lang.Math;


public class Prob3 {
		
		ArrayList<ArrayList<Integer>> bracket = new ArrayList<ArrayList<Integer>>();
		public int p;
		
    public Prob3(int numTeams, int p) {
    	this.p = p;
    	int k = numTeams/2;
    	ArrayList<Integer> line = new ArrayList<Integer>();
    	while(k > 0)
    	{
    		line = new ArrayList<Integer>();
    		for(int i = 0; i < k; i++)
    		{
    			line.add(0);
    		}
    		this.bracket.add(line);
    		k =  k/2;
    	}
    }
    
    public int solve(int[] missGames)
    {
    	for(int i = 0; i < missGames.length; i++)
    	{
    		int game = i/2;
    		int numToMiss = missGames[i];
    		for(int j = 0; j < p; j++)
    		{
    			if(j >= numToMiss)
    			{
    				bracket.get(j).set(game, 1);
    			}
    			game = game/2;
    		}
    	}
    	
    	return this.total();
    }
    
    public int total()
    {
    	int answer = 0;
    	for(int i = 0; i < bracket.size(); i++){
    		for(int j = 0; j < bracket.get(i).size(); j++){
    			if(bracket.get(i).get(j) == 1)
    				answer++;
    		}
    	}
    	return answer;
    }
    
    public static void main(String[] args){
    	String filename = args[0];
    	
    	try{
    	File file = new File(filename);
    	
    	Scanner sc = new Scanner(file);
    	
    	int numCases = sc.nextInt();
    	
    	for(int i = 0; i < numCases; i++)
    	{
    		int p = sc.nextInt();
    		int[] missGames = new int[(int)Math.pow(2,p)];
    		for(int j = 0; j < (int)Math.pow(2,p); j++)
    		{
    			missGames[j] = sc.nextInt();
    		}
    		for(int k = 0; k < (int)Math.pow(2,p)-1; k++)
    		{
    			sc.nextInt();
    		}
    		
    		Prob3 solver = new Prob3((int)Math.pow(2,p), p);
    		
    		int answer = solver.solve(missGames);
    		
    		System.out.println("Case #" + (i+1) + ": " + answer);
    	}
    	
    	
    	}
    	catch(Exception e){
    		System.out.println(e);
    	}
    }
}