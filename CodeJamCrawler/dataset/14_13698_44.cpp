package com.util;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class GoogleDeceitfulWar {

	private static List<String> resultList = new ArrayList<String>();
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in = null;
		int testCount = -1;
		int caseNo = 1;
		int numberOfBlocks = -1;
		String naomiBlocks[] = null;
		String kenBlocks[] = null;
		Double naomiBlocksNum[] = null;
		Double kenBlocksNum[] = null;
		while((in=br.readLine())!=null){
			if(testCount == -1){
				testCount = Integer.parseInt(in);
			} else if(numberOfBlocks == -1){
				numberOfBlocks = Integer.parseInt(in);
			} else if(naomiBlocks == null){
				naomiBlocks = in.split(" ");
				naomiBlocksNum = getStringArrayToDoubleArray(naomiBlocks);
			} else {
				//execute
				kenBlocks = in.split(" ");
				kenBlocksNum = getStringArrayToDoubleArray(kenBlocks);
				int warCount = doWar(Arrays.copyOf(naomiBlocksNum, naomiBlocksNum.length), Arrays.copyOf(kenBlocksNum, kenBlocksNum.length));
				int deceitefulWarCount = doDeceitfulWar(naomiBlocksNum, kenBlocksNum);				
				resultList.add("Case #"+caseNo+": "+deceitefulWarCount+" "+warCount);
				numberOfBlocks = -1;
				naomiBlocks = null;
				kenBlocks = null;
				caseNo++;
			}						
			if(testCount < caseNo){
				break;
			}
		}
		for(String out: resultList){
			System.out.println(out);
		}

	}
	
	private static int doWar(Double[] naomiBlocksNum, Double[] kenBlocksNum) {
		int count = 0;
		Arrays.sort(naomiBlocksNum);
		Arrays.sort(kenBlocksNum);
		int i=naomiBlocksNum.length-1;
		int j = 0;
		while(j<naomiBlocksNum.length){
			if(j == 0){
				if(naomiBlocksNum[i] < kenBlocksNum[0]) return 0;
				if(naomiBlocksNum[j] > kenBlocksNum[i]) return naomiBlocksNum.length;
			}
			if(naomiBlocksNum[i] > kenBlocksNum[i]){
				kenBlocksNum[getNonZeroMinIndex(kenBlocksNum)] = 0d;
				count++;
			} else {
				kenBlocksNum[i] = 0d;
			}
			naomiBlocksNum[i] = 0d;	
			Arrays.sort(naomiBlocksNum);
			Arrays.sort(kenBlocksNum);
			j++;
		}
		return count;
		
	}

	private static int getNonZeroMinIndex(Double[] kenBlocksNum) {
		int index = -1;
		for(int i=0; i<kenBlocksNum.length; i++){
			if(kenBlocksNum[i] == 0) continue;
			index = i;
			break;
		}
		return index;
	}

	private static int doDeceitfulWar(Double[] naomiBlocksNum,
			Double[] kenBlocksNum) {
		int count = 0;
		Arrays.sort(naomiBlocksNum);
		Arrays.sort(kenBlocksNum);
		for(int i=0; i< naomiBlocksNum.length; i++){
			if(i == 0) {
				if(naomiBlocksNum[i] > kenBlocksNum[kenBlocksNum.length - 1]) return naomiBlocksNum.length;
				if(naomiBlocksNum[kenBlocksNum.length - 1] < kenBlocksNum[0]) return 0;
			}
			if(naomiBlocksNum[i] > kenBlocksNum[i]){
				kenBlocksNum[i] = 0d;
				count++;
			} else {
				kenBlocksNum[kenBlocksNum.length - 1] = 0d;
			}
			naomiBlocksNum[i] = 0d;				
			Arrays.sort(naomiBlocksNum);
			Arrays.sort(kenBlocksNum);
		}
		return count;
		
	}

	private static Double[] getStringArrayToDoubleArray(String[] strArray) {
		Double[] doubleArray = new Double[strArray.length];
	    int i=0;
	    for(String str : strArray){
	    	doubleArray[i] = Double.parseDouble(str);
	        i++;
	    }
		return doubleArray;
	}

}
