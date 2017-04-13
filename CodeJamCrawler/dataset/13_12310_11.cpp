package com.util;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;


public class GoogleBullsEye {
	private static List<String> list = new ArrayList<String>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in = null;
		int testCount = -1;
		int caseNo = 1;
		BigInteger r = null;		
		BigInteger t = null;
		while((in=br.readLine())!=null){
			if(testCount == -1){
				testCount = Integer.parseInt(in);
			} else {
				r = new BigInteger(in.split(" ")[0]);
				t = new BigInteger(in.split(" ")[1]);
				check(r, t, caseNo);
				caseNo++;
			}
			if(testCount < caseNo){
				break;
			}

		}
		for(String out: list){
			System.out.println(out);
		}

	}
	private static void check(BigInteger r, BigInteger t, int caseNo) {
		BigInteger black = new BigInteger("0"); 
		BigInteger paint = null;		
		paint = r.multiply(new BigInteger("2")).add(BigInteger.ONE)	;
		while(t.compareTo(paint) >= 0){
			black = black.add(BigInteger.ONE);			
			r = r.add(new BigInteger("2"));
			t = t.subtract(paint);
			paint = r.multiply(new BigInteger("2")).add(BigInteger.ONE)	;			
		}
		list.add("Case #"+caseNo+": "+black.toString());
	}

}
