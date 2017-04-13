import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class Q2 {

	static Scanner scn = new Scanner(System.in);
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		int cases = scn.nextInt();
		
		for (int c = 1; c <= cases; c++) {
		
			long a,b,p;
			a = scn.nextLong();
			b = scn.nextLong();
			p = scn.nextLong();
			
			Sets sets = new Sets(a,b);
			for (long x = a; x < b; x++) {
				for (long y = x+1; y <= b; y++) {
					if (sharePrimeFactor(x, y, p)) {
//						System.out.println(x + " e " + y);
						sets.merge(x,y);
					}
				}
			}
			
			System.out.println("Case #" + c + ": " + sets.size());
		}		

	}

	private static boolean sharePrimeFactor(long x, long y, long p) {
		List<Long> fx = getFactors(x);
		List<Long> fy = getFactors(y);
		
		discardLessThen(fx, p);
		discardLessThen(fy, p);
		
		return shareCommon(fx, fy);
	}

	private static boolean shareCommon(List<Long> fx, List<Long> fy) {
		for(Long x : fx) {
			if (fy.contains(x)) {
				return true;
			}
		}
		return false;
	}

	private static void discardLessThen(List<Long> fy, long p) {
		while(fy.size() > 0 && fy.get(0) < p) {
			fy.remove(0);
		}
	}

	private static List<Long> getFactors(long x) {
		List<Long> f = new LinkedList<Long>();
		f.add(1L);

		if (x % 2 == 0) {
			f.add(2L);
		}
		for (long i = 3; i < x/2+1; i+=2) {
			if (x % i == 0 && isPrime(i)) {
				f.add(i);
			}
		}
		if (x != 1) {
			f.add(x);
		}
		return f;
	}

	private static boolean isPrime(long i) {
		if (i % 2 == 0) {
			return false;
		}
		for (int x = 3; x < i/2+1; x++) {
			if (i % x == 0) {
				return false;
			}
		}
		return true;
	}

}

class Sets {

	List<Set<Long>> sets;
	
	
	
	public Sets(long a, long b) {
		sets = new LinkedList<Set<Long>>();
		for (long x = a; x <= b; x++) {
			Set<Long> s = new TreeSet<Long>();
			s.add(x);
			sets.add(s);
		}
	}



	public long size() {
		return sets.size();
	}



	public void merge(long x, long y) {
		Set<Long> sx=null, sy=null;
		int ix=-1, iy=-1;
		
		for (int index = 0; index < sets.size(); index++) {
			Set<Long> s = sets.get(index);
			if (s.contains(x)) {
				sx = s;
				ix = index;
			}
			if (s.contains(y)) {
				sy = s;
				iy = index;
			}
		
		}
		if (ix == iy) {
			return;
		}
		
		sets.remove(ix);
		sy.addAll(sx);
		
	}
	
	public String toString() {
		return sets.toString();
	}
	
}
