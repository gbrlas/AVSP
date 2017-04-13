
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.util.Observable;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;


/**
 *
 * @author dante
 */
public class tongues {
    
    public tongues(String filename)
    {
        String strLine=null;
        int index=0;

        
        translate = new char[26][2];
        
        try{
        BufferedReader alphabetreader = new BufferedReader(new FileReader("Translator"));
        
        while ((strLine = alphabetreader.readLine()) != null) {
            
            translate[index++]=strLine.toCharArray(); 
        }
        
        
        alphabetreader.close();
        }catch (Exception e) {//Catch exception if any
            System.out.println("Error: " + e.toString() + " line: " + strLine);
        }
        
      
        
        parsing(filename);
        
    }
    
    
        void parsing(String filename)
     {
         
     
        String strLine=null;
          String oldstrLine = null;
           String newstrLine = null;
           int line=0;
          
        // Open the file that is the first
        // command line parameter
        try{
            
        

         BufferedReader oldreader = new BufferedReader(new FileReader(filename)); 
         
         PrintWriter out = new PrintWriter(new FileWriter("Translated"));
         
    //     BufferedReader newreader = new BufferedReader(new FileReader("new")); 
        //Read File Line By Line    
        
       // File f= new File(filename);
         
         
        if((strLine = oldreader.readLine()) != null)
        {
            System.out.println("Num_cases: "+ strLine);
        }

         
           while ((oldstrLine = oldreader.readLine()) != null) {
               
               line++;
               
                //out.println("To str einai: "+ oldstrLine);
             /*  
               if((newstrLine=newreader.readLine()) != null)
               {
                   char[] oldchars= oldstrLine.toCharArray();
                   char[] newchars=newstrLine.toCharArray();
                       System.out.println(oldstrLine);
                 //  System.out.println("to char[2] einai "+ chars[38] +" "+ chars.length);
                   
                   if(newchars.length==oldchars.length)
                   {
                       for(int i=0;i<oldchars.length;i++)
                       {
                           if(oldchars[i] != ' ')   
                           {
                                translation(oldchars[i],newchars[i]);
                           }
                           else
                               System.out.println("Vrika keno:"+oldchars[i]+"telos");
                       }
                   }                     
               }
               */
               
                  char[] oldchars= oldstrLine.toCharArray(); 
                  char[] newchars= new char[oldstrLine.length()];
                  
                  for(int i=0;i<oldchars.length;i++)
                  {
                      if(oldchars[i]!=' ')
                      {
                          newchars[i]=translation(oldchars[i]);
                          if(newchars[i]=='F')
                              System.out.println("ERROR TRANSLATION");
                      }
                      else
                      {
                          newchars[i]=oldchars[i];
                      }
               
                  }
                  
                 String phrase =new String(newchars); 
                  
                  
                 out.println("Case #"+line+": "+phrase); 
               
               
               
           }
                    
         
        oldreader.close();
        out.close();
   //     newreader.close();
        
    //    PrintWriter out = new PrintWriter(new FileWriter("Translator"));
  //      for(int j=0;j<translate.length;j++)
   //    {
   //     out.println(translate[j][0]+"_"+translate[j][1]);
   //     }
  //      out.close();
        } catch (Exception e) {//Catch exception if any
            System.out.println("Error: " + e.toString() + " line: " + oldstrLine);
        }
         
     }
        
   char translation(char oldchar)
   {
       for(int j=0;j<translate.length;j++)
       {
           if(translate[j][0]== oldchar)
           {
               return translate[j][1];
           }
       }
       return 'F';
   }
        
        
        
        
         
    public static void main(String[] args) {
        
       // System.out.println(args[0]);
         
        
        new tongues(args[0]);
        
 
    }
    
    char [][] translate;
    
}
