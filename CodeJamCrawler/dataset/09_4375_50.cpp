package net.antiwalking;

import java.io.*;
import java.util.Hashtable;
import java.util.Vector;

public class AllYourBase {
	  private static final AllYourBase instance = new AllYourBase();
	  private AllYourBase(){};
	  public static AllYourBase getInstance(){
	    return AllYourBase.instance;
	  }
	  
	  private long solve(String line){
		 long answer = 0;
		 int base;
		 long keta = 1;
		 char[] ca = line.toCharArray();
		 Vector<Character> v = new Vector<Character>();
		 Hashtable<Character,Integer> hash = new Hashtable<Character, Integer>();
		 for(int i = 0; i < ca.length;i++){
			 if(!v.contains(ca[i])){
				 v.add(ca[i]);
			 }
			 
		 }
		 base = v.size();
		 if(base == 1)
			 base = 2;
		 
		 int value  = 0;
		 boolean flag = false;
		 for(int i = 0; i < ca.length;i++){
			if(i == 0){
				hash.put(ca[i], 1);
			}else{
				if(!hash.containsKey(ca[i]) && !flag){
					flag = true;
					hash.put(ca[i], 0);
					value = 1;
				}else if(!hash.containsKey(ca[i])){
					value++;
					hash.put(ca[i],value);
				}
			}
		 }
		 for(int i = ca.length - 1; i >= 0; i--, keta = keta * base){
			 answer += hash.get(ca[i]) * keta;
		 }
		 return answer;
	  }
	  
	  private Vector<String> wordlist = new Vector<String>();
	  
	  public static void main(String args[]) throws IOException{
		  int cases;
		  //File inputFile = new File(args[0]);
		  //File inputFile = new File("A-small.test");
		  File inputFile = new File("A-small-attempt1.in");
		  //File inputFile = new File("A-large.in");
		  FileReader in = new FileReader(inputFile);
		  BufferedReader br = new BufferedReader(in);
		  String line;
		  
		  //read the 1st line
		  line = br.readLine();
		  String[] ldn = line.split("\\s");
		  cases = Integer.parseInt(ldn[0]);
		  
		  for(int i = 0; i < cases;i ++) {
			  line = br.readLine();
			  System.out.print("Case #" + (i+1) + ": ");
			  System.out.println(instance.solve(line));
		  }
		  
		  br.close();
		  in.close();
		  
	  }
}
