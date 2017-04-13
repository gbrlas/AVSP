import java.io.*;

public class A
{
 public static void main(String args[])throws IOException
 {
  BufferedReader br= new BufferedReader(new FileReader("A-large.in"));
  //create the input matrix
   FileWriter fstream = new FileWriter("out.txt");
        PrintWriter out = new PrintWriter(fstream,true);
  int testcases =Integer.parseInt(br.readLine());
  for(int i=0;i<testcases;i++)
  {
   String cases=br.readLine();
   String casetext[]=cases.split(" ");
   
   int inputs=Integer.parseInt(casetext[0]);
  
   int o[]=new int[inputs];
   int oi=0,bi=0;
   int b[]=new int[inputs];
   String bot[]=new String[inputs];
   int pos[]=new int[inputs];
   int boti=0;
   int posi=0;
   int cc=1;
   for(int j=0;j<inputs;j++)
   {
     bot[boti++]=casetext[cc++];
     pos[posi++]=Integer.parseInt(casetext[cc++]);
     if(casetext[cc-2].equalsIgnoreCase("B")) b[bi++]=Integer.parseInt(casetext[cc-1]);
     else o[oi++]=Integer.parseInt(casetext[cc-1]);
    
   }
  /* System.out.print("O ");   
   for(int m=0;m<o.length;m++)
   {
   System.out.print(o[m]+",");
   }
      System.out.print(" b ");   
   for(int m=0;m<b.length;m++)
   {
   System.out.print(b[m]+",");
   }*/
   //main function loop
   int seconds=0;
   int opos=1;
   int bpos=1;
   boti=0;
   oi=0;bi=0;
  int newpos;
   while(true)
   {
   if(boti<bot.length)
   { 
    if(bot[boti].equalsIgnoreCase("O")) //only o ccan push
    {
        if(opos!=o[oi])
        {
        // move o
        if(opos<o[oi]) opos++; 
        else opos--;
        //move b
        if(bpos<b[bi]) bpos++;
        else if(bpos>b[bi]) bpos--;
        
        }
        else //push
        {
        if(bpos<b[bi]) bpos++;
        else if(bpos>b[bi]) bpos--;   
           oi++;
           boti++;
        }
   //System.out.print("O");
    }
    else  //only b can push
    {
       if(bpos!=b[bi])
        {
        // move b
        if(bpos<b[bi]) bpos++; 
        else bpos--;
        //move o
        if(opos<o[oi]) opos++;
        else if(opos>o[oi]) opos--;
        }
        else //push
        {
           if(opos<o[oi]) opos++;
           else if(opos>o[oi]) opos--;
           bi++;
           boti++;
        }
    //    System.out.print("B");
    }
   //System.out.println(" "+opos+"  "+bpos);
    seconds++;      
    }else break;
   }//while ends
  out.println("Case #"+(i+1)+": "+(seconds));
  } //for ends
  
  
 }
}
