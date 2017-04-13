import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
public class QualifyMagic {


	/**
	 * @param args
	 */
	public static void main(String[] args) {

		String base="C:\\Users\\Bryan\\Documents\\PROCESSING\\GoogleJam\\src\\";
		String input= base + "A-small-attempt0.in";
		String output=base + "out.txt";

		try {
			Scanner sc = new Scanner(new FileReader(input));
			PrintWriter pw = new PrintWriter(output);
			int t = 0;
			int firstA = 0;
			int secondA = 0;


			t = sc.nextInt();
			sc.nextLine();
			//For each Test Case (2 rows and volunteer answers per run)
			for (int i = 0; i < t; i++){
				int[] row1 = new int[4];
				int[] row2 = new int[4];

				firstA = sc.nextInt();
				sc.nextLine();
				row1 = findRow(firstA, sc);

				secondA = sc.nextInt();
				sc.nextLine();
				row2 = findRow(secondA, sc);

				pw.print("Case #" + (i+1) + ": ");
				compareRows(row1, row2, pw);

				pw.println();
			}

			pw.println();
			pw.flush();
			pw.close();
			sc.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}
	public static int[] findRow(int answer, Scanner sc){
		int row = 1;
		int[] answerRow = new int[4];

		//skip lines to reach first answer
		while(row < answer ){
			sc.nextLine();
			row++;
		}
		//create row
		for(int x = 0; x < 4;x++){
			answerRow[x] = sc.nextInt();
		}
		sc.nextLine();
		//skip lines to reach second answer
		while(row < 4){
			sc.nextLine();
			row++;
		}
		return answerRow;
	}

	private static void compareRows(int[] row1, int[] row2, PrintWriter pw){
		int total = 0;
		int match = -1;
		for(int i : row1){
			for(int j: row2){
				if(i == j){
					match = i;
					total++;
				}
			}
		}
		if(total == 1){
			pw.print(match);
		}
		else if(total == 0){
			pw.print("Volunteer cheated!");
		}
		else{
			pw.print("Bad magician!");
		}

	}

}
