package com.util;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class GoogleTic {
	private static List<String> list = new ArrayList<String>();
	private static List<String> resultList = new ArrayList<String>();
	static char input[][] = new char[4][4];
	static boolean isResult = false;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in = null;
		int testCount = -1;
		int caseNo = 1;
		int index = 0;		
		while((in=br.readLine())!=null){
			if(testCount == -1){
				testCount = Integer.parseInt(in);
			} else {
				if(in.equals("")){
					caseNo++;	
					index = 0;
					input = new char[4][4];
					isResult = false;
					resultList.clear();
				} else{												
					if(!isResult){
						addResult(in, caseNo);
						input[index]=in.toCharArray();
						index++;
					}
					if(!isResult && index>=4){												
						int j = 0;
						String temp = "";
						while(j <= 5 ){
							if(j<4){
								for(int i=0; i<4;i++){
									temp = temp+input[i][j];
								}
							}else if(j == 4){
								temp = ""+input[0][0]+input[1][1]+input[2][2]+input[3][3];
							} else if(j == 5){
								temp = ""+input[0][3]+input[1][2]+input[2][1]+input[3][0];
							}
							addResult(temp, caseNo);
							if(isResult){
								break;
							}
							j++;
							temp = "";
						}
						if(!isResult){
							if(resultList.contains("INCOMPLETE")){
								list.add("Case #"+caseNo+": Game has not completed");
							}else{
								list.add("Case #"+caseNo+": Draw");
							}
						}
					}
				}					
			}
			if(testCount < caseNo){
				break;
			}

		}
		for(String out: list){
			System.out.println(out);
		}

	}

	static void addResult(String in, int caseNo){
		if((in.contains("O")||in.contains("T")) && (!in.contains("X") && !in.contains("."))){
			list.add("Case #"+caseNo+": O won");
			isResult = true;
		} else if((in.contains("X")||in.contains("T")) && (!in.contains("O") && !in.contains("."))){
			list.add("Case #"+caseNo+": X won");
			isResult = true;
		} else if(in.contains("O") && in.contains("X") && !in.contains(".")){
			resultList.add("DRAW");
			isResult = false;
		} else if(in.contains(".")){
			resultList.add("INCOMPLETE");
			isResult = false;
		}
	}
}
