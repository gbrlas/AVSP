import java.util.*;
import java.io.*;
public class B {

	public static boolean ugly(long input) {
		
		
		if (input ==0) {
			return true;
		}
		if (input %2==0 || input%3==0 || input%5==0 || input%7==0) {
			return true;
		}
		return false;
	}
	
	public static long cal(String s) {
		StringTokenizer token = new StringTokenizer (s,"+-",true);
		boolean plus=true;
		long result = 0;
		while (token.hasMoreTokens()) {
			String ss = token.nextToken();
		
			if (ss.equals("+")) {
				plus = true;
			} else if (ss.equals("-")) {
				plus = false;
			} else {
				if (plus) {
					result+= Long.parseLong(ss);
				} else {
					result-= Long.parseLong(ss);
				}
			}
		}
		return result;
		
		
		
	}
	public static long recur(String s,int depth,int curdepth) {
		//System.out.println(s);
		if (curdepth==1) {
			if (ugly(cal(s))) {
				return 1;
			} else  {
				return 0;
			}
		}
		//System.out.println(s.substring(0,depth-curdepth+1)+"+"+s.substring(depth-curdepth+1));
		
		return recur(s.substring(0,depth-curdepth+1)+"+"+s.substring(depth-curdepth+1),depth+1,curdepth-1)
		+recur(s.substring(0,depth-curdepth+1)+"-"+s.substring(depth-curdepth+1),depth+1,curdepth-1)
		+recur(s,depth,curdepth-1);
				

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			BufferedReader br = new BufferedReader(new FileReader("b2.in"));

			PrintWriter pw = new PrintWriter(new FileWriter("b_output.txt"));
			String s;
			int num = Integer.parseInt(br.readLine());
			
			for (int i=0; i<num; i++) {
				s = br.readLine();
				
				
				long result =0;
				result = recur(s,s.length(),s.length());
				System.out.println("Case #"+(i+1)+": "+result);
				pw.println("Case #"+(i+1)+": "+result);
			}
			pw.close();
		} catch (IOException e) {
			System.out.println("io error");
		}
	}

}
