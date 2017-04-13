import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Q1 {

	static Scanner scn = new Scanner(System.in);
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		int cases = scn.nextInt();
		
		for (int ca = 1; ca <= cases; ca++) {
		
			long n, a, b, c, d, x0, y0, m;
			n = scn.nextInt();
			a = scn.nextInt();
			b = scn.nextInt();
			c = scn.nextInt();
			d = scn.nextInt();
			x0 = scn.nextInt();
			y0 = scn.nextInt();
			m = scn.nextInt();
			
			List<Point> pointlist = null;
			long count = 0;
			pointlist = getPointList(n,a,b,c,d,x0,y0,m);
			for(int i1 = 0; i1 < pointlist.size(); i1++) {
				for(int i2 = i1+1; i2 < pointlist.size(); i2++) {
					for(int i3 = i2+1; i3 < pointlist.size(); i3++) {
						if (valid(pointlist, i1, i2, i3)) {
							count++;
						}
					}
				}
			}
			
			System.out.println("Case #" + ca + ": " + count);
		}
		
		

	}

	private static boolean valid(List<Point> pointlist, int i1, int i2, int i3) {
		Point a = pointlist.get(i1);
		Point b = pointlist.get(i2);
		Point c = pointlist.get(i3);
		long x = a.x + b.x + c.x;
		long y = a.y + b.y + c.y;
		if (x % 3 == 0 && y % 3 == 0) {
			return true;
		}
		return false;
	}

	private static List<Point> getPointList(long n, long a, long b, long c, long d,
			long x0, long y0, long m) {
		List<Point> points = new ArrayList<Point>((int) n);
		points.add(new Point(x0, y0));
		long x = x0;
		long y = y0;
		for (int i = 1; i < n; i++) {
			  x = (a*x+b) %m;
			  y = (c*y+d) %m;
			  points.add(new Point(x, y));
		}
		return points;
	}

}

class Point {
	public Point(long x0, long y0) {
		x = x0;
		y = y0;
	}

	long x,y;
	
	
	public String toString() {
		return "(" + x + "," + y + ")";
	}
	
}
