
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Abhishek
 */
public class MagicTrick {
    public static void main(String[] args)throws Exception
     {FileReader f=new FileReader("C:/Users/Abhishek/Downloads/A-small-attempt0.in");
    FileWriter fw=new FileWriter("MagicTrick.txt");   
      PrintWriter B=new PrintWriter(fw);
    Scanner s= new Scanner(f);
   int T=s.nextInt();
   
   
   for(int i=1;i<=T;i++)
  {   int r1,r2,arr1[][],arr[],marr[],temp;
  arr=new int[4];
  marr=new int [4];
  arr1=new int[4][4];
     r1=s.nextInt();         //ans row 1
    for(int j=0;j<4;j++)
    { for(int k=0;k<4;k++)
    {   arr1[j][k]=s.nextInt();
    }
  }// design1 assign
   
   for(int k=0;k<4;k++)
   { arr[k]=arr1[r1-1][k];// row 1 assign
   //System.out.print(arr[k]+" ");
   }
   r2=s.nextInt(); //ans row 2
   for(int j=0;j<4;j++)
    for(int k=0;k<4;k++)
        arr1[j][k]=s.nextInt();//design 2 assign
  for(int k=0;k<4;k++)
   marr[k]=arr1[r2-1][k];
   String y=" ";
   int t=0;
   for(int j=0;j<4;j++)
    {for(int k=0;k<4;k++)
    {//System.out.print(marr[j]+" "+arr[k]+" "+r1+" "+r2+"\n");
        if(arr[j]==marr[k])
    { 
        t++;
    if(t>1)
        break;
    y=y+arr[j];}
    }
    }
   if(t==0)
       y=" Volunteer cheated!";
   else if(t>1)
       y=" Bad magician!";
   B.println("Case #"+i+":"+y+"\n");
    }
   
    
 
 B.close();
 fw.close();
  }
}
