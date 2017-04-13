import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
/*
 * SmallInput.java
 *
 * Created on September 3, 2009, 12:34 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

/**
 *
 * @author ganeshramsakthi
 */
public class SmallInput
{
    String[] existingWords;
    int length;
    int noOfCases;
    FileReader fin;
    
    /** Creates a new instance of SmallInput */
    public SmallInput(FileReader fin)
    {
        this.fin = fin;
    }
    
    public void setFields(String str) throws Exception
    {
        String[] vals = str.split(" ");
        
        if(vals.length != 3)
        {
            throw new Exception("NOT A VALID INPUT.");
        }
        
        length = Integer.parseInt(vals[0]);
        existingWords = new String[Integer.parseInt(vals[1])];
        noOfCases = Integer.parseInt(vals[2]);
        
        System.out.println(length);
        System.out.println(Integer.parseInt(vals[1]));
        System.out.println(noOfCases);
    }
    
    public void writeOutput() throws IOException, Exception
    {
        BufferedReader br = new BufferedReader(fin);
        
        String str = br.readLine();
        if(br == null)
        {
            throw new Exception("NOT A VALID INPUT.");
        }
        setFields(str);
        
        int i = 0;
        while(i < existingWords.length)
        {
            str = br.readLine();
           
            if(str == null)
            {
                throw new Exception("No of existing numbers value and actual words doesnt match");
            }
            
            existingWords[i] = str;
            i++;
        }
        
        BufferedWriter bw = new BufferedWriter(new FileWriter(new File("C:\\Documents and Settings\\ganeshramsakthi\\Desktop\\test ODS files\\Output.out")));
        i = 0;
        while(i < noOfCases)
        {
            str = br.readLine();
            
            if(str == null)
            {
                throw new Exception("No of testCases value and actual testCases doesnt match");
            }
            
            str = str.replaceAll("[(]", "[");
            str = str.replaceAll("[)]", "]");
             
            int count = 0;
            for(String s : existingWords)
            {
                if(s.matches(str))
                {
                    count++;
                }
            }
            
            String output = "Case #"+(i+1)+": "+count;           
            bw.write(output+'\n');
            i++;
        }
        bw.close();
    }
    
    public static void main(String args[]) throws Exception
    {
        try
        {
            FileReader fin = new FileReader(new File("C:\\Documents and Settings\\ganeshramsakthi\\My Documents\\Downloads\\A-large.in"));
            
            SmallInput sI = new SmallInput(fin);
            sI.writeOutput();
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
}
