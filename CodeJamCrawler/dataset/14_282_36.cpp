import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class CodeJam {

	public static void compare(int tcase,String a,String b)
	{
		String[] aArr = a.split(" ");
		String[] bArr = b.split(" ");
		
		int match=0;
		String cardValue="";
		for(int i=0;i<aArr.length;i++)
		{
			if((aArr[i].equals(bArr[0]))||(aArr[i].equals(bArr[1]))||(aArr[i].equals(bArr[2]))||(aArr[i].equals(bArr[3])))
			{
				match++;
				cardValue=aArr[i];
			}
		}
		if(match==1)
		{
		System.out.println("Case #"+tcase+": "+cardValue);
		}
		else if(match > 1)
		{
			System.out.println("Case #"+tcase+": Bad magician!");
		}
		else if(match ==0)
		{
			System.out.println("Case #"+tcase+": Volunteer cheated!");
		}	
		}

	public static void main(String[] args) {
	
		try{
		File inFile  = new File("c://codejam//A-small-attempt4.in");  
		Scanner freader = new Scanner(inFile);
		 String line = null;
		 int tCount=0;
		int  tmpCount=0;
		 int lineCnt=0;
		 int magicStart=0;
		 int firstOrder=0;
		 int myData=0;
		 String firstRow="";
		 int secondOrder=0;
		 int myData2=0;
		 String secondRow="";
		 char[][] board = new char[4][4];
	        while (freader.hasNextLine()) {
	        	
	            line = freader.nextLine();
	            lineCnt++;
	            if(lineCnt==1)
	            {
	            	tCount = Integer.parseInt(line);
	            }
	            else if((magicStart==0)&&((lineCnt==2)||(lineCnt%10==2)))
	           {
	        	   magicStart=1;
	        	   firstOrder=Integer.parseInt(line);
	        	   myData=lineCnt+firstOrder;
	        	   tmpCount++;
	        	   
	           }
	            else if((magicStart==1)&&(lineCnt==myData))
	            {
	            firstRow=line;
	            magicStart=0;
	            }
	            
	            else if((magicStart==0)&&((lineCnt==7)||(lineCnt%10==7)))
		           {
		        	   magicStart=2;
		        	   secondOrder=Integer.parseInt(line);
		        	   myData2=lineCnt+secondOrder;
		        	   
		           }
	            else if((magicStart==2)&&(lineCnt==myData2))
	            {
	            secondRow=line;
	            magicStart=0;
	            
	            compare(tmpCount,firstRow,secondRow);
	            }
	          
	        
	        }
	        freader.close();
	        
		
		}catch(Exception e){}

	}

}
