package com.wildhemp.codejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class Bullseye {

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
	BufferedReader dis = new BufferedReader(new InputStreamReader(
		new FileInputStream(args[0])));

	int testNum = Integer.parseInt(dis.readLine());
	for (int test = 0; test < testNum; test++) {
	    String[] strs = dis.readLine().split(" ");
	    long r = Long.parseLong(strs[0]);
	    long t = Long.parseLong(strs[1]);
	    
	    long p = (r + 1) * (r + 1) - r * r;
	    long curr = p;
	    long counter = 0;
	    for (; curr <= t; counter ++) {
		p += 4;
		curr += p;
	    }
	    
	    System.out.println("Case #" + (test + 1) + ": " + counter);
	}
    }

}
