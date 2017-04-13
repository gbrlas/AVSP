import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class FairSquare {
	public static void main(String[] args) {
		FairSquareCache cache = new FairSquareCache((long)Math.pow(10, 12));
		cache.buildCache();
		
		if(args.length == 0) {
			System.err.println("Specify filename!");
			return;
		}
		
		Scanner s = null;
		try {
			s = new Scanner(new File(args[0]));
		} catch (FileNotFoundException e) {
			System.err.println("File not found: "+args[0]);
			return;
		}
		
		int cases = s.nextInt();
		
		for(int casenr = 0; casenr < cases; casenr++) {
			new Case(s, casenr);
		}
	}
}

class FairSquareCache {
	static Set<Long> cache = new LinkedHashSet<>();
	private long ts, tss;
	private long limit;
	
	FairSquareCache(long limit) {
		this.limit = limit;
	}
	
	void buildCache() {
		cache.add(1l);
		
		int max_digits = (int)Math.ceil(Math.log10(limit+1));
		
		System.err.print("Building Fair Square cache...");
		ts = tss =System.nanoTime();
		
		for(int digit = max_digits-1; digit <= max_digits; digit++) {
			getDigits(digit);
		}
		System.err.printf(" Finished in %.3f seconds\n", (double)(System.nanoTime() - tss) / 1000000000l);
	}
	
	long[] getDigits(int digit) {
		long out[];
		
		if(digit == 1) {
			out = new long[10];
			for(int i=0; i<=9; i++) {
				out[i] = i;
				checkNum(i);
			}
		}
		else if(digit == 2) {
			out = new long[10];
			for(int i=0; i<=9; i++) {
				out[i] = i + i*10;
				checkNum(i + i*10);
			}
		}
		else {
			long in[] = getDigits(digit-2);
			out = new long[in.length*10];
			for(int i=0; i<in.length; i++) {
				for(int j=0; j<=9; j++) {
					long r = 
							(    j  * (long)Math.pow(10, digit-1) ) +
							( in[i] * 10) +
							j;
					out[i*10 + j] = r;
					if(r < Math.sqrt(Long.MAX_VALUE)) {
						checkNum(r);
					}
				}
			}
		}
		return out;
	}

	void checkNum(long i) {
		if(cache.contains(i)) {
			return;
		}
		
		if(System.nanoTime() - ts > 1000000000l) {
			ts = System.nanoTime();
			System.err.print(".");
		}

		if(isPalindrome(i) && i > 1) {
			long n = i*i;
			while(n < limit && n < Math.sqrt(Long.MAX_VALUE) && isPalindrome(n)) {
				cache.add(n);
				n *= n;
			}
		}
	}
	
	static boolean isPalindrome(long i) {
		int len = (int)Math.ceil(Math.log10(i+1));
		for (int n = 0; n < len / 2; n++) {
	        if ((i / (int)Math.pow(10, n)) % 10 != (i / (int)Math.pow(10, len - n - 1)) % 10)
	            return false;
		}
		return true;
	}
}

class Case {
	int casenr;
	boolean res;
	
	Case(Scanner s, int casenr) {
		this.casenr = casenr;
		int a = s.nextInt();
		int b = s.nextInt();
		int c = 0;
		
		for(long i=a; i<=b; i++) {
			for(Long l : FairSquareCache.cache) {
				if(l == i) c++;
			}
		}
		
		resCount(c);
		resUnknown();
	}

	void resCount(int v) {
		if(!res) {
			res = true;
			System.out.printf("Case #%d: %d\n", casenr+1, v);
		}
	}
	
	void resUnknown() {
		if(!res) {
			System.out.printf("Case #%d: Fail :-(\n", casenr+1);
		}
	}
}
