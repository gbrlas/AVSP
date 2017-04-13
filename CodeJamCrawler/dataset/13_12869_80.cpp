import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class TicTacToe {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(TicTacToe.class.getResourceAsStream("A-large.in"));
		
		int count = sc.nextInt();
		for(int i=0;i<count;i++) {
			char[][] game = readGame(sc);
			String result = null;
			if(won('X', game)) {
				result = "X won";
			} else if(won('O', game)) {
				result = "O won";
			}else if(!isFinished(game)) {
				result = "Game has not completed";
			} else {
				result ="Draw";
			}
			
			System.out.println("Case #"+(i+1)+": "+ result);
		}

	}

	private static boolean won(char player, char[][] game) {
		for(int c=0;c<4;c++) {
			if(full(c,0,0,1,player, game)) {
				return true;
			}
		}
		for(int r=0;r<4;r++) {
			if(full(0,r,1,0, player, game)) {
				return true;
			}
		}
		
		return full(0,0,1,1,player,game) || full(0,3,1,-1,player,game); 
	}

	private static boolean full(int c, int r, int dc, int dr, char player,
			char[][] game) {

		int players = 0;
		int wildcards = 0;
		
		for(int ci =c, ri = r; 0<=ci && ci<4 && ri>=0&& ri<4; ci+=dc, ri+=dr) {
			if(game[ci][ri] == player) {
				players++;
			}
			if(game[ci][ri] == 'T') {
				wildcards++;
			}
		}
		
		return players == 4 || (players == 3 && wildcards ==1);
	}

	private static boolean isFinished(char[][] game) {
		for(int r=0;r<4;r++) {
			for(int c=0;c<4;c++) {
				if(game[r][c] =='.') {
					return false;
				}
			}
		}
		return true;
	}

	private static char[][] readGame(Scanner sc) {
		char[][] result = new char[4][4];
		for(int r=0;r<4;r++) {
			String line = sc.next();
			for(int c=0;c<4;c++) {
				result[r][c] = line.charAt(c);
			}
		}
		sc.nextLine();
		return result;
	}
	


}
