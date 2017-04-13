import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Vector;



public class round1c {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader file = new BufferedReader(new FileReader(new File("input.txt")));
		String line = "";
		int p, q, n, coins = 0;
		
		Integer[] toRelease;
		boolean[] cells;
		
		line = file.readLine();
		n = Integer.valueOf(line);
		
		for(int cases = 1; cases <= n; ++cases) {
			
			line = file.readLine();
			String[] tmp = line.split(" ");
			p = Integer.valueOf(tmp[0]);
			q = Integer.valueOf(tmp[1]);
			
			toRelease = new Integer[q];
			cells = new boolean[p];
			for(int j = 0; j < p; ++j)
				cells[j] = true;
			
			line = file.readLine();
			tmp = line.split(" ");
			int i = 0;
			
			for(String s: tmp)
				toRelease[i++] = Integer.valueOf(s);	
			
			Integer[] ta = null;
			
			int k=0, min = Integer.MAX_VALUE;
			Integer[] copy = Arrays.copyOf(toRelease, toRelease.length);
			while((ta = permute(copy, k++)) != null) {
				copy = Arrays.copyOf(toRelease, toRelease.length);
				
				int mc = getCoins(p, ta);
				if(mc < min)
					min = mc;
			}
			System.out.println("Case #" + cases + ": " +  min);
		}
	}
	
	static public Integer[] permute(Integer[] ia, int num) {
    
		int f = 1;
		for(int i = 2; i < ia.length; ++i)
			f *= i; 
	
		if (num/ia.length >= f)                       
			return null;
	
		for(int i = 0; i < ia.length - 1; ++i){
	
	        int newi = (num / f) % (ia.length - i);
			Integer tmp = ia[i + newi];
			
			for(int j = i + newi; j > i; --j)
				ia[j] = ia[j-1];
	
			ia[i] = tmp; 
			f /= (ia.length - (i + 1)); 
		}
		return ia;
	}
	
	static int getCoins(int cellCount, Integer[] release) {
		int coins = 0, i = 1;
		boolean[] cells = new boolean[cellCount];
		for(int j = 0; j < cellCount; ++j)
			cells[j] = true;
		
		for(int r: release) {
			r -=1;
			i = 1;
			
			cells[r] = false;
			
			//up
			try {
				while(cells[r+i++])
					coins++;
			} catch (ArrayIndexOutOfBoundsException e){}
			
			//down
			i = 1;
			try {
				while(cells[r-i++])
					coins++;
			} catch (ArrayIndexOutOfBoundsException e){}
		}
		
		return coins;
	}

}
