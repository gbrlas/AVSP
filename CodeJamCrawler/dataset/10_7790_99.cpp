import java.math.*;
import java.io.*;
import java.util.*;

class gcj2{
	public static void main(String argv[]){
		Scanner scan = new Scanner(System.in);
		int t,u,n,m;
		BigInteger res,back,toplus,temp;
		t = scan.nextInt();
		
		toplus=BigInteger.ONE;
		for(u=0;u<55;u++){
			toplus=toplus.multiply(BigInteger.TEN);
		}
		
		for(u=1;u<=t;u++){
			n = scan.nextInt();
			
			back=scan.nextBigInteger();
			temp=scan.nextBigInteger();
			res = temp.max(back).subtract(temp.min(back));
			for(m=2;m<n;m++){
				temp=scan.nextBigInteger();
				temp = temp.max(back).subtract(temp.min(back));
				res = res.gcd(temp);
			}
			
//			System.out.println(back.toString()+" "+res.toString());
			res = res.subtract(back.mod(res)).mod(res);
			System.out.println("Case #"+u+": "+res.toString());
		}
	}
}