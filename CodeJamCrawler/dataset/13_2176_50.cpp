package com.amazon.first;

	import java.io.BufferedReader;
import java.io.BufferedWriter;
	import java.io.File;
	import java.io.FileInputStream;
	import java.io.FileNotFoundException;
import java.io.FileOutputStream;
	import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

	public class LawnMover {

		/**
		 * @param args
		 * @throws IOException 
		 */
		public static void main(String[] args) throws IOException {
			BufferedReader br = null;
			
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("output2.out"))));
			try {
				br = new BufferedReader(new InputStreamReader(new FileInputStream(new File("input.txt"))));
				String tmp = br.readLine();
				Integer testCasesCount = Integer.parseInt(tmp);
				Boolean[] resultSet = new Boolean[testCasesCount];
				for(int i=0;i<testCasesCount;i++){
					String[] tmpArr = br.readLine().split(" ");
					Integer rows = Integer.parseInt(tmpArr[0]);
					Integer cols = Integer.parseInt(tmpArr[1]);
					Integer[] twoDimArr = new Integer[rows*cols];
					for(int j=0;j<rows;j++){
						tmpArr = br.readLine().split(" ");
						for(int k=0;k<cols;k++){
							twoDimArr [j*cols+k] = Integer.parseInt(tmpArr[k]);
						}
					}
					////////////////////////////
					Integer[] maxNums = new Integer[rows+cols];
					for(int j=0;j<rows;j++){
						int max =twoDimArr[j*cols];
						for(int k=0;k<cols;k++){
							int curr = twoDimArr[j*cols+k];
							//System.out.print(curr + " ");
							if(max<curr){
								max=curr;
							}
						}
						maxNums[j] = max;
						//System.out.println();
					}
					for(int j=0;j<cols;j++){
						int max =twoDimArr[j];
						for(int k=0;k<rows;k++){
							int curr = twoDimArr[k*cols+j];
							if(max<curr){
								max=curr;
							}
						}
						maxNums[rows + j] = max;
					}
					/////////////////////////////
					Boolean result = true;
					for(int j=0;j<rows;j++){
						for(int k=0;k<cols;k++){
								int curr = twoDimArr[j*cols+k];
								if( maxNums[j] > curr && maxNums[rows+k] > curr){
									result = false;
									break;
								}
							}
						if(!result)
							break;
					}
					resultSet[i] = result;
				}// Loop for iterating over number of test cases.
				br.close();
				
				for(int i=0;i<testCasesCount;i++)
					
					bw.write( "Case #" + (i+1) + ": " + ((resultSet[i])?"YES":"NO")+"\n");
					//bw.newLine();
					//System.out.println(resultSet[i]);
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}finally{
				bw.flush();
				bw.close();
				br.close();
				
			}
		}
	}
