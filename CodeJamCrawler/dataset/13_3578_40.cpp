import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class TicTacToe {
	public static void main(String...args) {
		String[][] strArr = new String[4][4];
		BufferedReader br = null;
		BufferedWriter bw = null;
		try {

			String sCurrentLine = null;
			br = new BufferedReader(new FileReader(System.getProperty("user.home") + "\\A-small-attempt1.in"));

			bw = new BufferedWriter(new FileWriter(System.getProperty("user.home") + "\\A-small-attempt1.out"));
			PrintWriter fileOut = new PrintWriter(bw);
			
			long numberInp = Integer.parseInt(br.readLine());
			String var = null;
			String winner = null;
			boolean incompleteGame = false;
			String diag1 = null;
			String diag2 = null;
			for (int i = 1; i<= numberInp; i++) {
				for (int line = 0; line < 4; line++) {
					sCurrentLine = br.readLine();
					strArr[line][0] = String.valueOf(sCurrentLine.charAt(0));
					strArr[line][1] = String.valueOf(sCurrentLine.charAt(1));
					strArr[line][2] = String.valueOf(sCurrentLine.charAt(2));
					strArr[line][3] = String.valueOf(sCurrentLine.charAt(3));
					
					if (sCurrentLine.contains(".")) {
						incompleteGame = true;
					}
					//winner row wise
					winner = winner(sCurrentLine);
					if (winner != null) {
						//read extra lines
						for (int read = line+1; read<4; read++) {
							br.readLine();
						}
						break;
					}
				}
				
				//check for column wise
				if (winner == null) {
					for (int arr1=0; arr1<4; arr1++) {
						var = strArr[0][arr1]+strArr[1][arr1]+strArr[2][arr1]+ strArr[3][arr1];		
						winner = winner(var);
						if (winner != null) {
							break;
						}
					}
				} 
				
				//check for diagonal
				if (winner == null) {
					diag1 = strArr[0][0]+strArr[1][1]+strArr[2][2]+ strArr[3][3];	
					winner = winner(diag1);
					if (winner == null) {
						diag2 = strArr[0][3]+strArr[1][2]+strArr[2][1]+ strArr[3][0];
						winner = winner(diag2);
					}
				}
				
				if (winner != null) {
					fileOut.println("Case #"+i+": "+ winner);
				} else if (incompleteGame) {
					fileOut.println("Case #"+i+": "+ "Game has not completed");
				} else {
					fileOut.println("Case #"+i+": "+ "Draw");
				}
				
				incompleteGame = false;
				winner = null;
				br.readLine();
			}
			fileOut.flush();
			bw.flush();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				br.close();
				bw.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
	}
	
	private static String winner (String sCurrentLine) {
		if(sCurrentLine.equals("XXXX") || sCurrentLine.equals("XTXX")
			|| sCurrentLine.equals("XXTX") || sCurrentLine.equals("XXXT")
			|| sCurrentLine.equals("TXXX")) {
			return "X won";
		} else if (sCurrentLine.equals("OOOO") || sCurrentLine.equals("OTOO")
				|| sCurrentLine.equals("OOTO") || sCurrentLine.equals("OOOT")
				|| sCurrentLine.equals("TOOO")) {
			return "O won";
		}
		return null;
	}

}
