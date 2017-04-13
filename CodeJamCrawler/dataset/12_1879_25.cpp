import java.io.File;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.List;
import java.util.Scanner;


public class tongues {
	
	private static Scanner x;
	private static Formatter y;
	static String newline = System.getProperty("line.separator");
	
	static List<String> words = new ArrayList<String>();	
	static int testCases;
	
	public static void main(String args[]){
		
		
		
		// set translation scheme from samples
		
		String g1="ejp mysljylc kd kxveddknmc re jsicpdrysi";
		String g2="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
		String g3="de kr kd eoya kw aej tysr re ujdr lkgc jv";
		
		String r1="our language is impossible to understand";
		String r2="there are twenty six factorial possibilities";
		String r3="so it is okay if you want to just give up";
		
		
	

		for(int i=0; i<g1.length();i++){
			search.setLetter(g1.charAt(i), r1.charAt(i));
		}
		for(int i=0; i<g2.length();i++){
			search.setLetter(g2.charAt(i), r2.charAt(i));
		}
		for(int i=0; i<g3.length();i++){
			search.setLetter(g3.charAt(i), r3.charAt(i));
		}
		
		//
		
		

		 try{
			  x= new Scanner(new File("A-small-attempt2.in"));
			 				
				
		  }catch(Exception e){
			  System.out.println("Could not find the file");
		  }		  

		
		
		while(x.hasNext()){
			words.add(x.nextLine());
			
		}
		
		testCases=Integer.parseInt(words.get(0));
		words.remove(0);
		
		
		
		
		for(int j=0; j<testCases; j++){
			
			System.out.print("Case #"+(j+1)+": ");
			
			for(int k=0; k<words.get(j).length();k++){				
				System.out.print(search.getLetter(words.get(j).charAt(k)));
			}
			
			System.out.println();
		}
		
		createFile();
		addRecords();
		closeFile();
		
		
	}
	
	
	//create output text file
		public static void createFile(){
			try{
				y= new Formatter("sampleTongue.ou");
				//System.out.println("sampleTongue.ou has been created");
			
			}catch(Exception e){
				System.out.println("Could not create a file");
			}
		}
		
		//add names to output text file
		public static void addRecords(){			
			
			
			for(int j=0; j<testCases; j++){
				
				//System.out.print("case#"+(j+1)+" ");
				
				y.format("Case #%d: ",(j+1));
				
				for(int k=0; k<words.get(j).length();k++){				
					//System.out.print(search.getLetter(words.get(j).charAt(k)));
					y.format("%c",search.getLetter(words.get(j).charAt(k)));
				}
				y.format(newline);
				
			}
			
		}
		
		//close files
		public static void closeFile(){
			x.close();
			y.close();
		}
}
