package cw.qualify;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class TicTacToe {
	public static void main(String[] args) throws IOException {
		// with your powers combined!
		File in = new File(args[0]);
		try (Scanner scanner = new Scanner(in)) {
			File out = new File(in.getParent(), in.getName() + "_OUT.txt");
			try (FileWriter fw = new FileWriter(out)) {
				int cases = Integer.parseInt(scanner.nextLine());
				for (int i = 1; i <= cases; i++) {
					char[][] arr = new char[4][4];
					for (int x = 0; x < 4; x++) {
						String line = scanner.nextLine().trim();
						arr[x] = line.toCharArray();
					}
					
					if(scanner.hasNextLine()){
						scanner.nextLine();
					}

					String ans = getStatus(arr);
					String msg = String.format("Case #%d: %s", i, ans);
					System.out.println(msg);
					fw.append(msg);
					if (i < cases) {
						fw.append("\n");
					}
				}
			}
		}
	}

	private static String getStatus(char[][] arr) {
		// scan each row
		for (int i = 0; i < 4; i++) {
			String winner = checkWinner(arr[i]);
			if (winner != null) {
				return winner;
			}
		}

		// scan each col
		for (int j = 0; j < 4; j++) {
			char[] colArr = new char[4];
			for (int i = 0; i < 4; i++) {
				colArr[i] = arr[i][j];
			}
			String winner = checkWinner(colArr);
			if (winner != null) {
				return winner;
			}
		}

		// scan right diag
		char[] rdiag = new char[4];
		for (int i = 0; i < 4; i++) {
			rdiag[i] = arr[i][i];
		}
		String winner = checkWinner(rdiag);
		if (winner != null) {
			return winner;
		}
		
		// scan left diag
		char[] ldiag = new char[4];
		for (int i = 3; i >= 0; i--) {
			ldiag[i] = arr[i][3-i];
		}
		winner = checkWinner(ldiag);
		if (winner != null) {
			return winner;
		}
		
		//scan for empty space
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(arr[i][j] == '.'){
					return "Game has not completed";
				}
			}
		}

		return "Draw";
	}

	private static String checkWinner(char[] line) {
		String str = new String(line);
		if(str.matches("[OT]{4}")){
			return "O won";
		} else if(str.matches("[XT]{4}")){
			return "X won";
		}
		return null;
	}
}
