package com.murphy.google.code.jam;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.util.Arrays;

public class Round1CProblem1 {
	
	public static void main(String arg[])throws Exception{
		String input_file = "A-small-attempt0.in";
		BufferedReader file_in = new BufferedReader(new FileReader(input_file));
		String output_file = "output.txt";
		FileOutputStream file_out = new FileOutputStream(output_file );
	
		int num_cases = Integer.parseInt(file_in.readLine());
		for(int i=1; i<=num_cases; i++){
			String[] token = file_in.readLine().split(" ");
			int P = Integer.parseInt(token[0]);
			int K = Integer.parseInt(token[1]);
			int L = Integer.parseInt(token[2]);
			int[] frequency = new int[L];
			token = file_in.readLine().split(" ");
			for(int j=0; j<L; j++){
				frequency[j] = Integer.parseInt(token[j]);
			}
			
			// sort the frequency
			Arrays.sort(frequency);
			int[] freq_table = new int[frequency.length];
			for(int j=0; j<L; j++){
				freq_table[L-1-j] = frequency[j];
			}
			
			int key_presses = 0;
			int pos = 0;
			for(int j=1; j<=P; j++){
				for(int k=0; k<K; k++){
					if(pos<freq_table.length){
						key_presses += (freq_table[pos]*j);
						pos++;
					}else break;
				}
			}
			String output = "Case #"+i+": "+key_presses+"\r\n";
			file_out.write(output.getBytes());
		}
		file_in.close();
		file_out.close();
	}
}
