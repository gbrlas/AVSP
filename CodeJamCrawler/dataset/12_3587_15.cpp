import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class base {
		
	public static void main(String args[]){
		List<Object> input = readFile("C:\\test.txt");
		for( int x = 0 ; x<Integer.parseInt((String) input.get(0)); x++ ){
			System.out.println("Case #"+(x+1)+": "+decrypt((String)input.get(x+1)));
		}
	}
	public static String decrypt(String s){
		String fin = "";
		for(int x = 0; x<s.length();x++){
			char c = s.charAt(x);
			switch(c){
			
			case'y': c='a'; fin+=c; break;
			case'n': c='b'; fin+=c; break;
			case'f': c='c'; fin+=c; break;
			case'i': c='d'; fin+=c; break;
			case'c': c='e'; fin+=c; break;
			case'w': c='f'; fin+=c; break;
			case'l': c='g'; fin+=c; break;
			case'b': c='h'; fin+=c; break;
			case'k': c='i'; fin+=c; break;
			case'u': c='j'; fin+=c; break;
			case'o': c='k'; fin+=c; break;
			case'm': c='l'; fin+=c; break;
			case'x': c='m'; fin+=c; break;
			case's': c='n'; fin+=c; break;
			case'e': c='o'; fin+=c; break;
			case'v': c='p'; fin+=c; break;
			case'z': c='q'; fin+=c; break;
			case'p': c='r'; fin+=c; break;
			case'd': c='s'; fin+=c; break;
			case'r': c='t'; fin+=c; break;
			case'j': c='u'; fin+=c; break;
			case'g': c='v'; fin+=c; break;
			case't': c='w'; fin+=c; break;
			case'h': c='x'; fin+=c; break;
			case'a': c='y'; fin+=c; break;
			case'q': c='z'; fin+=c; break;
			case' ': fin+=c; break;
			
			}
		}
		
		return fin;
	}

	public static List<Object> readFile(String inputfile){
		
		try{
			
			  FileInputStream fstream = new FileInputStream(inputfile);
			  DataInputStream in = new DataInputStream(fstream);
			  BufferedReader br = new BufferedReader(new InputStreamReader(in));
			  String strLine;
			  List<Object> contents = new ArrayList<Object>();
			  while ((strLine = br.readLine()) != null){
				  contents.add(strLine);
			  }
			  in.close();
			  return contents;
		}catch (Exception e){
			  System.err.println("Error: " + e.getMessage());
			  return null;
		}
		
	}
	
}
