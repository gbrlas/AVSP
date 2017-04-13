package com.spawn.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.atomic.AtomicInteger;


class Case {

	public int caseNumber;
	public String result;
	public Case(int i, Scanner s){
		caseNumber = i;
		parse(s);
	}
	
	public String getResult(){
		return "Case #" + caseNumber + ": " + result + "\n";
	}
	
	long a, b, k;
	public void parse(Scanner s){
		a = s.nextLong();
		b = s.nextLong();
		k = s.nextLong();
	}
	
	public void solve() {
		long sum = 0;
		for(long i=0; i<a; i++)
			for(long j=0; j<b; j++)
				if((i & j) < k)
					sum++;
		result = Long.toString(sum);
			
		System.out.println("#" + caseNumber + " done; " + Main.casesRemaining.decrementAndGet() + " remaining");
	}
}


public class Main {

	public static AtomicInteger casesRemaining = new AtomicInteger();
	public static void main(String[] args){
		try {
			String name = readLine(); 
			Scanner s = new Scanner(new File("../" + name + ".in"));
			
			int t = s.nextInt();
			casesRemaining.set(t);
			ArrayList<Case> cases = new ArrayList<Case>(t);
			File f = new File("../" + name + ".out");
			FileWriter output = new FileWriter(f);
			for(int i=0; i<t; i++){ 
				cases.add(i, new Case(i+1, s));
			}
			cases.parallelStream().forEach(Case::solve);
			
			for(int i=0; i<t; i++){
				output.write(cases.get(i).getResult());
			}
			output.close();
			s.close();
			
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private static String readLine() throws IOException {
	    if (System.console() != null) {
	        return System.console().readLine();
	    }
	    BufferedReader reader = new BufferedReader(new InputStreamReader(
	            System.in));
	    return reader.readLine();
	}
	
}

