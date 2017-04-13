import java.util.*;
import java.io.*;
public class goog1 {
    static int []q;
    static boolean st[];
    static int tot=Integer.MAX_VALUE;
   public static void main(String[] args)throws IOException {
  BufferedReader l=new BufferedReader(new FileReader("c_small.in"));
  PrintWriter o=new PrintWriter(new FileWriter("c_small.out"));
  int t=Integer.parseInt(l.readLine());
  for(int i=1;i<=t;i++){
  String ret=l.readLine();
  int p=Integer.parseInt(ret.split(" ")[0]);
  int q1=Integer.parseInt(ret.split(" ")[1]);
  q=new int [q1];
  st=new boolean [q1];
  int it=0;
  // System.out.println(p);
  ret=l.readLine();
  for(int j=0;j<q1;j++)
  q[j]=Integer.parseInt(ret.split(" ")[j]);
     // System.out.println(q[j]);}
  Go(p,0,0);
  o.println("Case #"+i+": "+tot);
  tot=Integer.MAX_VALUE;
  }
  o.close();
    
    }

    public static void Go(int p,int b,int cnt){
    if(cnt==q.length){tot=Math.min(b,tot);return;}
    int j,k,up,lo;
    for(int i=0;i<q.length;i++){
      boolean st1=false,st2=false;
    if(st[i])continue;
    for(j=i-1;j>=0;j--)if(st[j]){st1=true;break;}
    for(k=i+1;k<q.length;k++)if(st[k]){st2=true;break;}
     
    if(st1)lo=q[j]+1;
    else lo=1;
    if(st2)up=q[k]-1;
    else up=p;
  // System.out.println(st1+":"+st2+":"+i+":"+cnt+":"+j+":"+k+":"+tot+":"+(up-lo));
    st[i]=true;
    Go(p,b+up-lo,cnt+1);
    st[i]=false;
    }
    }

}
