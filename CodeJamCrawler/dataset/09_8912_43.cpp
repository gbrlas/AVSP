import java.util.*;
import java.io.*;


public class jam {
   static  char []x={'w','e','l','c','o','m','e',' ','t','o',' ','c','o','d','e',' ','j','a','m'};
static double tot=0;
   public static void main(String[] args)throws IOException {
    BufferedReader l=new BufferedReader(new FileReader("C-small-attempt1.in"));
    PrintWriter o=new PrintWriter(new FileWriter("C-small-attempt1.out"));
    int  N=Integer.parseInt(l.readLine());
    for(int i=1;i<=N;i++){
    String z=l.readLine();
    if(z.length()<x.length)o.println("Case #"+(int)(i)+": "+String.format("%04d",(int) (tot)));
    else {Go(z,0,0);o.println("Case #"+(int)(i)+": "+String.format("%04d", (int)(tot%10000)));}
    tot=0;
    }
    o.close();
    }
   public static  void Go(String z,int i,int j){
       if(j>=x.length){tot++;return;}   
       if(i>=z.length())return;
       for(int k=i;k<z.length();k++){
       if(z.charAt(k)==x[j])Go(z,k+1,j+1);
       }   
 } 
}
