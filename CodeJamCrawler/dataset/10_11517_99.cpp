import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class FairWarning {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int C = sc.nextInt();
		for(int i = 1; i <= C; ++i){	
			List<BigDecimal> v = new ArrayList<BigDecimal>();
			int N = sc.nextInt();
			for(int j = 0; j < N; ++j){
				v.add(sc.nextBigDecimal());
			}
			System.out.println("Case #" + i + ": " + calc(v));
		}
	}
	private static BigDecimal gcd(BigDecimal a, BigDecimal b){
		BigDecimal x = a.max(b),
				   y = a.min(b);
		while(y.compareTo(BigDecimal.ZERO) > 0){
			BigDecimal[] v = x.divideAndRemainder(y);
			x = y;
			y = v[1];
		}
		return x;
	}
	private static BigDecimal calc(List<BigDecimal> v) {
		if(v.size() == 1){
			return BigDecimal.ZERO;
		}
		Collections.sort(v);
		BigDecimal min = v.get(0);
		List<BigDecimal> d = new ArrayList<BigDecimal>();
		for(BigDecimal k : v){
			BigDecimal z = k.subtract(min);
			if(z.compareTo(BigDecimal.ZERO) == 0) continue;
			d.add(z);
		}
		
		BigDecimal y = d.get(0);
		for(BigDecimal k : d){
			y = gcd(y, k);
		}
		
		BigDecimal[] r = min.divideAndRemainder(y);
		//System.out.println(min + " " +  y + " " + r[0] + " " + r[1]);
		if(r[1].compareTo(BigDecimal.ZERO) > 0){
			r[0] = r[0].add(BigDecimal.ONE);
		}
		//System.out.println(r[0]);
		return y.multiply(r[0]).subtract(min);
	}

}
