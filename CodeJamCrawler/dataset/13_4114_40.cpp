import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;

class ProblemOne{
	public static void main(String[] args) throws NumberFormatException, IOException {
		File f = new File("input.txt");
		FileInputStream instream = new FileInputStream(f);
		BufferedReader reader = new BufferedReader(new InputStreamReader(instream));
				
		File f2 = new File("output.txt");
		FileOutputStream outstream = new FileOutputStream(f2);
		
		int cases = Integer.parseInt(reader.readLine());
		
		char[][] game = new char[4][4];
		
		for (int i = 0; i < cases; i++) {
			game[0] = reader.readLine().toCharArray();
			game[1] = reader.readLine().toCharArray();
			game[2] = reader.readLine().toCharArray();
			game[3] = reader.readLine().toCharArray();
			reader.readLine();
			
			String s = String.format("Case #%d: %s\n", i+1, calc(game));
			System.out.println(s);
			outstream.write(s.getBytes());
		}
		outstream.flush();
		outstream.close();
		instream.close();
	}
	
	public static String calc(char[][] game){
		// check rows
		for (int i = 0; i < 4; i++) {
			int sum = game[i][0] + game[i][1] + game[i][2] + game[i][3];
			sum = sum >> 2;
			
			if (sum == 'X' || sum == (3*'X'/4 + 'T'/4)) {
				return "X won";
			}else if(sum == 'O' || sum == (3*'O'/4 + 'T'/4)){
				return "O won";
			}
		}
		
		// check cols
		for (int i = 0; i < 4; i++) {
			int sum = game[0][i] + game[1][i] + game[2][i] + game[3][i];
			sum = sum >> 2;
			
			if (sum == 'X' || sum == (3*'X'/4 + 'T'/4)) {
				return "X won";
			}else if(sum == 'O' || sum == (3*'O'/4 + 'T'/4)){
				return "O won";
			}
		}
		
		// check diagonals
		int sum = game[0][0] + game[1][1] + game[2][2] + game[3][3];
		sum = sum >> 2;
		
		if (sum == 'X' || sum == (3*'X'/4 + 'T'/4)) {
			return "X won";
		}else if(sum == 'O' || sum == (3*'O'/4 + 'T'/4)){
			return "O won";
		}
		
		sum = game[0][3] + game[1][2] + game[2][1] + game[3][0];
		sum = sum >> 2;
		
		if (sum == 'X' || sum == (3*'X'/4 + 'T'/4)) {
			return "X won";
		}else if(sum == 'O' || sum == (3*'O'/4 + 'T'/4)){
			return "O won";
		}
		
		
		// Draw or no completed
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if(game[i][j] == '.')
					return "Game has not completed";
			}
		}
		return "Draw";
	}
	
	
}