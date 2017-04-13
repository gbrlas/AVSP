package com.util;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class GooleElf {

	private static List<String> resultList = new ArrayList<String>();
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in = null;
		int testCount = -1;
		double p = 0;
		double q = 0;
		int caseNo = 1;
		long gen = 1;
		while((in=br.readLine())!=null){
			if(testCount == -1){
				testCount = Integer.parseInt(in);
			} else {
				boolean whileLoop = true;
				p = Double.parseDouble(in.split("/")[0]);
				q = Double.parseDouble(in.split("/")[1]);
				double temp = 0;				
				if(q%2 != 0){
					resultList.add("Case #"+caseNo+": impossible");
				} else {
					for(int i=1; ; i++){
						temp = Math.pow(2, i);
						if( temp == q){
							break;
						} else if(temp > q){
							resultList.add("Case #"+caseNo+": impossible");
							whileLoop = false;
							break;
						}
					}
					while(whileLoop){
						if((Math.pow(2, gen)*p)/q >= 1){
							resultList.add("Case #"+caseNo+": "+gen);
							gen = 1;
							break;
						} else {
							gen++;
						}
					}					
				}
				caseNo++;
				if(testCount < caseNo){
					break;
				}
			}			
		}
		for(String out: resultList){
			System.out.println(out);
		}
	}

}
