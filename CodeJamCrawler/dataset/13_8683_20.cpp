import java.util.*;
import java.io.*;

public class TTTT {

	public static void main(String[] args) throws IOException {
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		Scanner scan = new Scanner(System.in);
		String tests = scan.nextLine();
		int numberOfTests = Integer.parseInt(tests);

		char playerX;
		char playerO;

		int rows = 4;
		int columns = 4;
		int[][] intArray = new int[rows][columns];

	
		
//		System.out.println("first line: " + one[0] );

		char[][] board = new char[4][4];		

		for (int x = 1; x <= numberOfTests; x++) {
			String line1 = scan.nextLine();
			if(line1.equals("")){
				line1=scan.nextLine();
			}
//			System.out.println("line1: " +line1);
			String line2 = scan.nextLine();
			String line3 = scan.nextLine();
			String line4 = scan.nextLine();
			char[] one = line1.toCharArray();
			char[] two = line2.toCharArray();
			char[] three = line3.toCharArray();
			char[] four = line4.toCharArray();
			for (int i = 0; i < 4; i++) {
//				System.out.println("what should be added: ");
//				System.out.println((one[i]));
//				System.out.println((two[i]));
//				System.out.println((three[i]));
//				System.out.println((four[i]));
				board[0][i] = one[i];
				board[1][i] = two[i];
				board[2][i] = three[i];
				board[3][i] = four[i];
				}
//			for (int z = 0; z < rows; z++) {
//				for (int j = 0; j < columns; j++) {
//					System.out.print(" " + board[z][j]);
//				}
//				System.out.println("");
//			}
			
			//XXXX
			if(board[0][0] == board[0][1] && board[0][2] == board[0][3] && board[0][2] == board[0][1] && board[0][0] == 'X'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//OOOO
			else if(board[0][0] == board[0][1] && board[0][2] == board[0][3] && board[0][2] == board[0][1] && board[0][0] == 'O'){
				out.append("Case #"+ x + ": O won" + "\n");
				System.out.println("8");
			}
			//
			//XXXX
			else if(board[1][0] == board[1][1] && board[1][2] == board[1][3] && board[1][2] == board[1][1] && board[1][3] == 'X'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//OOOO
			else if(board[1][0] == board[1][1] && board[1][2] == board[1][3] && board[1][2] == board[1][1] && board[1][3] == 'O'){
				out.append("Case #"+ x + ": O won"+ "\n");
				System.out.println("7");
			}
			//
			//
			//XXXX
			else if(board[2][0] == board[2][1] && board[2][2] == board[2][3] && board[1][2] == board[2][1] && board[2][3] == 'X'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//
			//OOOO
			else if(board[2][0] == board[2][1] && board[2][2] == board[2][3] && board[2][2] == board[2][1] && board[2][3] == 'O'){
				out.append("Case #"+ x + ": O won" + "\n");
				System.out.println("6");
			}
			//
			//
			//
			//XXXX
			else if(board[3][0] == board[3][1] && board[3][2] == board[3][3] && board[3][2] == board[3][1] && board[3][3] == 'X'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//
			//
			//OOOO
			else if(board[3][0] == board[3][1] && board[3][2] == board[3][3] && board[3][2] == board[3][1] && board[3][3] == 'O'){
				out.append("Case #"+ x + ": O won" + "\n");
				System.out.println("5");
			}
			/**
			 * 
			 */
			//XXXT
			else if(board[0][0] == board[0][1] && board[0][2] == board[0][1] && board[0][2] == 'X' && board[0][3] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//OOOT
			else if(board[0][0] == board[0][1] && board[0][2] == board[0][1] && board[0][2] == 'O' && board[0][3] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
				System.out.println("4");
			}
			//
			//XXXT
			else if(board[1][0] == board[1][1] && board[1][2] == board[1][1] && board[1][2] == 'X' && board[1][3] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//OOOT
			else if(board[1][0] == board[1][1] && board[1][2] == board[1][1] && board[1][2] == 'O' && board[1][3] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
				System.out.println("3");
			}
			//
			//
			//XXXT
			else if(board[2][0] == board[2][1] && board[2][2] == board[2][1] && board[2][2] == 'X' && board[2][3] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//
			//OOOT
			else if(board[2][0] == board[2][1] && board[2][2] == board[2][1] && board[2][2] == 'O' && board[2][3] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
				System.out.println("2");
			}
			//
			//
			//
			//XXXT
			else if(board[3][0] == board[3][1] && board[3][2] == board[3][1] && board[3][2] == 'X' && board[3][3] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//
			//
			//OOOT
			else if(board[3][0] == board[3][1] && board[3][2] == board[3][1] && board[3][2] == 'O' && board[3][3] == 'T'){
				out.append("Case #"+ x + ": O won" +"\n");
				System.out.println("1");
			}
			
			/**
			 * 
			 */
			//XXTX
			else if(board[0][0] == board[0][1] && board[0][3] == board[0][1] && board[0][1] == 'X' && board[0][2] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//OOTO
			else if(board[0][0] == board[0][1] && board[0][3] == board[0][1] && board[0][1] == 'O' && board[0][2] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//
			//XXTX
			else if(board[1][0] == board[1][1] && board[1][3] == board[1][1] && board[1][1] == 'X' && board[1][2] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//OOTO
			else if(board[1][0] == board[1][1] && board[1][3] == board[1][1] && board[1][1] == 'O' && board[1][2] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//
			//
			//XXTX
			else if(board[2][0] == board[2][1] && board[2][3] == board[2][1] && board[2][1] == 'X' && board[2][2] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//
			//OOTO
			else if(board[2][0] == board[2][1] && board[2][3] == board[2][1] && board[2][1] == 'O' && board[2][2] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//
			//
			//
			//XXTX
			else if(board[3][0] == board[3][1] && board[3][3] == board[3][1] && board[3][1] == 'X' && board[3][2] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//
			//
			//OOTO
			else if(board[3][0] == board[3][1] && board[3][3] == board[3][1] && board[3][1] == 'O' && board[3][2] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			/**
			 * 
			 */
			//XTXX
			else if(board[0][0] == board[0][2] && board[0][3] == board[0][0] && board[0][0] == 'X' && board[0][1] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//OTOO
			else if(board[0][0] == board[0][2] && board[0][3] == board[0][0] && board[0][0] == 'O' && board[0][1] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//
			//XTXX
			else if(board[1][0] == board[1][2] && board[1][3] == board[1][0] && board[1][0] == 'X' && board[1][1] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//OTOO
			else if(board[1][0] == board[1][2] && board[1][3] == board[1][0] && board[1][0] == 'O' && board[1][1] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//
			//
			//XTXX
			else if(board[2][0] == board[2][2] && board[2][3] == board[2][0] && board[2][0] == 'X' && board[2][1] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//
			//OTOO
			else if(board[2][0] == board[2][2] && board[2][3] == board[2][0] && board[2][0] == 'O' && board[2][1] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//
			//
			//
			//XTXX
			else if(board[3][0] == board[3][2] && board[3][3] == board[3][0] && board[3][0] == 'X' && board[3][1] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//
			//
			//OTOO
			else if(board[3][0] == board[3][2] && board[3][3] == board[3][0] && board[3][0] == 'O' && board[3][1] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			/**
			 * 
			 */
			//TXXX
			else if(board[0][1] == board[0][2] && board[0][3] == board[0][1] && board[0][1] == 'X' && board[0][0] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//TOOO
			else if(board[0][1] == board[0][2] && board[0][3] == board[0][1] && board[0][1] == 'O' && board[0][0] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//
			//TXXX
			else if(board[1][1] == board[1][2] && board[1][3] == board[1][1] && board[1][1] == 'X' && board[1][0] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//TOOO
			else if(board[1][1] == board[1][2] && board[1][3] == board[1][1] && board[1][1] == 'O' && board[1][0] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//
			//
			//TXXX
			else if(board[2][1] == board[2][2] && board[2][3] == board[2][1] && board[2][1] == 'X' && board[2][0] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//
			//TOOO
			else if(board[2][1] == board[2][2] && board[2][3] == board[2][1] && board[2][1] == 'O' && board[2][0] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//
			//
			//
			//TXXX
			else if(board[3][1] == board[3][2] && board[3][3] == board[3][1] && board[3][1] == 'X' && board[3][0] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//
			//
			//
			//TOOO
			else if(board[3][1] == board[3][2] && board[3][3] == board[3][1] && board[3][1] == 'O' && board[3][0] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			/**
			 * 
			 */
			//X
			//X
			//X
			//X
			else if(board[0][0] == board[1][0] && board[2][0] == board[3][0] && board[2][0] == board[1][0] && board[0][0] == 'X'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//O
			//O
			//O
			//O
			else if(board[0][0] == board[1][0] && board[2][0] == board[3][0] && board[2][0] == board[1][0] && board[0][0] == 'O'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			// X
			// X
			// X
			// X
			else if(board[0][1] == board[1][1] && board[2][1] == board[3][1] && board[2][1] == board[1][1] && board[0][1] == 'X'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			// O
			// O
			// O
			// O
			else if(board[0][1] == board[1][1] && board[2][1] == board[3][1] && board[2][1] == board[1][1] && board[0][1] == 'O'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//  X
			//  X
			//  X
			//  X
			else if(board[0][2] == board[1][2] && board[2][2] == board[3][2] && board[2][2] == board[1][2] && board[0][2] == 'X'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//  O
			//  O
			//  O
			//  O
			else if(board[0][2] == board[1][2] && board[2][2] == board[3][2] && board[2][2] == board[1][2] && board[0][2] == 'O'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//   X
			//   X
			//   X
			//   X
			else if(board[0][3] == board[1][3] && board[2][3] == board[3][3] && board[2][3] == board[1][3] && board[0][3] == 'X'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//   O
			//   O
			//   O
			//   O
			else if(board[0][3] == board[1][3] && board[2][3] == board[3][3] && board[2][3] == board[1][3] && board[0][3] == 'O'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			/**
			 * 
			 */
			//X
			//X
			//X
			//T
			else if(board[0][0] == board[1][0] && board[2][0] == board[0][0] && board[2][0] == board[1][0] && board[0][0] == 'X' && board[3][3] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//O
			//O
			//O
			//T
			else if(board[0][0] == board[1][0] && board[2][0] == board[0][0] && board[2][0] == board[1][0] && board[0][0] == 'O' && board[3][3] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			// X
			// X
			// X
			// T
			else if(board[0][1] == board[1][1] && board[2][1] == board[0][1] && board[2][1] == board[1][1] && board[0][1] == 'X' && board[3][1] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			// O
			// O
			// O
			// T
			else if(board[0][1] == board[1][1] && board[2][1] == board[0][1] && board[2][1] == board[1][1] && board[0][1] == 'O' && board[3][1] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//  X
			//  X
			//  X
			//  T
			else if(board[0][2] == board[1][2] && board[2][2] == board[0][2] && board[2][2] == board[1][2] && board[0][2] == 'X' && board[3][2] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//  O
			//  O
			//  O
			//  T
			else if(board[0][2] == board[1][2] && board[2][2] == board[0][2] && board[2][2] == board[1][2] && board[0][2] == 'O' && board[3][2] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//   X
			//   X
			//   X
			//   T
			else if(board[0][3] == board[1][3] && board[2][3] == board[0][3] && board[2][3] == board[1][3] && board[0][3] == 'X' && board[3][3] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//   O
			//   O
			//   O
			//   T
			else if(board[0][3] == board[1][3] && board[2][3] == board[0][3] && board[2][3] == board[1][3] && board[0][3] == 'O' && board[3][3] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			/**
			 * 
			 */
			//X
			//X
			//T
			//X
			else if(board[0][0] == board[1][0] && board[3][0] == board[0][0] && board[3][0] == board[1][0] && board[0][0] == 'X' && board[2][0] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//O
			//O
			//T
			//X
			else if(board[0][0] == board[1][0] && board[3][0] == board[0][0] && board[3][0] == board[1][0] && board[0][0] == 'O' && board[2][0] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			// X
			// X
			// T
			// X
			else if(board[0][1] == board[1][1] && board[3][1] == board[0][1] && board[3][1] == board[1][1] && board[0][1] == 'X' && board[2][1] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			// O
			// O
			// T
			// X
			else if(board[0][1] == board[1][1] && board[3][1] == board[0][1] && board[3][1] == board[1][1] && board[0][1] == 'O' && board[2][1] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//  X
			//  X
			//  T
			//  X
			else if(board[0][2] == board[1][2] && board[3][2] == board[0][2] && board[3][2] == board[1][2] && board[0][2] == 'X' && board[2][2] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//  O
			//  O
			//  T
			//  X
			else if(board[0][2] == board[1][2] && board[3][2] == board[0][2] && board[3][2] == board[1][2] && board[0][2] == 'O' && board[2][2] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//   X
			//   X
			//   T
			//   X
			else if(board[0][3] == board[1][3] && board[3][3] == board[0][3] && board[3][3] == board[1][3] && board[0][3] == 'X' && board[2][3] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//   O
			//   O
			//   T
			//   X
			else if(board[0][3] == board[1][3] && board[3][3] == board[0][3] && board[3][3] == board[1][3] && board[0][3] == 'O' && board[2][3] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			/**
			 * 
			 */
			//X
			//T
			//X
			//X
			else if(board[0][0] == board[2][0] && board[3][0] == board[0][0] && board[3][0] == board[2][0] && board[0][0] == 'X' && board[1][0] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//O
			//T
			//O
			//O
			else if(board[0][0] == board[2][0] && board[3][0] == board[0][0] && board[3][0] == board[2][0] && board[0][0] == 'O' && board[1][0] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			// X
			// T
			// X
			// X
			else if(board[0][1] == board[2][1] && board[3][1] == board[0][1] && board[3][1] == board[2][1] && board[0][1] == 'X' && board[1][1] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			// O
			// T
			// O
			// O
			else if(board[0][1] == board[2][1] && board[3][1] == board[0][1] && board[3][1] == board[2][1] && board[0][1] == 'O' && board[1][1] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//  X
			//  T
			//  X
			//  X
			else if(board[0][2] == board[2][2] && board[3][2] == board[0][2] && board[3][2] == board[2][2] && board[0][2] == 'X' && board[1][2] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//  O
			//  T
			//  O
			//  O
			else if(board[0][2] == board[2][2] && board[3][2] == board[0][2] && board[3][2] == board[2][2] && board[0][2] == 'O' && board[1][2] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//   X
			//   T
			//   X
			//   X
			else if(board[0][3] == board[2][3] && board[3][3] == board[0][3] && board[3][3] == board[2][3] && board[0][3] == 'X' && board[1][3] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//   O
			//   T
			//   O
			//   O
			else if(board[0][3] == board[2][3] && board[3][3] == board[0][3] && board[3][3] == board[2][3] && board[0][3] == 'O' && board[1][3] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//T
			//X
			//X
			//X
			else if(board[1][0] == board[2][0] && board[3][0] == board[1][0] && board[3][0] == board[2][0] && board[1][0] == 'X' && board[0][0] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//T
			//O
			//O
			//O
			else if(board[1][0] == board[2][0] && board[3][0] == board[1][0] && board[3][0] == board[2][0] && board[1][0] == 'O' && board[0][0] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			// T
			// X
			// X
			// X
			else if(board[1][1] == board[2][1] && board[3][1] == board[1][1] && board[3][1] == board[2][1] && board[1][1] == 'X' && board[0][1] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			// T
			// O
			// O
			// O
			else if(board[1][1] == board[2][1] && board[3][1] == board[1][1] && board[3][1] == board[2][1] && board[1][1] == 'O' && board[0][1] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//  T
			//  X
			//  X
			//  X
			else if(board[1][2] == board[2][2] && board[3][2] == board[1][2] && board[3][2] == board[2][2] && board[1][2] == 'X' && board[0][2] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//  T
			//  O
			//  O
			//  O
			else if(board[1][2] == board[2][2] && board[3][2] == board[1][2] && board[3][2] == board[2][2] && board[1][2] == 'O' && board[0][2] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//   T
			//   X
			//   X
			//   X
			else if(board[1][3] == board[2][3] && board[3][3] == board[1][3] && board[3][3] == board[2][3] && board[1][3] == 'X' && board[0][3] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//   T
			//   O
			//   O
			//   O
			else if(board[1][3] == board[2][3] && board[3][3] == board[1][3] && board[3][3] == board[2][3] && board[1][3] == 'O' && board[0][3] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//X
			// X
			//  X
			//   X
			else if(board[0][0] == board[1][1] && board[1][1]== board[2][2] && board[3][3] == board[2][2] && board[0][0] =='X'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//O
			// O
			//  O
			//   O
			else if(board[0][0] == board[1][1] && board[1][1]== board[2][2] && board[3][3] == board[2][2] && board[0][0] =='O'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//T
			// X
			//  X
			//   X
			else if(board[3][3] == board[1][1] && board[1][1]== board[2][2] && board[3][3] == board[2][2] && board[1][1] =='X' && board[0][0] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//T
			// O
			//  O
			//   O
			else if(board[3][3] == board[1][1] && board[1][1]== board[2][2] && board[3][3] == board[2][2] && board[1][1] =='O' && board[0][0] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//X
			// T
			//  X
			//   X
			else if(board[0][0] == board[3][3] && board[0][0]== board[2][2] && board[3][3] == board[2][2] && board[0][0] =='X' && board[1][1] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//O
			// T
			//  O
			//   O
			else if(board[0][0] == board[3][3] && board[0][0]== board[2][2] && board[3][3] == board[2][2] && board[0][0] =='O' && board[1][1] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//X
			// X
			//  T
			//   X
			else if(board[0][0] == board[1][1] && board[1][1]== board[3][3] && board[3][3] == board[1][1] && board[0][0] =='X' && board[2][2] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//O
			// O
			//  T
			//   O
			else if(board[0][0] == board[1][1] && board[1][1]== board[3][3] && board[3][3] == board[1][1] && board[0][0] =='O' && board[2][2] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//X
			// X
			//  X
			//   T
			else if(board[0][0] == board[1][1] && board[1][1]== board[2][2] && board[0][0] == board[2][2] && board[0][0] =='X' && board[3][3] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//O
			// O
			//  O
			//   T
			else if(board[0][0] == board[1][1] && board[1][1]== board[2][2] && board[0][0] == board[2][2] && board[0][0] =='O' && board[3][3] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			/**
			 * 
			 */
			//   X
			//  X
			// T 
			//X 
			else if(board[0][3] == board[1][2] && board[1][2]== board[3][0] && board[0][3] == board[3][0] && board[2][1] == board[1][2] && board[3][0] =='X'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			else if(board[0][3] == board[1][2] && board[1][2]== board[3][0] && board[0][3] == board[3][0] && board[2][1] == board[1][2] && board[3][0] =='O'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			else if(board[0][3] == board[1][2] && board[1][2]== board[3][0] && board[0][3] == board[3][0] && board[3][0] =='X' && board[2][1] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//   O
			//  O
			// O
			//T
			else if(board[0][3] == board[2][1] && board[1][2]== board[0][3] && board[0][3] == board[2][1] && board[0][3] =='O' && board[3][0] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//   X
			//  X
			// X 
			//T
			else if(board[0][3] == board[2][1] && board[1][2]== board[0][3] && board[0][3] == board[2][1] && board[0][3] =='X' && board[3][0] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//   O
			//  O
			// T
			//O
			else if(board[0][3] == board[1][2] && board[1][2]== board[3][0] && board[0][3] == board[3][0] && board[3][0] =='O' && board[2][1] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			//   X
			//  T
			// X 
			//X
			else if(board[2][1] == board[0][3] && board[2][1]== board[3][0] && board[0][3] == board[3][0] && board[3][0] =='X' && board[1][2] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//   O
			//  T
			// O 
			//O
			else if(board[2][1] == board[0][3] && board[2][1]== board[3][0] && board[0][3] == board[3][0] && board[3][0] =='O' && board[1][2] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
				}
			//   T
			//  X
			// X
			//X
			else if(board[1][2] == board[2][1] && board[3][0] == board[1][2] && board[3][0] == board[2][1] && board[3][0] == 'X' && board [0][3] == 'T'){
				out.append("Case #"+ x + ": X won" + "\n");
			}
			//   T
			//  O
			// O
			//O
			else if(board[1][2] == board[2][1] && board[3][0] == board[1][2] && board[3][0] == board[2][1] && board[3][0] == 'O' && board [0][3] == 'T'){
				out.append("Case #"+ x + ": O won" + "\n");
			}
			else if(board[0][0] == '.' || board[1][0] == '.' || board[2][0] == '.' ||board[3][0] == '.' || board[0][1] == '.' || 
					board[1][1] == '.' || board[2][1] == '.' || board[3][1] == '.' ||board[1][2] == '.' || board[2][2] == '.' ||board[3][2] == '.'){
				out.append("Case #"+ x + ": Game has not completed" + "\n");
			}
			else{
				out.append("Case #"+ x + ": Draw" + "\n");
			}
			
		}
		out.flush();
	}
}
