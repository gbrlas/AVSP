import java.io.*;
import java.util.*;
import java.lang.*;

public class LoadTesting{
  public static void main(String[] args) throws IOException{
    Scanner scan = new Scanner(new File("B-large.in"));
    BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
    int t = scan.nextInt();
    for(int t1=0; t1<t; t1++){
      int l = scan.nextInt();
      int p = scan.nextInt();
      int c = scan.nextInt();
      int count = -1;
      double dp = p * 1.0;
      while(dp>l){
        dp = dp / c;
        if(dp - (int)(dp) > 0.000001)
          dp = (int)dp + 1;
        count ++;
      }
      int r;
      if(count == 0)
          r = 0;
      else r = (int)(Math.log(1.0*count)/Math.log(2))+1;
      //System.out.print("Case #"+(t1+1)+": "+r+"\n");
      out.write("Case #"+(t1+1)+": "+r+"\n");
    }
    out.close();
  }
}
