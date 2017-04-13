import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;
public class A {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new FileInputStream("A-small-attempt1.in"));
		PrintWriter out =new PrintWriter(new BufferedWriter(new FileWriter("Aout.txt")));
		int ca= Integer.parseInt(sc.nextLine());
		HashMap<Character, Integer> map;
		for(int cas=1; cas<=ca; ++cas){
			map=new HashMap<Character, Integer>();
			String s= sc.nextLine();
			int ar[] = new int[s.length()];
			int next=0;
			map.put(s.charAt(0), 1);
			ar[0]=1;
			for(int i=1; i<s.length(); ++i){
				char c=s.charAt(i);
				if(map.containsKey(c)){
					ar[i]=map.get(c);
				}else{
					ar[i]=next;
					map.put(c, next++);
					if(next==1)
						++next;
				}
				//System.out.println(ar[i]);
			}
			if(next==0)
				next=2;
			BigInteger ans=BigInteger.ZERO;
			BigInteger base= BigInteger.valueOf(next);
			for(int i=0; i<s.length(); ++i){
				ans= ans.multiply(base).add(BigInteger.valueOf(ar[i]));
				//System.out.println(ans);
			}
			out.println("Case #"+cas+": "+ans);
		}
		out.close();
		sc.close();
	}
}
