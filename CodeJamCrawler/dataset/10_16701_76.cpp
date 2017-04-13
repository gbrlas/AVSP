import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class B {
    public static void main(String[] args) {
	try{
	    FileReader in =  new FileReader("B-large.in");
	    
	    BufferedReader br = new BufferedReader(in);
	    String line;
	    try {
		line = br.readLine();
		int num = Integer.parseInt(line);
		for(int i=0;i<num;i++) {
		    String[] arr;
		    line = br.readLine();
		    arr = line.split(" ");
		    int nnum = Integer.parseInt(arr[0]);
		    BigInteger delta = new BigInteger("0");
		    BigInteger[] s = new BigInteger[nnum];
		    for(int j = 0; j < nnum; j++) {
			s[j] = new BigInteger(arr[j+1]);
		    }

		    s = sort(s);

		    for(int j = 0; j < nnum-1; j++) {

			BigInteger j1 = s[j];
			BigInteger j2 = s[j+1];
			if(delta.compareTo(BigInteger.ZERO) == 0) {
			    delta = j2.subtract(j1);
			} else {
			    BigInteger p = j2.subtract(j1);
			    if(0 != p.compareTo(BigInteger.ZERO))
				delta = gcd(delta.max(p), delta.min(p));
			}
		    }
	    
		    BigInteger a = new BigInteger(arr[1]);
		    if(delta.compareTo(BigInteger.ZERO) == 0) {
			System.out.println("Case #" + (i+1) + ": 0");
		    }else{
			a = a.remainder(delta);
			
			if(0 == a.compareTo(BigInteger.ZERO)) {
			    System.out.println("Case #" + (i+1) + ": " + a.toString());
			} else {
			    BigInteger ans = delta.subtract(a);
			    System.out.println("Case #" + (i+1) + ": " + ans.toString());
			}
		    }
		}
	    }catch(IOException e) {
		System.out.println("owari");
	    }

	} catch(FileNotFoundException e) {
	    System.out.println("File not found");
	}

    }
    public static BigInteger gcd(BigInteger a, BigInteger b) {
        // a>b
        BigInteger c = a.remainder(b);
        if(0 == c.compareTo(BigInteger.ZERO)) return b;
        return gcd(b,c);
    }
    public static BigInteger[] sort(BigInteger[] s) {
	Arrays.sort(s);
	return s;
    }
}

