
import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

import sun.security.util.BigInt;
public class Alien_Language {

	public static String[] input;
	public static String[] output;
	public static int index;
	public static int outindex;
	public static int Case=1;
	public static void main(String args[])
	{
		try
		{
			File aFile = new File("A-small-attempt0.in");
			File wFile = new File("out.txt");
			
			input = getContents(aFile);
			output = new String[input.length];
		    Case = getData(input[index]);
			writecontents(wFile,output,Case);
		}
		catch (IOException ex)
		{
		      ex.printStackTrace();
		}
		
	}
	
	
	
	public static int getData(String rdata)
	{
		String[] sdata = rdata.split(" ");
		int l = Integer.parseInt(sdata[0]);
		int d = Integer.parseInt(sdata[1]);
		int n = Integer.parseInt(sdata[2]);
		String[] words=new String[d];
		int count=0;
		
		for(int i=0;i<d;i++)
		{
			words[i] = input[i+1];
			//System.out.println(words[i]);
		}
		index=index+d;
		for(int j=0;j<n;j++)
		{
			output[count]=getCase(words,input[index+j+1],l)+"";
			//System.out.println(j);
			count++;
		}
		//index=index+2;
		
		return count;
	}
	public static String[] GetString(String[] str)
	{
	
		ArrayList list = new ArrayList();
		int count=0;
		
		for(int i=0;i<str.length;i++)
		{
			if(!(str[i].equals("") || str==null))
			{
				list.add(str[i]);
				count++;
			}
		}
		String []strArray = new String[count];
		list.toArray(strArray);
		return strArray;
	}
	
	public static int getCase(String[] words,String wcase,int l)
	{
		String sub;
		sub = wcase.replace(")","@;");
		
		//sub =wcase;
		sub =sub.replace("(",";");
		sub=sub.replace(";;",";");
		//sub = sub.replace(" ",";");
		sub = sub.trim();
		String[] arrsub = sub.split(";");
		arrsub = GetString(sub.split(";"));
		String temp=null;
		int tindex=0;
		int count=0;
		boolean found=true;
		int m=0;
		
		
		for(int i=0;i<words.length;i++)
		{
			found=true;
			temp=words[i];
			//for(int j=0;j<temp.length();j++)
			{
				m=0;
				for(int k=0;k<arrsub.length;k++,m++)
				{
					
					if(arrsub.length==1)
					{
						arrsub[m]=arrsub[m].replace("@","");
						arrsub[m]=arrsub[m].replace(")","");
						if(arrsub[m].equals(temp))
						{
							//System.out.println(1);
							break;
						}
						else
						{
							found=false;
							break;
						}
					}
					if(arrsub[m].endsWith("@")==false)
					{
						if(temp.indexOf(arrsub[m])!=-1)
							{
								k=arrsub[m].length();
								continue;
							}
						else
						{
							found=false;
							//break;
						}
					}
					else
					{
						tindex = arrsub[m].indexOf(temp.charAt(k));
						if(tindex!=-1)
							continue;
						else
						{
							found=false;
							break;
						}
					}
					
				}
			}
			if(found)
			{
				//System.out.println(words[i]);
				count++;
			}
		}
		//System.out.println(count);
		
		
		
		return count;
	}
	
	
	
	
	
	
	 static public String[] getContents(File aFile) 
	 {
		 
		    StringBuilder contents = new StringBuilder();
		    try {
		     
		      BufferedReader input =  new BufferedReader(new FileReader(aFile));
		      try {
		        String line = null;
		        
		        while (( line = input.readLine()) != null){
		          contents.append(line);
		          contents.append(System.getProperty("line.separator"));
		        }
		      }
		      finally {
		        input.close();
		      }
		    }
		    catch (IOException ex){
		      ex.printStackTrace();
		    }
		    
		    return contents.toString().split(System.getProperty("line.separator"));
		  }
	 public static void writecontents (File file,String[] out,int length) throws IOException
	 {
		    Writer output = null;
		    output = new BufferedWriter(new FileWriter(file));
		    for(int i=0;i<length;i++)
		    {
		    	output.write("Case #"+(i+1)+": "+out[i]);
		    	System.out.println("Case #"+(i+1)+": "+out[i]);
		    	if(i!=length-1)
		    	output.write(System.getProperty("line.separator"));
		    }
		    output.close();    
		    
	 }

}
