import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
public class CodeJam {

	public static void compare(int tcase,String a,String b)
	{
		String[] aArr = a.split(" ");
		String[] bArr = b.split(" ");
		int warWin=0;
		int win=0;
		List<Float> naka = new ArrayList();
		List<Float> ken = new ArrayList();
		List<Integer> jVal = new ArrayList();
		int match=0;
		String cardValue="";
		for(int i=0;i<aArr.length;i++)
		{
			naka.add(Float.parseFloat(aArr[i]));
			ken.add(Float.parseFloat(bArr[i]));
		}
	
	Collections.sort(naka);
	Collections.sort(ken);
	for(int i=0;i<naka.size();i++)
	{
		float current = naka.get(i);
		int currentWin=0;
		for(int j=0;j<ken.size();j++)
		{
			if(!(jVal.contains(j)))
			{
			if(current > ken.get(j))
			{
				win++;
				jVal.add(j);
				currentWin=1;
				break;
			}
			else
			{
				//jVal.add(j);
			 break;
			}
			
			}
		}
		
	}
	//Collections.reverse(ken);
	//System.out.println(naka);
	//System.out.println(ken);
	//Collections.reverse(ken);
	List<Integer> warJ = new ArrayList();
	int loss=0;
	for(int i=0;i<naka.size();i++)
	{
		float currentNaka = naka.get(i);
		for(int j=0;j<ken.size();j++)
		{
			if(!(warJ.contains(j)))
			{
			if(ken.get(j)>currentNaka)
			{
				warJ.add(j);
				loss++;
				break;
			}
			}
			
		}
	}
	warWin = naka.size() - loss;
	//System.out.println(naka);
	//System.out.println(ken);
	System.out.println("Case #"+tcase+": "+win +" "+warWin);
	//System.out.println("War Win:"+win);
	}

	public static void main(String[] args) {
	
		try{
		File inFile  = new File("c://codejam//D-large.in");  
		Scanner freader = new Scanner(inFile);
		 String line = null;
		 int lineCnt=0;
		int tCount=0;
		int gameStart=0;
		int tCase=0;
		int n=0;
		String naka="";
		String ken="";
		 while (freader.hasNextLine()) {
	        	
	            line = freader.nextLine();
	            lineCnt++;
	            if(lineCnt==1)
	            {
	            	tCount = Integer.parseInt(line);
	            }
	            else if((gameStart==0)&&((lineCnt==2)||(lineCnt%3==2)))
	            {
	            	tCase++;
	            	gameStart=1;
	            	n=Integer.parseInt(line);
	            }
	            else if((gameStart==1)&&(lineCnt%3==0))
	            {
	            	naka = line;
	            }
	            else if((gameStart==1)&&(lineCnt%3==1))
	            {
	            	ken = line;
	            	gameStart=0;
	            	compare(tCase,naka,ken);
	            }
	        }
	        freader.close();
	        
		
		}catch(Exception e){}

	}

}
