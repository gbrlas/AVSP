import java.util.*;
import java.io.PrintWriter;
import java.io.File;

public class Main {
	public static void main(String[] args) {
		Scanner input = null;
		PrintWriter output = null;
		try {
			input = new Scanner(new File("A-small-attempt1.in"));
			output = new PrintWriter("A-small-attempt1.out");
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		
		int cases;
		int r, i, vacuum;
		int[] row1 = new int[4];
		int[] row2 = new int[4];
		
		cases = input.nextInt();
		int c = 1;
		while (c < cases+1) {
			r = input.nextInt();
			for (i = 0; i< (r-1)*4; i++) vacuum = input.nextInt();
			for (i=0; i<4; i++) row1[i] = input.nextInt();
			for (i=0; i<(4-r)*4; i++) vacuum = input.nextInt();
			
			r = input.nextInt();
			for (i = 0; i< (r-1)*4; i++) vacuum = input.nextInt();
			for (i=0; i<4; i++) row2[i] = input.nextInt();
			for (i=0; i<(4-r)*4; i++) vacuum = input.nextInt();
			
			int thesame=0, val = 0;
			for (i=0; i<4; i++) {
				for (int j=0; j<4; j++) {
					if (row1[i] == row2[j]) {
						thesame++;
						val = row1[i];
					}
				}
			}
			
			if (thesame == 0)
				output.println("Case #"+c+": Volunteer cheated!");
			else if (thesame == 1)
				output.println("Case #"+c+": "+val);
			else output.println("Case #"+c+": Bad magician!");
			c++;
		}
		output.close();
	}
}