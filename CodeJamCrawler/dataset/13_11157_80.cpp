package phase1.problemC;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Palindromes {
    
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Palindromes s = new Palindromes();
		try {
			s.doIt();
			//s.test();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private void doIt() throws Exception {
		//Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p3\\A-large.in"));
		Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p3\\C-small-attempt2.in"));
		//Scanner s = new Scanner(new File("C:\\Andre\\GCJInputs\\fase1\\p3\\test.in"));
		
		int T = Integer.valueOf(s.nextLine());
        int cont=1;
        
        //Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p3\\A-large.out"));
        Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p3\\C-small-attempt2.out"));
        //Writer out = new OutputStreamWriter(new FileOutputStream("C:\\Andre\\GCJInputs\\fase1\\p3\\test.out"));
        
        while (cont<=T) {
        	out.write("Case #"+cont+": ");
        	String[] params = s.nextLine().split(" ");
        	out.write(verify(params[0], params[1]));
        	out.write("\n");
        	cont++;
        }
        
        out.flush();
        out.close();
	}
	
	private String verify(String A, String B) {
		String xs = null;
		String lastDigit = null;
		double xd = 0;
		
		Double a = new Double(A);
		Double b = new Double(B);
		// casos especiais, a=1, a<5, a==b

		double q1 = 0;
		double q2 = 0;
		double tmp =0;
		
		if (a==b) {
			xs = String.valueOf(a);
			xs = xs.substring(0, xs.indexOf("."));
			
			lastDigit = xs.substring(xs.length()-1);
			if (("2378").indexOf(lastDigit)>-1) {
				return "0";
			}
			
			xd = Math.sqrt(a);
			String xi = String.valueOf(xd).substring(0, xs.indexOf("."));
			if (xd - Double.parseDouble(xi) > 0) {
				return "0";
			}
			return "1";
		}

		double x = a;
		double nextq = 0;
		int contResp = 0;
		
        if (a>4) {
			while (q1==0 || q2==0) {
				x--;
				
				xs = String.valueOf(x);
				xs = xs.substring(0, xs.indexOf("."));
			
				lastDigit = xs.substring(xs.length()-1);
				if (("2378").indexOf(lastDigit)>-1) {
					continue;
				}
				
				xd = Math.sqrt(x);
				String xi = String.valueOf(xd).substring(0, String.valueOf(xd).indexOf("."));
				if (xd - Double.parseDouble(xi) > 0) {
					continue;
				}
				
				if (q1==0){
					q1=x;
				}
				else {
					q2=x;
				}
			}
			
			double diff = q1 - q2;
			nextq = diff+2+q1;
        }
        else{
        	// 1, 4, 9
        	if (a==1 && b<4) {contResp=1; nextq=4;}
        	else if (a==1) {contResp=2; nextq=9; q1=4;}
        	else if (a>1 && b<4) {contResp=1; nextq=4;}
        	else if (a>1) {contResp=1; nextq=9; q1=4;}
        }
		
		while (nextq<=b) {
			// nextq é >=A e <=B, é palindrome E a raiz quadrada de nextq é palindrome? -> somar +1 na resposta
			if (nextq>=a && nextq<=b && ehPalindrome(nextq) && ehPalindrome(Math.sqrt(nextq))) {
				contResp++;
			}
		
			// pegar proximo quadrado perfeito -> nextq = nextq - q1 + 2 + nextq
			tmp = nextq;
			nextq = nextq - q1 + 2 + nextq;
			q1 = tmp;
		}
		
		return String.valueOf(contResp);
	}
	
	private boolean ehPalindrome(double number) {
		String xs = String.valueOf(number);
		xs = xs.substring(0, xs.indexOf("."));
		
		if (xs.equals(new StringBuilder(xs).reverse().toString())) {
			return true;
		}
		
		return false;
	}
	
	
	private void test() {
		double x = 102;
		String xs = String.valueOf(x);
		xs = xs.substring(0, xs.indexOf("."));
		
		String lastDigit = xs.substring(xs.length()-1);
		
		System.out.println(lastDigit);
		
		//System.out.println(b.doubleValue());
	}

}













