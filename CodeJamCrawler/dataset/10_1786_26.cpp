import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class NumDirectories {
	public static void main(String[] args) {
		NumDirectories test = new NumDirectories();
		try {
			test.doMain();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}


	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("/home/sajith/A-small-attempt1.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("/home/sajith/out1.out"));
		int N = sc.nextInt();
		
		NumberFormat nf = NumberFormat.getInstance();
		for (int caseNum=1; caseNum <= N; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			int value = solve(sc);
			pw.println(value);
		}
		pw.flush();
		pw.close();
		sc.close();
	}

	private int solve(Scanner sc) {
		int n = sc.nextInt();
		int m = sc.nextInt();
		int count = 0;
		List<Set<String>> exDirectories = new ArrayList<Set<String>>();  

		for(int i=0; i<n ; i++){
			String dir = sc.next();
			updateDir(exDirectories, dir);
		}
		
		for(int i=0; i<m ; i++){
			String dir = sc.next();
			count += updateWithNewDir(exDirectories, dir);
		}
		return count;
	}


	private int updateWithNewDir(List<Set<String>> exDirectories, String dir) {
		int strlen = dir.length();
		int ind = 0;
		String parent;
		int count = 0;
		Set<String> levelDirs = new HashSet<String>();
		for(int i=1;i<strlen; i++){
			if(dir.charAt(i) != '/')
				continue;
			parent = dir.substring(0, i);
			if(exDirectories.size() <= ind)
				exDirectories.add(new HashSet<String>());
			levelDirs = exDirectories.get(ind);
			if(! levelDirs.contains(parent)){
				levelDirs.add(parent);
				count ++;
			}
			ind++;
		}
		if(dir.charAt(strlen-1) != '/'){
			if(exDirectories.size() <= ind)
				exDirectories.add(new HashSet<String>());
			levelDirs = exDirectories.get(ind);
			if(!levelDirs.contains(dir)){
				levelDirs.add(dir);
				count++;
			}
			
		}
		// TODO Auto-generated method stub
		return count;
	}


	private void updateDir(List<Set<String>> exDirectories, String dir) {
		int strlen = dir.length();
		int ind = 0;
		String parent;
		for(int i=1;i<strlen; i++){
			if(dir.charAt(i) != '/' )
				continue;
			parent = dir.substring(0, i);
			if(exDirectories.size() <= ind)
				exDirectories.add(new HashSet<String>());
			exDirectories.get(ind).add(parent);
			ind++;
		}
		if(dir.charAt(strlen-1) != '/'){
			if(exDirectories.size() <= ind)
				exDirectories.add(new HashSet<String>());
			exDirectories.get(ind).add(dir);
			ind++;
			
			
		}
		// TODO Auto-generated method stub
		
	}
	

}
