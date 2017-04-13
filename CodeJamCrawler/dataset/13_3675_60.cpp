import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class MainProgram {

	static BufferedReader in = null;
	int X = 1, O = -1, T = 0;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		in = new BufferedReader(new FileReader("/Users/himanshugupta/workspace/practice/TicTacToeTomek/input.txt")); 
		int N = Integer.parseInt(in.readLine());
		for (int i=0; i<N; i++){
			System.out.println("Case #"+(i+1)+": "+getOutput(readInput()));
		}
		in.close();
	}

	public static char[][] readInput() throws IOException{
		char[][] A = new char[4][4];
		for (int i=0; i<4; i++){
			String s = in.readLine();
			for (int j=0; j<4; j++){
				A[i][j] = s.charAt(j); 
			}
		}
		in.readLine();
		return A;
	}
	
	public static String getOutput(char[][] A){
		boolean XhasWon = false, OhasWon = false, dotEncountered = false;
		for (int i=0; i<4; i++){
			XhasWon = true;
			OhasWon = true;
			for (int j=0; j<4; j++){
				if (A[i][j] == 'X'){
					OhasWon = false;
				}
				else if (A[i][j] == 'O'){
					XhasWon = false;
				}
				else if (A[i][j] == '.'){
					XhasWon = OhasWon = false;
					dotEncountered = true;
					break;
				}
				if (!XhasWon && !OhasWon)
					break;
			}
			if (XhasWon)
				return "X won";
			if (OhasWon)
				return "O won";
		}
		for (int i=0; i<4; i++){
			XhasWon = true;
			OhasWon = true;
			for (int j=0; j<4; j++){
				if (A[j][i] == 'X'){
					OhasWon = false;
				}
				else if (A[j][i] == 'O'){
					XhasWon = false;
				}
				else if (A[j][i] == '.'){
					XhasWon = OhasWon = false;
					dotEncountered = true;
					break;
				}
				if (!XhasWon && !OhasWon)
					break;
			}
			if (XhasWon)
				return "X won";
			if (OhasWon)
				return "O won";
		}
		XhasWon = true;
		OhasWon = true;
		for (int i=0; i<4; i++){
			if (A[i][i] == 'X'){
				OhasWon = false;
			}
			else if (A[i][i] == 'O'){
				XhasWon = false;
			}
			else if (A[i][i] == '.'){
				XhasWon = OhasWon = false;
				dotEncountered = true;
				break;
			}
			if (!XhasWon && !OhasWon)
				break;
		}
		if (XhasWon)
			return "X won";
		if (OhasWon)
			return "O won";
		XhasWon = true;
		OhasWon = true;
		for (int i=0; i<4; i++){
			if (A[i][3-i] == 'X'){
				OhasWon = false;
			}
			else if (A[i][3-i] == 'O'){
				XhasWon = false;
			}
			else if (A[i][3-i] == '.'){
				XhasWon = OhasWon = false;
				dotEncountered = true;
				break;
			}
			if (!XhasWon && !OhasWon)
				break;
		}
		if (XhasWon)
			return "X won";
		if (OhasWon)
			return "O won";
		if (dotEncountered)
			return "Game has not completed";
		return "Draw";
	}
	
}
