import java.io.*;
import java.util.*;

public class Rope{
  public static void main(String[] args) throws IOException{
    Scanner scan = new Scanner(new File("A-large.in"));
    BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
    int t = scan.nextInt();
    for(int t1=0; t1<t; t1++){
      int n = scan.nextInt();
      int[] a = new int[n];
      int[] b = new int[n];
      for(int i=0; i<n; i++){
        a[i] = scan.nextInt();
        b[i] = scan.nextInt();
      }
      int count = 0;
      for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++){
          if((a[j]>a[i] && b[j]<b[i]) || (a[j]<a[i] && b[j]>b[i]))
            count ++;
        }
      out.write("Case #"+(t1+1)+": "+count+"\n");
    }
    out.close();
  }
}

