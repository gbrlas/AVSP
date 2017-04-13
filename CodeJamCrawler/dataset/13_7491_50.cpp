/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package fair.square;

import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.IntBuffer;
import java.util.ArrayList;

/**
 *
 * @author Owner
 */
public class FairSquare {


    /**
     * @param args the command line arguments
     */
    
   boolean AreAll9s( int[] num, int n )
    {
        int i;
        for( i = 0; i < n; ++i )
            if( num[i] != 9 )
                return false;
        return true;
    }  
    int[] findNextPalindrome(int[] arr,int n)
{
	int i,j,carry,low,high;

        if( AreAll9s( arr, n ) )
    {
        arr = new int[n+1];
        arr[0] = 1;
        for( i = 1; i < n; i++ )
            arr[i] = 0;
        arr[i] = 1;
    }
        else
        {
	i=0;j=n-1;
	while(i<j && arr[j]>=arr[i])
        {
	i++;j--;
        }

	if(i>=j)
	{
		if(n%2 == 0){
                    //handle even length palindrome
			i--;j++;
                }
		carry=1;
		while(i>=0)
		{
			arr[i]+=carry;
			carry=arr[i]/10;
			arr[i]%=10;
			arr[j++]=arr[i--];
		}
	}
	else
	{
		low=i+1;high=j-1;
		while(i>=0)
			arr[j++]=arr[i--];
		while(low<high)	// handle the case 8683
		{
			arr[low]=arr[high]=arr[low]<arr[high]?arr[low]:arr[high];
			low++;high--;
		}
	}
        }
        return arr;
}
  public static BigDecimal sqrt(BigInteger in1, int scale)
  {
        BigDecimal sqrt = new BigDecimal(1);
        BigDecimal in = new BigDecimal(in1);
        sqrt.setScale(scale + 3, RoundingMode.FLOOR);
        BigDecimal store = new BigDecimal(in.toString());
        boolean first = true;
        do{
            if (!first){
                store = new BigDecimal(sqrt.toString());
            }
            else first = false;
            store.setScale(scale + 3, RoundingMode.FLOOR);
            sqrt = in.divide(store, scale + 3, RoundingMode.FLOOR).add(store).divide(
                BigDecimal.valueOf(2), scale + 3, RoundingMode.FLOOR);
        }while (!store.equals(sqrt));
        return sqrt.setScale(scale, RoundingMode.FLOOR);
    }

    boolean checkPalindrome(String text)
    {
        String rev = new StringBuffer(text).reverse().toString();
        if(text.equalsIgnoreCase(rev))
            return true;
        else
            return false;
    }
   
    int[] convertbyteArray(String str1)
    {
        /*
        int[] res = new int[res1.length];
        for(int i = 0; i < res.length; i++)
        {
            res[i]=res1[i] & 0Xff;
            System.out.println("Result"+res[i]+" : "+res1[i]);
        }
     
        //res = toIntArray(res1);
        StringBuffer str = new StringBuffer();
        for(int i = 0; i < res.length; i++)
            str.append(res[i]);
        
        String str1 = str.toString();
        if(str1.startsWith("0"))
            str1 = str1.substring(1);
        System.out.println(str);
        * 
        */
        int newres[] = new int[str1.length()];
        for(int i = 0; i < str1.length(); i++)
        {
            newres[i] =   Integer.parseInt(str1.charAt(i)+"");
            //System.out.print(":"+newres[i]);
        }
        return newres;
    }
    int checkFairSquare(String index1,String index2) throws UnsupportedEncodingException
    {
        
        Palindrome p1 = new Palindrome();
        BigInteger b1 = new BigInteger(index1);
        BigInteger b2 = new BigInteger(index2);
        int count = 0;
        BigInteger i;
        BigInteger palin = new BigInteger("0");
        for(i = b1; i.compareTo(b2) <= 0; i = i.add(BigInteger.ONE))
        {
            
            if(checkPalindrome(i.toString()))
            {
                //System.out.println(i);
                BigDecimal b3 = sqrt(i,3);
                BigDecimal fraction = b3.remainder(BigDecimal.ONE);
               // System.out.println(i+":"+b3);
                if(fraction.compareTo(BigDecimal.ZERO) == 0 && checkPalindrome(b3.toBigInteger().toString()))
                {    
                    //System.out.println(i+":"+b3.toBigInteger());
                    palin = b3.toBigInteger();
                    ++count;
                    break;
                }
            }
        }
        boolean proceed = true;
        if(palin.compareTo(BigInteger.ZERO) != 0)
        {
            while(proceed)
            {
                
                int coun = 0;
                String num1 = palin.toString();
                int[] num = convertbyteArray(num1);
                int[] res = findNextPalindrome( num,num.length);
                StringBuffer str = new StringBuffer();
                for(int a = 0; a < res.length; a++)str.append(res[a]);
                BigInteger b4 = new BigInteger(str.toString());
                BigInteger b5 = b4.multiply(b4);
                if(b5.compareTo(b2) <= 0)
                {
                    if(checkPalindrome(b5.toString()))
                    {
                        //System.out.println(b5+":"+b4);
                        ++count;
                    }
                    palin = b4;
                    //System.out.println("Palin : "+palin);
                    proceed = true;
                    
                }
                else
                    proceed = false;
                
            }
        }
        return count;
    }
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
        FairSquare f1 = new FairSquare();
        File input = new File("C:/Documents and Settings/Owner/My Documents/Downloads/C-small-attempt1.in");
        BufferedReader reader = new BufferedReader(new FileReader(input));
        String line;
        
        File output = new File("C:/Documents and Settings/Owner/Desktop/output.txt");
        BufferedWriter writer = new BufferedWriter(new FileWriter(output));
        
        int testcase = Integer.parseInt(reader.readLine());
        ArrayList<String> inp = new ArrayList<String>();
        while((line = reader.readLine()) != null)
        {
              if(!line.isEmpty())
              {
                 inp.add(line);
              }
        }
        String text;
        String index1,index2;
        int j = 0;
        int count = 0;
        String caseStr;
        int caseNo = 0;
        while(j < inp.size())
        {
            ++caseNo;
            text = inp.get(j);
            int a = text.indexOf(" ");
            index1 = text.substring(0,a);
            index2 = text.substring(a+1);
            //System.out.println(index1+":"+index2);
            count = f1.checkFairSquare(index1,index2);
            caseStr = "Case #"+caseNo+": "+count;
            writer.write(caseStr);
            writer.write("\n");
            //System.out.println(caseStr);
            ++j;
        }
        writer.close();
    }
}
