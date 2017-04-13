import java.io.BufferedWriter;
//port java.util.*;


//port java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;	
//import java.lang.Math;
//import java.util.ArrayList;
//import java.util.HashMap;
public class Problem1
{
	public static void main(String args[])
	{
		String filename = args[0];
		int i=0,j=0;
		int testcase=0 ;
		int n=0,k=0;
		String out="";
		BufferedWriter bufferedWriter = null;
		try { BufferedReader in = new BufferedReader(new FileReader(filename));
		String str;

		boolean output;
		str = in.readLine();
		testcase = Integer.parseInt(str);
 int C;
		//Construct the BufferedWriter object
		bufferedWriter = new BufferedWriter(new FileWriter("oneoutput.txt"));
		
		for (n=0;n <testcase; n++)
		{
			String result = null;
			int not_over =-1;
		/*	ArrayList<Integer> o=new ArrayList<Integer>();
			ArrayList<Integer> b=new ArrayList<Integer>();
			ArrayList<String> next=new ArrayList<String>();
		*/	
			char[][] ch =new char[4][4];
			for(i=0;i<4;i++)
			{
				str = in.readLine(); //xoxo
				for(j=0;j<4;j++)
					ch[i][j]=str.charAt(j);
					
			}
			str = in.readLine(); //reaed empty
			
			//logic
			/*
			OOXX
			OXXX
			OX.T
			O..O
			*/
			
			int ti=-1,tj=-1;
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(ch[i][j]=='T')
					{
						ti=i; tj=j;
					}
				}
			}//get T position else -1,-1
			System.out.println(" t at "+ti+","+tj);
			//check if X won
			if( ti > -1)
				ch[ti][tj]='X';
			if(ch[0][0]==ch[1][1] && ch[0][0]==ch[2][2] && ch[0][0]==ch[3][3] && ch[0][0]=='X')
			{
				result ="X won";
			 
			}
			if(ch[0][3]==ch[1][2] && ch[0][3]==ch[2][1] && ch[0][3]==ch[3][0] && ch[0][3]=='X')
			{
				result ="X won";
		
			}
			System.out.println(" result="+result);
			if (result == null)
			{
			for(i=0;i<4;i++)
			{
				System.out.println(" char at "+ ch[i][0]+" "+ch[i][1]+" "+ch[i][0]+" "+ch[i][2]+" "+ch[i][0]+" "+ch[i][3]);
				if(ch[i][0]==ch[i][1] && ch[i][0]==ch[i][2] && ch[i][0]==ch[i][3] && ch[i][0]=='X')
				{
					result ="X won";
				 	break;
				}
				if(ch[0][i]==ch[1][i] && ch[0][i]==ch[2][i] && ch[0][i]==ch[3][i] && ch[0][i]=='X')
				{
					result ="X won";
				 	break;
				}
			
			}
			}
			
			//check if O won
			if( ti > -1)
				ch[ti][tj]='O';
			if(ch[0][0]==ch[1][1] && ch[0][0]==ch[2][2] && ch[0][0]==ch[3][3] && ch[0][0]=='O' && result == null)
			{
				result ="O won";
			 
			}
			if(ch[0][3]==ch[1][2] && ch[0][3]==ch[2][1] && ch[0][3]==ch[3][0] && ch[0][3]=='O'  && result == null)
			{
				result ="O won";
		
			}
			if (result == null)
			{
			for(i=0;i<4;i++)
			{
				if(ch[i][0]==ch[i][1] && ch[i][0]==ch[i][2] && ch[i][0]==ch[i][3] && ch[i][0]=='O')
				{
					result ="O won";
				 	break;
				}
				if(ch[0][i]==ch[1][i] && ch[0][i]==ch[2][i] && ch[0][i]==ch[3][i] && ch[0][i]=='O')
				{
					result ="O won";
				 	break;
				}
			
			}
			}
			
			//CHECK FOR GAME NOT COMPLETED
			if(result == null )
			{
				for(i=0;i<4;i++)
				{
					for(j=0;j<4;j++)
					{
						if(ch[i][j]=='.')
						{
							not_over =1;
							break;
						}
					}
				}
			}
			if(result == null )
			{
				if ( not_over ==1 )
			
				result = "Game has not completed";
			
				else
					result = "Draw";
			}
			
			
			
			
			//logic end
			
			//logic ends here output has a string	
			out="Case #"+(n+1)+": "+result;
		/*	for(int r1=0;r1<output1.length();r1++)
			out = out+output1.charAt(r1)+", ";
			if (output1.length()>0)
			out= out.substring(0, out.length()-2);
			out=out+"]";
		*/	bufferedWriter.write(out);
			if (i !=testcase)
			bufferedWriter.newLine();
		}
		in.close(); } 
		catch (IOException ex) {               ex.printStackTrace();} 
		finally {
			//Close the BufferedWriter
			try {
				if (bufferedWriter != null) {
					bufferedWriter.flush();
					bufferedWriter.close();
				}
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}

	}

	
}
