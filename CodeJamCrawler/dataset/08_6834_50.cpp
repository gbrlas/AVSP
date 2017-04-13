import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;


public class ProblemB {
	public static void main(String[] args) throws Exception {
		new ProblemB();
	}

	public ProblemB() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input_b.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output_b.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int turnAround = scan.nextInt();
			int na = scan.nextInt();
			int nb = scan.nextInt();
			ArrayList<Event> list = new ArrayList<Event>();
			for ( int i = 0; i < na; i++ ) {
				int depart = parseTime(scan.next());
				int arrive = parseTime(scan.next()) + turnAround;
				list.add(new Event(depart, false, 0));
				list.add(new Event(arrive, true, 1));
			}
			for ( int i = 0; i < nb; i++ ) {
				int depart = parseTime(scan.next());
				int arrive = parseTime(scan.next()) + turnAround;
				list.add(new Event(depart, false, 1));
				list.add(new Event(arrive, true, 0));
			}
			Collections.sort(list);
			int[] supply = new int[2];
			int[] x = new int[2];
			supply[0] = supply[1] = 0;
			x[0] = x[1] = 0;
			for ( Event e: list ) {
				if ( e.arrive ) {
					supply[e.place]++;
				} else {
					supply[e.place]--;
					x[e.place] = Math.min(x[e.place], supply[e.place]	);
				}
			}
			System.out.printf("Case #%d: %d %d\n", test + 1, -x[0], -x[1]);
			out.printf("Case #%d: %d %d\n", test + 1, -x[0], -x[1]);
		}
		out.close();
	}
	
	public int parseTime(String time) {
		String[] data = time.split(":");
		return Integer.parseInt(data[0])*60+Integer.parseInt(data[1]);
	}
	public class Event implements Comparable<Event> {
		int time;
		int place;
		boolean arrive;

		public Event(int time, boolean arrive, int place ) {
			this.time = time;
			this.arrive = arrive;
			this.place = place;
		}

		public int compareTo( Event other ) {
			if (time != other.time ) 
				return ( time < other.time ? -1 : 1 );
			if ( arrive ) return -1;
			if ( other.arrive ) return 1;
			return 0;
		}
	}
}
