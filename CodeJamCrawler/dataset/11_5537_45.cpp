import java.io.*;
import java.util.*;
import java.util.regex.*;
public class B
{
 public static void main(String args[])throws IOException
 {
  Scanner br= new Scanner(new FileReader("B-small-attempt2.in"));
  FileWriter fstream = new FileWriter("out.txt");
        PrintWriter out = new PrintWriter(fstream,true);
  int testcases =br.nextInt();
  for(int i=0;i<testcases;i++)
  {
  //input taking
  int c=br.nextInt();
  ArrayList comb=new ArrayList(c);
  String arr[][]=new String[c][2];
  for(int ci=0;ci<c;ci++)
  {  
  comb.add(br.next());
  }
  
  int d=br.nextInt();
  ArrayList opp=new ArrayList();
  
  for(int ci=0;ci<d;ci++)  opp.add(br.next());
  
  int n=br.nextInt();
  
  String lis=br.next();
  //algorithm
  
  String curr="";
  for(int k=0;k<lis.length();k++)
  {
    curr+=lis.charAt(k);
    if(curr.length()>=2)
    {
     //replacing loop
     for(int li=0;li<comb.size();li++)
     {
      String tochk=curr.substring(curr.length()-2,curr.length());
      String a=comb.get(li).toString().substring(0,2);
      String b=new StringBuffer(a).reverse().toString();
      //System.out.println(a+"  "+b+"   "+tochk);
      if(tochk.equalsIgnoreCase(a)||tochk.equalsIgnoreCase(b))
      {
       //System.out.println(curr.substring(curr.length()-2,curr.length())+"         "+comb.get(li).toString().substring(0,2));
       //now replace
       //String c=comb.get(li).toString().charAt(2)+"";
       StringBuffer m=new StringBuffer(curr);
       m.delete(m.length()-2,m.length());
       m.append(comb.get(li).toString().charAt(2));
       curr= m.toString();
       //System.out.print(curr);
      }
     }
     //now chk for deleting loop
     if(curr.length()>=2)
     {
    
     for(int di=0;di<opp.size();di++)
     {
       String to=opp.get(di).toString();
       if((curr.indexOf(to.charAt(0))!=-1&&(curr.indexOf(to.charAt(1))!=-1))||(curr.indexOf(to.charAt(1))!=-1&&(curr.indexOf(to.charAt(0))!=-1)))
       {
        int a=curr.indexOf(to.charAt(0));
        int b=curr.indexOf(to.charAt(1));
        if(a<b)
        curr=new StringBuffer(curr).delete(a,b+1).toString();
        else
         curr=new StringBuffer(curr).delete(b,a+1).toString();
        curr="";
       }
     }
     
     }
    // System.out.println();
    }
  
  }
  ArrayList ds=new ArrayList();
  for(int kj=0;kj<curr.length();kj++)ds.add(curr.charAt(kj));
  
  out.println("Case #"+(i+1)+": "+ds);
  } //for ends
  
  
 
 }//main ends
 
  static int min(int a[])
  {
   int min=9999;
   for(int i=0;i<a.length;i++)
   {
   if(a[i]<min) min=a[i];
   }
   return min;
  }
  
  static int find(int a[],int key)
  {
   int ind=-1;
   for(int i=0;i<a.length;i++)
   {
    if(a[i]==key) return i;
   }
   return ind;
  }
}
