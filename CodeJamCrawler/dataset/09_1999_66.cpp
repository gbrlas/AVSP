import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.math.*;

import javax.print.attribute.standard.PresentationDirection;

public class ProblemC {
	String st = "welcome to code jam";
	void doMain() throws Exception {
		BufferedReader sc = new BufferedReader(new FileReader("C-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output_large_C.txt"));
		
		int N = Integer.parseInt(sc.readLine());
		int[][] intArray;
		String currString;
		String priStr = "";
				
		for (int caseNum=1; caseNum <= N; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			currString = sc.readLine();

			intArray = new int[currString.length()+1][20];
			for(int i=0; i<currString.length()+1;i++)
				intArray[i][19]=1;
			
			int cnt;
			for(int i=currString.length()-1; i>=0; i--){
				for(int j=18; j>=0; j--){
					if(st.charAt(j) == currString.charAt(i))
						cnt = intArray[i+1][j+1] + intArray[i+1][j];
					else
						cnt = intArray[i+1][j];
					cnt = cnt % 10000;
					intArray[i][j] = cnt;
				}
			}

			priStr = ""+intArray[0][0];
			int x = priStr.length();
			for(int i=0;i<4-x;i++)
				priStr = "0"+priStr;
			pw.println(priStr);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemC()).doMain();
	}
}
