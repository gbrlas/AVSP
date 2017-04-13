import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;

public class AlienLanguage 
{
  public AlienLanguage()
  {
  } 
  
  public static void main(String[] args)
  {
    try{
      BufferedReader in = new BufferedReader(new FileReader("C:/CodeJam2009/A-small-attempt1.in"));
      String inputParams = in.readLine();
      String dictWord = null;
      String[] parameters = inputParams.split(" ");
      int totalTokens = Integer.parseInt(parameters[0]);
      int dictionaryWords = Integer.parseInt(parameters[1]);
      int totalInputs = Integer.parseInt(parameters[2]);
      
      Writer output = null;
      File file = new File("C:/CodeJam2009/A-Small.out");
      output = new BufferedWriter(new FileWriter(file));
      
      List inputList = new ArrayList();
      List dictionaryList = new ArrayList();
      
      for(int wordCount = 0; wordCount < dictionaryWords; wordCount++)
      {
        dictWord = in.readLine();
        dictionaryList.add(dictWord);
      }
      
      String sampleInput = null;
      StringBuffer sbSampleInput = null;
      StringBuffer tempBuff = new StringBuffer();
      
      String progOutput = null;
      
      int matchPatternCount = 0;
      for(int testSetCount = 0; testSetCount < totalInputs; testSetCount++)
      {        
        sampleInput = in.readLine();
        sbSampleInput = new StringBuffer(sampleInput);
        
        boolean regExp = false;
        inputList.clear();
        for(int charPos = 0; charPos < sbSampleInput.length(); charPos++)
        {
          if(sbSampleInput.charAt(charPos) == '(')
          {
            regExp = true; 
          }else if(sbSampleInput.charAt(charPos) == ')')
          {
            regExp = false; 
            inputList.add(tempBuff.toString());
            tempBuff = new StringBuffer();
          }else
          {
            if(regExp == false)
            {
              inputList.add(String.valueOf(sbSampleInput.charAt(charPos)));   
            }else
            {
              tempBuff = tempBuff.append(sbSampleInput.charAt(charPos));
            }            
          }
        }
               
        String tokStr = null;
        matchPatternCount = 0;
        StringBuffer dictWordBuf = null;
        for(int k=0; k < dictionaryWords; k++)
        {
          dictWordBuf = new StringBuffer((String)dictionaryList.get(k));
          boolean misMatchFound = false;
          for(int m=0; m < totalTokens; m++)
          {
            tokStr = (String)inputList.get(m);
            if(tokStr.indexOf(dictWordBuf.charAt(m)) == -1)
            {
              misMatchFound = true;
              break;
            }
          }
          if(misMatchFound == false)
          {
            matchPatternCount++; 
          }
        }
        progOutput = "Case #" + (testSetCount + 1) + ":" + " " + matchPatternCount + "\r\n";
        output.write(progOutput);        
      }
      output.flush();
      output.close();
      System.out.println("Execution End");
    }catch(Exception ex){
      ex.printStackTrace();
    }
  }
  
 
  
}