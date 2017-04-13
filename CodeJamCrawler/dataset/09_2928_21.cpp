import java.awt.Point;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class Q4 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		DecimalFormat format = new DecimalFormat("0.000000000");
		DecimalFormatSymbols symb = new DecimalFormatSymbols();
		symb.setDecimalSeparator('.');
		format.setDecimalFormatSymbols(symb);
		
		Scanner scn = new Scanner(System.in);
		int cases = scn.nextInt();
		for(int c = 1; c <= cases; c++) {
			int plantNumber = scn.nextInt();
			Plant[] plants = new Plant[plantNumber];
			for(int p = 0; p < plantNumber; p++) {
				int x = scn.nextInt();
				int y = scn.nextInt();
				int r = scn.nextInt();
				plants[p] = new Plant(x,y,r);
			}
			
			double res = 0;
			if(plants.length == 1) {
				res = plants[0].r;
			} else if(plants.length == 2) {
				double opt = (plants[0].distance(plants[1]) + plants[0].r + plants[1].r)/2.0;
				double opt2 = Math.max(plants[0].r, plants[1].r);
				res = Math.min(opt, opt2);
			} else if(plants.length == 3) {
				double dist01 = calculate(plants[0], plants[1], plants[2]);
				double dist02 = calculate(plants[0], plants[2], plants[1]);
				double dist12 = calculate(plants[1], plants[2], plants[0]);
				List<Double> ds = new LinkedList<Double>();
				
				ds.add(dist01);
				ds.add(dist02);
				ds.add(dist12);
				Collections.sort(ds);
				res = ds.get(0);
			}
			
			//small only

			
			StringBuilder builder = new StringBuilder();
			builder.append("Case #");
			builder.append(c);
			builder.append(": ");
			builder.append(format.format(res));
			System.out.println(builder.toString());
		}
	}

	private static double calculate(Plant plant, Plant plant2, Plant plant3) {
		double link = (plant.distance(plant2) + plant.r + plant2.r)/2.0; 
		return Math.max(link, plant3.r);
	}
}

class Plant extends Point {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	int r;
	
	public Plant(int x, int y, int r2) {
		super(x, y);
		r = r2;
	}

}
