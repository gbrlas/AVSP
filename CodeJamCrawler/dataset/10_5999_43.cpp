import java.io.*;
import java.util.*;

public class no3{
  public static void main(String args[]){
	String filesmall = "C-small-attempt1.in";
	String filelarge = "C-large.in";
	String anssmall = "F-small.out";
	String anslarge = "F-large.out";
    try{
		FileInputStream in = new FileInputStream(filesmall);
		PrintWriter outStream = new PrintWriter(new FileOutputStream(anssmall));
		Scanner scan = new Scanner(in);
		int x = scan.nextInt();
		for (int i=0; i<x; i++){
		  int r=scan.nextInt();
		  int k=scan.nextInt();
		  int n=scan.nextInt();
		  int[] dt = new int[n];
		  for (int j=0; j<n; j++){
			  dt[j]=scan.nextInt();
		  }
		  long ans=0;
		  int idx=0;
		  for (int j=0; j<r; j++){
			int full=0;
			if (n==1) full=1; else {
			  int l=0;
			  int hs;
			  while (full+(hs=dt[idx = idx%n])<k+1 && l<n){
				full += hs;
				idx++;
				l++;
			  }
			}
			ans+=full;
		  }
		  //System.out.println(" Case #"+(i+1)+": "+ans+" : "+r+" : "+k+" : "+n);
		  outStream.println("Case #"+(i+1)+": "+ans);
		}
		outStream.close();
		in.close();
    } catch (Exception e) {
		e.printStackTrace();
	}

  }
}