
import java.util.Scanner;
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;
class AlienLang 
{
	public static void main(String[] args) 
	{
        try {
            int len = 3;
            int wordCnt = 5;
            int patterns = 4;

            //String[] wordArr = new String[]{"abc","bca","dac","dbc","cba"};
            //String[] patternsArr = new String[] {"(ab)(bc)(ca)","abc","(abc)(abc)(abc)","(zyx)bc"};
            Scanner scannerObj;
            scannerObj = new Scanner(new File("D:\\Code Jam Files and Folders\\2009\\Qualifying round problems\\Ashwini\\in.txt"));

            len = scannerObj.nextInt();
            wordCnt = scannerObj.nextInt();
            patterns = scannerObj.nextInt();
            
            String[] wordArr = new String[wordCnt];
            String[] patternsArr = new String[patterns];
                  
            for (int i = 0; i < wordCnt; i++) {
                wordArr[i]=scannerObj.next();
            }
            for(int j=0;j<patterns;j++){
                patternsArr[j]=scannerObj.next();
            }
            for (int i = 0; i < patterns; i++) {
                int Count = 0;
                if (patternsArr[i].contains("(") == false) {
                    for (int j = 0; j < wordCnt; j++) {
                        if (patternsArr[i].equals(wordArr[j])) {
                            Count++;
                        }
                    }
                    System.out.println("Case #" + (i+1) + ": " + Count);
                } else {
                    for (int j = 0; j < wordCnt; j++) {
                        if (scanWord(patternsArr[i], wordArr[j])) {
                            Count++;
                        }
                    }
                    System.out.println("Case #" + (i+1) + ": " + Count);
                }
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(AlienLang.class.getName()).log(Level.SEVERE, null, ex);
        }
	}
        public static boolean scanWord(String patternStr,String word)
        {
            boolean retVal = false;
            int wordLen = word.length();
            int wordItr = 0;
            boolean found = false;
            for(int i=0;i<patternStr.length() && i>=0;i++)
            {                
                if(patternStr.charAt(i) == '(')
                {                    
                    int indOFCB = patternStr.indexOf(')',i);
                    String substr = patternStr.substring(i+1, indOFCB);
                    if(wordLen>0)
                    {
                        if(!substr.contains(word.substring(wordItr,wordItr+1)))
                        {
                            found = false;
                            break;
                        }
                        else{
                            found = true;
                            wordLen--;
                            wordItr++;
                            i=indOFCB;                                     
                        }
                    }
                }else{
                    int indOFCB = patternStr.indexOf('(',i);
                    String substr = null;
                    if(indOFCB != -1)
                        substr = patternStr.substring(i, indOFCB);
                    else
                        substr = patternStr.substring(i);
                    if(wordLen>0)
                    {
                        if(!substr.equals(word.substring(wordItr,wordItr+substr.length())))
                        {
                            found = false;
                            break;
                        }
                        else{
                            found = true;
                            wordLen = wordLen - substr.length();
                            wordItr = wordItr + substr.length();
                            i=indOFCB-1;         
                        }
                    }
                }                
            }
            if(found)
                retVal = true;
            return retVal;
        }
}
