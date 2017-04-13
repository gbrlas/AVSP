package com.spawn.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args){
		try {
			String name = readLine(); 
			Scanner s = new Scanner(new File("../" + name + ".in"));
			
			int t = s.nextInt();
			ArrayList<Case> cases = new ArrayList<Case>(t);
			File f = new File("../" + name + ".out");
			FileWriter output = new FileWriter(f);
			for(int i=0; i<t; i++){ 
				cases.add(i, new Case(i+1));
				cases.get(i).parse(s);
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
