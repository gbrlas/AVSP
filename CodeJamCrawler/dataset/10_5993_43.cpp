import java.io.*;
import java.util.*;

public class no1{
  public static void main(String args[]){
	String filesmall = "A-small-attempt2.in";
	String filelarge = "A-large.in";
	String anssmall = "F-small.out";
	String anslarge = "F-large.out";
    try{
		FileInputStream in = new FileInputStream(filelarge);
		PrintWriter outStream = new PrintWriter(new FileOutputStream(anslarge));
		Scanner scan = new Scanner(in);
		int x = scan.nextInt();
		for (int i=0; i<x; i++){
		  int n = scan.nextInt();
		  int k = scan.nextInt();
		  double r = Math.pow(2, n);
		  outStream.println("Case #"+(i+1)+": "+((k+1)%r ==0 ? "ON" : "OFF"));
		}
		outStream.close();
		in.close();
    } catch (Exception e) {
		e.printStackTrace();
	}

  }
}