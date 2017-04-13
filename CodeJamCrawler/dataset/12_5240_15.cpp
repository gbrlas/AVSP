import java.io.*;
/**
 * 
 *	Converts Googlerese language into English
 *
 */
public class Googlerese {

	public static String translateString(String googlerese)
	{
		StringBuffer buff = new StringBuffer();
		for(int i=0; i<googlerese.length(); i++)
		{
			char letter = googlerese.charAt(i);
			if(letter=='a' || letter == 'A')
				buff.append('y');
			else if(letter=='b' || letter == 'B')
				buff.append('h');
			else if(letter=='c' || letter == 'C')
				buff.append('e');
			else if(letter=='d' || letter == 'D')
				buff.append('s');
			else if(letter=='e' || letter == 'E')
				buff.append('o');
			else if(letter=='f' || letter == 'F')
				buff.append('c');
			else if(letter=='g' || letter == 'G')
				buff.append('v');
			else if(letter=='h' || letter == 'H')
				buff.append('x');
			else if(letter=='i' || letter == 'I')
				buff.append('d');
			else if(letter=='j' || letter == 'J')
				buff.append('u');
			else if(letter=='k' || letter == 'K')
				buff.append('i');
			else if(letter=='l' || letter == 'L')
				buff.append('g');
			else if(letter=='m' || letter == 'M')
				buff.append('l');
			else if(letter=='n' || letter == 'N')
				buff.append('b');
			else if(letter=='o' || letter == 'O')
				buff.append('k');
			else if(letter=='p' || letter == 'P')
				buff.append('r');
			else if(letter=='q' || letter == 'Q')
				buff.append('z');
			else if(letter=='r' || letter == 'R')
				buff.append('t');
			else if(letter=='s' || letter == 'S')
				buff.append('n');
			else if(letter=='t' || letter == 'T')
				buff.append('w');
			else if(letter=='u' || letter == 'U')
				buff.append('j');
			else if(letter=='v' || letter == 'V')
				buff.append('p');
			else if(letter=='w' || letter == 'W')
				buff.append('f');
			else if(letter=='x' || letter == 'X')
				buff.append('m');
			else if(letter=='y' || letter == 'Y')
				buff.append('a');
			else if(letter=='z' || letter =='Z')
				buff.append('q');
				else
					buff.append(' ');
			
		}
		
		return buff.toString();
		
	}
	
	public static void main(String [] args) throws IOException
	{
		  FileInputStream fstream = null;
		try 
		{
			fstream = new FileInputStream("A-small-attempt2.in");
		} 
		catch (FileNotFoundException e) 
		{
			e.printStackTrace();
		}
	      DataInputStream in = new DataInputStream(fstream);
	      BufferedReader br = new BufferedReader(new InputStreamReader(in));
	      
	      String t;
	      int caseNo = 1;
	      br.readLine();
	      while((t = br.readLine()) != null)
	      {
	    	  System.out.println("Case #" + caseNo + ": " + translateString(t)  );
	    	  caseNo++;
	      }
		
		
	}
}
