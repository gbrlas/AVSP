package net.antiwalking;

import java.io.*;
import java.util.Hashtable;
import java.util.Vector;

public class AlienLanguage {
	  private static final AlienLanguage instance = new AlienLanguage();
	  private AlienLanguage(){};
	  public static AlienLanguage getInstance(){
	    return AlienLanguage.instance;
	  }
	  
	  private String solve(String recieved){
		 String answer = "";
		 //括弧内かどうかを保持
		 boolean in_par = false;
		 
		 //作業用にワードリストをコピー
		 Vector<String> wl = (Vector<String>) instance.wordlist.clone();
		 Vector<String> removelist = new Vector<String>();
		 String par = "";
		 int num = 0;
		 
		 for(int i = 0; i < recieved.length(); i++){
			 if(wl.size() == 0){
				 answer = "0";
				 break;
			 }
			 
			 char c = recieved.charAt(i);
			 
			 switch(c){
			 case '(':
				 in_par = true;
				 break;
			 case ')':
				 in_par = false;
				 for(String word : wl){
					 boolean matches = false;
					 for(int j = 0; j < par.length(); j++){
						 if(word.charAt(num) == par.charAt(j)){
							 matches = true;
						 }
					 }
					 if(!matches){
						 removelist.add(word);
					 }
				 }
				 wl.removeAll(removelist);
				 par = "";
				 num++;
				 break;
			 default:
				 if(in_par){
					 par += c;
				 }else{
					for(String word : wl){
						if(word.charAt(num) != c){
							removelist.add(word);
						}
					}
					wl.removeAll(removelist);
					num++;
				 }
		 
			 }
		 }
		 
		 answer = String.valueOf(wl.size());
		 
		 
		 return answer;
	  }
	  
	  private Vector<String> wordlist = new Vector<String>();
	  
	  public static void main(String args[]) throws IOException{
		  int l,d,n;
		  //File inputFile = new File(args[0]);
		  File inputFile = new File("A-small-attempt0.in");
		  FileReader in = new FileReader(inputFile);
		  BufferedReader br = new BufferedReader(in);
		  String line;
		  
		  //read the 1st line
		  line = br.readLine();
		  String[] ldn = line.split("\\s");
		  l = Integer.parseInt(ldn[0]);
		  d = Integer.parseInt(ldn[1]);
		  n = Integer.parseInt(ldn[2]);
		  
		  for(int i = 0; i < d ;i ++) {
			  line = br.readLine();
			  instance.wordlist.add(line);
			  //System.out.println(line);
		  }
		  
		  for(int i = 0; i < n ;i ++) {
			  line = br.readLine();
			  System.out.print("Case #" + (i+1) + ": ");
			  String answer = instance.solve(line);
			  System.out.println(answer);
		  }
		  br.close();
		  in.close();
		  
	  }
}
