package com.util;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;


public class GoogleFnS {
	private static List<String> list = new ArrayList<String>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in = null;
		int testCount = -1;
		int caseNo = 0;
		BigInteger bi = null;
		BigInteger biEnd = null;
		BigInteger temp = null;
		int resultCount = 0;
		while((in=br.readLine())!=null){
			if(testCount == -1){
				testCount = Integer.parseInt(in);
			} else {
				caseNo++;				
				bi = new BigInteger(in.split(" ")[0]);
				biEnd = new BigInteger(in.split(" ")[1]);
				while(true){
					temp = getNextPalindrom(bi.toString());
					int diff = biEnd.compareTo(temp);
					if(diff>=0){
						double d = Math.sqrt(temp.doubleValue());
						if("0".equals((""+d).split("[.]")[1])){
							if(isPalindrom((""+d).split("[.]")[0])){
								resultCount++;
							}							
						}
					} else {
						break;
					}
					temp = temp.add(BigInteger.ONE);
					bi = temp;
				}
				list.add("Case #"+caseNo+": "+resultCount);
				resultCount = 0;
				if(testCount == caseNo){
					break;
				}
			}
		}
		for(String out: list){
			System.out.println(out);
		}

	}
	
	private static boolean isPalindrom(String s) {
		int len = s.length();
		if(len == 1) return true;
		String p1, p2;
		BigInteger b1, b2;
		boolean pal = false;
		if(len%2 == 0){
			p1 = s.substring(0, len/2);
			p2 = s.substring(len/2);
			b1 = new BigInteger(p1);
			b2 = new BigInteger(p2);
			int diff = b1.compareTo(b2);
			if(diff == 0){
				pal = true;
			} 
		} else {
			p1 = s.substring(0, len/2);
			p2 = s.substring((len/2)+1);
			b1 = new BigInteger(p1);
			b2 = new BigInteger(p2);
			int diff = b1.compareTo(b2);
			if(diff == 0){
				pal = true;
			}
		}
		return pal;
	}

	static BigInteger getNextPalindrom(String s){
		int len = s.length();
		if(len == 1) return new BigInteger(s);
		String p1, p2;
		BigInteger b1, b2;
		String pal = null;
		if(len%2 == 0){
			p1 = s.substring(0, len/2);
			p2 = s.substring(len/2);
			b1 = new BigInteger(p1);
			b2 = new BigInteger(p2);
			int diff = b1.compareTo(b2);
			if(diff>0){
				pal = p1+new StringBuffer(p1).reverse();
			} else if(diff == 0){
				pal = s;
			} else{
				b1=b1.add(BigInteger.ONE);				
				pal = b1.toString()+new StringBuffer(b1.toString()).reverse();
			}
		} else {
			p1 = s.substring(0, len/2);
			int mid = Integer.parseInt(s.substring(len/2, (len/2)+1));
			p2 = s.substring((len/2)+1);
			b1 = new BigInteger(p1);
			b2 = new BigInteger(p2);
			int diff = b1.compareTo(b2);
			if(diff>0){
				pal = p1+mid+new StringBuffer(p1).reverse();
			} else if(diff == 0){
				pal = s;
			} else{
				mid = mid+1;
				if(mid == 10){
					b1=b1.add(BigInteger.ONE);	
					pal = b1.toString()+"0"+new StringBuffer(b1.toString()).reverse();
				} else {
					pal = b1.toString()+mid+new StringBuffer(b1.toString()).reverse();
				}
				
			}
		}
		return new BigInteger(pal);
	}

}
