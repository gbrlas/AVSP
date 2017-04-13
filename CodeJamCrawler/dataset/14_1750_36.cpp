import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MagicTrick {
	private static PrintWriter sortie;
	private static Scanner scanner = new Scanner(System.in);
	
    public static <T> List<T> intersection(List<T> list1, List<T> list2) {
        List<T> list = new ArrayList<T>();

        for(T t : list1)
            if(list2.contains(t)) list.add(t);

        return list;
    }
	
	public static void main(String[] args) {
		start();
		
	    int T = scanner.nextInt();
	    
	    System.out.println(T);
	    scanner.nextLine();
	    
	    for(int i = 0;i<T;++i) {
	    	int row = scanner.nextInt();
	    	int j = 0;
	    	System.out.println(row);
	    	ArrayList<Integer> cards1 = new ArrayList<Integer>(4);
	    	
	    	for(j = 0;j<row;++j) scanner.nextLine();
	    	for(int k = 0;k<4;++k) cards1.add(scanner.nextInt());
	    	for(;j<4;++j) scanner.nextLine();
	    	
	    	scanner.nextLine();
	    	
	    	row = scanner.nextInt();
	    	
	    	ArrayList<Integer> cards2 = new ArrayList<Integer>(4);
	    	
	    	for(j = 0;j<row;++j) scanner.nextLine();
	    	for(int k = 0;k<4;++k) cards2.add(scanner.nextInt());
	    	for(;j<4;++j) scanner.nextLine();
	    	
	    	scanner.nextLine();
	    	
	    	ArrayList<Integer> intersect = (ArrayList<Integer>) intersection(cards1, cards2);
	    	
	    	if(intersect.size() == 1) sortie.println("Case #"+(i+1)+": "+intersect.get(0));
	    	else if(intersect.size() > 1) sortie.println("Case #"+(i+1)+": Bad magician!");
	    	else sortie.println("Case #"+(i+1)+": Volunteer cheated!");
	    }
	    
	    end();
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
