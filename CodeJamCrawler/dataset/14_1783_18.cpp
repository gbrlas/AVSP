import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class TrainCars {
	private static PrintWriter sortie;
	
	private static Scanner scanner;
	private boolean[] used;
	private int total = 0;
	private int size;
	private String[] cars;
	private ArrayList<String> chain = new ArrayList<String>();
	
	public static void main(String[] args) {
		start();
		scanner = new Scanner(System.in);
		
	    int T = scanner.nextInt();
	    
	    scanner.nextLine();

	    for(int i = 0;i<T;++i) {
	    	TrainCars test = new TrainCars();
	    	
	    	sortie.println("Case #"+(i+1)+": "+test.getResult());
	    }
	    
	    end();
	}

	private int getResult() {
		int N = scanner.nextInt();
		scanner.nextLine();
		String str = scanner.nextLine();
		
		cars = str.split(" ");
		size = N;
		used = new boolean[N];
		total = 0;
		
		for(int i = 0;i<N;++i) {
			used[i] = true;
			chain.add(cars[i]);
			recTest(i);
			chain.remove(chain.size()-1);
			used[i] = false;
		}

		return total;
	}

	private void recTest(int current) {
		if(allUsed()) {
			if(testOk()) {
				//System.out.println(chain);
				total++;
			}
			
			return;
		}
		
		for(int i = 0;i<size;++i) {
			if(!used[i]) {
				if(canAdd(current, i)) {
					used[i] = true;
					chain.add(cars[i]);
					recTest(i);
					chain.remove(chain.size()-1);
					used[i] = false;
				}
			}
		}
	}

	private boolean testOk() {
		char current = chain.get(0).charAt(0);
		boolean[] letters = new boolean[26];
		letters[current - 'a'] = true;
		
		for(int i = 0;i<chain.size();++i) {
			String str = chain.get(i);
			
			for(int j = 0;j<str.length();++j) {
				char newOne = str.charAt(j);
				
				if(newOne == current)
					continue;
				else if(letters[newOne - 'a']) 
					return false;
				else {
					letters[newOne - 'a'] = true;
					current = newOne;
				}
			}
		}
		
		return true;
	}

	private boolean allUsed() {
		return chain.size() == size;
	}

	private boolean canAdd(int current, int i) {
		return true;
		/*
		String first = cars[current];
		String second = cars[i];
		
		return first.charAt(first.length()-1) == second.charAt(0);
		// */
	}

	private static void end() {
	    sortie.close();
	    try {
		    InputStream ips=new FileInputStream("C:\\Users\\Thomas\\Desktop\\output.txt"); 
			InputStreamReader ipsr=new InputStreamReader(ips);
			BufferedReader br=new BufferedReader(ipsr);
			String ligne;
			while ((ligne=br.readLine())!=null) System.out.println(ligne);
			br.close(); 
	    } catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void start() {
		try {
			sortie =  new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\Thomas\\Desktop\\output.txt")));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
