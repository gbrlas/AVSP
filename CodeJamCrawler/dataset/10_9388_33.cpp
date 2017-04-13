import java.util.*;
public class Snapper {
	public static void main(String[] args) {
		int n, k, t, caseNum;
		double onValue;
		int onValue2;
		boolean on = false;
		Scanner input = new Scanner(System.in);
		t = input.nextInt();
		for (int i = 0; i < t; i++) {
			on = false;
			n = input.nextInt();
			k = input.nextInt();
			onValue = Math.pow(2, n);
			onValue2 = (int) onValue - 1;
			caseNum = i + 1;
			if ((k % onValue) == onValue2)
				on = true;
			if (on == true)
				System.out.println("Case #" + caseNum + ": ON");
			else System.out.println("Case #" + caseNum + ": OFF");
		}
	}
}
