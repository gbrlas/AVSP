package com.RND;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class SnapperChain {
	public static void main(String args[]){
			String inputFile = "C:\\Subir\\CodeJam\\A-small-attempt2.in";
		//	String inputFile = "C:\\Subir\\CodeJam\\A-large-practice.in";
			
			String outputFile = "C:\\Subir\\CodeJam\\A-small-attempt2.out";
	//		String outputFile = "C:\\Subir\\CodeJam\\A-large-practice.out";
			try{
				FileWriter fr = new FileWriter(outputFile);
				BufferedWriter br = new BufferedWriter(fr);
				
				FileInputStream fstream = new FileInputStream(inputFile);
				DataInputStream dis = new DataInputStream(fstream);
				BufferedReader reader = new BufferedReader(new InputStreamReader(dis));
				int T=Integer.parseInt(reader.readLine());
				
				for(int i=0;i<T;i++){
					String input = reader.readLine();
					String[] inputs = input.split(" ");
					int N=Integer.parseInt(inputs[0]);
					int K=Integer.parseInt(inputs[1]);
					int s[]=new int[N];
					for(int j=0;j<N;j++){
						s[j]=0;
					}
					for(int l=0;l<K;l++){
						
						for(int m=0;m<N;m++)
						{
							if(s[m]==0){
								s[m]=1;
								break;
							}
							else{
								s[m]=0;
							}
						}
					}
					String bulbState="ON";
					for(int n=0;n<N;n++){
						if(s[n]==0)
						{
							bulbState="OFF";
							break;
						}
					}
					
					
					System.out.print("Case #"+(i+1)+": "+bulbState+"\n");
					br.write("Case #"+(i+1)+": "+bulbState+"\n");
					
					
				}
				br.close();
				reader.close();
			}
			catch(FileNotFoundException e){
				e.printStackTrace();
			}
			catch(IOException e){
				e.printStackTrace();
			}
			
		}
}
