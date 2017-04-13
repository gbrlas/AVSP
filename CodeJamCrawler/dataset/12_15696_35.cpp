import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Dictionary {
	private String fileName; 
	private FileReader file;
	private FileWriter fileOutput;
	private PrintWriter pw;
	private BufferedReader br;
	private int nbTest;
	private char [] vector;
	private boolean verbose;


	public Dictionary (String[] args){
	
		try{
			 fileName =(args[0]);
				
			   file = new FileReader(fileName);
			    br = new BufferedReader(file);
			    fileOutput=new FileWriter(fileName+"_sol.txt");
	    		pw = new PrintWriter(fileOutput);
		    	
		   } catch (Exception e) {
			   e.printStackTrace();
		   }
		   nbTest=1;
		   verbose=false;
		   vector=new char[26];
		   
		   vector[0]='y';//a
		   vector[1]='h';//b
		   vector[2]='e';//c
		   vector[3]='s';//d
		   vector[4]='o';//e
		   vector[5]='c';//f
		   vector[6]='v';//g
		   vector[7]='x';//h
		   vector[8]='d';//i
		   vector[9]='u';//j
		   vector[10]='i';//k
		   vector[11]='g';//l
		   vector[12]='l';//m
		   vector[13]='b';//n
		   vector[14]='k';//o
		   vector[15]='r';//p
		   vector[16]='z';//q
		   vector[17]='t';//r
		   vector[18]='n';//s
		   vector[19]='w';//t
		   vector[20]='j';//u
		   vector[21]='p';//v
		   vector[22]='f';//w
		   vector[23]='m';//x
		   vector[24]='a';//y
		   vector[25]='q';//z
		   
		   
	}

	
	public int readNum(String line, int startPos, int [] endPos) {
		String s="";
		int i=0;
		while(startPos<line.length() && line.charAt(startPos)!=' ')
		{
			s+=line.charAt(startPos);
			startPos++;
			i++;
		}
		if(endPos!=null)
			endPos[0]=startPos+1;
		return Integer.parseInt(s);
		
	}


	
	public void dealWithFile () throws IOException{
		int pos[]=new int [1];
		String line = br.readLine();
		int nbTests= Integer.parseInt(line);
		if(verbose)
			System.out.println("nbTests: " + nbTests );
		
		for(nbTest=1; nbTest<= nbTests; nbTest++)
		{
			line = br.readLine();
			System.out.print("Case #"+nbTest+": ");
			pw.print("Case #"+nbTest+": ");
			 
			for(int j=0; j<line.length();j++)
			{
				int c= line.charAt(j);
				if(verbose)
					System.out.print(" "+ c);
				if(c==32)
				{
				 System.out.print(" ");
				 pw.print(" ");
				}
				else
				{
				 System.out.print(vector[c-97]);	
				 pw.print(vector[c-97]);
				}
				
			}
			 System.out.println();
			 pw.println();
			
		}
		
		}


	public static void main(String[] args) throws IOException  {
				
		if(args.length!=1)
		{
			System.out.println("Usage: java AlphabetSoup.java <instanceFileName>");
			System.exit(0);
		}
		 Dictionary dictionary= new Dictionary(args);
		 dictionary.dealWithFile();
		 if(dictionary.verbose)
			 System.out.println("End");

		 dictionary.file.close();
		 dictionary.fileOutput.close();
	}
}