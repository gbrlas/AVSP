import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class WaterPlants {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Scanner in = new Scanner(new File("input"));
			PrintWriter out = new PrintWriter(new File("output"));
			int tc = in.nextInt();
			for(int t = 0; t < tc; t++) {
				int n = in.nextInt();
				int[] x = new int[n];
				int[] y = new int[n];
				int[] r = new int[n];
				for(int i = 0; i < n; i++){
					x[i] = in.nextInt();
					y[i] = in.nextInt();
					r[i] = in.nextInt();
				}
				if(n == 1) {
					out.printf("Case #%d: %f\n",t + 1,(double)r[0]);
				}
				if(n == 2) {
					out.printf("Case #%d: %f\n",t + 1,(double)Math.max(r[0], r[1]));
				} 
				if(n == 3) {
					double ab = Math.sqrt((x[0]-x[1])*(x[0]-x[1]) + (y[0]-y[1])*(y[0]-y[1])) + r[0] + r[1];
					double ac = Math.sqrt((x[0]-x[2])*(x[0]-x[2]) + (y[0]-y[2])*(y[0]-y[2])) + r[0] + r[2];
					double cb = Math.sqrt((x[2]-x[1])*(x[2]-x[1]) + (y[2]-y[1])*(y[2]-y[1])) + r[1] + r[2];
					out.printf("Case #%d: %f\n",t + 1,(double)Math.min(ab, Math.min(ac, cb))/2);
				}
			}
			out.close();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}

}
