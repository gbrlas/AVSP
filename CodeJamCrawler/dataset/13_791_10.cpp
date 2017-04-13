import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;


public class FairAndSquare {
	
	public static void main(String[] args) {
		double d = Math.pow(10, 14);
				
		try{
			FileInputStream fi = new FileInputStream("C:\\Users\\PGuha\\Documents\\VMWare\\vmworkspace\\QuickTest\\src\\C-small-attempt0.in");
			FileOutputStream fo = new FileOutputStream("C:\\Users\\PGuha\\Documents\\VMWare\\vmworkspace\\QuickTest\\src\\c-small.out");
			
			InputStreamReader isr = new InputStreamReader(fi);
			OutputStreamWriter osr = new OutputStreamWriter(fo);
			
			BufferedReader br = new BufferedReader(isr);
			BufferedWriter bw = new BufferedWriter(osr);
			
			int totalTestCase = Integer.parseInt(br.readLine());
			
			for(int testCaseCount = 1; testCaseCount <= totalTestCase; testCaseCount++){
				String input[] = br.readLine().split(" ");
				BigInteger fairSquare = new BigInteger("0");
				BigInteger a = new BigInteger(input[0]);
				BigInteger b = new BigInteger(input[1]);
				BigInteger bigOne = new BigInteger("1");
				
				double sqrtVal = 0.0;
				Integer sqrtIntVal = 0;
				
				BigInteger terminate = b.add(bigOne);
				
				for(BigInteger i=a; i.equals(terminate) == false; ){
					if(isPalindrome(i)){
						sqrtVal = Math.sqrt(i.doubleValue());
						sqrtIntVal = new Double(sqrtVal).intValue();
						if(sqrtVal == new Double(sqrtIntVal)){
							if(isPalindrome(new BigInteger(String.valueOf(sqrtIntVal)))){
								fairSquare = fairSquare.add(bigOne);
							}					
						}
					}
					i = i.add(bigOne);
				}
				bw.write("Case #" + testCaseCount + ": " + fairSquare);
				bw.newLine();
			}
			bw.flush();
			osr.close();
			fo.close();

			isr.close();
			fi.close();
		}catch(FileNotFoundException fnfe){
			fnfe.printStackTrace();
		}catch(IOException ioe){
			ioe.printStackTrace();
		}

	}
	
	private static boolean isPalindrome(BigInteger palindromNum){
		boolean palinDrom = false;
		
		StringBuffer sb = new StringBuffer(String.valueOf(palindromNum));
		
		int numLength = sb.toString().length();
		
		String firstPart = null;
		String secondPart = null;		
				
		if(numLength % 2 == 0){
			firstPart = sb.toString().substring(0, numLength/2);
			secondPart = sb.toString().substring(numLength/2);		
		}else{
			firstPart = sb.toString().substring(0, numLength/2);
			secondPart = sb.toString().substring(numLength/2+1);
		}

		if(firstPart.equalsIgnoreCase((new StringBuffer(secondPart).reverse()).toString())){
			palinDrom = true;
		}else{
			palinDrom = false;
		}
		
		return palinDrom;
	}

}
