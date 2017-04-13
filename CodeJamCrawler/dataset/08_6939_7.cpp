import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;


public class ProblemB {
	public static void main(String[] args) throws Exception {
		new ProblemB();
	}

	public ProblemB() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input_b.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"output-B.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			HashMap<String,Integer> colorMap = new HashMap<String,Integer>();
			int colorIndex = 0;
			int n = scan.nextInt();
			Event[] list = new Event[n];
			for (int i = 0; i < n; i++) {
				String color = scan.next();
				int c = 0;
				if ( colorMap.containsKey(color)) c = colorMap.get(color);
				else {
					c = colorIndex;
					colorMap.put(color, colorIndex++);
				}
				int a = scan.nextInt();
				int b = scan.nextInt();
				list[i] = new Event(a,b, c);
			}
			Arrays.sort(list);
//			for ( Event e: list) System.out.println(e);
			int INF = 1000000;
			int answer = INF;
			for (int mask = 0; mask < 1 << n; mask++) {
			    int need = 1;
			    int used = 0;
			    boolean ok = true;
			    for (int i = 0; i < n; i++) {
					if ((mask & (1 << i)) == 0) continue;
					used |= list[i].color;
					if ( need < list[i].a ) ok = false;
					need = Math.max(need, list[i].b+1);
				}
			    ok &= need > 10000;
			    ok &= Integer.bitCount(used) <= 3;
			    int offers = Integer.bitCount(mask);
			    if ( ok & offers < answer ) answer = offers;
			}
			String result = String.format("Case #%d: ",test+1);
			if ( answer == INF ) result += "IMPOSSIBLE\n";
			else result += answer + "\n";
			System.out.print(result);
			out.print(result);
		}
		out.close();
	}
	
	public class Event implements Comparable<Event> {
		int a;
		int b;
		int color;
		int c;
		public Event(int a, int b, int c) {
			this.a = a;
			this.b = b;
			this.c = c;
			color = 1 << c;
		}

		public int compareTo(Event e) {
			if ( a != e.a ) return a-e.a;
			return b-e.b;
		}
		public String toString() {
			return String.format("a = %d, b = %d, c = %d\n",a,b, c);
		}
	}

}
