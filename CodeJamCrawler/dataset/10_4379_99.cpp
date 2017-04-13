package net.antiwalking;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class FairWarning {
	  private static final FairWarning instance = new FairWarning();
	  private FairWarning(){};
	  public static FairWarning getInstance(){
	    return FairWarning.instance;
	  }
	  
	  private String solve(Vector<BigInteger> v ){
		  int n = v.size();
		  Vector<BigInteger> sub = new Vector<BigInteger>();
		  Vector<BigInteger> mod = new Vector<BigInteger>();
		  for(int i = 0; i < n ;i ++){
			  for(int j = i + 1; j < n; j++){
				  sub.add(v.get(i).subtract(v.get(j)).abs());
			  }
		  }
		  BigInteger div = sub.get(0);
		  for(int i = 1; i < sub.size() ;i ++){
			  div = div.gcd(sub.get(i));
		  }
		  //System.out.println("div : " + div );
		  BigInteger min = (div.subtract(v.get(0).divideAndRemainder(div)[1])).divideAndRemainder(div)[1];
		  for(int i = 1; i < n ;i ++){
			  min = (div.subtract(v.get(i).divideAndRemainder(div)[1]).divideAndRemainder(div)[1]).min(min);
			  //System.out.println(mod.get(i));
		  }
		  return min.toString();
	  }
	  
	  
	  public static void main(String args[]) throws IOException{
		  Scanner sc = new Scanner(new File("B-small-attempt0.in"));
		  int cases = sc.nextInt();
		  
		  for(int i = 0; i < cases;i ++) {
			  int n = sc.nextInt();
			  Vector<BigInteger> v = new Vector<BigInteger>();
			  for(int j = 0; j< n;j++){
				  String s = sc.next();
				  v.add(new BigInteger(s));
			  }
			  System.out.print("Case #" + (i+1) + ": ");
			  String answer = instance.solve(v);
			  System.out.println(answer);
		  }
		  sc.close();
		  
	  }
}
