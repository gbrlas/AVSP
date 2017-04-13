package com.baskok.codejam.round1c2009;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class B {

	public class Point {

		public double x;
		public double y;
		public double z;

		public Point(double x, double y, double z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}

		double length() {
			return Math.sqrt(Math.abs(x*x + y*y + z*z));
		}

		public Point minus(Point middle) {
			return new Point(x-middle.x,y-middle.y,z-middle.z);
		}

		public double inProd(Point middle) {
			return x*middle.x + y*middle.y + z*middle.z;
		}

	}

	public class FireFly {

		private double x;
		private double y;
		private double z;
		private double vx;
		private double vy;
		private double vz;

		public FireFly(double x, double y,
				double z, double vx, double vy,
				double vz) {
			this.x = x;
			this.y = y;
			this.z = z;
			this.vx = vx;
			this.vy = vy;
			this.vz = vz;
		}

		public double xAt(double time) {
			return x + vx * time;
		}

		public double yAt(double time) {
			return y + vy * time;
		}

		public double zAt(double time) {
			return z + vz * time;
		}
	
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		File file = new File("src/com/baskok/codejam/round1c2009/B-large.in");
		Scanner in = new Scanner(file);
		int runs = in.nextInt();
		for (int run = 1; run <= runs; run++) {
			B problem = new B();
			// add arguments
			String result = problem.solve(in);
			System.out.println("Case #" + run + ": " + result);
		}
	}

	private String solve(Scanner in) {
		int numberOfFlies = in.nextInt();
		ArrayList<FireFly> flies = new ArrayList<FireFly>();
		for (int i = 0; i < numberOfFlies; i++) {
			flies.add(new FireFly(in.nextDouble(), in.nextDouble(), in.nextDouble(), in.nextDouble(), in.nextDouble(), in.nextDouble()));
		}
		
		double startTime = 0;
		double endTime = 9999999999.0d;
		double middleTime = 0d;
		Point middle, start, end;
		
		while (true) {
			
			start = calcDt(flies, startTime);
			end  = calcDt(flies, endTime);

			middleTime = ((startTime + endTime) / 2);
			middle = calcDt(flies, middleTime);
			
//			System.out.println("st: " + +startTime + " et: " + endTime + " mt: " + middleTime);
//			System.out.println("smlen: " + start.minus(end).length());
			
			if (start.minus(end).length() < 0.000000001d) {
				break;
			}
			
			if (start.minus(middle).inProd(middle) > 0) {
				startTime = middleTime;
			} else {
				endTime = middleTime;
			}
		}
		
		// TODO: test velocity zero
		// 
		return String.format("%.08f %.08f", middle.length(), startTime);
	}

	private Point calcDt(ArrayList<FireFly> flies, double time) {
		double x = 0;
		double y = 0;
		double z = 0;
		for (FireFly fireFly : flies) {
			x += fireFly.xAt(time);
			y += fireFly.yAt(time);
			z += fireFly.zAt(time);
		}
		x /= (double) flies.size();
		y /= (double) flies.size();
		z /= (double) flies.size();
		return new Point(x,y,z);
	}

}
