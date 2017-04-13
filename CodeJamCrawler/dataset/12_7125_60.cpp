import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) {
		String v[] = new String[26];
		v[0] = "y"; //a
		v[1] = "h"; //b
		v[2] = "e"; //c
		v[3] = "s"; //d
		v[4] = "o"; //e
		v[5] = "c"; //f
		v[6] = "v"; //g
		v[7] = "x"; //h
		v[8] = "d"; //i
		v[9] = "u"; //j
		v[10] = "i"; //k
		v[11] = "g"; //l
		v[12] = "l"; //m
		v[13] = "b"; //n
		v[14] = "k"; //o
		v[15] = "r"; //p
		v[16] = "z"; //q
		v[17] = "t"; //r
		v[18] = "n"; //s
		v[19] = "w"; //t
		v[20] = "j"; //u
		v[21] = "p"; //v
		v[22] = "f"; //w
		v[23] = "m"; //x
		v[24] = "a"; //y
		v[25] = "q"; //z
		Scanner sc = new Scanner(System.in);
		int t = Integer.parseInt(sc.nextLine());
		for (int tt = 1; tt <= t; tt++) {
			String s = sc.nextLine();
			String r = "";
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
					r = r + v[s.charAt(i) - 'a'];
				} else if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
					r = r + v[s.charAt(i) - 'A'];
				} else {
					r = r + s.charAt(i);
				}
			}
			System.out.println("Case #" + tt + ": " + r);
		}
	}

}
