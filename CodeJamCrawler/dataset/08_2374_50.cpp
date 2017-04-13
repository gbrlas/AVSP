import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class TrainTimetable {

	static Scanner scn;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		scn = new Scanner(System.in);
		int cases = Integer.parseInt(scn.nextLine());
		
		for (int c = 1; c <= cases; c++) {
			Time turnaroundTime = Time.parseToTime(Integer.parseInt(scn.nextLine()));
			int na,nb;
			String[] n = scn.nextLine().split(" ");
			na = Integer.parseInt(n[0]);
			nb = Integer.parseInt(n[1]);
			Station sa = new Station();
			Station sb = new Station();
			for (int a = 0; a < na; a++) {
				String line = scn.nextLine();
				String[] times = line.split(" ");
				sa.addRequired(new Time(times[0]));
				sb.addHave(Time.add(new Time(times[1]), turnaroundTime));
			}
			for (int b = 0; b < nb; b++) {
				String line = scn.nextLine();
				String[] times = line.split(" ");
				sb.addRequired(new Time(times[0]));
				sa.addHave(Time.add(new Time(times[1]), turnaroundTime));
			}
			
			System.out.println("Case #" + c + ": " + sa.getTrains() + " " + sb.getTrains());
		}
	}

}

class Time implements Comparable<Time> {
	int h;
	int m;
	
	public Time() {	
	}
	
	public static Time add(Time a, Time b) {
		Time t = new Time();
		t.h = a.h + b.h;
		t.m = a.m + b.m;
		t.h += t.m / 60;
		t.m = t.m % 60;
		return t;
	}

	public Time(int h, int m) {
		this.h = h;
		this.m = m;
	}
	
	public Time(String t) {
		String[] s = t.split(":");
		 h = Integer.parseInt(s[0]);
		 m = Integer.parseInt(s[1]);
	}

	public int compareTo(Time o) {
		if (h == o.h) {
			return m - o.m;
		}
		return h - o.h;
	}
	public static Time parseToTime(int m) {
		return new Time(m/60, m % 60);
	}
	public String toString() {
		return h + ":" + m;
	}
}
class Station {
	List<Time> required;
	List<Time> have;
	
	public Station() {
		required = new LinkedList<Time>();
		have = new LinkedList<Time>();
	}
	
	public void addRequired(Time t) {
		required.add(t);
	}
	
	public void addHave(Time t) {
		have.add(t);
	}
	
	public int getTrains() {
		Collections.sort(required);
		Collections.sort(have);
		
		int hIndex = 0;
		int count = 0;
		for (int i = 0; i < required.size(); i++) {
			if (hIndex >= have.size() || (required.get(i).compareTo(have.get(hIndex)) < 0)) {
				count++;
			} else {
				hIndex++;
			}
		}
		return count;
	}
	public String toString() {
		return "Req: " + required.toString() + " ::: Have: " + have.toString();
	}
}
