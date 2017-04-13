import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;
import java.math.BigInteger;

public class WelcomeCodeJam 
{
        public static Integer[] wArray = new Integer[500];      
        public static Integer[] eArray = new Integer[500];
        public static Integer[] lArray = new Integer[500];
        public static Integer[] cArray = new Integer[500];
        public static Integer[] oArray = new Integer[500];
        public static Integer[] mArray = new Integer[500];
        public static Integer[] spArray = new Integer[500];
        public static Integer[] tArray = new Integer[500];
        public static Integer[] dArray = new Integer[500];
        public static Integer[] jArray = new Integer[500];
        public static Integer[] aArray = new Integer[500];

  public WelcomeCodeJam()
  {
  }
  
  public BigInteger getCombinationCount(int lastCharIndex, int strPosIndex)
  {
    BigInteger combinationCnt = new BigInteger("0");
    switch(strPosIndex)
    {
      case 1:
        for(int i = 0; (i < eArray.length && eArray[i] != null); i++){
          if(lastCharIndex < eArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(eArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 2:
        for(int i = 0; (i < lArray.length && lArray[i] != null); i++){
          if(lastCharIndex < lArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(lArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 3:
        for(int i = 0; (i < cArray.length && cArray[i] != null); i++){
          if(lastCharIndex < cArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(cArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 4:
        for(int i = 0; (i < oArray.length && oArray[i] != null); i++){
          if(lastCharIndex < oArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(oArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 5:
        for(int i = 0; (i < mArray.length && mArray[i] != null); i++){
          if(lastCharIndex < mArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(mArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 6:
        for(int i = 0; (i < eArray.length && eArray[i] != null); i++){
          if(lastCharIndex < eArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(eArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 7:
        for(int i = 0; (i < spArray.length && spArray[i] != null); i++){
          if(lastCharIndex < spArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(spArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 8:
        for(int i = 0; (i < tArray.length && tArray[i] != null); i++){
          if(lastCharIndex < tArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(tArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 9:
        for(int i = 0; (i < oArray.length && oArray[i] != null); i++){
          if(lastCharIndex < oArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(oArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 10:
        for(int i = 0; (i < spArray.length && spArray[i] != null); i++){
          if(lastCharIndex < spArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(spArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 11:
        for(int i = 0; (i < cArray.length && cArray[i] != null); i++){
          if(lastCharIndex < cArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(cArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 12:
        for(int i = 0; (i < oArray.length && oArray[i] != null); i++){
          if(lastCharIndex < oArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(oArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 13:
        for(int i = 0; (i < dArray.length && dArray[i] != null); i++){
          if(lastCharIndex < dArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(dArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 14:
        for(int i = 0; (i < eArray.length && eArray[i] != null); i++){
          if(lastCharIndex < eArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(eArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 15:
        for(int i = 0; (i < spArray.length && spArray[i] != null); i++){
          if(lastCharIndex < spArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(spArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 16:
        for(int i = 0; (i < jArray.length && jArray[i] != null); i++){
          if(lastCharIndex < jArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(jArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 17:
        for(int i = 0; (i < aArray.length && aArray[i] != null); i++){
          if(lastCharIndex < aArray[i].intValue()){
            combinationCnt = combinationCnt.add(getCombinationCount(aArray[i].intValue(), (strPosIndex+1)));
          }
        }
        break;
        
      case 18:
        for(int i = 0; (i < mArray.length && mArray[i] != null); i++){
          if(lastCharIndex < mArray[i].intValue()){
            combinationCnt = combinationCnt.add(new BigInteger("1"));
          }
        }
        break;
        
    }
    
    return combinationCnt;
  }

  /**
   * 
   * @param args
   */
  public static void main(String[] args)
  {
    try{
      BufferedReader in = new BufferedReader(new FileReader("C:/CodeJam2009/C-small-attempt0.in"));
      String inputParams = in.readLine();
      int totalInputs = Integer.parseInt(inputParams);
      String textLine = null;
      
      Writer output = null;
      File file = new File("C:/CodeJam2009/C-small.out");
      output = new BufferedWriter(new FileWriter(file));
      
      int wCount = 0, eCount = 0, lCount = 0, cCount = 0, oCount = 0, mCount = 0, spCount = 0, sCount = 0, tCount = 0, dCount = 0, jCount = 0, aCount = 0;
      
      
      StringBuffer sb = null;
      BigInteger subStringCount = new BigInteger("0");
      WelcomeCodeJam wcj = new WelcomeCodeJam();

      String progOutput = null;
      for(int testCount = 0; testCount < totalInputs; testCount++)
      {
        textLine = in.readLine();
        subStringCount = new BigInteger("0");
        sb = new StringBuffer(textLine);
        
        wArray = new Integer[500];      
        eArray = new Integer[500];
        lArray = new Integer[500];
        cArray = new Integer[500];
        oArray = new Integer[500];
        mArray = new Integer[500];
        spArray = new Integer[500];
        tArray = new Integer[500];
        dArray = new Integer[500];
        jArray = new Integer[500];
        aArray = new Integer[500];
        
        wCount = eCount = lCount = cCount = oCount = mCount = spCount = sCount = tCount = dCount = jCount = aCount = 0;
        
        for(int charInd = 0; charInd < sb.length(); charInd++)
        {
          switch(sb.charAt(charInd))
          {
            case 'w' : wArray[wCount++] = new Integer(charInd); break;
            case 'e' : eArray[eCount++] = new Integer(charInd); break;
            case 'l' : lArray[lCount++] = new Integer(charInd); break;
            case 'c' : cArray[cCount++] = new Integer(charInd); break;
            case 'o' : oArray[oCount++] = new Integer(charInd); break;
            case 'm' : mArray[mCount++] = new Integer(charInd); break;
            case ' ' : spArray[spCount++] = new Integer(charInd); break;
            case 't' : tArray[tCount++] = new Integer(charInd); break;
            case 'd' : dArray[dCount++] = new Integer(charInd); break;
            case 'j' : jArray[jCount++] = new Integer(charInd); break;
            case 'a' : aArray[aCount++] = new Integer(charInd); break;
          }
        }
        
        for(int w = 0; (w < wArray.length && wArray[w] != null); w++)
        {
          subStringCount = subStringCount.add(wcj.getCombinationCount(wArray[w].intValue(), 1));          
        }
        String strSubStringCount = subStringCount.toString();
        int length = strSubStringCount.length();
        if(length > 4)
        {
          strSubStringCount = strSubStringCount.substring(length-4);
        }else
        {
          String temp = "";
          for(int zero = 0; zero < 4 - length; zero ++ )
          {
            temp = temp + "0";
          }
          strSubStringCount = temp + strSubStringCount;
        }
        
        progOutput = "Case #" + (testCount + 1) + ":" + " " + strSubStringCount + "\r\n";
        output.write(progOutput);        
      }
      
      output.flush();
      output.close();      
      System.out.println("Execution Ends");
      
    }catch(Exception ex)
    {
      ex.printStackTrace();
    }

  }
}