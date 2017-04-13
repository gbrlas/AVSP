import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class fairWarning2 {
	
	public static void main(String[] args) {
		fairWarning2 test = new fairWarning2();
		try {
			test.doMain();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}


	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("C:\\Documents and Settings\\SAJITH\\Desktop\\B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("C:\\Documents and Settings\\SAJITH\\Desktop\\output_B_0.txt"));
		int N = sc.nextInt();
		
		for (int caseNum=1; caseNum <= N; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			String value = solve(sc);
			pw.println(value);
		}
		pw.flush();
		pw.close();
		sc.close();
	}

	private String solve(Scanner sc) {
		int n = sc.nextInt();
		
		int[] contents = new int[n];
		for(int i=0; i<n; i++){
			contents[i] = sc.nextInt();
		}
		int earliest = getBiggest(contents);
		int[] diffArray = getDifferenceArray(contents, earliest);
		int gcd = findGCD(diffArray);
		String result = findApo(earliest, gcd);

		return result;
	}
	
	private String findApo(int earliest, int gcd) {
		if(gcd == 1)
			return "0";
		int val = gcd - (earliest%gcd);
		if(val == gcd)
			return "0";
		else 
			return ""+val;
	}

	private int findGCD(int[] diffArray) {
		List<Integer> newArray = new ArrayList<Integer>();
		for(int val: diffArray){
			if(val != 0)
				newArray.add(val);
		}
		
		int[] newArray2 = new int[newArray.size()];
		for(int i=0; i<newArray2.length; i++){
			newArray2[i] = newArray.get(i);
		}
		diffArray = newArray2;
		int gcd = diffArray[0];
		for(int i=1; i<diffArray.length; i++){
			if(gcd == 1)
				break;
			gcd = findGCD(gcd, diffArray[i]);
		}
		return gcd;
	}
	
	private int findGCD(int a, int b){
		if(a == b)
			return a;
		while( true  ){
			int t = a%b;
			a = b;
			b = t;
			if(b == 0)
				return a;
		}
	}

	private int[] getDifferenceArray(int[] contents, int earliest) {
		int[] newArray = new int[contents.length];
		for(int i=0; i<newArray.length; i++){
			newArray[i] = earliest- contents[i];
		}
		return newArray;
	}

	private int getBiggest(int[] contents) {
		// TODO Auto-generated method stub
		int biggest = contents[0];
		for(int i =1; i<contents.length; i++){
			if(contents[i]>biggest)
				biggest = contents[i];
		}
		return biggest;
	}

	private String strSub(String a, String b){
		int alen = a.length();
		int blen = b.length();
		int maxL = Math.max(alen, blen);
		
		a = fmtString(a, maxL);
		b = fmtString(b, maxL);
		
		int v = 0;
		int bl = 0;
		String res = "";
		for(int i=maxL-1; i>=0; i--){
			int val = (a.charAt(i)-bl) - b.charAt(i);
			bl = val < 0? 1:0;
			val = (bl == 0)? val:val+10;
			res = val+res;
		}
		return res;
	}
	
	private String fmtString(String a, int len){
		if(a.length() == len)
			return a;
		StringBuffer buff = new StringBuffer();
		int append = len - a.length();
		for(int i=0; i<append; i++){
			buff.append('0');
		}
		buff.append(a);
		return buff.toString();
	}
	
	private boolean isEqual(String a, String b){
		if(a.length() == b.length())
			return(a.equals(b));
		int alen = a.length();
		int blen = b.length();
		int maxL = Math.max(alen, blen);
		a = fmtString(a, maxL);
		b = fmtString(b, maxL);
		for(int i=0; i<maxL; i++){
			if(a.charAt(i)!=b.charAt(i))
				return false;
		}
		return true;
	}
	
	private String getBigString(String a, String b){
		int alen = a.length();
		int blen = b.length();
		int maxL = Math.max(alen, blen);
		a = fmtString(a, maxL);
		b = fmtString(b, maxL);
		if (isEqual(a, b))
			return a;
		for(int i=0; i<maxL; i++){
			if(a.charAt(i)>b.charAt(i))
				return a;
			else if(b.charAt(i)>a.charAt(i))
				return b;
		}
		return a;
	}
	
	private String getSmallString(String a, String b){
		int alen = a.length();
		int blen = b.length();
		int maxL = Math.max(alen, blen);
		a = fmtString(a, maxL);
		b = fmtString(b, maxL);
		if (isEqual(a, b))
			return a;
		for(int i=0; i<maxL; i++){
			if(a.charAt(i)<b.charAt(i))
				return a;
			else if(b.charAt(i)<a.charAt(i))
				return b;
		}
		return a;
	}
	
}
