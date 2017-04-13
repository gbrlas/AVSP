package com.RND;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class ThemePark {
	public static void main(String args[]){
			String inputFile = "C:\\Subir\\CodeJam\\C-small-attempt1.in";
		//	String inputFile = "C:\\Subir\\CodeJam\\A-large-practice.in";
			
			String outputFile = "C:\\Subir\\CodeJam\\C-small-attempt1.out";
		//	String outputFile = "C:\\Subir\\CodeJam\\A-large-practice.out";
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
					int R=Integer.parseInt(inputs[0]);
					int K=Integer.parseInt(inputs[1]);
					int N=Integer.parseInt(inputs[2]);
					
					String samples = reader.readLine();
					String[] sampleArr = samples.split(" ");
					int s[]=new int[N];
					for(int j=0;j<N;j++)
					{
						s[j]=Integer.parseInt(sampleArr[j]);
					}
					int total=0;
					int k=0;
					int start=k;
					for(int j=0;j<R;j++){
						int curTrip=0;
						do{
							if(k==N)
								k=0;
							if(curTrip+s[k]<=K){
								curTrip+=s[k];
								k++;
								if(k==N)
									k=0;
							}
							else{
								break;
							}
						}
						while(k!=start);
						start=k;
						total+=curTrip;
					}
					System.out.print("Case #"+(i+1)+": "+total+"\n");
					br.write("Case #"+(i+1)+": "+total+"\n");
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
