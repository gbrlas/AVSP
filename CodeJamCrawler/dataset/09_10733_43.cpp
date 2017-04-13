/*
 * PrefactoredRandom.java
 *
 */

import java.math.*;
import java.util.*;
import java.io.*;


public class A {
public static String getProper(String s) {
	String ret = "";
	boolean inside = false;
	for(int i = 0; i < s.length(); i++){
		char ch = s.charAt(i);
		if(ch ==')') ch = ']';
		if(ch =='(') ch = '[';
		ret += ch;
	}

	return ret;
}


	public static void main(String[] args) throws IOException {
		BufferedReader  in = new BufferedReader (new InputStreamReader(System.in));
		String line = in.readLine();
		String parts[] = line.split(" ");

		int L = Integer.parseInt(parts[0]);
		int D = Integer.parseInt(parts[1]);
		int N = Integer.parseInt(parts[2]);

		Vector<String> dict = new Vector<String>();

		for(int cnt = 0; cnt < D; cnt++)
			dict.add(in.readLine());
		
		for(int cnt = 0; cnt < N; cnt++) {
			String pat = getProper(in.readLine());
			int ans = 0;
			for(int i = 0; i < dict.size(); i++) if(dict.get(i).matches(pat)) ans++;
			System.out.println("Case #" + (cnt+1) + ": " + ans);
		}
	}
}
