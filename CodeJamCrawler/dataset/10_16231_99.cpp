import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.sql.Time;
import java.util.Scanner;


public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//	 BufferedReader br=new BufferedReader(new FileReader("D:\\"));
//	 BufferedWriter bw=new BufferedWriter(new FileWriter("D:\\"));
     int t,T,n,i,j,k;
     BigInteger Time[]=new BigInteger[1005];
     BigInteger a[]=new BigInteger[1005];
     Scanner cin = new Scanner(System.in);  
     T=cin.nextInt();
     for(t=1;t<=T;t++){
    	 n=cin.nextInt();
    	 for(i=1;i<=n;i++){
    		 Time[i]=cin.nextBigInteger();
    	 }
    	 for(i=1;i<n;i++){
    		 a[i]=Time[i].subtract(Time[i+1]).abs();
    	 }
    	 BigInteger maxT=a[1];
    	 for(i=1;i<n;i++){
    		 maxT=a[i].gcd(maxT);
    	 }
    	 if(Time[1].mod(maxT)==BigInteger.ZERO)  System.out.println("Case #"+t+": "+0+"");
    	 else {
    		 BigInteger ans;
    		 ans=maxT.subtract(Time[1].mod(maxT));
    		 System.out.println("Case #"+t+": "+ans+"");
    	 }
    	 
     }
	}

}
